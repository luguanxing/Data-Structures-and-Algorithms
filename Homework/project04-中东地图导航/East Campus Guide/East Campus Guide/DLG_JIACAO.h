#pragma once


// DLG_JIACAO 对话框

class DLG_JIACAO : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_JIACAO)

public:
	DLG_JIACAO(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_JIACAO();

// 对话框数据
	enum { IDD = IDD_JIACAO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedEnd();
	afx_msg void OnBnClickedButtonClose();
};
