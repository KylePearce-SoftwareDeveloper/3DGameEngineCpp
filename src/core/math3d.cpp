/*
 * This engine was built upon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirely
 * created by Kyle Pearce.
 */

#include "math3d.h"

Vector3f Vector3f::Rotate(const Quaternion& rotation) const
{
	Quaternion conjugateQ = rotation.Conjugate();
	Quaternion w = rotation * (*this) * conjugateQ;

	Vector3f ret(w.GetX(), w.GetY(), w.GetZ());

	return ret;
}
