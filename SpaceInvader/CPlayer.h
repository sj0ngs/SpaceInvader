#pragma once
#include "CObj.h"

class CTexture;

class CPlayer :
    public CObj
{
private:
    float m_fSpeed;
    float m_fMissileCool;

    bool m_bLeftBlock;
    bool m_bRightBlock;

    int m_iHP;

public:
    CPlayer();
    ~CPlayer();

public:
    virtual void Tick() override;
    virtual void Render(HDC _hDC)   override;

public:
    virtual void BeginOverlap(CCollider* _pOther);
    virtual void OnOverlap(CCollider* _pOther);
    virtual void EndOverlap(CCollider* _pOther);
};

