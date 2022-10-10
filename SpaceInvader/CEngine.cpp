#include "pch.h"
#include "CEngine.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CCollisionMgr.h"
#include "CEventMgr.h"
#include "CPathMgr.h"

CEngine::CEngine()	:
	m_hWnd(nullptr),
	m_hDC(nullptr),
	m_ptResolution{},
	m_memBit(nullptr),
	m_memDC(nullptr),
	m_arrPen{},
	m_arrBrush{}
{
}

CEngine::~CEngine()
{
	ReleaseDC(m_hWnd, m_hDC);

	DeleteDC(m_memDC);
	DeleteObject(m_memBit);

	for (int i = 0; i < (UINT)EPEN_TYPE::END; i++)
	{
		DeleteObject(m_arrPen[i]);
	}
	for (int i = 0; i < (UINT)EBRUSH_TYPE::END; i++)
	{
		DeleteObject(m_arrBrush[i]);
	}
}

void CEngine::Init(HWND _hWnd, UINT _iWidth, UINT _iHeight)
{
	m_hWnd = _hWnd;

	m_ptResolution.x = _iWidth;
	m_ptResolution.y = _iHeight;

	RECT Rt = { 0, 0, m_ptResolution.x , m_ptResolution.y };
	AdjustWindowRect(&Rt, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(m_hWnd, nullptr, 500, 200, abs(Rt.right - Rt.left), abs(Rt.bottom - Rt.top), 0);

	m_hDC = GetDC(m_hWnd);

	m_memBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	SelectObject(m_memDC, GetStockObject(BLACK_BRUSH));

	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_memDC, m_memBit);
	DeleteObject(hPrevBit);

	CreatePenBrush();

	CPathMgr::GetInst()->Init();
	CTimeMgr::GetInst()->Init();
	CKeyMgr::GetInst()->Init();
	CLevelMgr::GetInst()->Init();
}

void CEngine::Tick()
{
	CTimeMgr::GetInst()->Tick();
	CKeyMgr::GetInst()->Tick();
	CLevelMgr::GetInst()->Tick();
	CCollisionMgr::GetInst()->Tick();
}

void CEngine::Render(HDC _DC)
{
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	CLevelMgr::GetInst()->Render(m_memDC);

	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);

	CTimeMgr::GetInst()->Render();
}

void CEngine::Progress()
{
	Tick();

	Render(m_hDC);

	CEventMgr::GetInst()->Tick();
}

void CEngine::CreatePenBrush()
{
	m_arrPen[(UINT)EPEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)EPEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)EPEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	m_arrPen[(UINT)EPEN_TYPE::HOLLOW] = CreatePen(PS_NULL, 0, RGB(0, 0, 0));

	m_arrBrush[(UINT)EBRUSH_TYPE::YELLOW] = CreateSolidBrush(RGB(255, 234, 0));
	m_arrBrush[(UINT)EBRUSH_TYPE::AQUA] = CreateSolidBrush(RGB(0, 255, 255));
	m_arrBrush[(UINT)EBRUSH_TYPE::FIREBRICK] = CreateSolidBrush(RGB(178, 34, 34));
}
