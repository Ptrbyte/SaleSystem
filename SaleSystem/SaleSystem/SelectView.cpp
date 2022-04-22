// SelectView.cpp : ʵ���ļ�
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


// CSelectView ���

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


// CSelectView ��Ϣ�������


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	//ͼ�����CWinApp::LoadIconW()
	HICON ico = AfxGetApp()->LoadIconW(IDI_ICON_RE);

	//ͼ���б�CImageList::Create(ͼ�Ŀ�ͼ�ߣ�ͼ���ʽ����1��1���ж���ͼ��д����ͼ)��
	m_imagelist.Create(30, 30, ILC_COLOR32, 1, 1);

	//ͼ���б������ͼ��CImageList::Add
	m_imagelist.Add(ico);

	//��ȡ�����б�CTreeView::GetTreeCtrl
	m_treectrl = &GetTreeCtrl();

	//���ؼ�����ͼ�б�
	m_treectrl->SetImageList(&m_imagelist, TVSIL_NORMAL);
	
	//���ýڵ�CTreeCtrl::InsertItem
	m_treectrl->InsertItem(TEXT("������Ϣ"),0,0,NULL);
	m_treectrl->InsertItem(TEXT("������Ϣ"), 0, 0, NULL);
	m_treectrl->InsertItem(TEXT("�����Ϣ"), 0, 0, NULL);
	m_treectrl->InsertItem(TEXT("������"), 0, 0, NULL);
	m_treectrl->InsertItem(TEXT("���ɾ��"), 0, 0, NULL);


}


void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	//��ȡ��ǰ�ڵ�ѡ����ĿCTreeCtrl::GetSelectItem
	HTREEITEM item= m_treectrl->GetSelectedItem();

	//��ȡ��ǰѡ������CTreeCtrl::GetItemText
	CString str=m_treectrl->GetItemText(item);
	//MessageBox(str);

	if (str == TEXT("������Ϣ"))
	{
		//��Ҫ���������ͷ�ļ�#include "MainFrm.h" 
		//CWnd::PostMessage ��һ����Ϣ���봰�ڵ���Ϣ����
		//AfxGetMainWnd()����ܴ��ڶ����ָ��
		//AfxGetMainWnd()->GetSafeHwnd()����ȡ���ش��ڵľ����CWnd::GetSafeHwnd
		//NM_A�������Զ�����Ϣ
		//(WPARAM)NM_A��ָ���˸��ӵ���Ϣ��Ϣ
		//(LPARAM)0��ָ���˸��ӵ���Ϣ��Ϣ���˲�������û������
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);

	}
	else if (str == TEXT("������Ϣ"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	}
	else if (str == TEXT("�����Ϣ"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	else if (str == TEXT("������"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
	}
	else if (str == TEXT("���ɾ��"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
	}
}



