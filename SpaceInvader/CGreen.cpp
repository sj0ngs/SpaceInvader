#include "pch.h"
#include "CGreen.h"

#include "CTimeMgr.h"
#include "CResMgr.h"

#include "CCollider.h"
#include "CMissile.h"

#include "CTexture.h"

CGreen::CGreen()
{
	GetCollider()->SetScale(Vec2(40.f, 32.f));
	SetTexture(CResMgr::GetInst()->LoadTexture(L"GreenImage", L"texture\\green.bmp"));
}

CGreen::~CGreen()
{
}

void CGreen::Tick()
{
	float m_fCool = GetCool();


	if (1.f <= m_fCool)
	{
		int iRand = rand() % 100;
		if (iRand < 50)
		{
			CMissile* pMissile = new CMissile;
			Vec2 vPos = GetPos();
			vPos.y += 10.f;
			pMissile->SetScale(Vec2{ 10.f, 10.f });
			pMissile->SetSpeed(400.f);
			pMissile->SetDir(270.f);
			pMissile->GetCollider()->SetScale(Vec2(10.f, 10.f));
			pMissile->SetLayer(ELAYER::MONSTER_PROJECTILE);

			Instantiate(pMissile, vPos, ELAYER::MONSTER_PROJECTILE);
		}
		SetCool(0.f);
	}

	CMonster::Tick();
}

void CGreen::Render(HDC _hDC)
{
	CMonster::Render(_hDC);
}
