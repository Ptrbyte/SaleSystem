
// MainFrm.h : CMainFrame 类的接口
//

#pragma once

//WM_USER用户自定义消息的起始值
//WM_USER+100区分系统消息和自定义消息，避免冲突
#define NM_A (WM_USER+100)
#define NM_B (WM_USER+101)
#define NM_C (WM_USER+102)
#define NM_D (WM_USER+103)
#define NM_E (WM_USER+104)

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
private:

	//拆分窗口类对象
	CSplitterWnd m_spliter;

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//自定义消息处理函数
	afx_msg LRESULT OnMyChange(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32775();
	afx_msg void On32776();
	afx_msg void On32771();
};


