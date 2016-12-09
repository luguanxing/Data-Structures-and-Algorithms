// DLG_JIACAO.cpp : 实现文件
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_JIACAO.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_JIACAO 对话框

IMPLEMENT_DYNAMIC(DLG_JIACAO, CDialogEx)

DLG_JIACAO::DLG_JIACAO(CWnd* pParent /*=NULL*/)
	: CDialogEx(DLG_JIACAO::IDD, pParent)
{

}

DLG_JIACAO::~DLG_JIACAO()
{
}

void DLG_JIACAO::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DLG_JIACAO, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(ID_START, &DLG_JIACAO::OnBnClickedStart)
	ON_BN_CLICKED(ID_END, &DLG_JIACAO::OnBnClickedEnd)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &DLG_JIACAO::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// DLG_JIACAO 消息处理程序


void DLG_JIACAO::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_JIACAO); //载入资源里的位图
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //创建一个兼容pdc的设备上下文
	bmp.SelectObject(&mybitmap); //替换设备环境位图
	pdc->BitBlt(0,0,400,275,&bmp,0,0,SRCCOPY); //复制位图至pdc 也就是主窗口
	mybitmap.DeleteObject();//释放掉对象
	ReleaseDC(pdc); //释放掉设备上下文
	ReleaseDC(&bmp); //释放掉设备上下文
	CDialogEx::OnPaint();
}

void DLG_JIACAO::OnShowWindow(BOOL bShow, UINT nStatus)
{
	// TODO: 在此处添加消息处理程序代码
	AnimateWindow(200, AW_CENTER);  //窗口淡入
	DLG_JIACAO::OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
}

void DLG_JIACAO::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //淡出1秒
	CDialogEx::OnClose();
}





void DLG_JIACAO::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	start = 8;
	::MessageBox(NULL, _T("起点设置为:假草"),	_T("设置"),  MB_ICONINFORMATION);
}


void DLG_JIACAO::OnBnClickedEnd()
{
	// TODO: 在此添加控件通知处理程序代码
	end = 8;
	::MessageBox(NULL, _T("终点设置为:假草"),	_T("设置"),  MB_ICONINFORMATION);
}


void DLG_JIACAO::OnBnClickedButtonClose()
{
	// TODO: 在此添加控件通知处理程序代码
	OnClose();
}
