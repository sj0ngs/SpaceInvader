#include "pch.h"
#include "CLevel.h"

#include "CObj.h"

CLevel::CLevel()
{
}

CLevel::~CLevel()
{
	for (size_t i = 0; i < (UINT)ELAYER::END; i++)
	{
		for (size_t j = 0; j < m_arrLayer[i].size(); j++)
		{
			SAFE_DELETE(m_arrLayer[i][j]);
		}
	}
}

void CLevel::Tick()
{
	for (size_t i = 0; i < (UINT)ELAYER::END; i++)
	{
		for (size_t j = 0; j < m_arrLayer[i].size(); j++)
		{
			m_arrLayer[i][j]->Tick();
		}
	}
}

void CLevel::Render(HDC _hDC)
{
	for (size_t i = 0; i < (UINT)ELAYER::END; i++)
	{
		vector<CObj*>::iterator iter = m_arrLayer[i].begin();

		for (; iter != m_arrLayer[i].end(); )
		{
			if ((*iter)->IsDead())
				iter = m_arrLayer[i].erase(iter);
			else
			{
				(*iter)->Render(_hDC);
				++iter;
			}
		}
	}
}
