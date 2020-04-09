/*
 * This engine was built uppon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirly
 * created by Kyle Pearce.
 */
#ifndef PHYSICS_ENGINE_COMPONENT_INCLUDED_H
#define PHYSICS_ENGINE_COMPONENT_INCLUDED_H

#include "../core/entityComponent.h"
#include "../physics/physicsEngine.h"

/** This class is temporary! */
class PhysicsEngineComponent : public EntityComponent
{
public:
	PhysicsEngineComponent(const PhysicsEngine& engine) :
		m_physicsEngine(engine) {}

	virtual void Update(float delta);

	inline const PhysicsEngine& GetPhysicsEngine() { return m_physicsEngine; }
private:
	PhysicsEngine m_physicsEngine;
};


#endif
