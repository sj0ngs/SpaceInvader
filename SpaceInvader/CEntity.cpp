#include "pch.h"
#include "CEntity.h"

UINT CEntity::g_iNextID = 0;

CEntity::CEntity()	:
	m_ID(g_iNextID++)
{
}

CEntity::CEntity(const CEntity& _Origin)	:
	m_strName(_Origin.m_strName),
	m_ID(g_iNextID++)
{
}

CEntity::~CEntity()
{
}
