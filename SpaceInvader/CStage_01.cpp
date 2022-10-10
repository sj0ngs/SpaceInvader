#include "pch.h"
#include "CStage_01.h"

#include "CCollisionMgr.h"

#include "CObj.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CRed.h"
#include "CYellow.h"
#include "CGreen.h"
#include "CExtra.h"
#include "CWall.h"
#include "CCover.h"

#include "CCollider.h"

CStage_01::CStage_01()
{
}

CStage_01::~CStage_01()
{
}

void CStage_01::Init()
{
	// 위쪽 벽
	CWall* pWall = new CWall;
	pWall->SetPos(Vec2(640.f, 5.f));
	pWall->GetCollider()->SetScale(Vec2(1280.f, 10.f));
	AddObject(pWall, ELAYER::WALL);

	// 왼쪽 벽
	pWall = new CWall;
	pWall->SetPos(Vec2(5.f, 365.f));
	pWall->GetCollider()->SetScale(Vec2(10.f, 710.f));
	AddObject(pWall, ELAYER::WALL);

	// 오른쪽 벽
	pWall = new CWall;
	pWall->SetPos(Vec2(1275.f, 365.f));
	pWall->GetCollider()->SetScale(Vec2(10.f, 710.f));
	AddObject(pWall, ELAYER::WALL);

	// 아래쪽 벽
	pWall = new CWall;
	pWall->SetPos(Vec2(640.f, 725.f));
	pWall->GetCollider()->SetScale(Vec2(1280.f, 10.f));
	AddObject(pWall, ELAYER::WALL);
	
	CPlayer* pPlayer = new CPlayer;
	pPlayer->SetPos(Vec2(640.f, 700.f));

	AddObject(pPlayer, ELAYER::PLAYER);

	CMonster* pMonster = nullptr;

	for (int i = 0; i < 10; i++)
	{
		pMonster = new CRed;
		pMonster->SetPos(Vec2(74.f + 126.f * i, 100.f));

		AddObject(pMonster, ELAYER::MONSTER);
	}

	for (int i = 0; i < 10; i++)
	{
		pMonster = new CGreen;
		pMonster->SetPos(Vec2(74.f + 126.f * i, 200.f));

		AddObject(pMonster, ELAYER::MONSTER);
	}

	for (int i = 0; i < 10; i++)
	{
		pMonster = new CYellow;
		pMonster->SetPos(Vec2(74.f + 126.f * i, 300.f));

		AddObject(pMonster, ELAYER::MONSTER);
	}

	pMonster = new CExtra;
	pMonster->SetPos(Vec2(-20.f, 30.f));

	AddObject(pMonster, ELAYER::MONSTER);
	
	CCover* pCover = nullptr;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				pCover = new CCover;
				pCover->SetPos(Vec2(256.f * k + 103.f + 10.f * j, 600.f + 10.f * i));

				AddObject(pCover, ELAYER::DESTROYABLE_OBJECT);
			}
		}
	}

	CCollisionMgr::GetInst()->LayerCheck(ELAYER::PLAYER, ELAYER::MONSTER);
	CCollisionMgr::GetInst()->LayerCheck(ELAYER::PLAYER, ELAYER::WALL);
	CCollisionMgr::GetInst()->LayerCheck(ELAYER::WALL, ELAYER::MONSTER);
	CCollisionMgr::GetInst()->LayerCheck(ELAYER::PLAYER_PROJECTILE, ELAYER::WALL);
	CCollisionMgr::GetInst()->LayerCheck(ELAYER::MONSTER_PROJECTILE, ELAYER::WALL);
	CCollisionMgr::GetInst()->LayerCheck(ELAYER::PLAYER, ELAYER::MONSTER_PROJECTILE);
	CCollisionMgr::GetInst()->LayerCheck(ELAYER::PLAYER_PROJECTILE, ELAYER::MONSTER);
	CCollisionMgr::GetInst()->LayerCheck(ELAYER::PLAYER_PROJECTILE, ELAYER::DESTROYABLE_OBJECT);
	CCollisionMgr::GetInst()->LayerCheck(ELAYER::DESTROYABLE_OBJECT, ELAYER::MONSTER_PROJECTILE);
	CCollisionMgr::GetInst()->LayerCheck(ELAYER::PLAYER_PROJECTILE, ELAYER::MONSTER_PROJECTILE);
}
