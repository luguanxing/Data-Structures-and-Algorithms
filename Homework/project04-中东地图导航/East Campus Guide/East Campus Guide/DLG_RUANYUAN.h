#pragma once


// DLG_RUANYUAN �Ի���

class DLG_RUANYUAN : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_RUANYUAN)

public:
	DLG_RUANYUAN(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG_RUANYUAN();

// �Ի�������
	enum { IDD = IDD_RUANYUAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
//	afx_msg void OnClose();
	afx_msg void OnClose();
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedEnd();
	afx_msg void OnBnClickedButtonClose();
};
