#pragma once


// DLG_TUSHUGUAN �Ի���

class DLG_TUSHUGUAN : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_TUSHUGUAN)

public:
	DLG_TUSHUGUAN(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG_TUSHUGUAN();

// �Ի�������
	enum { IDD = IDD_TUSHUGUAN };

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
