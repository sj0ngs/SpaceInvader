#include "pch.h"
#include "CKeyMgr.h"

int g_arrVK[(UINT)EKEY::END] =
{
	VK_UP,
	VK_DOWN,
	VK_LEFT,
	VK_RIGHT,

	VK_SPACE,
	VK_RETURN,
	VK_ESCAPE,
	VK_LMENU,
	VK_LCONTROL,
	VK_LSHIFT,
	VK_TAB,

	VK_LBUTTON,
	VK_RBUTTON,

	'Q',
	'W',
	'E',
	'R'
};

CKeyMgr::CKeyMgr()
{
}

CKeyMgr::~CKeyMgr()
{
}

void CKeyMgr::Init()
{
	for (int i = 0; i < (UINT)EKEY::END; i++)
	{
		m_vecKey.push_back(tKeyInfo{ (EKEY)i, EKEY_STATE::NONE, false });
	}
}

void CKeyMgr::Tick()
{
	if (GetFocus())
	{
		for (size_t i = 0; i < m_vecKey.size(); i++)
		{
			// 이번 프레임에 눌려졌다
			if (GetAsyncKeyState(g_arrVK[(UINT)m_vecKey[i].Key]) & 0x8000)
			{
				// 이전 프레임에 안눌렸었다 == 이번 프레임에 막 눌려진거다
				if (!m_vecKey[i].bPrev)
				{
					m_vecKey[i].State = EKEY_STATE::TAP;
					m_vecKey[i].bPrev = true;
				}
				else
					m_vecKey[i].State = EKEY_STATE::PRESSED;
			}
			else
			{
				if (m_vecKey[i].bPrev)
				{
					m_vecKey[i].State = EKEY_STATE::RELEASED;
					m_vecKey[i].bPrev = false;
				}
				else
					m_vecKey[i].State = EKEY_STATE::NONE;
			}
		}
	}
	else
	{
		for (size_t i = 0; i < m_vecKey.size(); i++)
		{
			if (EKEY_STATE::TAP == m_vecKey[i].State || EKEY_STATE::PRESSED == m_vecKey[i].State)
			{
				m_vecKey[i].State = EKEY_STATE::RELEASED;
				m_vecKey[i].bPrev = false;
			}
			else
				m_vecKey[i].State = EKEY_STATE::NONE;
		}
	}
}
