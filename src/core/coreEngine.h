/*
 * This engine was built uppon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirly
 * created by Kyle Pearce.
 */

#ifndef COREENGINE_H
#define COREENGINE_H

#include "../rendering/renderingEngine.h"
#include <string>
class Game;

//This is the central part of the game engine. It's purpose is to manage interaction 
//between the various sub-engines (such as the rendering and physics engines) and the game itself.
class CoreEngine
{
public:
	CoreEngine(double frameRate, Window* window, RenderingEngine* renderingEngine, Game* game);
	
	void Start(); //Starts running the game; contains central game loop.
	void Stop();  //Stops running the game, and disables all subsystems.
	
	inline RenderingEngine* GetRenderingEngine() { return m_renderingEngine; }
	virtual Game* GetGame() { return m_game; }//2/2/20 test
	virtual Window* GetWindow() { return m_window; };//19/3/20
protected:
private:
	bool             m_isRunning;       //Whether or not the engine is running
	double           m_frameTime;       //How long, in seconds, one frame should take
	Window*          m_window;          //Used to display the game
	RenderingEngine* m_renderingEngine; //Used to render the game. Stored as pointer so the user can pass in a derived class.
	Game*            m_game;            //The game itself. Stored as pointer so the user can pass in a derived class.
};

#endif // COREENGINE_H
