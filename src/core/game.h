/*
 * Copyright (C) 2014 Benny Bobaganoosh
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
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
