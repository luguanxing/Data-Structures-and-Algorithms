// DLG_SHIYANLOU.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_SHIYANLOU.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_SHIYANLOU �Ի���

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


// DLG_SHIYANLOU ��Ϣ�������


void DLG_SHIYANLOU::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_SHIYANLOU); //������Դ���λͼ
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //����һ������pdc���豸������
	bmp.SelectObject(&mybitmap); //�滻�豸����λͼ
	pdc->BitBlt(0,0,400,260,&bmp,0,0,SRCCOPY); //����λͼ��pdc Ҳ����������
	mybitmap.DeleteObject();//�ͷŵ�����
	ReleaseDC(pdc); //�ͷŵ��豸������
	ReleaseDC(&bmp); //�ͷŵ��豸������
	CDialogEx::OnPaint();
}


void DLG_SHIYANLOU::OnShowWindow(BOOL bShow, UINT nStatus)
{
	AnimateWindow(200, AW_CENTER);  //���ڵ���
	OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
	// TODO: �ڴ˴������Ϣ����������
}


void DLG_SHIYANLOU::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //����1��
	CDialogEx::OnClose();
}


void DLG_SHIYANLOU::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	start = 5;
	::MessageBox(NULL, _T("�������Ϊ:ʵ��¥"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_SHIYANLOU::OnBnClickedEnd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	end = 5;
	::MessageBox(NULL, _T("�յ�����Ϊ:ʵ��¥"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_SHIYANLOU::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnClose();
}
