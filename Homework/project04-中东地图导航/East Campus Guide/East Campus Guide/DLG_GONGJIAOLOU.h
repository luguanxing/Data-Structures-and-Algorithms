#pragma once


// DLG_GONGJIAOLOU �Ի���

class DLG_GONGJIAOLOU : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_GONGJIAOLOU)

public:
	DLG_GONGJIAOLOU(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG_GONGJIAOLOU();

// �Ի�������
	enum { IDD = IDD_GONGJIAOLOU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg void OnInitMenu(CMenu* pMenu);
//	virtual BOOL OnInitDialog();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
//	virtual void OnCancel();
//	virtual BOOL DestroyWindow();
	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedEnd();
};
