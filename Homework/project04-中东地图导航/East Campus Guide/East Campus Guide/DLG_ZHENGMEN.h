#pragma once

// DLG_ZHENGMEN 对话框

class DLG_ZHENGMEN : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_ZHENGMEN)

public:
	DLG_ZHENGMEN(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_ZHENGMEN();

// 对话框数据
	enum { IDD = IDD_ZHENGMEN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonClose();
//	afx_msg void OnBnClickedOk();
//	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedEnd();
};
