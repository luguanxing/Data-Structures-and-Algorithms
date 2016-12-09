// DLG_ZHENGMEN.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_ZHENGMEN.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_ZHENGMEN �Ի���

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


// DLG_ZHENGMEN ��Ϣ�������


void DLG_ZHENGMEN::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_ZHENGMEN); //������Դ���λͼ
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //����һ������pdc���豸������
	bmp.SelectObject(&mybitmap); //�滻�豸����λͼ
	pdc->BitBlt(0,0,400,270,&bmp,0,0,SRCCOPY); //����λͼ��pdc Ҳ����������
	mybitmap.DeleteObject();//�ͷŵ�����
	ReleaseDC(pdc); //�ͷŵ��豸������
	ReleaseDC(&bmp); //�ͷŵ��豸������
	CDialogEx::OnPaint();
}


//int DLG_ZHENGMEN::OnCreate(LPCREATESTRUCT lpCreateStruct)
//{
//	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
//		return -1;
//
//	// TODO:  �ڴ������ר�õĴ�������
//
//	return 0;
//}


void DLG_ZHENGMEN::OnShowWindow(BOOL bShow, UINT nStatus)
{
	AnimateWindow(200, AW_CENTER);  //���ڵ���
	OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
	// TODO: �ڴ˴������Ϣ����������
}


void DLG_ZHENGMEN::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //����1��
	CDialogEx::OnClose();
}


void DLG_ZHENGMEN::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnClose();
}


void DLG_ZHENGMEN::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	start = 0;
	::MessageBox(NULL, _T("�������Ϊ:����"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_ZHENGMEN::OnBnClickedEnd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	end = 0;
	::MessageBox(NULL, _T("�յ�����Ϊ:����"),	_T("����"),  MB_ICONINFORMATION);
}
