// DLG_GONGJIAOLOU.cpp : 实现文件
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_GONGJIAOLOU.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_GONGJIAOLOU 对话框

IMPLEMENT_DYNAMIC(DLG_GONGJIAOLOU, CDialogEx)

DLG_GONGJIAOLOU::DLG_GONGJIAOLOU(CWnd* pParent /*=NULL*/)
	: CDialogEx(DLG_GONGJIAOLOU::IDD, pParent)
{

}

DLG_GONGJIAOLOU::~DLG_GONGJIAOLOU()
{
}

void DLG_GONGJIAOLOU::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DLG_GONGJIAOLOU, CDialogEx)
	ON_WM_PAINT()
//	ON_WM_CREATE()
//ON_WM_INITMENU()
ON_WM_SHOWWINDOW()
ON_WM_CLOSE()
ON_BN_CLICKED(IDC_BUTTON_CLOSE, &DLG_GONGJIAOLOU::OnBnClickedButtonClose)
ON_BN_CLICKED(IDOK, &DLG_GONGJIAOLOU::OnBnClickedOk)
ON_BN_CLICKED(IDCANCEL, &DLG_GONGJIAOLOU::OnBnClickedCancel)
ON_BN_CLICKED(ID_START, &DLG_GONGJIAOLOU::OnBnClickedStart)
ON_BN_CLICKED(ID_END, &DLG_GONGJIAOLOU::OnBnClickedEnd)
END_MESSAGE_MAP()


// DLG_GONGJIAOLOU 消息处理程序


void DLG_GONGJIAOLOU::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_GONGJIAOLOU); //载入资源里的位图
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //创建一个兼容pdc的设备上下文
	bmp.SelectObject(&mybitmap); //替换设备环境位图
	pdc->BitBlt(0,0,400,240,&bmp,0,0,SRCCOPY); //复制位图至pdc 也就是主窗口
	mybitmap.DeleteObject();//释放掉对象
	ReleaseDC(pdc); //释放掉设备上下文
	ReleaseDC(&bmp); //释放掉设备上下文
	CDialogEx::OnPaint();
}


void DLG_GONGJIAOLOU::OnShowWindow(BOOL bShow, UINT nStatus)
{
	AnimateWindow(200, AW_CENTER);  //窗口淡入
	DLG_GONGJIAOLOU::OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
	// TODO: 在此处添加消息处理程序代码
}


void DLG_GONGJIAOLOU::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //淡出1秒
	CDialogEx::OnClose();
}


void DLG_GONGJIAOLOU::OnBnClickedButtonClose()
{
	// TODO: 在此添加控件通知处理程序代码
	OnClose();
}


void DLG_GONGJIAOLOU::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
}


void DLG_GONGJIAOLOU::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
}


void DLG_GONGJIAOLOU::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	start = 3;
	::MessageBox(NULL, _T("起点设置为:公教楼"),	_T("设置"),  MB_ICONINFORMATION);
}


void DLG_GONGJIAOLOU::OnBnClickedEnd()
{
	// TODO: 在此添加控件通知处理程序代码
	end = 3;
	::MessageBox(NULL, _T("终点设置为:公教楼"),	_T("设置"),  MB_ICONINFORMATION);
}
