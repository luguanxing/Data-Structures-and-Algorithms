
// East Campus GuideDlg.h : ͷ�ļ�
//

#pragma once
#include "DLG_TUSHUGUAN.h"
#include "DLG_ZHENGMEN.h"
#include "DLG_GONGJIAOLOU.h"
#include "DLG_TONGXIANG.h"
#include "DLG_SHIYANLOU.h"
#include "DLG_TIYUGUAN.h"
#include "DLG_ZHENCAO.h"
#include "DLG_JIACAO.h"
#include "DLG_XINTIANDI.h"
#include "DLG_RUANYUAN.h"


// CEastCampusGuideDlg �Ի���
class CEastCampusGuideDlg : public CDialogEx
{
// ����
public:
	CEastCampusGuideDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EASTCAMPUSGUIDE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedButtonChangemap();
	afx_msg void OnBnClickedButtonEixt();
	afx_msg void OnStnClickedStaticZhengmen();
	afx_msg void OnStnClickedStaticTushuguan();


	DLG_ZHENGMEN dlg_zhengmen;
	DLG_TUSHUGUAN dlg_tushuguan;
	DLG_GONGJIAOLOU  dlg_gongjiaolou;
	DLG_TONGXIANG  dlg_tongxiang;
	DLG_SHIYANLOU dlg_shiyanlou;
	DLG_TIYUGUAN dlg_tiyuguan;
	DLG_ZHENCAO dlg_zhencao;
	DLG_JIACAO dlg_jiacao;
	DLG_XINTIANDI dlg_xintiandi;
	DLG_RUANYUAN dlg_ruanyuan;
	afx_msg void OnStnClickedStaticGongjiaolou();
	afx_msg void OnStnClickedStaticTongxiang();
	afx_msg void OnStnClickedStaticShiyanlou();
	afx_msg void OnStnClickedStaticTiyuguan();
//	afx_msg void OnBnClickedButtonInfomation();
	afx_msg void OnStnClickedStaticZhencao();
	afx_msg void OnStnClickedStaticJiacao();
	afx_msg void OnStnClickedStaticXintiandi();
	afx_msg void OnStnClickedStaticRuanyuan();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnBnClickedButtonOpendata();
//	afx_msg void OnDestroy();
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg void OnDestroy();
//	afx_msg void OnDestroy();
	afx_msg void OnClose();
//	afx_msg void OnBnClickedButtonOpendata2();
	afx_msg void OnBnClickedButtonWalk();
	afx_msg void OnBnClickedButtonDrive();
};
