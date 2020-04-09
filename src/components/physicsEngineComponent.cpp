/*
 * This engine was built upon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirely
 * created by Kyle Pearce.
 */
#include "physicsEngineComponent.h"

void PhysicsEngineComponent::Update(float delta)
{
	m_physicsEngine.Simulate(delta);
	m_physicsEngine.HandleCollisions();
}
