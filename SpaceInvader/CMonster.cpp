#include "pch.h"
#include "CMonster.h"

#include "CTimeMgr.h"

#include "CCollider.h"

#include "CTexture.h"
#include "CEffect.h"

CMonster::CMonster() :
	m_fSpeed(100.f),
	m_iHP(1),
	m_vDir{1.f, 0.f},
	m_iDirChange(-1),
	m_vPrev{},
	m_fCool(3.f)
{
	SetLayer(ELAYER::MONSTER);

	CreateCollider();
	GetCollider()->SetOffset(Vec2(0.f, 0.f));
	GetCollider()->SetScale(Vec2(80.f, 80.f));
}

CMonster::~CMonster()
{
}

void CMonster::Tick()
{
	if (0 >= m_iHP || GetPos().y >= 760)
	{
		SetDead();
	}

	Vec2 vPos = GetPos();

	vPos += m_vDir * m_fSpeed * DELTA_TIME;

	SetPos(vPos);

	m_fCool += DELTA_TIME;

	CObj::Tick();
}

void CMonster::Render(HDC _hDC)
{
	Vec2 vPos = GetPos();

	Vec2 vLeftTop = Vec2(vPos.x - GetTexture()->GetWidth() / 2.f,
		vPos.y - GetTexture()->GetHeight() / 2.f);

	TransparentBlt(_hDC, (int)vLeftTop.x, (int)vLeftTop.y,
		(int)GetTexture()->GetWidth(), (int)GetTexture()->GetHeight(),
		GetTexture()->GetDC(), 0, 0,
		(int)GetTexture()->GetWidth(), (int)GetTexture()->GetHeight(),
		RGB(255, 255, 255));

	CObj::Render(_hDC);
}

void CMonster::BeginOverlap(CCollider* _pOther)
{
	if (ELAYER::PLAYER_PROJECTILE == _pOther->GetOwner()->GetLayer())
	{
		--m_iHP;
		CEffect* pEffect = new CEffect;
		Instantiate(pEffect, GetPos(), pEffect->GetLayer());
	}

	if (ELAYER::WALL == _pOther->GetOwner()->GetLayer())
	{
		SetDir(Vec2(0.f, 1.f));
		m_vPrev = GetPos();
	}
}

void CMonster::OnOverlap(CCollider* _pOther)
{
	if (ELAYER::WALL == _pOther->GetOwner()->GetLayer())
	{
		float m_fDist = GetPos().y - m_vPrev.y;

		if (50.f <= m_fDist)
			SetDir(Vec2((float)m_iDirChange, 0.f));
	}
}

void CMonster::EndOverlap(CCollider* _pOther)
{
	if (ELAYER::WALL == _pOther->GetOwner()->GetLayer())
	{
		m_iDirChange *= -1;
		m_fSpeed += 100.f;
	}
}
