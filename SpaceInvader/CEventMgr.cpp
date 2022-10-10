#include "pch.h"
#include "CEventMgr.h"

#include "CLevelMgr.h"

#include "CLevel.h"
#include "CObj.h"

CEventMgr::CEventMgr()
{
}

CEventMgr::~CEventMgr()
{
}

void CEventMgr::Tick()
{
	// ���� ���� ������Ʈ ����
	for (size_t i = 0; i < m_vecGarbage.size(); i++)
	{
		delete m_vecGarbage[i];
	}
	m_vecGarbage.clear();

	// �̺�Ʈ ó��
	for (size_t i = 0; i < m_vecEvent.size(); i++)
	{
		switch (m_vecEvent[i].eType)
		{
			// wParam : Object Address
			// lParam : Layer Type
		case EEVENT_TYPE::CREATE_OBJECT:
		{
			CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

			CObj* pNewObj = (CObj*)m_vecEvent[i].wParam;
			ELAYER Layer = (ELAYER)m_vecEvent[i].lParam;

			pCurLevel->AddObject(pNewObj, Layer);
		}
		break;
		case EEVENT_TYPE::DELETE_OBJECT:
		{
			// ���� ���� ������Ʈ�� Dead ���·� �ΰ� Garbage�� �־��ش�
			CObj* pObj = (CObj*)m_vecEvent[i].wParam;

			// ���� ���� Ȯ���� ���� Tick ���ÿ� ���� ������Ʈ�� ������ ��û ���� ��
			if (false == pObj->m_bDead)
			{
				m_vecGarbage.push_back(pObj);
				pObj->m_bDead = true;
			}
		}
		break;
		case EEVENT_TYPE::LEVEL_CHANGE:
			break;
		}
	}

	m_vecEvent.clear();
}