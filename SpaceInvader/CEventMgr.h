#pragma once

class CObj;
class CEventMgr
{
	SINGLE(CEventMgr);

private:
	vector<tEvent> m_vecEvent;
	vector<CObj*> m_vecGarbage;

public:
	void AddEvent(const tEvent& _Event) { m_vecEvent.push_back(_Event); }

public:
	void Tick();
};

