// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <CryMath/Cry_Geo.h>

struct IMeshObj;
struct IPhysicalEntity;
struct IGeometry;
struct IArea;

//////////////////////////////////////////////////////////////////////////
//! Reference to one visual or physical geometry, for particle attachment.

struct GeomRef
{
	_smart_ptr<IMeshObj>        m_pMeshObj;      //!< Render object attachment.
	_smart_ptr<IPhysicalEntity> m_pPhysEnt;      //!< Physics object attachment.
	IArea*                      m_pArea     = 0; //!< Area attachment.

	void Set(IMeshObj* pMesh)
	{
		m_pMeshObj = pMesh;
	}
	void Set(IPhysicalEntity* pPhys)
	{
		m_pPhysEnt = pPhys;
	}
	void Set(IArea* pArea)
	{
		m_pArea = pArea;
	}
	int  Set(IEntity* pEntity, int iSlot = -1);

	operator bool() const
	{
		return m_pMeshObj || m_pPhysEnt || m_pArea;
	}
	bool operator==(const GeomRef& other) const
	{
		return m_pMeshObj == other.m_pMeshObj && m_pPhysEnt == other.m_pPhysEnt && m_pArea == other.m_pArea;
	}
	bool operator!=(const GeomRef& other) const
	{
		return !operator==(other);
	}

	IMeshObj* GetMesh() const
	{
		return m_pMeshObj;
	}
	IArea* GetArea() const
	{
		return m_pArea;
	}
	IPhysicalEntity* GetPhysicalEntity() const;
	IGeometry*       GetGeometry() const;

	void             GetAABB(AABB& bb, EGeomType eAttachType, QuatTS const& tLoc, bool bCentered = false) const;
	float            GetExtent(EGeomType eAttachType, EGeomForm eForm) const;
	void             GetRandomPos(PosNorm& ran, CRndGen seed, EGeomType eAttachType, EGeomForm eForm, QuatTS const& tWorld, bool bCentered = false) const;
};
