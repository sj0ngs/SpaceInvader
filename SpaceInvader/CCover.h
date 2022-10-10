#pragma once
#include "CObj.h"

class CCover :
    public CObj
{
public:
    CCover();
    ~CCover();

public:
    virtual void Render(HDC _hDC) override;

public:
    virtual void BeginOverlap(CCollider* _pOther);
};

