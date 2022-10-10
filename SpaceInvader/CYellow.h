#pragma once
#include "CMonster.h"
class CYellow :
    public CMonster
{
public:
    CYellow();
    ~CYellow();

public:
    virtual void Tick() override;
    virtual void Render(HDC _DC)   override;
};

