#pragma once


// DLG_SHIYANLOU �Ի���

class DLG_SHIYANLOU : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_SHIYANLOU)

public:
	DLG_SHIYANLOU(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG_SHIYANLOU();

// �Ի�������
	enum { IDD = IDD_SHIYANLOU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnClose();
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedEnd();
	afx_msg void OnBnClickedButtonClose();
};
