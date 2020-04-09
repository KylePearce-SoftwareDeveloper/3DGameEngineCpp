/*
 * This engine was built uppon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirly
 * created by Kyle Pearce.
 */

#ifndef FREELOOK_H
#define FREELOOK_H

#include "../core/math3d.h"
#include "../core/entityComponent.h"

class FreeLook : public EntityComponent
{
public:
	FreeLook(const Vector2f& windowCenter, float sensitivity = 0.5f, int unlockMouseKey = Input::KEY_ESCAPE) :
		m_sensitivity(sensitivity),
		m_unlockMouseKey(unlockMouseKey),
		m_mouseLocked(false),
		m_windowCenter(windowCenter) {}
	
	virtual void ProcessInput(const Input& input, float delta);
protected:
private:
	float    m_sensitivity;
	int      m_unlockMouseKey;
	bool     m_mouseLocked;
	Vector2f m_windowCenter;
};

#endif // FREELOOK_H
