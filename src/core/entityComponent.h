/*
 * This engine was built uppon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirly
 * created by Kyle Pearce.
 */

#ifndef ENTITYCOMPONENT_H_INCLUDED
#define ENTITYCOMPONENT_H_INCLUDED

#include "transform.h"
#include "entity.h"
#include "input.h"
class RenderingEngine;
class Shader;

class EntityComponent
{
public:
	EntityComponent() :
		m_parent(0) {}
	virtual ~EntityComponent() {}

	virtual void ProcessInput(const Input& input, float delta) {}
	virtual void Update(float delta) {}
	virtual void Render(const Shader& shader, const RenderingEngine& renderingEngine, const Camera& camera) const {}

	//virtual void RenderTextRenderer(const Shader& shader, const RenderingEngine& renderingEngine, const Camera& camera) {}//12/3/20
	
	virtual void AddToEngine(CoreEngine* engine) const { }
	
	inline Transform* GetTransform()             { return m_parent->GetTransform(); }
	inline const Transform& GetTransform() const { return *m_parent->GetTransform(); }
	
	virtual void SetParent(Entity* parent) { m_parent = parent; }
	virtual Entity* GetParent() { return m_parent; }//2/2/20 test

	//inline void SetDynamicRender(bool isDynamicRender) { dynamicRender = isDynamicRender; }//28/2/20
	//inline bool GetDynamicRender() { return dynamicRender; }//28/2/20
	//inline void SetHasBeenRendered(bool isHasBeenRendered) { hasBeenRendered = isHasBeenRendered; }//28/2/20
	//inline bool GetHasBeenRendered() { return hasBeenRendered; }//28/2/20
	//inline void SetIsTextRenderer(bool isTextRendererArg) { isTextRenderer = isTextRendererArg; }//12/3/20
	//inline bool GetIsTextRenderer() { return isTextRenderer; }//12/3/20
private:
	Entity* m_parent;
	
	EntityComponent(const EntityComponent& other) {}
	void operator=(const EntityComponent& other) {}

	//bool dynamicRender = true;//28/2/20
	//bool hasBeenRendered = false;//28/2/20
	//bool isTextRenderer = false;//12/3/20
};

#endif // GAMECOMPONENT_H_INCLUDED
