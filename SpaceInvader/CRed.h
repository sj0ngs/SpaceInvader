#pragma once
#include "CMonster.h"
class CRed :
    public CMonster
{
public:
    CRed();
    ~CRed();

public:
    virtual void Tick() override;
    virtual void Render(HDC _DC)   override;
};

