// UerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "UerDlg.h"
#include "InfoFile.h"


// CUerDlg

IMPLEMENT_DYNCREATE(CUerDlg, CFormView)

CUerDlg::CUerDlg()
	: CFormView(DIALOG_USER)
	, m_user(_T(""))
	, m_name(_T(""))
	, m_newpwd(_T(""))
	, m_surepwd(_T(""))
{

}

CUerDlg::~CUerDlg()
{
}

void CUerDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT3, m_name);
	DDX_Text(pDX, IDC_EDIT4, m_newpwd);
	DDX_Text(pDX, IDC_EDIT5, m_surepwd);
}

BEGIN_MESSAGE_MAP(CUerDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CUerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CUerDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CUerDlg ���

#ifdef _DEBUG
void CUerDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUerDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUerDlg ��Ϣ�������


void CUerDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);

	//��ʼ��������Ϣ
	m_user = TEXT("����Ա");
	m_name = name;
	
	UpdateData(FALSE);

}


void CUerDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�޸�����

	UpdateData(TRUE);
	
	if (m_newpwd.IsEmpty() || m_surepwd.IsEmpty())
	{
		MessageBox(TEXT("��������Ϊ��"));
		return;
	}
	if (m_newpwd != m_surepwd)
	{
		MessageBox(TEXT("��������ȷ�����벻���"));
		/*m_newpwd.Empty();
		m_surepwd.Empty();*/
		return;
	}

	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);

	if (pwd == m_newpwd)
	{
		MessageBox(TEXT("�����벻���뵱ǰ�������"));
		/*m_newpwd.Empty();
		m_surepwd.Empty();*/
		return;
	}

	//��������
	//���û����������CString����תΪchar *
	char *tmpName, *tmpPwd;
	//�û���
	CStringA tmp1;
	tmp1 = name;
	tmpName = tmp1.GetBuffer();
	
	//����
	CStringA tmp2;
	tmp2 = m_surepwd;
	tmpPwd = tmp2.GetBuffer();

	file.WritePwd(tmpName, tmpPwd); //�޸�����

	MessageBox(TEXT("�����޸ĳɹ�"));

	//������������
	m_surepwd.Empty();
	m_newpwd.Empty();

	UpdateData(FALSE); //�����ݸ��µ��ؼ���


}


void CUerDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_newpwd.Empty();
	m_surepwd.Empty();

	UpdateData(FALSE);
}
