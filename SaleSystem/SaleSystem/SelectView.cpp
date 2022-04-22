// SelectView.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "SelectView.h"
#include "MainFrm.h"


// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView 诊断

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView 消息处理程序


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	//图标加载CWinApp::LoadIconW()
	HICON ico = AfxGetApp()->LoadIconW(IDI_ICON_RE);

	//图标列表CImageList::Create(图的宽，图高，图标格式，（1，1）有多少图，写多少图)；
	m_imagelist.Create(30, 30, ILC_COLOR32, 1, 1);

	//图标列表中添加图标CImageList::Add
	m_imagelist.Add(ico);

	//获取数控列表CTreeView::GetTreeCtrl
	m_treectrl = &GetTreeCtrl();

	//树控件设置图列表
	m_treectrl->SetImageList(&m_imagelist, TVSIL_NORMAL);
	
	//设置节点CTreeCtrl::InsertItem
	m_treectrl->InsertItem(TEXT("个人信息"),0,0,NULL);
	m_treectrl->InsertItem(TEXT("销售信息"), 0, 0, NULL);
	m_treectrl->InsertItem(TEXT("库存信息"), 0, 0, NULL);
	m_treectrl->InsertItem(TEXT("库存添加"), 0, 0, NULL);
	m_treectrl->InsertItem(TEXT("库存删除"), 0, 0, NULL);


}


void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	//获取当前节点选中项目CTreeCtrl::GetSelectItem
	HTREEITEM item= m_treectrl->GetSelectedItem();

	//获取当前选中内容CTreeCtrl::GetItemText
	CString str=m_treectrl->GetItemText(item);
	//MessageBox(str);

	if (str == TEXT("个人信息"))
	{
		//需要包含框架类头文件#include "MainFrm.h" 
		//CWnd::PostMessage 将一个消息放入窗口的消息队列
		//AfxGetMainWnd()：框架窗口对象的指针
		//AfxGetMainWnd()->GetSafeHwnd()：获取返回窗口的句柄，CWnd::GetSafeHwnd
		//NM_A：发送自定义消息
		//(WPARAM)NM_A：指定了附加的消息信息
		//(LPARAM)0：指定了附加的消息信息，此参数这里没有意义
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);

	}
	else if (str == TEXT("销售信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	}
	else if (str == TEXT("库存信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	else if (str == TEXT("库存添加"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
	}
	else if (str == TEXT("库存删除"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
	}
}



