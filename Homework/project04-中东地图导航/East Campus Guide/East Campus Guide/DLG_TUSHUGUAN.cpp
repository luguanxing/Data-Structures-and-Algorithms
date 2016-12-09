// DLG_TUSHUGUAN.cpp : 实现文件
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_TUSHUGUAN.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_TUSHUGUAN 对话框

IMPLEMENT_DYNAMIC(DLG_TUSHUGUAN, CDialogEx)

DLG_TUSHUGUAN::DLG_TUSHUGUAN(CWnd* pParent /*=NULL*/)
	: CDialogEx(DLG_TUSHUGUAN::IDD, pParent)
{

}

DLG_TUSHUGUAN::~DLG_TUSHUGUAN()
{
}

void DLG_TUSHUGUAN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DLG_TUSHUGUAN, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
	ON_WM_CLOSE()
	ON_BN_CLICKED(ID_START, &DLG_TUSHUGUAN::OnBnClickedStart)
	ON_BN_CLICKED(ID_END, &DLG_TUSHUGUAN::OnBnClickedEnd)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &DLG_TUSHUGUAN::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// DLG_TUSHUGUAN 消息处理程序


void DLG_TUSHUGUAN::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_TUSHUGUAN); //载入资源里的位图
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //创建一个兼容pdc的设备上下文
	bmp.SelectObject(&mybitmap); //替换设备环境位图
	pdc->BitBlt(0,0,400,225,&bmp,0,0,SRCCOPY); //复制位图至pdc 也就是主窗口
	mybitmap.DeleteObject();//释放掉对象
	ReleaseDC(pdc); //释放掉设备上下文
	ReleaseDC(&bmp); //释放掉设备上下文
	CDialogEx::OnPaint();
}


void DLG_TUSHUGUAN::OnShowWindow(BOOL bShow, UINT nStatus)
{
	AnimateWindow(200, AW_CENTER);  //窗口淡入
	OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
	// TODO: 在此处添加消息处理程序代码
}


void DLG_TUSHUGUAN::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //淡出1秒
	CDialogEx::OnClose();
}


void DLG_TUSHUGUAN::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	start = 4;
	::MessageBox(NULL, _T("起点设置为:图书馆"),	_T("设置"),  MB_ICONINFORMATION);
}


void DLG_TUSHUGUAN::OnBnClickedEnd()
{
	// TODO: 在此添加控件通知处理程序代码
	end = 4;
	::MessageBox(NULL, _T("终点设置为:图书馆"),	_T("设置"),  MB_ICONINFORMATION);
}


void DLG_TUSHUGUAN::OnBnClickedButtonClose()
{
	// TODO: 在此添加控件通知处理程序代码
	OnClose();
}
