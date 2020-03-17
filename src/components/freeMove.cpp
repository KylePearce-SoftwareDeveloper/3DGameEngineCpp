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
}
/*
Vector3f* FreeMove::getOldPos() {
	return &oldPos;
}
*/
