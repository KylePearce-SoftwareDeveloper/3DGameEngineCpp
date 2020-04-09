/*
 * This engine was built upon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirely
 * created by Kyle Pearce.
 */

#include "game.h"

#include "../rendering/renderingEngine.h"

#include <iostream>

void Game::ProcessInput(const Input& input, float delta)
{
	m_inputTimer.StartInvocation();
	m_root.ProcessInputAll(input, delta);
	m_inputTimer.StopInvocation();
}

void Game::Update(float delta)
{
	m_updateTimer.StartInvocation();
	m_root.UpdateAll(delta);//6/2/20 test
	m_updateTimer.StopInvocation();
}

void Game::Render(RenderingEngine* renderingEngine)
{
	renderingEngine->Render(m_root, textRendererObject);//15/3/20
}
