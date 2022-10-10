#pragma once
#include "CMonster.h"
class CGreen :
    public CMonster
{
public:
    CGreen();
    ~CGreen();

public:
    virtual void Tick() override;
    virtual void Render(HDC _DC)   override;
};

