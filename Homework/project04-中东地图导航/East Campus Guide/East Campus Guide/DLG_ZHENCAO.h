#pragma once


// DLG_ZHENCAO �Ի���

class DLG_ZHENCAO : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_ZHENCAO)

public:
	DLG_ZHENCAO(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG_ZHENCAO();

// �Ի�������
	enum { IDD = IDD_ZHENCAO };

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
