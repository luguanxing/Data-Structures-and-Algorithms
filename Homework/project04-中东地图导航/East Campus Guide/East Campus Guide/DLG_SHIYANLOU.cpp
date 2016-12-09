// DLG_SHIYANLOU.cpp : 实现文件
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_SHIYANLOU.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_SHIYANLOU 对话框

IMPLEMENT_DYNAMIC(DLG_SHIYANLOU, CDialogEx)

DLG_SHIYANLOU::DLG_SHIYANLOU(CWnd* pParent /*=NULL*/)
	: CDialogEx(DLG_SHIYANLOU::IDD, pParent)
{

}

DLG_SHIYANLOU::~DLG_SHIYANLOU()
{
}

void DLG_SHIYANLOU::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DLG_SHIYANLOU, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
	ON_WM_CLOSE()
	ON_BN_CLICKED(ID_START, &DLG_SHIYANLOU::OnBnClickedStart)
	ON_BN_CLICKED(ID_END, &DLG_SHIYANLOU::OnBnClickedEnd)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &DLG_SHIYANLOU::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// DLG_SHIYANLOU 消息处理程序


void DLG_SHIYANLOU::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_SHIYANLOU); //载入资源里的位图
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //创建一个兼容pdc的设备上下文
	bmp.SelectObject(&mybitmap); //替换设备环境位图
	pdc->BitBlt(0,0,400,260,&bmp,0,0,SRCCOPY); //复制位图至pdc 也就是主窗口
	mybitmap.DeleteObject();//释放掉对象
	ReleaseDC(pdc); //释放掉设备上下文
	ReleaseDC(&bmp); //释放掉设备上下文
	CDialogEx::OnPaint();
}


void DLG_SHIYANLOU::OnShowWindow(BOOL bShow, UINT nStatus)
{
	AnimateWindow(200, AW_CENTER);  //窗口淡入
	OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
	// TODO: 在此处添加消息处理程序代码
}


void DLG_SHIYANLOU::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //淡出1秒
	CDialogEx::OnClose();
}


void DLG_SHIYANLOU::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	start = 5;
	::MessageBox(NULL, _T("起点设置为:实验楼"),	_T("设置"),  MB_ICONINFORMATION);
}


void DLG_SHIYANLOU::OnBnClickedEnd()
{
	// TODO: 在此添加控件通知处理程序代码
	end = 5;
	::MessageBox(NULL, _T("终点设置为:实验楼"),	_T("设置"),  MB_ICONINFORMATION);
}


void DLG_SHIYANLOU::OnBnClickedButtonClose()
{
	// TODO: 在此添加控件通知处理程序代码
	OnClose();
}
