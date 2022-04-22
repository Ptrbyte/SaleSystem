// UerDlg.cpp : 实现文件
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


// CUerDlg 诊断

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


// CUerDlg 消息处理程序


void CUerDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);

	//初始化个人信息
	m_user = TEXT("销售员");
	m_name = name;
	
	UpdateData(FALSE);

}


void CUerDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//修改密码

	UpdateData(TRUE);
	
	if (m_newpwd.IsEmpty() || m_surepwd.IsEmpty())
	{
		MessageBox(TEXT("输入密码为空"));
		return;
	}
	if (m_newpwd != m_surepwd)
	{
		MessageBox(TEXT("新密码与确认密码不相等"));
		/*m_newpwd.Empty();
		m_surepwd.Empty();*/
		return;
	}

	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);

	if (pwd == m_newpwd)
	{
		MessageBox(TEXT("新密码不能与当前密码相等"));
		/*m_newpwd.Empty();
		m_surepwd.Empty();*/
		return;
	}

	//更新密码
	//把用户名和密码的CString类型转为char *
	char *tmpName, *tmpPwd;
	//用户名
	CStringA tmp1;
	tmp1 = name;
	tmpName = tmp1.GetBuffer();
	
	//密码
	CStringA tmp2;
	tmp2 = m_surepwd;
	tmpPwd = tmp2.GetBuffer();

	file.WritePwd(tmpName, tmpPwd); //修改密码

	MessageBox(TEXT("密码修改成功"));

	//输入框内容清空
	m_surepwd.Empty();
	m_newpwd.Empty();

	UpdateData(FALSE); //把数据更新到控件上


}


void CUerDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_newpwd.Empty();
	m_surepwd.Empty();

	UpdateData(FALSE);
}
