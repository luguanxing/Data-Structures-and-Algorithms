// DLG_TIYUGUAN.cpp : 实现文件
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_TIYUGUAN.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_TIYUGUAN 对话框

IMPLEMENT_DYNAMIC(DLG_TIYUGUAN, CDialogEx)

DLG_TIYUGUAN::DLG_TIYUGUAN(CWnd* pParent /*=NULL*/)
	: CDialogEx(DLG_TIYUGUAN::IDD, pParent)
{

}

DLG_TIYUGUAN::~DLG_TIYUGUAN()
{
}

void DLG_TIYUGUAN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DLG_TIYUGUAN, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
	ON_WM_CLOSE()
	ON_BN_CLICKED(ID_START, &DLG_TIYUGUAN::OnBnClickedStart)
	ON_BN_CLICKED(ID_END, &DLG_TIYUGUAN::OnBnClickedEnd)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &DLG_TIYUGUAN::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// DLG_TIYUGUAN 消息处理程序


void DLG_TIYUGUAN::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_TIYUGUAN); //载入资源里的位图
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


void DLG_TIYUGUAN::OnShowWindow(BOOL bShow, UINT nStatus)
{
	AnimateWindow(200, AW_CENTER);  //窗口淡入
	OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
	// TODO: 在此处添加消息处理程序代码
}


void DLG_TIYUGUAN::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //淡出1秒
	CDialogEx::OnClose();
}


void DLG_TIYUGUAN::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	start = 6;
	::MessageBox(NULL, _T("起点设置为:体育馆"),	_T("设置"),  MB_ICONINFORMATION);
}


void DLG_TIYUGUAN::OnBnClickedEnd()
{
	// TODO: 在此添加控件通知处理程序代码
	end = 6;
	::MessageBox(NULL, _T("终点设置为:体育馆"),	_T("设置"),  MB_ICONINFORMATION);
}


void DLG_TIYUGUAN::OnBnClickedButtonClose()
{
	// TODO: 在此添加控件通知处理程序代码
	OnClose();
}
