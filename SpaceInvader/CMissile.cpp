#include "pch.h"
#include "CMissile.h"

#include "CTimeMgr.h"

#include "CCollider.h"

CMissile::CMissile() :
	m_fSpeed(200.f),
	m_fDegree(90.f),
	m_fTime(0.f)
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(10.f, 10.f));
}

CMissile::~CMissile()
{
}

void CMissile::Tick()
{
	Vec2 vPos = GetPos();

	// 60 분법 -> 라디안
	float fRadian = (m_fDegree * PI) / 180.f;

	vPos.x += m_fSpeed * cosf(fRadian) * DELTA_TIME;
	vPos.y -= m_fSpeed * sinf(fRadian) * DELTA_TIME;

	SetPos(vPos);

	CObj::Tick();
}

void CMissile::Render(HDC _hDC)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	HBRUSH hPrevBrush = (HBRUSH)SelectObject(_hDC, GetStockObject(WHITE_BRUSH));

	Ellipse(_hDC, (int)(vPos.x - vScale.x / 2),
		(int)(vPos.y - vScale.y / 2),
		(int)(vPos.x + vScale.x / 2),
		(int)(vPos.y + vScale.y / 2));

	SelectObject(_hDC, hPrevBrush);

	CObj::Render(_hDC);
}

void CMissile::BeginOverlap(CCollider* _pOther)
{
	SetDead();
}