#pragma once


// DLG_TIYUGUAN �Ի���

class DLG_TIYUGUAN : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_TIYUGUAN)

public:
	DLG_TIYUGUAN(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG_TIYUGUAN();

// �Ի�������
	enum { IDD = IDD_TIYUGUAN };

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
