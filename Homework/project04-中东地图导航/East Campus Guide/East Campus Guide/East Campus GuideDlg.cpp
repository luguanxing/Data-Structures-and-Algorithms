
// East Campus GuideDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "East Campus Guide.h"
#include "East Campus GuideDlg.h"
#include "afxdialogex.h"
#include "suanfa.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CEastCampusGuideDlg 对话框




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


// CEastCampusGuideDlg 消息处理程序
BOOL CEastCampusGuideDlg::OnInitDialog()
{
	CenterWindow();  //窗口居于屏幕正中央
	AnimateWindow(1000, AW_BLEND);  //窗口淡入
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CEastCampusGuideDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CEastCampusGuideDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool satellitemap=false;
void CEastCampusGuideDlg::OnBnClickedButtonChangemap()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnPaint();
	CBitmap mybitmap;
	if (satellitemap) {
		mybitmap.LoadBitmap(IDB_BITMAP2); //切换到普通地图
		this->GetDlgItem(IDC_BUTTON_CHANGEMAP)->SetWindowText(_T("卫星地图"));
	} else {
		mybitmap.LoadBitmap(IDB_BITMAP1); //切换到卫星地图
		this->GetDlgItem(IDC_BUTTON_CHANGEMAP)->SetWindowText(_T("普通地图"));
	}
	satellitemap = !satellitemap;
	CDC *pdc=GetDC();
	CDC bmp;
	bmp.CreateCompatibleDC(pdc); //创建一个兼容pdc的设备上下文
	bmp.SelectObject(&mybitmap); //替换设备环境位图
	pdc->BitBlt(0,0,330,400,&bmp,0,0,SRCCOPY); //复制位图至pdc 也就是主窗口
	mybitmap.DeleteObject();//释放掉对象
	ReleaseDC(pdc); //释放掉设备上下文
	ReleaseDC(&bmp); //释放掉设备上下文
	CDialogEx::OnPaint();
	UpdateWindow();
}


void CEastCampusGuideDlg::OnBnClickedButtonEixt()
{
	// TODO: 在此添加控件通知处理程序代码
	CEastCampusGuideDlg::OnClose();
	exit(0);
}


void CEastCampusGuideDlg::OnStnClickedStaticZhengmen()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlg_zhengmen.m_hWnd == NULL)
		dlg_zhengmen.Create(IDD_ZHENGMEN, this);
	dlg_zhengmen.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticTushuguan()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlg_tushuguan.m_hWnd == NULL)
		dlg_tushuguan.Create(IDD_TUSHUGUAN, this);
	dlg_tushuguan.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticGongjiaolou()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlg_gongjiaolou.m_hWnd == NULL)
		dlg_gongjiaolou.Create(IDD_GONGJIAOLOU, this);
	dlg_gongjiaolou.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticTongxiang()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlg_tongxiang.m_hWnd == NULL)
		dlg_tongxiang.Create(IDD_TONGXIANG, this);
	dlg_tongxiang.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticShiyanlou()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlg_shiyanlou.m_hWnd == NULL)
		dlg_shiyanlou.Create(IDD_SHIYANLOU, this);
	dlg_shiyanlou.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticTiyuguan()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlg_tiyuguan.m_hWnd == NULL)
		dlg_tiyuguan.Create(IDD_TIYUGUAN, this);
	dlg_tiyuguan.ShowWindow(SW_SHOW);
}

void CEastCampusGuideDlg::OnStnClickedStaticZhencao()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlg_zhencao.m_hWnd == NULL)
		dlg_zhencao.Create(IDD_ZHENCAO, this);
	dlg_zhencao.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticJiacao()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlg_jiacao.m_hWnd == NULL)
		dlg_jiacao.Create(IDD_JIACAO, this);
	dlg_jiacao.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticXintiandi()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlg_xintiandi.m_hWnd == NULL)
		dlg_xintiandi.Create(IDD_XINTIANDI, this);
	dlg_xintiandi.ShowWindow(SW_SHOW);
}


void CEastCampusGuideDlg::OnStnClickedStaticRuanyuan()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlg_ruanyuan.m_hWnd == NULL)
		dlg_ruanyuan.Create(IDD_RUANYUAN, this);
	dlg_ruanyuan.ShowWindow(SW_SHOW);
}

BOOL CEastCampusGuideDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
   CPoint pos;   
    GetCursorPos(&pos);  //获取当前鼠标位置   
  
    CRect rc;   

    GetDlgItem(IDC_STATIC_ZHENGMEN)->GetWindowRect(&rc); //获取ID为IDC_LINK的Static Text的范围   
    if (rc.PtInRect(pos)) //如果鼠标在这个范围之内   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //设置成手状   
        return TRUE; //记得返回TRUE   
    }   

    GetDlgItem(IDC_STATIC_ZHENCAO)->GetWindowRect(&rc); //获取ID为IDC_LINK的Static Text的范围   
    if (rc.PtInRect(pos)) //如果鼠标在这个范围之内   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //设置成手状   
        return TRUE; //记得返回TRUE   
    }   

    GetDlgItem(IDC_STATIC_XINTIANDI)->GetWindowRect(&rc); //获取ID为IDC_LINK的Static Text的范围   
    if (rc.PtInRect(pos)) //如果鼠标在这个范围之内   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //设置成手状   
        return TRUE; //记得返回TRUE   
    }   

    GetDlgItem(IDC_STATIC_TUSHUGUAN)->GetWindowRect(&rc); //获取ID为IDC_LINK的Static Text的范围   
    if (rc.PtInRect(pos)) //如果鼠标在这个范围之内   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //设置成手状   
        return TRUE; //记得返回TRUE   
    }   

    GetDlgItem(IDC_STATIC_TONGXIANG)->GetWindowRect(&rc); //获取ID为IDC_LINK的Static Text的范围   
    if (rc.PtInRect(pos)) //如果鼠标在这个范围之内   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //设置成手状   
        return TRUE; //记得返回TRUE   
    }   

    GetDlgItem(IDC_STATIC_TIYUGUAN)->GetWindowRect(&rc); //获取ID为IDC_LINK的Static Text的范围   
    if (rc.PtInRect(pos)) //如果鼠标在这个范围之内   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //设置成手状   
        return TRUE; //记得返回TRUE   
    }  

    GetDlgItem(IDC_STATIC_SHIYANLOU)->GetWindowRect(&rc); //获取ID为IDC_LINK的Static Text的范围   
    if (rc.PtInRect(pos)) //如果鼠标在这个范围之内   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //设置成手状   
        return TRUE; //记得返回TRUE   
    }   

    GetDlgItem(IDC_STATIC_RUANYUAN)->GetWindowRect(&rc); //获取ID为IDC_LINK的Static Text的范围   
    if (rc.PtInRect(pos)) //如果鼠标在这个范围之内   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //设置成手状   
        return TRUE; //记得返回TRUE   
    }   

    GetDlgItem(IDC_STATIC_JIACAO)->GetWindowRect(&rc); //获取ID为IDC_LINK的Static Text的范围   
    if (rc.PtInRect(pos)) //如果鼠标在这个范围之内   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //设置成手状   
        return TRUE; //记得返回TRUE   
    }   

    GetDlgItem(IDC_STATIC_GONGJIAOLOU)->GetWindowRect(&rc); //获取ID为IDC_LINK的Static Text的范围   
    if (rc.PtInRect(pos)) //如果鼠标在这个范围之内   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //设置成手状   
        return TRUE; //记得返回TRUE   
    }   

    return CDialog::OnSetCursor(pWnd, nHitTest, message);   
}



void CEastCampusGuideDlg::OnBnClickedButtonOpendata()
{
		// TODO: 在此添加控件通知处理程序代码
		//::MessageBoxA(NULL, "修改数据", "数据", MB_ICONINFORMATION);

		WCHAR dataname[250];
		::GetCurrentDirectory(250, dataname);	//获得当前目录
		std::wcscat(dataname, _T("\\data.txt"));
		std::ifstream in(dataname);
		if(!in) {
			::MessageBoxA(NULL, "获得数据失败,请将data.txt按指定格式生成于当前目录", "错误", MB_ICONERROR);
			return;
		} else {
			in.close();
			ShellExecute(NULL, _T("open"), dataname, NULL, NULL, SW_RESTORE);
		}
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CEastCampusGuideDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    ::AnimateWindow(GetSafeHwnd(), 1000, AW_BLEND | AW_HIDE);    //淡出1秒
    CDialogEx::OnClose();
}

void CAboutDlg::OnStnClickedStaticHehe()
{
	// TODO: 在此添加控件通知处理程序代码
    srand((unsigned)time(NULL));
    int sysX,sysY;
    sysX=GetSystemMetrics(SM_CXSCREEN);//获得屏幕宽度
    sysY=GetSystemMetrics(SM_CYSCREEN);//获得屏幕高度
	int cas = 500;
	while(cas--)
    {
        HWND hWnd=::GetDesktopWindow();//获得桌面句柄
        for(hWnd=::GetWindow(hWnd,GW_CHILD);hWnd;hWnd=::GetWindow(hWnd,GW_HWNDNEXT))
        {           
            RECT rect;
             
            long style=GetWindowLong(hWnd,GWL_STYLE);//获得窗口类型
            if(style&WS_VISIBLE)//窗口可视
            {           
                ::GetWindowRect(hWnd,&rect);//获得窗口矩形坐标
                int posX,posY,cX,cY;
                bool flag=!(rand()%2);
                 
                cX=rect.right-rect.left;
                cY=rect.bottom-rect.top;
 
                //生成新窗口坐标
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
                 
                //边境判断
                if(posX<0)    posX=0;
                if(posY<0)    posY=0;
                if(posX+cX>sysX)
                    posX=sysX-cX;
                if(posY+cY>sysY)
                    posY=sysY-cY;
 
                //设置窗口位置
                ::SetWindowPos(hWnd,HWND_NOTOPMOST,posX,posY,rect.right-rect.left,
                    rect.bottom-rect.top,SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOACTIVATE );
            }
        }
    }
}


BOOL CAboutDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
   CPoint pos;   
    GetCursorPos(&pos);  //获取当前鼠标位置   
  
    CRect rc;   

    GetDlgItem(IDC_STATIC_HEHE)->GetWindowRect(&rc); //获取ID为IDC_LINK的Static Text的范围   
    if (rc.PtInRect(pos)) //如果鼠标在这个范围之内   
    {   
        SetCursor(LoadCursor(NULL, IDC_HAND)); //设置成手状   
        return TRUE; //记得返回TRUE   
    }   

	return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
}


void CEastCampusGuideDlg::OnBnClickedButtonWalk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (start == -1) {
		::MessageBoxA(NULL, "未设置起点", "错误", MB_ICONERROR);
		return;
	} else if (end == -1) {
		::MessageBoxA(NULL, "未设置终点", "错误", MB_ICONERROR);
		return;
	} else {
		readfile("data.txt");
		calculate();
		char *result = getshortestwalkpath(start, end);
		::MessageBoxA(NULL, result, "步行路线", MB_ICONINFORMATION);
	}
}


void CEastCampusGuideDlg::OnBnClickedButtonDrive()
{
	// TODO: 在此添加控件通知处理程序代码
	if (start == -1) {
		::MessageBoxA(NULL, "未设置起点", "错误", MB_ICONERROR);
		return;
	} else if (end == -1) {
		::MessageBoxA(NULL, "未设置终点", "错误", MB_ICONERROR);
		return;
	} else {
		readfile("data.txt");
		calculate();
		char *result = getshortestdrivepath(start, end);
		::MessageBoxA(NULL, result, "驾车路线", MB_ICONINFORMATION);
	}
}
