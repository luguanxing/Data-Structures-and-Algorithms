// DLG_TIYUGUAN.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_TIYUGUAN.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_TIYUGUAN �Ի���

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


// DLG_TIYUGUAN ��Ϣ�������


void DLG_TIYUGUAN::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_TIYUGUAN); //������Դ���λͼ
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


void DLG_TIYUGUAN::OnShowWindow(BOOL bShow, UINT nStatus)
{
	AnimateWindow(200, AW_CENTER);  //���ڵ���
	OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
	// TODO: �ڴ˴������Ϣ����������
}


void DLG_TIYUGUAN::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //����1��
	CDialogEx::OnClose();
}


void DLG_TIYUGUAN::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	start = 6;
	::MessageBox(NULL, _T("�������Ϊ:������"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_TIYUGUAN::OnBnClickedEnd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	end = 6;
	::MessageBox(NULL, _T("�յ�����Ϊ:������"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_TIYUGUAN::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnClose();
}
