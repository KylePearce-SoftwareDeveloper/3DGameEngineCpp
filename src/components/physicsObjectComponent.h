/*
 * This engine was built uppon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirly
 * created by Kyle Pearce.
 */
#ifndef PHYSICS_OBJECT_COMPONENT_INCLUDED_H
#define PHYSICS_OBJECT_COMPONENT_INCLUDED_H

#include "../core/entityComponent.h"
#include "../physics/physicsEngine.h"

/** This class is temporary! */
class PhysicsObjectComponent : public EntityComponent
{
public:
	PhysicsObjectComponent(const PhysicsObject* object) :
		m_physicsObject(object) {}

	virtual void Update(float delta);
private:
	const PhysicsObject* m_physicsObject;
};


#endif
