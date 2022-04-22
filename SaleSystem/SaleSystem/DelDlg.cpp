// DelDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "DelDlg.h"
#include "InfoFile.h"


// CDelDlg

IMPLEMENT_DYNCREATE(CDelDlg, CFormView)

CDelDlg::CDelDlg()
	: CFormView(DIALOG_DEL)
	, m_price(0)
	, m_num(0)
{

}

CDelDlg::~CDelDlg()
{
}

void CDelDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT2, m_price);
	DDX_Text(pDX, IDC_EDIT6, m_num);
}

BEGIN_MESSAGE_MAP(CDelDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDelDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON5, &CDelDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &CDelDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CDelDlg ���

#ifdef _DEBUG
void CDelDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDelDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDelDlg ��Ϣ�������


void CDelDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	CInfoFile file;
	file.ReadDocline();

	for (auto it = file.ls.begin(); it != file.ls.end(); it++)
	{
		m_combo.AddString((CString)it->name.c_str());
	}
	m_combo.SetCurSel(0);

	OnCbnSelchangeCombo1();
}


void CDelDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index = m_combo.GetCurSel();
	CString name;
	m_combo.GetLBText(index, name);

	CInfoFile file;
	file.ReadDocline();

	for (auto it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (name == (CString)it->name.c_str())
		{
			m_price = it->price;
			m_num = 0;
			UpdateData(FALSE);
			break;
		}
	}
	file.ls.clear();
	
}


void CDelDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	if (m_num <= 0)
	{
		MessageBox(TEXT("��������С�ڵ���0"));
		return;
	}
	int index = m_combo.GetCurSel();
	CString name;
	m_combo.GetLBText(index, name);

	CInfoFile file;
	file.ReadDocline();

	for (auto it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (name == (CString)it->name.c_str())
		{
			it->num -= m_num;
		}
	}
	file.WirteDocline();
	CString str;
	str.Format(_T("ɾ����Ʒ��%s \r\n���ۣ�%d \r\n������%d "), name, m_price, m_num);
	MessageBox(str);
	m_num = 0;
	UpdateData(FALSE);

}


void CDelDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_combo.SetCurSel(0);
	m_num = 0;
	OnCbnSelchangeCombo1();
}
