#pragma once


// DLG_XINTIANDI �Ի���

class DLG_XINTIANDI : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_XINTIANDI)

public:
	DLG_XINTIANDI(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG_XINTIANDI();

// �Ի�������
	enum { IDD = IDD_XINTIANDI };

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
