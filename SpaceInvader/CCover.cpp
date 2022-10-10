#include "pch.h"
#include "CCover.h"

#include "CEngine.h"

#include "CCollider.h"

CCover::CCover()
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(10.f, 10.f));
	GetCollider()->SetOffset(Vec2(0.f, 0.f));
	SetScale(Vec2(10.f, 10.f));
}

CCover::~CCover()
{
}

void CCover::Render(HDC _hDC)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	HPEN PrevPen = (HPEN)SelectObject(_hDC, CEngine::GetInst()->GetPen(EPEN_TYPE::HOLLOW));
	HBRUSH PrevBrush = (HBRUSH)SelectObject(_hDC, CEngine::GetInst()->GetBrush(EBRUSH_TYPE::YELLOW));

	Rectangle(_hDC, (int)(vPos.x - vScale.x / 2), (int)(vPos.y - vScale.y / 2),
		(int)(vPos.x + vScale.x / 2), (int)(vPos.y + vScale.y / 2));

	SelectObject(_hDC, PrevPen);
	SelectObject(_hDC, PrevBrush);

	CObj::Render(_hDC);
}

void CCover::BeginOverlap(CCollider* _pOther)
{
	if (ELAYER::MONSTER_PROJECTILE == _pOther->GetOwner()->GetLayer() ||
		ELAYER::PLAYER_PROJECTILE == _pOther->GetOwner()->GetLayer())
		SetDead();
}
