// DLG_GONGJIAOLOU.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_GONGJIAOLOU.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_GONGJIAOLOU �Ի���

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


// DLG_GONGJIAOLOU ��Ϣ�������


void DLG_GONGJIAOLOU::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_GONGJIAOLOU); //������Դ���λͼ
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //����һ������pdc���豸������
	bmp.SelectObject(&mybitmap); //�滻�豸����λͼ
	pdc->BitBlt(0,0,400,240,&bmp,0,0,SRCCOPY); //����λͼ��pdc Ҳ����������
	mybitmap.DeleteObject();//�ͷŵ�����
	ReleaseDC(pdc); //�ͷŵ��豸������
	ReleaseDC(&bmp); //�ͷŵ��豸������
	CDialogEx::OnPaint();
}


void DLG_GONGJIAOLOU::OnShowWindow(BOOL bShow, UINT nStatus)
{
	AnimateWindow(200, AW_CENTER);  //���ڵ���
	DLG_GONGJIAOLOU::OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
	// TODO: �ڴ˴������Ϣ����������
}


void DLG_GONGJIAOLOU::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //����1��
	CDialogEx::OnClose();
}


void DLG_GONGJIAOLOU::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnClose();
}


void DLG_GONGJIAOLOU::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void DLG_GONGJIAOLOU::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void DLG_GONGJIAOLOU::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	start = 3;
	::MessageBox(NULL, _T("�������Ϊ:����¥"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_GONGJIAOLOU::OnBnClickedEnd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	end = 3;
	::MessageBox(NULL, _T("�յ�����Ϊ:����¥"),	_T("����"),  MB_ICONINFORMATION);
}
