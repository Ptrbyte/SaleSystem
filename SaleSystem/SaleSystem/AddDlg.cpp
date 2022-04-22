// AddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "AddDlg.h"
#include "InfoFile.h"


// CAddDlg

IMPLEMENT_DYNCREATE(CAddDlg, CFormView)

CAddDlg::CAddDlg()
	: CFormView(DIALOG_ADD)
	, m_price(0)
	, m_num(0)
	, m_name(_T(""))
	, m_price1(0)
	, m_num1(0)
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_price);
	DDX_Text(pDX, IDC_EDIT2, m_num);
	DDX_Text(pDX, IDC_EDIT4, m_name);
	DDX_Text(pDX, IDC_EDIT5, m_price1);
	DDX_Text(pDX, IDC_EDIT8, m_num1);
}

BEGIN_MESSAGE_MAP(CAddDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAddDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CAddDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON6, &CAddDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CAddDlg ���

#ifdef _DEBUG
void CAddDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAddDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAddDlg ��Ϣ�������


void CAddDlg::OnInitialUpdate()
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

	file.ls.clear();

}


void CAddDlg::OnCbnSelchangeCombo1()
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


void CAddDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	if (m_num <= 0)
	{
		MessageBox(TEXT("��������С�ڻ��ߵ�����"));
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
			it->num += m_num;
			break;
		}
	}
	file.WirteDocline();

	CString str;
	str.Format(_T("����� ��Ʒ��%s \r\n���ۣ�%d \r\n������%d"), name, m_price, m_num);

	MessageBox(str);
	m_num = 0;
	UpdateData(FALSE);
}


void CAddDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_combo.SetCurSel(0);
	m_num = 0;

	OnCbnSelchangeCombo1();
}


void CAddDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	if (m_name.IsEmpty() || m_price1 < 0 || m_num1 <= 0)
	{
		MessageBox(TEXT("����Ʒ��Ϣ������"));
		return;
	}

	
	CInfoFile file;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ
	file.Addline(m_name, m_num1, m_price1); //�����Ʒ
	file.WirteDocline(); //д�ļ�
	file.ls.clear(); //���list������
	MessageBox(_T("��ӳɹ�"));

	OnInitialUpdate();
	m_name.Empty();
	m_num1 = 0;
	m_price1 = 0;
	UpdateData(FALSE);
}


void CAddDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_name.Empty();
	m_num1 = 0;
	m_price1 = 0;
	UpdateData(FALSE);
}
