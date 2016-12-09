#pragma once


// DLG_TONGXIANG 对话框

class DLG_TONGXIANG : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_TONGXIANG)

public:
	DLG_TONGXIANG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_TONGXIANG();

// 对话框数据
	enum { IDD = IDD_TONGXIANG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnClose();
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedEnd();
	afx_msg void OnBnClickedButtonClose();
};
