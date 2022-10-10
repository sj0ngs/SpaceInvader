#include "pch.h"
#include "CExtra.h"

#include "CResMgr.h"
#include "CTimeMgr.h"

#include "CCollider.h"
#include "CMissile.h"
#include "CEffect.h"

CExtra::CExtra()	:
	m_fStopTime(0.f)
{
	SetHP(2);
	SetTexture(CResMgr::GetInst()->LoadTexture(L"ExtraImage", L"texture\\extra.bmp"));

	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 20.f));

	SetDir(Vec2(-1.f, 0));
	SetSpeed(500.f);
}

CExtra::~CExtra()
{
}

void CExtra::Tick()
{
	Vec2 vPos = GetPos();

	if (-20.f >= GetPos().x || 1300.f <= GetPos().x)
	{
		SetSpeed(0.f);

		if (5.f <= m_fStopTime)
		{
			SetDir(GetDir() * -1.f);
			SetSpeed(300.f);
			vPos.x += GetDir().x * 5;
			m_fStopTime = 0;
		}

		int a = 0;

		m_fStopTime += DELTA_TIME;
	}
	else
	{
		if (0.5f <= GetCool())
		{
			int iRand = rand() % 100;

			if (iRand < 30)
			{
				for (int i = 0; i < 5; i++)
				{
					CMissile* pMissile = new CMissile;
					Vec2 vPos = GetPos();
					vPos.y += 10.f;
					pMissile->SetScale(Vec2{ 20.f, 20.f });
					pMissile->SetSpeed(400.f);
					pMissile->SetDir(250.f + 10 * i);
					pMissile->GetCollider()->SetScale(Vec2(20.f, 20.f));
					pMissile->SetLayer(ELAYER::MONSTER_PROJECTILE);

					Instantiate(pMissile, vPos, ELAYER::MONSTER_PROJECTILE);
				}
			}
			SetCool(0.f);
		}
	}

	vPos.x += GetSpeed() * GetDir().x * DELTA_TIME;

	SetPos(vPos);

	CMonster::Tick();
}

void CExtra::BeginOverlap(CCollider* _pOther)
{
	if (ELAYER::PLAYER_PROJECTILE == _pOther->GetOwner()->GetLayer())
	{
		SetHP(GetHP() - 1);
		CEffect* pEffect = new CEffect;
		Instantiate(pEffect, GetPos(), pEffect->GetLayer());
	}
}

void CExtra::OnOverlap(CCollider* _pOther)
{
}

void CExtra::EndOverlap(CCollider* _pOther)
{
}
