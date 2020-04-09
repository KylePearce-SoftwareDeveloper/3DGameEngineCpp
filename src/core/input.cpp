/*
 * This engine was built upon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirely
 * created by Kyle Pearce.
 */

#include "input.h"

#include "../rendering/window.h"

#include <SDL2/SDL.h>
#include <cstring>

Input::Input(Window* window) :
	m_mouseX(0),
	m_mouseY(0),
	m_window(window)
{
	memset(m_inputs, 0, NUM_KEYS * sizeof(bool));
	memset(m_downKeys, 0, NUM_KEYS * sizeof(bool));
	memset(m_upKeys, 0, NUM_KEYS * sizeof(bool));
	
	memset(m_mouseInput, 0, NUM_MOUSEBUTTONS * sizeof(bool));
	memset(m_downMouse, 0, NUM_MOUSEBUTTONS * sizeof(bool));
	memset(m_upMouse, 0, NUM_MOUSEBUTTONS * sizeof(bool));
}

void Input::SetCursor(bool visible) const
{
	if(visible)
		SDL_ShowCursor(1);
	else
		SDL_ShowCursor(0);
}

void Input::SetMousePosition(const Vector2f& pos) const
{
	SDL_WarpMouseInWindow(m_window->GetSDLWindow(), (int)pos.GetX(), (int)pos.GetY());
//	SDLSetMousePosition((int)pos.GetX(), (int)pos.GetY());
}
