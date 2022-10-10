#pragma once

class CLevel;

class CLevelMgr
{
	SINGLE(CLevelMgr);
private:
	CLevel* m_arrLevel[(UINT)ELEVEL_TYPE::END];
	CLevel* m_CurLevel;

public:
	CLevel* GetCurLevel() { return m_CurLevel; }

public:
	void Init();
	void Tick();
	void Render(HDC _DC);
};

