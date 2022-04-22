// SellDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "SellDlg.h"
#include "InfoFile.h"


// CSellDlg

IMPLEMENT_DYNCREATE(CSellDlg, CFormView)

CSellDlg::CSellDlg()
	: CFormView(DIALOG_SELL)
	, m_combo()
	, m_price(0)
	, m_num(0)
	, m_sellInfo(_T(""))
{

}

CSellDlg::~CSellDlg()
{
}

void CSellDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_price);
	DDX_Text(pDX, IDC_EDIT6, m_num);
	DDX_Text(pDX, IDC_EDIT7, m_sellInfo);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
}

BEGIN_MESSAGE_MAP(CSellDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSellDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &CSellDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CSellDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CSellDlg 诊断

#ifdef _DEBUG
void CSellDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSellDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSellDlg 消息处理程序


void CSellDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	CInfoFile file;
	file.ReadDocline();
	for (auto it = file.ls.begin(); it != file.ls.end(); it++)
	{
		m_combo.AddString((CString)it->name.c_str());
	}
	file.ls.clear();

	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();
}


void CSellDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取当前项
	CString text;
	int index = m_combo.GetCurSel();
	m_combo.GetLBText(index, text);

	CInfoFile file;
	file.ReadDocline();

	for (auto it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (text == (CString)it->name.c_str())
		{
			m_price = it->price;
			m_num = 0;
			UpdateData(FALSE);
			break;
		}
	}
	file.ls.clear();

}


void CSellDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	if (m_num <= 0)
	{
		MessageBox(TEXT("购买数量不能小于等于0"));
		return;
	}

	int index = m_combo.GetCurSel();
	CString name;
	m_combo.GetLBText(index,name);


	CInfoFile file;
	file.ReadDocline();

	for (auto it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (name == (CString)it->name.c_str())
		{
			it->num = it->num - m_num;
			CString  str;
			str.Format(TEXT("商品：%s \r\n单价：%d \r\n个数：%d \r\n总价：%d"),
				name, m_price, m_num, m_price*m_num);
			m_sellInfo = str;
			UpdateData(FALSE);
			break;
		}
	}

	file.WirteDocline();
	file.ls.clear();


}


void CSellDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_combo.SetCurSel(0);
	m_num = 0;
	m_sellInfo = "";

	OnCbnSelchangeCombo1();
}
