/*
 * This engine was built upon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirely
 * created by Kyle Pearce.
 */

#include "camera.h"
#include "renderingEngine.h"

#include "../core/coreEngine.h"

Matrix4f Camera::GetViewProjection() const
{
	//This comes from the conjugate rotation because the world should appear to rotate
	//opposite to the camera's rotation.
	Matrix4f cameraRotation = GetTransform().GetTransformedRot().Conjugate().ToRotationMatrix();
	Matrix4f cameraTranslation;
	
	//Similarly, the translation is inverted because the world appears to move opposite
	//to the camera's movement.
	cameraTranslation.InitTranslation(GetTransform().GetTransformedPos() * -1);
	
	return m_projection * cameraRotation * cameraTranslation;
}

void CameraComponent::AddToEngine(CoreEngine* engine) const
{
	//TODO: This is probably not the correct solution in the case of multiple cameras,
	//and should be investigated in the future.
	engine->GetRenderingEngine()->SetMainCamera(m_camera);
}

void CameraComponent::SetParent(Entity* parent)
{
	EntityComponent::SetParent(parent);
	
	//The camera's transform is initialized here because this is the first point where
	//there is a parent object with a transform.
	m_camera.SetTransform(GetTransform());
}
