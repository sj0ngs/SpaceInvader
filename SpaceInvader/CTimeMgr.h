#pragma once

class CTimeMgr
{
	SINGLE(CTimeMgr);

private:
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llFrequency;

	float m_fDeltaTime;
	float m_fTime;
	int m_iCount;


public:
	float GetDeltaTime() { return m_fDeltaTime; }

public:
	void Init();
	void Tick();
	void Render();
};

