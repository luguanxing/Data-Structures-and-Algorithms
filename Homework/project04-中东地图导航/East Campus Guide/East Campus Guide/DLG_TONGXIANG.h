#pragma once


// DLG_TONGXIANG �Ի���

class DLG_TONGXIANG : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_TONGXIANG)

public:
	DLG_TONGXIANG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG_TONGXIANG();

// �Ի�������
	enum { IDD = IDD_TONGXIANG };

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
