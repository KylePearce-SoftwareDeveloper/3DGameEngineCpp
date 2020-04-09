/*
 * This engine was built uppon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirly
 * created by Kyle Pearce.
 */

#ifndef MYGAME_H
#define MYGAME_H

#include "entity.h"
#include "coreEngine.h"
#include "profiling.h"
#include "../rendering/TextRenderer.h"

class Game
{
public:
	Game() {}
	virtual ~Game() {}

	virtual void Init(const Window& window) {}
	void ProcessInput(const Input& input, float delta);
	void Update(float delta);
	void Render(RenderingEngine* renderingEngine);
	
	inline double DisplayInputTime(double dividend) { return m_inputTimer.DisplayAndReset("Input Time: ", dividend); }
	inline double DisplayUpdateTime(double dividend) { return m_updateTimer.DisplayAndReset("Update Time: ", dividend); }
	
	inline void SetEngine(CoreEngine* engine) { m_root.SetEngine(engine); }

	virtual void CheckTerrainHeight() {}
	virtual void checkTreeHeight(Entity* treePos){}//6/2/20
	virtual void updateSunAngle() {}
	virtual void CheckTreeCollision() {}//6/3/20
	//virtual void renderText() {}//11/3/20
	virtual void ChangeText() {}//18/3/20
	virtual void CheckCollisionWithModel() {}//19/3/20
protected:
	void AddToScene(Entity* child) { m_root.AddChild(child); }
	void AddTextOnScreen(TextRenderer *textRendererObjectArg) { textRendererObject = textRendererObjectArg; }//15/3/20
private:
	Game(Game& game) {}
	void operator=(Game& game) {}
	
	ProfileTimer m_updateTimer;
	ProfileTimer m_inputTimer;
	Entity       m_root;
	TextRenderer* textRendererObject;//15/3/20
};

#endif
