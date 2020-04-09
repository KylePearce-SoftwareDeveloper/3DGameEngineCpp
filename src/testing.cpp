/*
 * This engine was built upon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirely
 * created by Kyle Pearce.
 */

#include "testing.h"

#include "physics/boundingSphere.h"
#include "physics/aabb.h"
#include "physics/plane.h"
#include "physics/physicsObject.h"

#include <iostream>
#include <cassert>

void Testing::RunAllTests()
{
	BoundingSphere::Test();
	AABB::Test();
	Plane::Test();
	PhysicsObject::Test();
}


