#include "pch.h"
#include "CPlayer.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CResMgr.h"

#include "CCollider.h"
#include "CPlayerMissile.h"
#include "CEffect.h"

#include "CTexture.h"

CPlayer::CPlayer()	:
	m_fSpeed(200.f),
	m_fMissileCool(1.f),
	m_bLeftBlock(false),
	m_bRightBlock(false),
	m_iHP(3)
{
	SetLayer(ELAYER::PLAYER);

	CreateCollider();
	GetCollider()->SetOffset(Vec2(0.f, -4.f));
	GetCollider()->SetScale(Vec2(60.f, 25.f));

	SetTexture(CResMgr::GetInst()->LoadTexture(L"PlayerImage", L"texture\\player.bmp"));
}

CPlayer::~CPlayer()
{
}

void CPlayer::Tick()
{
	Vec2 vPos = GetPos();

	if (m_iHP <= 0)
		SetDead();

	if (false == m_bLeftBlock)
	{
		if (IS_PRESSED(EKEY::LEFT))
		{
			vPos.x -= m_fSpeed * DELTA_TIME;
		}
	}

	if (false == m_bRightBlock)
	{
		if (IS_PRESSED(EKEY::RIGHT))
		{
			vPos.x += m_fSpeed * DELTA_TIME;
		}
	}

	if (IS_PRESSED(EKEY::SPACE) || IS_TAP(EKEY::SPACE))
	{
		if (0.5f <= m_fMissileCool)
		{
			CPlayerMissile* pMissile = new CPlayerMissile;
			Vec2 vPos = GetPos();
			vPos.y -= 10.f;
			pMissile->SetScale(Vec2{ 10.f, 30.f });
			pMissile->SetSpeed(400.f);
			pMissile->SetDir(90.f);
			pMissile->GetCollider()->SetScale(Vec2(10.f, 30.f));
			pMissile->SetLayer(ELAYER::PLAYER_PROJECTILE);

			Instantiate(pMissile, vPos, ELAYER::PLAYER_PROJECTILE);

			m_fMissileCool = 0.f;
		}
	}

	m_fMissileCool += DELTA_TIME;

	SetPos(vPos);

	CObj::Tick();
}

void CPlayer::Render(HDC _hDC)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	//HBRUSH hPrevBrush = (HBRUSH)SelectObject(_hDC, GetStockObject(WHITE_BRUSH));

	//Rectangle(_hDC, (int)(vPos.x - vScale.x / 2),
	//				(int)(vPos.y - vScale.y / 2),
	//				(int)(vPos.x + vScale.x / 2),
	//				(int)(vPos.y + vScale.y / 2));

	Vec2 vLeftTop = Vec2(vPos.x - GetTexture()->GetWidth() / 2.f,
		vPos.y - GetTexture()->GetHeight() / 2.f);

	//BitBlt(_hDC, (int)vLeftTop.x, (int)vLeftTop.y,
	//	(int)m_pTexture->GetWidth(), (int)m_pTexture->GetHeight(),
	//	m_pTexture->GetDC(), 0, 0, SRCCOPY);

	TransparentBlt(_hDC, (int)vLeftTop.x, (int)vLeftTop.y,
		(int)GetTexture()->GetWidth(), (int)GetTexture()->GetHeight(),
		GetTexture()->GetDC(), 0, 0,
		(int)GetTexture()->GetWidth(), (int)GetTexture()->GetHeight(),
		RGB(255, 255, 255));

	CObj::Render(_hDC);

	//SelectObject(_hDC, hPrevBrush);
}

void CPlayer::BeginOverlap(CCollider* _pOther)
{
	if (ELAYER::WALL == _pOther->GetOwner()->GetLayer())
	{
		Vec2 vPos = _pOther->GetOwner()->GetPos();

		if (vPos.x > GetPos().x)
			m_bRightBlock = true;

		if (vPos.x < GetPos().x)
			m_bLeftBlock = true;
	}
	if (ELAYER::MONSTER_PROJECTILE == _pOther->GetOwner()->GetLayer() || 
		ELAYER::MONSTER == _pOther->GetOwner()->GetLayer())
	{
		--m_iHP;
		CEffect* pEffect = new CEffect;
		Instantiate(pEffect, GetPos(), pEffect->GetLayer());
	}
}

void CPlayer::OnOverlap(CCollider* _pOther)
{
}

void CPlayer::EndOverlap(CCollider* _pOther)
{
	if (ELAYER::WALL == _pOther->GetOwner()->GetLayer())
	{
		if (true == m_bRightBlock)
			m_bRightBlock = false;

		if (true == m_bLeftBlock)
			m_bLeftBlock = false;
	}
}
