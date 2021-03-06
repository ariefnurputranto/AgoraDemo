
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "AgoraSDKDemoPro.h"

#include "MainFrm.h"

#include "DlgJoinChannel.h"

#include "AGEventDef.h"

#include "SetupSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()


/*	ON_UPDATE_COMMAND_UI(ID_WND_USERVIEW, &CMainFrame::OnUpdateViewUserList)
	ON_UPDATE_COMMAND_UI(ID_WND_LOCALVIEW, &CMainFrame::OnUpdateLocalVideoView)
	ON_UPDATE_COMMAND_UI(ID_WND_REMOTEVIEW, &CMainFrame::OnUpdateRemoteVideoView)

	ON_COMMAND(ID_WND_USERVIEW, &CMainFrame::OnViewUserlist)
	ON_COMMAND(ID_WND_LOCALVIEW, &CMainFrame::OnLocalVideoView)	
	ON_COMMAND(ID_WND_REMOTEVIEW, &CMainFrame::OnRemoteVideoView)	
*/
	ON_REGISTERED_MESSAGE(AFX_WM_CREATETOOLBAR, &CMainFrame::OnToolbarCreateNew)
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL bNameValid;

	// 设置用于绘制所有用户界面元素的视觉管理器
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));

	if (!m_wndMenuBar.Create(this))
	{
		TRACE0("未能创建菜单栏\n");
		return -1;      // 未能创建
	}

	m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);

	// 防止菜单栏在激活时获得焦点
	CMFCPopupMenu::SetForceMenuFocus(FALSE);

	// 创建一个视图以占用框架的工作区
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("未能创建视图窗口\n");
		return -1;
	}

	CMFCToolBar::SetSizes (CSize (36, 30), CSize (24, 24));
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME, IDB_TOOLBAR_NORMAL, NULL, TRUE, NULL, NULL, IDB_TOOLBAR_NORMAL))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	CString strToolBarName;
	bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_STANDARD);
	ASSERT(bNameValid);
	m_wndToolBar.SetWindowText(strToolBarName);

	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);
	m_wndToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	m_wndToolBar.EnableTextLabels(TRUE);

	m_wndToolBar.SetButtonText(0, _T("加入频道"));
	m_wndToolBar.SetButtonText(1, _T("离开频道"));
	m_wndToolBar.SetButtonText(3, _T("参数设置"));

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}

	m_lpElementTextInfo = new CMFCRibbonStatusBarPane(ID_STATUSBAR_USERSTATUS, _T("当前离线(请登录)"), TRUE, 0, _T("当前离线(请登录)                   "));
	m_wndStatusBar.AddElement(m_lpElementTextInfo, _T("当前离线(请登录)"));
	m_wndStatusBar.AddSeparator();
	
	m_lpElementRoomInfo = new CMFCRibbonStatusBarPane(ID_STATUSBAR_ROOMINFO, _T("未加入任何房间"), TRUE, 0, _T("ROOM:00000000-[1000]ONLINE             "));
	m_wndStatusBar.AddElement(m_lpElementRoomInfo, _T("未加入任何房间"));
	m_wndStatusBar.AddSeparator();

	m_lpElementNetQuality = new CMFCRibbonStatusBarPane(ID_STATUSBAR_NETINFO, _T("网络质量:0"), TRUE, 0, _T("网络质量:0"));
	m_wndStatusBar.AddElement(m_lpElementNetQuality, _T("网络质量:0"));
	m_wndStatusBar.AddSeparator();
	
#ifdef UNICODE
	WCHAR wszVer[128];

	::MultiByteToWideChar(CP_ACP, 0, getAgoraRtcEngineVersion(), -1, wszVer, 128);
	m_lpElementSDKVer = new CMFCRibbonStatusBarPane(ID_STATUSBAR_SDKVER, wszVer, TRUE, 0, _T("SDKVer: 1.0.0-RC2      "));
	m_wndStatusBar.AddElement(m_lpElementSDKVer, wszVer);
#else
	m_lpElementSDKVer = new CMFCRibbonStatusBarPane(ID_STATUSBAR_SDKVER, getAgoraRtcEngineVersion(), TRUE, 0, _T("SDKVer: 1.0.0-RC2      "));
	m_wndStatusBar.AddElement(m_lpElementSDKVer, getAgoraRtcEngineVersion());
#endif

	// TODO: 如果您不希望工具栏和菜单栏可停靠，请删除这五行
	m_wndMenuBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndMenuBar);
	DockPane(&m_wndToolBar);

	// 启用 Visual Studio 2005 样式停靠窗口行为
	CDockingManager::SetDockingMode(DT_SMART);
	// 启用 Visual Studio 2005 样式停靠窗口自动隐藏行为
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// 加载菜单项图像(不在任何标准工具栏上):
	CMFCToolBar::AddToolBarForImageCollection(IDR_MENU_IMAGES, theApp.m_bHiColorIcons ? IDB_MENU_IMAGES_24 : 0);

	// 创建停靠窗口
/*	if (!m_wndUserView.Create(_T("在线用户列表"), this, CRect(0, 0, 250, 200), TRUE, ID_WND_USERVIEW, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
	{
		TRACE0("未能创建“类视图”窗口\n");
		return FALSE; // 未能创建
	}

	// 创建视频窗口
	if (!m_wndLocalView.Create(_T("本地视频"), this, CRect(0, 0, 250, 200), TRUE, ID_WND_LOCALVIEW, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
	{
		TRACE0("未能创建本地视频窗口\n");
		return FALSE; // 未能创建
	}

	if (!m_wndRemoteView.Create(_T("远端视频"), this, CRect(0, 0, 250, 200), TRUE, ID_WND_REMOTEVIEW, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_RIGHT | CBRS_FLOAT_MULTI))
	{
		TRACE0("未能创建远端视频窗口\n");
		return FALSE; // 未能创建
	}

	m_lpUserListCtrl = m_wndUserView.GetUserListCtrl();
	m_lpAgoraObject = CAgoraObject::GetAgoraObject();
	m_lpRTCEngine = CAgoraObject::GetEngine();
	m_lpAgoraObject->SetMsgHandlerWnd(GetSafeHwnd());

	m_lpRTCEngine->initialize("6D7A26A1D3554A54A9F43BE6797FE3E2");

	m_lpWndLocalVideo = m_wndLocalView.GetAgoraVideoWnd();
	for(int nIndex = 0; nIndex < 4; nIndex++)
		m_lpWndRemoteVideo[nIndex] = m_wndRemoteView.GetAgoraVideoWnd(nIndex);

	m_wndUserView.EnableDocking(CBRS_ALIGN_LEFT);
	m_wndLocalView.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndUserView);
	DockPane(&m_wndLocalView);
	m_wndLocalView.DockToWindow(&m_wndUserView, CBRS_TOP);

	m_wndRemoteView.EnableDocking(CBRS_ALIGN_RIGHT);	
	DockPane(&m_wndRemoteView);
*/
	// 启用工具栏和停靠窗口菜单替换
	EnablePaneMenu(TRUE, ID_VIEW_CUSTOMIZE, strCustomize, ID_VIEW_TOOLBAR);

	// 启用快速(按住 Alt 拖动)工具栏自定义
	CMFCToolBar::EnableQuickCustomization();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		 | WS_THICKFRAME | WS_MINIMIZEBOX /*| WS_MAXIMIZEBOX | WS_MAXIMIZE*/ | WS_SYSMENU;

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// 将焦点前移到视图窗口
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// 让视图第一次尝试该命令
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// 否则，执行默认处理
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CMainFrame::OnViewCustomize()
{
	CMFCToolBarsCustomizeDialog* pDlgCust = new CMFCToolBarsCustomizeDialog(this, TRUE /* 扫描菜单*/);
	pDlgCust->Create();
}

LRESULT CMainFrame::OnToolbarCreateNew(WPARAM wp,LPARAM lp)
{
	LRESULT lres = CFrameWndEx::OnToolbarCreateNew(wp,lp);
	if (lres == 0)
	{
		return 0;
	}

	CMFCToolBar* pUserToolbar = (CMFCToolBar*)lres;
	ASSERT_VALID(pUserToolbar);

	BOOL bNameValid;
	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);

	pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	return lres;
}

/*

void CMainFrame::OnUpdateViewUserList(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndUserView.IsVisible());
}

void CMainFrame::OnViewUserlist()
{
	ShowPane(&m_wndUserView, !(m_wndUserView.IsVisible ()), FALSE, TRUE);
}

void CMainFrame::OnUpdateLocalVideoView(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndLocalView.IsVisible());
}

void CMainFrame::OnLocalVideoView()
{
	ShowPane(&m_wndLocalView, !(m_wndLocalView.IsVisible ()), FALSE, TRUE);
}

void CMainFrame::OnUpdateRemoteVideoView(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndRemoteView.IsVisible());
}

void CChildView::OnRemoteVideoView()
{
	ShowPane(&m_wndRemoteView, !(m_wndRemoteView.IsVisible ()), FALSE, TRUE);
}
*/
void CMainFrame::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	lpMMI->ptMinTrackSize.x = 900;
	lpMMI->ptMinTrackSize.y = 680;

	lpMMI->ptMaxTrackSize.x = 900;
	lpMMI->ptMaxTrackSize.y = 680;

	CFrameWndEx::OnGetMinMaxInfo(lpMMI);
}
