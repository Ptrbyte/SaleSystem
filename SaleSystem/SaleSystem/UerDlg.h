#pragma once



// CUerDlg 窗体视图

class CUerDlg : public CFormView
{
	DECLARE_DYNCREATE(CUerDlg)

protected:
	CUerDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CUerDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_USER };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_user;
private:
	CString m_name;
	CString m_newpwd;
	CString m_surepwd;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
};


