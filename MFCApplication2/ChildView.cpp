
// ChildView.cpp : реализация класса CChildView
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "ChildView.h"
#include "C2DMyPoint.h"
#include "My2DObject13.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_nCacthed = -1;
}

CChildView::~CChildView()
{
	for (int i = 0; i<m_Objects.size(); i++) {
		delete m_Objects[i];
	}
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_NEWFIGURE,OnNewFigure)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

BOOL CChildView::OnEraseBkgnd(CDC* pDC) {
	return true;
}

// обработчики сообщений CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}
double x = 200;
double y = 200;
double A = 300;
double A1 = 100;
double A2 = 50;
double A3 = 80;

CMy2DPoint centr1 = CMy2DPoint(x, y);

//CChildView::CChildView() :figure(A, A1, A2, A3, 0, centr1) {}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // контекст устройства для рисования
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CRect rect;
	GetClientRect(&rect);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	CBitmap *pOldBmp = dcMem.SelectObject(&bmp);
	dcMem.FillSolidRect(0, 0, rect.Width(), rect.Height(), 0xFFFFFF);
	for (int i = 0; i < m_Objects.size(); i++) {
		m_Objects[i]->Draw(dcMem);
	}
	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, SRCCOPY);
	dcMem.SelectObject(pOldBmp);
	/*
	double x = figure.Get_centr().m_x;
	double y = figure.Get_centr().m_y;
	double A = figure.GetA();
	double A1 = figure.GetA1();
	double A2 = figure.GetA2();
	double A3 = figure.GetA3();

	dc.MoveTo(x - A/2 + A2,y - A/2);
	dc.LineTo(x+A/2,y-A/2);
	dc.LineTo(x+A/2,y-A1);
	dc.AngleArc(x+A/2,y,A1,90,180);
	dc.LineTo(x+A/2,y+A/2);
	dc.LineTo(x-A/2+A3,y+A/2);
	dc.AngleArc(x-A/2,y+A/2,A3,0,90);
	dc.LineTo(x-A/2,y-A/2+A2);
	dc.LineTo(x-A/2+A2,y-A/2+A2);
	dc.LineTo(x-A/2+A2,y-A/2);

	*/
	// Не вызывайте CWnd::OnPaint() для сообщений рисования
}
	
int CChildView::FindObject(CPoint point) {
	int nObj = -1;
	for (int i = m_Objects.size() - 1; i >= 0; i--) {
		if (m_Objects[i]->IsInside(point.x,2* m_Objects[i]->Get_centr().m_y - point.y)) {
			nObj = i;
			break;
		}
	}
	return nObj;
}
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	m_nCacthed = FindObject(point);
	if (m_nCacthed >= 0) {
		m_MousePos = point;
		SetCapture();
	}
	/*
	double y = figure.Get_centr().m_y;
	if (figure.IsInside(point.x, -point.y + 2 * y)) {
		m_bCatched = true;
		m_MousePos = point;
		SetCapture();
	}
	//	AfxMessageBox(_T("Success"));
	//else AfxMessageBox(_T("Fail"));
	*/
	CWnd::OnLButtonDown(nFlags, point);
	
}

void CChildView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	
	m_nCacthed = FindObject(point);
	if (m_nCacthed >= 0) {
		//m_MousePos = point;
		//SetCapture();
		//m_Objects[m_nCacthed]->
	
		CDlgProperties Dlg(m_Objects[m_nCacthed]->GetA1(), m_Objects[m_nCacthed]->GetA(), 
			m_Objects[m_nCacthed]->GetA2(), m_Objects[m_nCacthed]->GetA3(), m_Objects[m_nCacthed]->Get_Angle());
		if(Dlg.DoModal()) {
			m_Objects[m_nCacthed]->setA1(Dlg.m_A1);
			m_Objects[m_nCacthed]->setA(Dlg.m_A);
			m_Objects[m_nCacthed]->setA2(Dlg.m_A2);
			m_Objects[m_nCacthed]->setA3(Dlg.m_A3);
			m_Objects[m_nCacthed]->setAngle(Dlg.m_Angle);
			Invalidate();
			m_nCacthed = -1;
			ReleaseCapture();
		}
	}
	CWnd::OnLButtonDblClk(nFlags, point);
}



void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	m_nCacthed = -1;


	ReleaseCapture();
	
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (m_nCacthed >=0) {
		CRect rect;
		GetClientRect(&rect);
		point.x = min(rect.right, max(rect.left, point.x));
		point.y = min(rect.bottom, max(rect.top, point.y));
		CPoint Delta = point - m_MousePos;
		m_Objects[m_nCacthed]->Move(Delta.x, Delta.y);
		m_MousePos = point;
		Invalidate();
	}

	CWnd::OnMouseMove(nFlags, point);
}

void CChildView::OnNewFigure() {
	CRect rect;
	GetClientRect(&rect);
	double x = rand()%rect.Width();
	double y = rand()%rect.Height();
	double A = 300;
	double A1 = 100;
	double A2 = 50;
	double A3 = 80;
	double angle = rand()%7;
	CMy2DPoint centr1 = CMy2DPoint(x, y);
	m_Objects.push_back(new CMy2DObject13(A, A1, A2, A3, angle, centr1));
	Invalidate();
}



BOOL CChildView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	int m_nCacthed2 = -1;
	m_nCacthed2 = FindObject(pt);
	if (m_nCacthed2 >= 0) {
		m_MousePos = pt;
		m_Objects[m_nCacthed2]->setAngle(m_Objects[m_nCacthed2]->Get_Angle() + zDelta/100.0);
		Invalidate();
		
	}
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	return CWnd::OnMouseWheel(nFlags, zDelta, pt);
}
