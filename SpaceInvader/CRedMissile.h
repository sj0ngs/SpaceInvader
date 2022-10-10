#pragma once
#include "CMissile.h"
class CRedMissile :
    public CMissile
{
public:
    CRedMissile();
    ~CRedMissile();

public:
    virtual void Render(HDC _DC)   override;
};

