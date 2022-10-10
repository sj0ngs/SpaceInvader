#pragma once
#include "CEntity.h"

class CObj;
class CComponent :
    public CEntity
{
private:
    CObj* const m_pOwner;

public:
    CObj* GetOwner() { return m_pOwner; }

public:
    CComponent(CObj* _pOwner);
    ~CComponent();
    
public:
    virtual void Tick() = 0;
    virtual void Render(HDC _DC) = 0;
};

