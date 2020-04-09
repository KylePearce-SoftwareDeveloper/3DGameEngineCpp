/*
 * This engine was built upon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirely
 * created by Kyle Pearce.
 */

#include "freeMove.h"
#include "../core/game.h"//2/2/20 test
	
void FreeMove::ProcessInput(const Input& input, float delta)
{
	SetOldPos(Vector3f(GetTransform()->GetPos()->GetX(), GetTransform()->GetPos()->GetY(), GetTransform()->GetPos()->GetZ()));//27/2/20
	float movAmt = m_speed * delta;
	Vector3f movementVector(0.0f, 0.0f,0.0f);
	//movementVector.add
	if(input.GetKey(m_forwardKey))
		movementVector += GetTransform()->GetRot()->GetForward();//Move(GetTransform()->GetRot()->GetForward(), movAmt);
	if(input.GetKey(m_backKey))
		movementVector -= GetTransform()->GetRot()->GetForward();//Move(GetTransform()->GetRot()->GetBack(), movAmt);
	if(input.GetKey(m_leftKey))
		movementVector += GetTransform()->GetRot()->GetLeft();//Move(GetTransform()->GetRot()->GetLeft(), movAmt);
	if(input.GetKey(m_rightKey))
		movementVector += GetTransform()->GetRot()->GetRight();//Move(GetTransform()->GetRot()->GetRight(), movAmt);

	movementVector.SetY(0.0f);
	if (movementVector.Length() > 0)
		movementVector.Normalized();

	Move(movementVector, movAmt);

	if(input.GetKey(input.KEY_ESCAPE))
		exit(0);
}

void FreeMove::Move(const Vector3f& direction, float amt)
{
	GetTransform()->SetPos(*GetTransform()->GetPos() + (direction * amt));
	//GetParent()->GetEngine()->GetGame()->CheckTerrainHeight();//6/2/20
}

void FreeMove::Update(float delta) {//2/2/20 test
	GetParent()->GetEngine()->GetGame()->CheckTerrainHeight();
	//EntityComponent::GetParent()->GetEngine->GetGame->CheckTerrainHeight;// .getEngine().getGame().checkTerraineHeight();
	GetParent()->GetEngine()->GetGame()->updateSunAngle();
	GetParent()->GetEngine()->GetGame()->CheckTreeCollision();//6/3/20
	//GetParent()->GetEngine()->GetGame()->renderText();//11/3/20
	GetParent()->GetEngine()->GetGame()->ChangeText();//18/3/20
	GetParent()->GetEngine()->GetGame()->CheckCollisionWithModel();//19/3/20
}
/*
Vector3f* FreeMove::getOldPos() {
	return &oldPos;
}
*/
