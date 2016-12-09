
// East Campus GuideDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "East Campus GuideDlg.h"
#include "afxdialogex.h"
#include "suanfa.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedStaticHehe();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
	ON_STN_CLICKED(IDC_STATIC_HEHE, &CAboutDlg::OnStnClickedStaticHehe)
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CEastCampusGuideDlg �Ի���




CEastCampusGuideDlg::CEastCampusGuideDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEastCampusGuideDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEastCampusGuideDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEastCampusGuideDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_BUTTON_ZHENGMEN, &CEastCampusGuideDlg::OnBnClickedButtonZhengmen)
	ON_BN_CLICKED(IDC_BUTTON_CHANGEMAP, &CEastCampusGuideDlg::OnBnClickedButtonChangemap)
//	ON_WM_ERASEBKGND()
//	ON_BN_CLICKED(IDC_BUTTON_CLOSEMAP, &CEastCampusGuideDlg::OnBnClickedButtonClosemap)
ON_BN_CLICKED(IDC_BUTTON_EIXT, &CEastCampusGuideDlg::OnBnClickedButtonEixt)
ON_STN_CLICKED(IDC_STATIC_ZHENGMEN, &CEastCampusGuideDlg::OnStnClickedStaticZhengmen)
ON_STN_CLICKED(IDC_STATIC_TUSHUGUAN, &CEastCampusGuideDlg::OnStnClickedStaticTushuguan)
ON_STN_CLICKED(IDC_STATIC_GONGJIAOLOU, &CEastCampusGuideDlg::OnStnClickedStaticGongjiaolou)
ON_STN_CLICKED(IDC_STATIC_TONGXIANG, &CEastCampusGuideDlg::OnStnClickedStaticTongxiang)
ON_STN_CLICKED(IDC_STATIC_SHIYANLOU, &CEastCampusGuideDlg::OnStnClickedStaticShiyanlou)
ON_STN_CLICKED(IDC_STATIC_TIYUGUAN, &CEastCampusGuideDlg::OnStnClickedStaticTiyuguan)
//ON_BN_CLICKED(IDC_BUTTON_INFOMATION, &CEastCampusGuideDlg::OnBnClickedButtonInfomation)
ON_STN_CLICKED(IDC_STATIC_ZHENCAO, &CEastCampusGuideDlg::OnStnClickedStaticZhencao)
ON_STN_CLICKED(IDC_STATIC_JIACAO, &CEastCampusGuideDlg::OnStnClickedStaticJiacao)
ON_STN_CLICKED(IDC_STATIC_XINTIANDI, &CEastCampusGuideDlg::OnStnClickedStaticXintiandi)
ON_STN_CLICKED(IDC_STATIC_RUANYUAN, &CEastCampusGuideDlg::OnStnClickedStaticRuanyuan)
//ON_WM_MOUSEHOVER()
//ON_WM_MOUSEMOVE()
//ON_WM_MOUSELEAVE()
//ON_WM_MOUSEHOVER()
//ON_WM_MOUSEMOVE()
ON_WM_SETCURSOR()
//ON_BN_CLICKED(IDC_BUTTON_DATA, &CEastCampusGuideDlg::OnBnClickedButtonData)
ON_BN_CLICKED(IDC_BUTTON_OPENDATA, &CEastCampusGuideDlg::OnBnClickedButtonOpendata)
//ON_WM_DESTROY()
//ON_WM_CREATE()
//ON_WM_DESTROY()
//ON_WM_DESTROY()
ON_WM_CLOSE()
//ON_BN_CLICKED(IDC_BUTTON_OPENDATA2, &CEastCampusGuideDlg::OnBnClickedButtonOpendata2)
ON_BN_CLICKED(IDC_BUTTON_WALK, &CEastCampusGuideDlg::OnBnClickedButtonWalk)
ON_BN_CLICKED(IDC_BUTTON_DRIVE, &CEastCampusGuideDlg::OnBnClickedButtonDrive)
END_MESSAGE_MAP()


// CEastCampusGuideDlg ��Ϣ�������
BOOL CEastCampusGuideDlg::OnInitDialog()
{
	CenterWindow();  //���ھ�����Ļ������
	AnimateWindow(1000, AW_BLEND);  //���ڵ���
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CEastCampusGuideDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CEastCampusGuideDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CEastCampusGuideDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool satellitemap=false;
void CEastCampusGuideDlg::OnBnClickedButtonChangemap()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnPaint();
	CBitmap mybitmap;
	if (satellitemap) {
		mybitmap.LoadBitmap(IDB_BITMAP2); //�л�����ͨ��ͼ
		this->GetDlgItem(IDC_BUTTON_CHANGEMAP)->SetWindowText(_T("���ǵ�ͼ"));
	} else {
		mybitmap.LoadBitmap(IDB_BITMAP1); //�л������ǵ�ͼ
		this->GetDlgItem(IDC_BUTTON_CHANGEMAP)->SetWindowText(_T("��ͨ��ͼ"));
	}
	satellitemap = !satellitemap;
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //����һ������pdc���豸������
	bmp.SelectObject(&mybitmap); //�滻�豸����λͼ
	pdc->BitBlt(0,0,330,400,&bmp,0,0,SRCCOPY); //����λͼ��pdc Ҳ����������
	mybitmap.DeleteObject();//�ͷŵ�����
	ReleaseDC(pdc); //�ͷŵ��豸������
	ReleaseDC(&bmp); //�ͷŵ��豸������
	CDialogEx::OnPaint();
	UpdateWindow();
}


void CEastCampusGuideDlg::OnBnClickedButtonEixt()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEastCampusGuideDlg::OnClose();
	exit(0);
}


void CEastCampusGuideDlg::OnStnClickedStaticZhengmen()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (dlg_zhengmen.m_hWnd == NULL)
		dlg_zhengmen.Create(IDD_ZHENGMEN, this);
	dlg_zhengmen.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticTushuguan()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (dlg_tushuguan.m_hWnd == NULL)
		dlg_tushuguan.Create(IDD_TUSHUGUAN, this);
	dlg_tushuguan.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticGongjiaolou()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (dlg_gongjiaolou.m_hWnd == NULL)
		dlg_gongjiaolou.Create(IDD_GONGJIAOLOU, this);
	dlg_gongjiaolou.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticTongxiang()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (dlg_tongxiang.m_hWnd == NULL)
		dlg_tongxiang.Create(IDD_TONGXIANG, this);
	dlg_tongxiang.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticShiyanlou()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (dlg_shiyanlou.m_hWnd == NULL)
		dlg_shiyanlou.Create(IDD_SHIYANLOU, this);
	dlg_shiyanlou.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticTiyuguan()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (dlg_tiyuguan.m_hWnd == NULL)
		dlg_tiyuguan.Create(IDD_TIYUGUAN, this);
	dlg_tiyuguan.ShowWindow(SW_SHOW);
}

void CEastCampusGuideDlg::OnStnClickedStaticZhencao()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (dlg_zhencao.m_hWnd == NULL)
		dlg_zhencao.Create(IDD_ZHENCAO, this);
	dlg_zhencao.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticJiacao()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (dlg_jiacao.m_hWnd == NULL)
		dlg_jiacao.Create(IDD_JIACAO, this);
	dlg_jiacao.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticXintiandi()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (dlg_xintiandi.m_hWnd == NULL)
		dlg_xintiandi.Create(IDD_XINTIANDI, this);
	dlg_xintiandi.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticRuanyuan()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (dlg_ruanyuan.m_hWnd == NULL)
		dlg_ruanyuan.Create(IDD_RUANYUAN, this);
	dlg_ruanyuan.ShowWindow(SW_SHOW);
}

BOOL CEastCampusGuideDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
   CPoint pos;   
    GetCursorPos(&pos);  //��ȡ��ǰ���λ��   
  
    CRect rc;   

    GetDlgItem(IDC_STATIC_ZHENGMEN)->GetWindowRect(&rc); //��ȡIDΪIDC_LINK��Static Text�ķ�Χ   
    if (rc.PtInRect(pos)) //�������������Χ֮��   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //���ó���״   
        return TRUE; //�ǵ÷���TRUE   
    }   

    GetDlgItem(IDC_STATIC_ZHENCAO)->GetWindowRect(&rc); //��ȡIDΪIDC_LINK��Static Text�ķ�Χ   
    if (rc.PtInRect(pos)) //�������������Χ֮��   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //���ó���״   
        return TRUE; //�ǵ÷���TRUE   
    }   

    GetDlgItem(IDC_STATIC_XINTIANDI)->GetWindowRect(&rc); //��ȡIDΪIDC_LINK��Static Text�ķ�Χ   
    if (rc.PtInRect(pos)) //�������������Χ֮��   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //���ó���״   
        return TRUE; //�ǵ÷���TRUE   
    }   

    GetDlgItem(IDC_STATIC_TUSHUGUAN)->GetWindowRect(&rc); //��ȡIDΪIDC_LINK��Static Text�ķ�Χ   
    if (rc.PtInRect(pos)) //�������������Χ֮��   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //���ó���״   
        return TRUE; //�ǵ÷���TRUE   
    }   

    GetDlgItem(IDC_STATIC_TONGXIANG)->GetWindowRect(&rc); //��ȡIDΪIDC_LINK��Static Text�ķ�Χ   
    if (rc.PtInRect(pos)) //�������������Χ֮��   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //���ó���״   
        return TRUE; //�ǵ÷���TRUE   
    }   

    GetDlgItem(IDC_STATIC_TIYUGUAN)->GetWindowRect(&rc); //��ȡIDΪIDC_LINK��Static Text�ķ�Χ   
    if (rc.PtInRect(pos)) //�������������Χ֮��   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //���ó���״   
        return TRUE; //�ǵ÷���TRUE   
    }  

    GetDlgItem(IDC_STATIC_SHIYANLOU)->GetWindowRect(&rc); //��ȡIDΪIDC_LINK��Static Text�ķ�Χ   
    if (rc.PtInRect(pos)) //�������������Χ֮��   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //���ó���״   
        return TRUE; //�ǵ÷���TRUE   
    }   

    GetDlgItem(IDC_STATIC_RUANYUAN)->GetWindowRect(&rc); //��ȡIDΪIDC_LINK��Static Text�ķ�Χ   
    if (rc.PtInRect(pos)) //�������������Χ֮��   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //���ó���״   
        return TRUE; //�ǵ÷���TRUE   
    }   

    GetDlgItem(IDC_STATIC_JIACAO)->GetWindowRect(&rc); //��ȡIDΪIDC_LINK��Static Text�ķ�Χ   
    if (rc.PtInRect(pos)) //�������������Χ֮��   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //���ó���״   
        return TRUE; //�ǵ÷���TRUE   
    }   

    GetDlgItem(IDC_STATIC_GONGJIAOLOU)->GetWindowRect(&rc); //��ȡIDΪIDC_LINK��Static Text�ķ�Χ   
    if (rc.PtInRect(pos)) //�������������Χ֮��   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //���ó���״   
        return TRUE; //�ǵ÷���TRUE   
    }   

    return CDialog::OnSetCursor(pWnd, nHitTest, message);   
}



void CEastCampusGuideDlg::OnBnClickedButtonOpendata()
{
		// TODO: �ڴ���ӿؼ�֪ͨ����������
		//::MessageBoxA(NULL, "�޸�����", "����", MB_ICONINFORMATION);

		WCHAR dataname[250];
		::GetCurrentDirectory(250, dataname);	//��õ�ǰĿ¼
		std::wcscat(dataname, _T("\\data.txt"));
		std::ifstream in(dataname);
		if(!in) {
			::MessageBoxA(NULL, "�������ʧ��,�뽫data.txt��ָ����ʽ�����ڵ�ǰĿ¼", "����", MB_ICONERROR);
			return;
		} else {
			in.close();
			ShellExecute(NULL, _T("open"), dataname, NULL, NULL, SW_RESTORE);
		}
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CEastCampusGuideDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    ::AnimateWindow(GetSafeHwnd(), 1000, AW_BLEND | AW_HIDE);    //����1��
    CDialogEx::OnClose();
}

void CAboutDlg::OnStnClickedStaticHehe()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    srand((unsigned)time(NULL));
    int sysX,sysY;
    sysX=GetSystemMetrics(SM_CXSCREEN);//�����Ļ���
    sysY=GetSystemMetrics(SM_CYSCREEN);//�����Ļ�߶�
	int cas = 500;
	while(cas--)
    {
        HWND hWnd=::GetDesktopWindow();//���������
        for(hWnd=::GetWindow(hWnd,GW_CHILD);hWnd;hWnd=::GetWindow(hWnd,GW_HWNDNEXT))
        {           
            RECT rect;
             
            long style=GetWindowLong(hWnd,GWL_STYLE);//��ô�������
            if(style&WS_VISIBLE)//���ڿ���
            {           
                ::GetWindowRect(hWnd,&rect);//��ô��ھ�������
                int posX,posY,cX,cY;
                bool flag=!(rand()%2);
                 
                cX=rect.right-rect.left;
                cY=rect.bottom-rect.top;
 
                //�����´�������
                if(flag)
                {
                    posX=rect.left+rand()%10*5;
                    posY=rect.top+rand()%10*5;
                }               
                else
                {
                    posX=rect.left-rand()%10*5;
                    posY=rect.top-rand()%10*5;
                }
                 
                //�߾��ж�
                if(posX<0)    posX=0;
                if(posY<0)    posY=0;
                if(posX+cX>sysX)
                    posX=sysX-cX;
                if(posY+cY>sysY)
                    posY=sysY-cY;
 
                //���ô���λ��
                ::SetWindowPos(hWnd,HWND_NOTOPMOST,posX,posY,rect.right-rect.left,
                    rect.bottom-rect.top,SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOACTIVATE );
            }
        }
    }
}


BOOL CAboutDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
   CPoint pos;   
    GetCursorPos(&pos);  //��ȡ��ǰ���λ��   
  
    CRect rc;   

    GetDlgItem(IDC_STATIC_HEHE)->GetWindowRect(&rc); //��ȡIDΪIDC_LINK��Static Text�ķ�Χ   
    if (rc.PtInRect(pos)) //�������������Χ֮��   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //���ó���״   
        return TRUE; //�ǵ÷���TRUE   
    }   

	return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
}


void CEastCampusGuideDlg::OnBnClickedButtonWalk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (start == -1) {
		::MessageBoxA(NULL, "δ�������", "����", MB_ICONERROR);
		return;
	} else if (end == -1) {
		::MessageBoxA(NULL, "δ�����յ�", "����", MB_ICONERROR);
		return;
	} else {
		readfile("data.txt");
		calculate();
		char *result = getshortestwalkpath(start, end);
		::MessageBoxA(NULL, result, "����·��", MB_ICONINFORMATION);
	}
}


void CEastCampusGuideDlg::OnBnClickedButtonDrive()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (start == -1) {
		::MessageBoxA(NULL, "δ�������", "����", MB_ICONERROR);
		return;
	} else if (end == -1) {
		::MessageBoxA(NULL, "δ�����յ�", "����", MB_ICONERROR);
		return;
	} else {
		readfile("data.txt");
		calculate();
		char *result = getshortestdrivepath(start, end);
		::MessageBoxA(NULL, result, "�ݳ�·��", MB_ICONINFORMATION);
	}
}
