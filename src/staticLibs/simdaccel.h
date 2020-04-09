/*
 * This engine was built uppon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirly
 * created by Kyle Pearce.
 */

#ifndef SIMDACCEL_H_INCLUDED
#define SIMDACCEL_H_INCLUDED

#include "simddefines.h"

#if defined(SIMD_CPU_ARCH_x86) || defined(SIMD_CPU_ARCH_x86_64)
	#include "x86simdaccel.h"
#else
	#include "simdemulator.h"
#endif

#endif // SIMDACCEL_H_INCLUDED
