// DLG_JIACAO.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "DLG_JIACAO.h"
#include "afxdialogex.h"
extern int start, end;

// DLG_JIACAO �Ի���

IMPLEMENT_DYNAMIC(DLG_JIACAO, CDialogEx)

DLG_JIACAO::DLG_JIACAO(CWnd* pParent /*=NULL*/)
	: CDialogEx(DLG_JIACAO::IDD, pParent)
{

}

DLG_JIACAO::~DLG_JIACAO()
{
}

void DLG_JIACAO::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DLG_JIACAO, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(ID_START, &DLG_JIACAO::OnBnClickedStart)
	ON_BN_CLICKED(ID_END, &DLG_JIACAO::OnBnClickedEnd)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &DLG_JIACAO::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// DLG_JIACAO ��Ϣ�������


void DLG_JIACAO::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap mybitmap;
	mybitmap.LoadBitmap(IDB_BITMAP_JIACAO); //������Դ���λͼ
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //����һ������pdc���豸������
	bmp.SelectObject(&mybitmap); //�滻�豸����λͼ
	pdc->BitBlt(0,0,400,275,&bmp,0,0,SRCCOPY); //����λͼ��pdc Ҳ����������
	mybitmap.DeleteObject();//�ͷŵ�����
	ReleaseDC(pdc); //�ͷŵ��豸������
	ReleaseDC(&bmp); //�ͷŵ��豸������
	CDialogEx::OnPaint();
}

void DLG_JIACAO::OnShowWindow(BOOL bShow, UINT nStatus)
{
	// TODO: �ڴ˴������Ϣ����������
	AnimateWindow(200, AW_CENTER);  //���ڵ���
	DLG_JIACAO::OnPaint();
	CDialogEx::OnShowWindow(bShow, nStatus);
}

void DLG_JIACAO::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	::AnimateWindow(GetSafeHwnd(), 300, AW_BLEND | AW_HIDE);    //����1��
	CDialogEx::OnClose();
}





void DLG_JIACAO::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	start = 8;
	::MessageBox(NULL, _T("�������Ϊ:�ٲ�"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_JIACAO::OnBnClickedEnd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	end = 8;
	::MessageBox(NULL, _T("�յ�����Ϊ:�ٲ�"),	_T("����"),  MB_ICONINFORMATION);
}


void DLG_JIACAO::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnClose();
}
