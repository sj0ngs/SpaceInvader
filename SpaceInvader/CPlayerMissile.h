#pragma once
#include "CMissile.h"

class CPlayerMissile :
    public CMissile
{
public:
    CPlayerMissile();
    ~CPlayerMissile();

public:
    virtual void Render(HDC _DC)   override;
};

