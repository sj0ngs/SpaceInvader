#pragma once

class CPathMgr
{
	SINGLE(CPathMgr);

private:
	wchar_t m_szContentPath[256];


public:
	void Init();
	void Render();

public:
	const wchar_t* GetContentPath() { return m_szContentPath; }
};

