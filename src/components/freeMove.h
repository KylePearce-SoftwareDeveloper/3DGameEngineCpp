/*
 * This engine was built uppon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirly
 * created by Kyle Pearce.
 */

#ifndef FREEMOVE_H
#define FREEMOVE_H

#include "../core/math3d.h"
#include "../core/entityComponent.h"

class FreeMove : public EntityComponent
{
public:
	FreeMove(float speed = 10.0f, int forwardKey = Input::KEY_W, int backKey = Input::KEY_S, int leftKey = Input::KEY_A, int rightKey = Input::KEY_D)  :
		m_speed(speed),
		m_forwardKey(forwardKey),
		m_backKey(backKey),
		m_leftKey(leftKey),
		m_rightKey(rightKey) {}
	
	virtual void ProcessInput(const Input& input, float delta);
	virtual void Update(float delta);//6/2/20 test
	//virtual Entity* GetParent();//2/2/20 test
	inline Vector3f* getOldPos() { return &oldPos; }//27/2/20 test
	inline void SetOldPos(const Vector3f& oldPosArg) { oldPos = oldPosArg; }//27/2/20 test
protected:
private:
	void Move(const Vector3f& direction, float amt);

	float m_speed;
	int m_forwardKey;
	int m_backKey;
	int m_leftKey;
	int m_rightKey;

	Vector3f oldPos;//27/2/20 test
};

#endif // FREEMOVE_H
