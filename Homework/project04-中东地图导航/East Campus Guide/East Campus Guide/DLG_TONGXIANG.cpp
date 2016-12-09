// DLG_TONGXIANG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_TONGXIANG.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_TONGXIANG �Ի���

IMPLEMENT_DYNAMIC(DLG_TONGXIANG, CDialogEx)

DLG_TONGXIANG::DLG_TONGXIANG(CWnd* pParent /*=NULL*/)
	: CDialogEx(DLG_TONGXIANG::IDD, pParent)
{

}

DLG_TONGXIANG::~DLG_TONGXIANG()
{
}

void DLG_TONGXIANG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DLG_TONGXIANG, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
	ON_WM_CLOSE()
	ON_BN_CLICKED(ID_START, &DLG_TONGXIANG::OnBnClickedStart)
	ON_BN_CLICKED(ID_END, &DLG_TONGXIANG::OnBnClickedEnd)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &DLG_TONGXIANG::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// DLG_TONGXIANG ��Ϣ�������


void DLG_TONGXIANG::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_TONGXIANG); //������Դ���λͼ
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //����һ������pdc���豸������
	bmp.SelectObject(&mybitmap); //�滻�豸����λͼ
	pdc->BitBlt(0,0,400,300,&bmp,0,0,SRCCOPY); //����λͼ��pdc Ҳ����������
	mybitmap.DeleteObject();//�ͷŵ�����
	ReleaseDC(pdc); //�ͷŵ��豸������
	ReleaseDC(&bmp); //�ͷŵ��豸������
	CDialogEx::OnPaint();
}


void DLG_TONGXIANG::OnShowWindow(BOOL bShow, UINT nStatus)
{
	AnimateWindow(200, AW_CENTER);  //���ڵ���
	OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
	// TODO: �ڴ˴������Ϣ����������
}


void DLG_TONGXIANG::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //����1��
	CDialogEx::OnClose();
}


void DLG_TONGXIANG::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	start = 2;
	::MessageBox(NULL, _T("�������Ϊ:ͭ��"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_TONGXIANG::OnBnClickedEnd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	end = 2;
	::MessageBox(NULL, _T("�յ�����Ϊ:ͭ��"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_TONGXIANG::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnClose();
}
