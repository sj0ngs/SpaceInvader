#include "pch.h"
#include "CRed.h"

#include "CTimeMgr.h"
#include "CResMgr.h"

#include "CCollider.h"
#include "CRedMissile.h"

#include "CTexture.h"

CRed::CRed()
{
	GetCollider()->SetScale(Vec2(40.f, 32.f));
	SetTexture(CResMgr::GetInst()->LoadTexture(L"RedImage", L"texture\\red.bmp"));
}

CRed::~CRed()
{
}

void CRed::Tick()
{
	float m_fCool = GetCool();


	if (1.f <= m_fCool)
	{
		int iRand = rand() % 100;
		if (iRand < 10)
		{
			for (int i = 0; i < 3; i++)
			{
				CRedMissile* pMissile = new CRedMissile;
				Vec2 vPos = GetPos();
				vPos.y += 10.f;
				pMissile->SetScale(Vec2{ 10.f, 10.f });
				pMissile->SetSpeed(400.f);
				pMissile->SetDir(180.f + 75.f + 15 * i);
				pMissile->GetCollider()->SetScale(Vec2(10.f, 10.f));
				pMissile->SetLayer(ELAYER::MONSTER_PROJECTILE);

				Instantiate(pMissile, vPos, ELAYER::MONSTER_PROJECTILE);
			}
		}
		SetCool(0.f);
	}

	CMonster::Tick();
}

void CRed::Render(HDC _hDC)
{
	CMonster::Render(_hDC);
}
