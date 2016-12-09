#pragma once


// DLG_TUSHUGUAN 对话框

class DLG_TUSHUGUAN : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_TUSHUGUAN)

public:
	DLG_TUSHUGUAN(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_TUSHUGUAN();

// 对话框数据
	enum { IDD = IDD_TUSHUGUAN };

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
