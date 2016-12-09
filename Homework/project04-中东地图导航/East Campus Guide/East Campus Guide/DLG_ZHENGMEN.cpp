// DLG_ZHENGMEN.cpp : 实现文件
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_ZHENGMEN.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_ZHENGMEN 对话框

IMPLEMENT_DYNAMIC(DLG_ZHENGMEN, CDialogEx)

DLG_ZHENGMEN::DLG_ZHENGMEN(CWnd* pParent /*=NULL*/)
	: CDialogEx(DLG_ZHENGMEN::IDD, pParent)
{

}

DLG_ZHENGMEN::~DLG_ZHENGMEN()
{
}

void DLG_ZHENGMEN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DLG_ZHENGMEN, CDialogEx)
	ON_WM_PAINT()
//	ON_WM_CREATE()
ON_WM_SHOWWINDOW()
ON_WM_CLOSE()
ON_BN_CLICKED(IDC_BUTTON_CLOSE, &DLG_ZHENGMEN::OnBnClickedButtonClose)
//ON_BN_CLICKED(IDOK, &DLG_ZHENGMEN::OnBnClickedOk)
//ON_BN_CLICKED(IDCANCEL, &DLG_ZHENGMEN::OnBnClickedCancel)
ON_BN_CLICKED(ID_START, &DLG_ZHENGMEN::OnBnClickedStart)
ON_BN_CLICKED(ID_END, &DLG_ZHENGMEN::OnBnClickedEnd)
END_MESSAGE_MAP()


// DLG_ZHENGMEN 消息处理程序


void DLG_ZHENGMEN::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_ZHENGMEN); //载入资源里的位图
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //创建一个兼容pdc的设备上下文
	bmp.SelectObject(&mybitmap); //替换设备环境位图
	pdc->BitBlt(0,0,400,270,&bmp,0,0,SRCCOPY); //复制位图至pdc 也就是主窗口
	mybitmap.DeleteObject();//释放掉对象
	ReleaseDC(pdc); //释放掉设备上下文
	ReleaseDC(&bmp); //释放掉设备上下文
	CDialogEx::OnPaint();
}


//int DLG_ZHENGMEN::OnCreate(LPCREATESTRUCT lpCreateStruct)
//{
//	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
//		return -1;
//
//	// TODO:  在此添加您专用的创建代码
//
//	return 0;
//}


void DLG_ZHENGMEN::OnShowWindow(BOOL bShow, UINT nStatus)
{
	AnimateWindow(200, AW_CENTER);  //窗口淡入
	OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
	// TODO: 在此处添加消息处理程序代码
}


void DLG_ZHENGMEN::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //淡出1秒
	CDialogEx::OnClose();
}


void DLG_ZHENGMEN::OnBnClickedButtonClose()
{
	// TODO: 在此添加控件通知处理程序代码
	OnClose();
}


void DLG_ZHENGMEN::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	start = 0;
	::MessageBox(NULL, _T("起点设置为:正门"),	_T("设置"),  MB_ICONINFORMATION);
}


void DLG_ZHENGMEN::OnBnClickedEnd()
{
	// TODO: 在此添加控件通知处理程序代码
	end = 0;
	::MessageBox(NULL, _T("终点设置为:正门"),	_T("设置"),  MB_ICONINFORMATION);
}
