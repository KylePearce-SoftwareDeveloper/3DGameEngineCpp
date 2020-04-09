/*
 * This engine was built uppon 
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which 
 * this engine was developed further by Kyle Pearce. 
 * The game created using this engine has been entirly
 * created by Kyle Pearce.
 */

#ifndef __3DENGINE_H_INCLUDED
#define __3DENGINE_H_INCLUDED

//This header is just a convinient way to include all necessary files to use the engine.

#include "rendering/mesh.h"
#include "rendering/shader.h"
#include "core/transform.h"
#include "rendering/camera.h"
#include "rendering/lighting.h"
#include "core/entity.h"
#include "components/meshRenderer.h"
#include "rendering/window.h"
#include "core/coreEngine.h"
#include "core/game.h"

//SDL2 defines a main macro, which can prevent certain compilers from finding the main function.
#undef main

#endif // 3DENGINE_H_INCLUDED
