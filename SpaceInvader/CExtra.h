#pragma once
#include "CMonster.h"
class CExtra :
    public CMonster
{
private:
    float m_fStopTime;

public:
    CExtra();
    ~CExtra();

public:
    virtual void Tick() override;

public:
    virtual void BeginOverlap(CCollider* _pOther);
    virtual void OnOverlap(CCollider* _pOther);
    virtual void EndOverlap(CCollider* _pOther);
};

