// DLG_XINTIANDI.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_XINTIANDI.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_XINTIANDI �Ի���

IMPLEMENT_DYNAMIC(DLG_XINTIANDI, CDialogEx)

DLG_XINTIANDI::DLG_XINTIANDI(CWnd* pParent /*=NULL*/)
	: CDialogEx(DLG_XINTIANDI::IDD, pParent)
{

}

DLG_XINTIANDI::~DLG_XINTIANDI()
{
}

void DLG_XINTIANDI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DLG_XINTIANDI, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
	ON_WM_CLOSE()
	ON_BN_CLICKED(ID_START, &DLG_XINTIANDI::OnBnClickedStart)
	ON_BN_CLICKED(ID_END, &DLG_XINTIANDI::OnBnClickedEnd)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &DLG_XINTIANDI::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// DLG_XINTIANDI ��Ϣ�������


void DLG_XINTIANDI::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_XINTIANDI); //������Դ���λͼ
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


void DLG_XINTIANDI::OnShowWindow(BOOL bShow, UINT nStatus)
{
	AnimateWindow(200, AW_CENTER);  //���ڵ���
	OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
	// TODO: �ڴ˴������Ϣ����������
}


void DLG_XINTIANDI::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //����1��
	CDialogEx::OnClose();
}


void DLG_XINTIANDI::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	start = 9;
	::MessageBox(NULL, _T("�������Ϊ:�����"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_XINTIANDI::OnBnClickedEnd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	end = 9;
	::MessageBox(NULL, _T("�յ�����Ϊ:�����"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_XINTIANDI::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnClose();
}
