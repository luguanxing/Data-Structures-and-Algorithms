// DLG_RUANYUAN.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_RUANYUAN.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_RUANYUAN �Ի���

IMPLEMENT_DYNAMIC(DLG_RUANYUAN, CDialogEx)

DLG_RUANYUAN::DLG_RUANYUAN(CWnd* pParent /*=NULL*/)
	: CDialogEx(DLG_RUANYUAN::IDD, pParent)
{

}

DLG_RUANYUAN::~DLG_RUANYUAN()
{
}

void DLG_RUANYUAN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DLG_RUANYUAN, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
//	ON_WM_CLOSE()
ON_WM_CLOSE()
ON_BN_CLICKED(ID_START, &DLG_RUANYUAN::OnBnClickedStart)
ON_BN_CLICKED(ID_END, &DLG_RUANYUAN::OnBnClickedEnd)
ON_BN_CLICKED(IDC_BUTTON_CLOSE, &DLG_RUANYUAN::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// DLG_RUANYUAN ��Ϣ�������


void DLG_RUANYUAN::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_RUANYUAN); //������Դ���λͼ
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //����һ������pdc���豸������
	bmp.SelectObject(&mybitmap); //�滻�豸����λͼ
	pdc->BitBlt(0,0,400,280,&bmp,0,0,SRCCOPY); //����λͼ��pdc Ҳ����������
	mybitmap.DeleteObject();//�ͷŵ�����
	ReleaseDC(pdc); //�ͷŵ��豸������
	ReleaseDC(&bmp); //�ͷŵ��豸������
	CDialogEx::OnPaint();
}


void DLG_RUANYUAN::OnShowWindow(BOOL bShow, UINT nStatus)
{
	AnimateWindow(200, AW_CENTER);  //���ڵ���
	OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
	// TODO: �ڴ˴������Ϣ����������
}

void DLG_RUANYUAN::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //����1��
	CDialogEx::OnClose();
}


void DLG_RUANYUAN::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	start = 1;
	::MessageBox(NULL, _T("�������Ϊ:��Ժ"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_RUANYUAN::OnBnClickedEnd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	end = 1;
	::MessageBox(NULL, _T("�յ�����Ϊ:��Ժ"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_RUANYUAN::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnClose();
}
