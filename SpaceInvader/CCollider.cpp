#include "pch.h"
#include "CCollider.h"

#include "CEngine.h"

#include "CObj.h"

CCollider::CCollider(CObj* _pOwner)	:
	CComponent(_pOwner),
	m_vOffsetPos{},
	m_vFinalPos{},
	m_iOverlapCount(0)
{
}

CCollider::~CCollider()
{
}

void CCollider::Tick()
{
	m_vFinalPos = GetOwner()->GetPos() - m_vOffsetPos;

	if (0 > m_iOverlapCount)
		assert(false);
}

void CCollider::Render(HDC _DC)
{
	Vec2 vPos = GetFinalPos();
	Vec2 vScale = GetScale();

	HPEN hPen = nullptr;

	if(0 < m_iOverlapCount)
		hPen = CEngine::GetInst()->GetPen(EPEN_TYPE::RED);
	else
		hPen = CEngine::GetInst()->GetPen(EPEN_TYPE::GREEN);

	HPEN hPrevPen = (HPEN)SelectObject(_DC, hPen);

	HBRUSH hHollow = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	HBRUSH hPrevBrush = (HBRUSH)SelectObject(_DC, hHollow);

	Rectangle(_DC, (int)(vPos.x - vScale.x / 2),
		(int)(vPos.y - vScale.y / 2),
		(int)(vPos.x + vScale.x / 2),
		(int)(vPos.y + vScale.y / 2));

	SelectObject(_DC, hPrevPen);
	SelectObject(_DC, hPrevBrush);
}

void CCollider::BeginOverlap(CCollider* _pOther)
{
	++m_iOverlapCount;

	GetOwner()->BeginOverlap(_pOther);
}

void CCollider::OnOverlap(CCollider* _pOther)
{
	GetOwner()->OnOverlap(_pOther);
}

void CCollider::EndOverlap(CCollider* _pOther)
{
	--m_iOverlapCount;

	GetOwner()->EndOverlap(_pOther);
}
