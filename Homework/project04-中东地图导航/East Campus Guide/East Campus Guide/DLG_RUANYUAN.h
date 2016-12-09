#pragma once


// DLG_RUANYUAN 对话框

class DLG_RUANYUAN : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_RUANYUAN)

public:
	DLG_RUANYUAN(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_RUANYUAN();

// 对话框数据
	enum { IDD = IDD_RUANYUAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
