// DLG_ZHENCAO.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_ZHENCAO.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_ZHENCAO �Ի���

IMPLEMENT_DYNAMIC(DLG_ZHENCAO, CDialogEx)

DLG_ZHENCAO::DLG_ZHENCAO(CWnd* pParent /*=NULL*/)
	: CDialogEx(DLG_ZHENCAO::IDD, pParent)
{

}

DLG_ZHENCAO::~DLG_ZHENCAO()
{
}

void DLG_ZHENCAO::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DLG_ZHENCAO, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
	ON_WM_CLOSE()
	ON_BN_CLICKED(ID_START, &DLG_ZHENCAO::OnBnClickedStart)
	ON_BN_CLICKED(ID_END, &DLG_ZHENCAO::OnBnClickedEnd)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &DLG_ZHENCAO::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// DLG_ZHENCAO ��Ϣ�������


void DLG_ZHENCAO::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_ZHENCAO); //������Դ���λͼ
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //����һ������pdc���豸������
	bmp.SelectObject(&mybitmap); //�滻�豸����λͼ
	pdc->BitBlt(0,0,400,250,&bmp,0,0,SRCCOPY); //����λͼ��pdc Ҳ����������
	mybitmap.DeleteObject();//�ͷŵ�����
	ReleaseDC(pdc); //�ͷŵ��豸������
	ReleaseDC(&bmp); //�ͷŵ��豸������
	CDialogEx::OnPaint();
}


void DLG_ZHENCAO::OnShowWindow(BOOL bShow, UINT nStatus)
{
	AnimateWindow(200, AW_CENTER);  //���ڵ���
	OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
	// TODO: �ڴ˴������Ϣ����������
}


void DLG_ZHENCAO::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //����1��
	CDialogEx::OnClose();
}


void DLG_ZHENCAO::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	start = 7;
	::MessageBox(NULL, _T("�������Ϊ:���"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_ZHENCAO::OnBnClickedEnd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	end = 7;
	::MessageBox(NULL, _T("�յ�����Ϊ:���"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_ZHENCAO::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnClose();
}
