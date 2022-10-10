#include "pch.h"
#include "CCollisionMgr.h"

#include "CLevelMgr.h"

#include "CLevel.h"
#include "CObj.h"
#include "CCollider.h"

CCollisionMgr::CCollisionMgr()	:
	m_Matrix{}
{
}

CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::Tick()
{
	for (UINT iRow = 0; iRow < (UINT)ELAYER::END; iRow++)
	{
		for (UINT iCol = iRow; iCol < (UINT)ELAYER::END; iCol++)
		{
			if (!(m_Matrix[iRow] & (1 << iCol)))
				continue;

			CollisionBtwLayer((ELAYER)iRow, (ELAYER)iCol);
		}
	}
}

void CCollisionMgr::LayerCheck(ELAYER _Left, ELAYER _Right)
{
	UINT iRow = (UINT)_Left;
	UINT iCol = (UINT)_Right;

	if (iRow > iCol)
	{
		int temp = iRow;
		iRow = iCol;
		iCol = temp;
	}

	m_Matrix[iRow] |= (1 << iCol);
}

void CCollisionMgr::Clear()
{
	for (int i = 0; i < (UINT)ELAYER::END; i++)
	{
		m_Matrix[i] = 0;
	}
}

void CCollisionMgr::CollisionBtwLayer(ELAYER _Left, ELAYER _Right)
{
	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

	const vector<CObj*>& vecLeft = pCurLevel->GetLayer(_Left);
	const vector<CObj*>& vecRight = pCurLevel->GetLayer(_Right);

	for (size_t i = 0; i < vecLeft.size(); i++)
	{
		if (nullptr == vecLeft[i]->GetCollider())
			continue;

		size_t j = 0;
		if (_Left == _Right)
			j = i;

		for (; j < vecRight.size(); ++j)
		{
			if (nullptr == vecRight[j]->GetCollider() || vecLeft[i] == vecRight[j])
				continue;

			CollisionID ID = {};
			ID.LeftID = vecLeft[i]->GetCollider()->GetID();
			ID.RightID = vecRight[j]->GetCollider()->GetID();

			map<UINT_PTR, bool>::iterator iter = m_mapPrevInfo.find(ID.ID);

			if (iter == m_mapPrevInfo.end())
			{
				m_mapPrevInfo.insert(make_pair(ID.ID, false));
				iter = m_mapPrevInfo.find(ID.ID);
			}

			bool bDead = vecLeft[i]->IsDead() || vecRight[j]->IsDead();

			// ���� �����ִ�
			if (CollisionBtwCollider(vecLeft[i]->GetCollider(), vecRight[j]->GetCollider()))
			{
				// �������� �����־���
				if (iter->second)
				{
					// ���� �ϳ��� dead �� ���
					if (bDead)
					{
						vecLeft[i]->GetCollider()->EndOverlap(vecRight[j]->GetCollider());
						vecRight[j]->GetCollider()->EndOverlap(vecLeft[i]->GetCollider());
					}
					else
					{
						vecLeft[i]->GetCollider()->OnOverlap(vecRight[j]->GetCollider());
						vecRight[j]->GetCollider()->OnOverlap(vecLeft[i]->GetCollider());
					}
				}
				// �̹��� ��������
				else
				{
					// ���� �ϳ��� Dead ���¶�� �浹�� ������ �ɷ� �Ѵ�
					if (!bDead)
					{
						vecLeft[i]->GetCollider()->BeginOverlap(vecRight[j]->GetCollider());
						vecRight[j]->GetCollider()->BeginOverlap(vecLeft[i]->GetCollider());
						iter->second = true;
					}
				}
			}
			// ���� �������ִ�
			else
			{
				// ���� �� ��������
				if (iter->second)
				{
					vecLeft[i]->GetCollider()->EndOverlap(vecRight[j]->GetCollider());
					vecRight[j]->GetCollider()->EndOverlap(vecLeft[i]->GetCollider());
					iter->second = false;
				}
			}
		}
	}
}

bool CCollisionMgr::CollisionBtwCollider(CCollider* _pLeft, CCollider* _pRight)
{
	Vec2 vLeftPos = _pLeft->GetFinalPos();
	Vec2 vLeftScale = _pLeft->GetScale();
	Vec2 vRightPos = _pRight->GetFinalPos();
	Vec2 vRightScale = _pRight->GetScale();

	if (fabsf(vLeftPos.x - vRightPos.x) > fabsf((vLeftScale.x + vRightScale.x) / 2))
		return false;

	if (fabsf(vLeftPos.y - vRightPos.y) > fabsf((vLeftScale.y + vRightScale.y) / 2))
		return false;

	return true;
}