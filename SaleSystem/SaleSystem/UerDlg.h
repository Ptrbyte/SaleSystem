#pragma once



// CUerDlg ������ͼ

class CUerDlg : public CFormView
{
	DECLARE_DYNCREATE(CUerDlg)

protected:
	CUerDlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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


