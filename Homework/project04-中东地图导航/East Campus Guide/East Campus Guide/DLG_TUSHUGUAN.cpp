// DLG_TUSHUGUAN.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_TUSHUGUAN.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_TUSHUGUAN �Ի���

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


// DLG_TUSHUGUAN ��Ϣ�������


void DLG_TUSHUGUAN::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_TUSHUGUAN); //������Դ���λͼ
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //����һ������pdc���豸������
	bmp.SelectObject(&mybitmap); //�滻�豸����λͼ
	pdc->BitBlt(0,0,400,225,&bmp,0,0,SRCCOPY); //����λͼ��pdc Ҳ����������
	mybitmap.DeleteObject();//�ͷŵ�����
	ReleaseDC(pdc); //�ͷŵ��豸������
	ReleaseDC(&bmp); //�ͷŵ��豸������
	CDialogEx::OnPaint();
}


void DLG_TUSHUGUAN::OnShowWindow(BOOL bShow, UINT nStatus)
{
	AnimateWindow(200, AW_CENTER);  //���ڵ���
	OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
	// TODO: �ڴ˴������Ϣ����������
}


void DLG_TUSHUGUAN::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //����1��
	CDialogEx::OnClose();
}


void DLG_TUSHUGUAN::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	start = 4;
	::MessageBox(NULL, _T("�������Ϊ:ͼ���"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_TUSHUGUAN::OnBnClickedEnd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	end = 4;
	::MessageBox(NULL, _T("�յ�����Ϊ:ͼ���"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_TUSHUGUAN::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnClose();
}
