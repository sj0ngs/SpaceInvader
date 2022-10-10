#pragma once
#include "CObj.h"

class CTexture;

class CMonster :
    public CObj
{
private:
    float m_fSpeed;
    int m_iHP;
    float m_fCool;

    Vec2 m_vDir;
    int m_iDirChange;
    Vec2 m_vPrev;

public:
    void SetSpeed(float _fSpeed) { m_fSpeed = _fSpeed; }
    float GetSpeed() { return m_fSpeed; }
    void SetHP(UINT _iHP) { m_iHP = _iHP; } 
    int GetHP() { return m_iHP; }
    void SetDir(Vec2 _Dir) { m_vDir = _Dir; }
    Vec2 GetDir() { return m_vDir; }
    void SetCool(float _fCool) { m_fCool = _fCool; }
    float GetCool() { return m_fCool; }

public:
    CMonster();
    ~CMonster();

public:
    virtual void Tick() override;
    virtual void Render(HDC _hDC)   override;

public:
    virtual void BeginOverlap(CCollider* _pOther);
    virtual void OnOverlap(CCollider* _pOther);
    virtual void EndOverlap(CCollider* _pOther);
};

