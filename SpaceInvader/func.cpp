#include "pch.h"
#include "func.h"

#include "CObj.h"

bool IsValid(CObj*& _pTarget)
{
	if (nullptr == _pTarget)
		return false;

	else if (_pTarget->IsDead())
	{
		_pTarget = nullptr;
		return false;
	}

	return true;
}
