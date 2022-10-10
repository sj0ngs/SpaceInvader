#include "pch.h"
#include "CLevelMgr.h"

#include "CLevel.h"
#include "CStage_01.h"

CLevelMgr::CLevelMgr()	:
	m_arrLevel{},
	m_CurLevel(nullptr)
{
}

CLevelMgr::~CLevelMgr()
{
	for (int i = 0; i < (UINT)ELEVEL_TYPE::END; i++)
	{
		SAFE_DELETE(m_arrLevel[i]);
	}
}

void CLevelMgr::Init()
{
	m_arrLevel[0] = new CStage_01;
	
	for (int i = 0; i < (UINT)ELEVEL_TYPE::END; i++)
	{
		m_arrLevel[i]->Init();
	}

	m_CurLevel = m_arrLevel[0];
}

void CLevelMgr::Tick()
{
	m_CurLevel->Tick();
}

void CLevelMgr::Render(HDC _DC)
{
	m_CurLevel->Render(_DC);
}
