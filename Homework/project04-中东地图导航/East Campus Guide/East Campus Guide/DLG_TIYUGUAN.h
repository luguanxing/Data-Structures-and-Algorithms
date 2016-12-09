#pragma once


// DLG_TIYUGUAN 对话框

class DLG_TIYUGUAN : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_TIYUGUAN)

public:
	DLG_TIYUGUAN(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_TIYUGUAN();

// 对话框数据
	enum { IDD = IDD_TIYUGUAN };

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
