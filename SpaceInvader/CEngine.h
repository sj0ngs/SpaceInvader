#pragma once

class CEngine
{
	SINGLE(CEngine);

private:
	HWND m_hWnd;
	HDC m_hDC;
	POINT m_ptResolution;
	HBITMAP m_memBit;
	HDC m_memDC;

	HPEN m_arrPen[(UINT)EPEN_TYPE::END];
	HBRUSH m_arrBrush[(UINT)EBRUSH_TYPE::END];

public:
	HWND GetMainWnd() const { return m_hWnd; }

	HDC GetMainDC()	const { return m_hDC; }

	HPEN GetPen(EPEN_TYPE _Type) { return m_arrPen[(UINT)_Type]; }

	HBRUSH GetBrush(EBRUSH_TYPE _Type) { return m_arrBrush[(UINT)_Type]; }

public:
	void Init(HWND _hWnd, UINT _iWidth, UINT _iHeight);
	void Tick();
	void Render(HDC _DC);
	void Progress();

public:
	void CreatePenBrush();
};

