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

#include "3DEngine.h"
#include "testing.h"

#include "components/freeLook.h"
#include "components/freeMove.h"
#include "components/physicsEngineComponent.h"
#include "components/physicsObjectComponent.h"
#include "physics/boundingSphere.h"

class TestGame : public Game
{
public:
	TestGame() {}
	
	virtual void Init(const Window& window);
	virtual void CheckTerrainHeight(); 
	virtual void checkTreeHeight(Entity* treePos);
	virtual void updateSunAngle();
	virtual float checkTreeHeightForShader(glm::vec3 treePos);//6/3/20
	virtual void CheckTreeCollision();//6/3/20
protected:
private:
	TestGame(const TestGame& other) {}
	void operator=(const TestGame& other) {}
	std::vector<FreeMove*> freeMoveObjects;
	std::vector<MeshRenderer*> trees;
	std::vector<Entity*> treeObjects;
	std::vector<MeshRenderer*> terrainObjects;
	std::vector<Mesh*> meshObjects;
	std::vector<DirectionalLight*> directionalLightObjects;
	float sunCount = 0;
	glm::vec3 translations[1000];//6/3/20
};

void TestGame::Init(const Window& window)
{
	Material bricks("bricks", Texture("bricks.jpg"), 0.0f, 0, 
			Texture("bricks_normal.jpg"), Texture("bricks_disp.png"), 0.03f, -0.5f);
	Material bricks2("bricks2", Texture("bricks2.jpg"), 0.0f, 0, 
			Texture("bricks2_normal.png"), Texture("bricks2_disp.jpg"), 0.04f, -1.0f);
	Material magenta("magenta", Texture("magenta.jpg"), 0.0f, 0, 
			Texture("magenta.jpg"), Texture("magenta_disp.jpg"), 0.04f, -1.0f);
	Material black("black", Texture("black.jpg"), 0.0f, 0,
		Texture("black.jpg"), Texture("black_disp.jpg"), 0.04f, -1.0f);
	Material cyan("cyan", Texture("cyan.png"), 0.0f, 0,
		Texture("cyan.png"), Texture("cyan_disp.png"), 0.04f, -1.0f);

	/*
	Entity *terrainObject = new Entity(Vector3f(0, 0, 0), Quaternion(), 1.0f);
	Mesh *terrainMesh = new Mesh("terrainBigger.obj");
	meshObjects.push_back(terrainMesh);
	Material *terraineMaterial = new Material("magenta");
	MeshRenderer *terrainRenderer = new MeshRenderer(*terrainMesh, *terraineMaterial);
	terrainObjects.push_back(terrainRenderer);
	terrainObject->AddComponent(terrainRenderer);
	AddToScene(terrainObject);
	*/

	//24/2/20 test - new terrain
	Entity *newTerrainObject = new Entity(Vector3f(0, 0, 0), Quaternion(), 1.0f);
	Mesh *newTerrainMesh = new Mesh("terrainFinished.obj");
	meshObjects.push_back(newTerrainMesh);
	Material *terraineMaterial = new Material("magenta");
	MeshRenderer *newTerrainRenderer = new MeshRenderer(*newTerrainMesh, *terraineMaterial);//, false);
	terrainObjects.push_back(newTerrainRenderer);
	newTerrainObject->AddComponent(newTerrainRenderer);
	AddToScene(newTerrainObject);

	//25/2/20 test - water
	Entity *waterObject = new Entity(Vector3f(0, -5.0f, 0), Quaternion(), 1.0f);
	Mesh *waterMesh = new Mesh("water19.obj");
	Material *waterMaterial = new Material("cyan");
	MeshRenderer *waterRenderer = new MeshRenderer(*waterMesh, *waterMaterial);//, false);
	waterObject->AddComponent(waterRenderer);
	AddToScene(waterObject);
	
	//AddToScene((new Entity(Vector3f(), Quaternion(Vector3f(1,0,0), ToRadians(-90))))
	//	->AddComponent(new DirectionalLight(Vector3f(1,1,1), 0.4f, 10, 80.0f, 1.0f)));

	//Directional light handel
	Entity *sun = new Entity(Vector3f(), Quaternion(Vector3f(1, 0, 0), ToRadians(0)));
	DirectionalLight *directionalLight = new DirectionalLight(Vector3f(1, 1, 1), 0.4f, 10, 80.0f, 1.0f);
	directionalLightObjects.push_back(directionalLight);
	sun->AddComponent(directionalLight);
	AddToScene(sun);

	AddToScene((new Entity(Vector3f(24, -12, 5), Quaternion(Vector3f(0, 1, 0), ToRadians(30.0f))))
		->AddComponent(new MeshRenderer(Mesh("sphere.obj"), Material("bricks"))));//, false)));
		
	Entity *player = new Entity(Vector3f(0, 0, 0), Quaternion(), 1.0f);
	FreeMove *playerMovement = new FreeMove(50.0f);
	freeMoveObjects.push_back(playerMovement);
	FreeLook *playerLook = new FreeLook(window.GetCenter());
	CameraComponent *playerCamera = new CameraComponent(Matrix4f().InitPerspective(ToRadians(70.0f), window.GetAspect(), 0.1f, 1000.0f));
	player->AddComponent(playerMovement);
	player->AddComponent(playerLook);
	player->AddComponent(playerCamera);
	AddToScene(player);
	/*
	trees.reserve(100);
	treeObjects.reserve(100);
	for (int i = 0; i < 100; i++) {
		trees.push_back(new MeshRenderer(Mesh("Lowpoly_tree_sample.obj"), Material("black")));//, false));
	}

	for (int i = 0; i < 100; i++) {
		treeObjects.push_back((new Entity(Vector3f(-550 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (550 - (-550)))), 0.0f, -550 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (550 - (-550))))), Quaternion(Vector3f(0, 1, 0), ToRadians(0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (360 - 0))))), 1.0f))->AddComponent(trees[i]));//treeObjects.push_back((new Entity(Vector3f(rand() % 200 + (-200), 0.0f, rand() % 200 + (-200)), Quaternion(Vector3f(0, 1, 0), ToRadians(rand() % 360 + (0))), 1.0f))->AddComponent(trees[i]));
		checkTreeHeight(treeObjects[i]);
		//printf("Tree X Pos: %f\n", treeObjects[i]->GetTransform()->GetPos()->GetX());
		//printf("Tree Z Pos: %f\n", treeObjects[i]->GetTransform()->GetPos()->GetZ());
	}
	for (int i = 0; i < 100; i++) {
		AddToScene(treeObjects[i]);
	}
	*/

	//glm::vec3 translations[1000];//6/3/20
	for (int i = 0; i < 1000; i++) {
		translations[i] = glm::vec3(-550 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (550 - (-550)))), 0, -550 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (550 - (-550)))));
		float height = checkTreeHeightForShader(translations[i]);
		translations[i].y = height;
	}

	//1/3/20
	Entity *treeObject = new Entity(Vector3f(0, 0, 0), Quaternion(), 1.0f);
	Mesh *treeMesh = new Mesh("Lowpoly_tree_sample.obj");
	Material *treeMaterial = new Material("black");
	MeshRenderer *treeRenderer = new MeshRenderer(*treeMesh, *treeMaterial);//, false);
	treeRenderer->setTranslations(translations);//6/3/20
	treeRenderer->setIsTree(true);
	checkTreeHeight(treeObject);
	treeObject->AddComponent(treeRenderer);
	AddToScene(treeObject);
}

void TestGame::CheckTerrainHeight() 
{
	Vector3f *testPlayerPos = freeMoveObjects[0]->GetParent()->GetTransform()->GetPos();
	Vector3f playerPos(testPlayerPos->GetX(), testPlayerPos->GetY() - 1.0f, testPlayerPos->GetZ());
	float terrainheightAtPlayerPos = meshObjects[0]->newTerrainHeightFuncFloat(playerPos);
	if (terrainheightAtPlayerPos == 10000.0f) {
		freeMoveObjects[0]->GetParent()->GetTransform()->SetPos(Vector3f(freeMoveObjects[0]->getOldPos()->GetX(), freeMoveObjects[0]->getOldPos()->GetY(), freeMoveObjects[0]->getOldPos()->GetZ()));//return;
	}
	else {
		freeMoveObjects[0]->GetParent()->GetTransform()->GetPos()->SetY(terrainheightAtPlayerPos + 8.0f);
	}
}

void TestGame::checkTreeHeight(Entity* treeObject)
{
	/*
	float treeHeight = 5.0f;

	for (Vector3f currentVector : meshObjects[0]->getMeshVertices()) {
		Vector3f vertexPos = currentVector;
		Vector3f vertexScale(2.0f, 2.0f, 2.0f);
		Vector3f *treePos = treeObject->GetTransform()->GetPos();
		Vector3f testPlayerScale(2.0f, 2.0f, 2.0f);

		Vector3f tmp(treePos->GetX(), treePos->GetY() - 1.0f, treePos->GetZ());
		//check the X axis
		if (abs(tmp.GetX() - vertexPos.GetX()) < testPlayerScale.GetX() + (vertexScale.GetX()) / 1.0f) {
			//check the Z axis
			if (abs(tmp.GetZ() - vertexPos.GetZ()) < testPlayerScale.GetZ() + (vertexScale.GetZ()) / 1.0f) {
				treeObject->GetTransform()->GetPos()->SetY(vertexPos.GetY());
			}
		}
	}
	*/

	
	Vector3f *testTreePos = treeObject->GetTransform()->GetPos();
	Vector3f treePos(testTreePos->GetX(), testTreePos->GetY() - 1.0f, testTreePos->GetZ());
	float terrainheightAtTreePos = meshObjects[0]->newTerrainHeightFuncFloat(treePos);
	if (terrainheightAtTreePos == 10000.0f) {
		return;
	}
	else {
		treeObject->GetTransform()->GetPos()->SetY(terrainheightAtTreePos);
	}
	
}

float TestGame::checkTreeHeightForShader(glm::vec3 treePosArg)//6/3/20
{
	//Vector3f *testTreePos = treeObject->GetTransform()->GetPos();
	Vector3f treePos(treePosArg.x, treePosArg.y, treePosArg.z);
	float terrainheightAtTreePos = meshObjects[0]->newTerrainHeightFuncFloat(treePos);
	if (terrainheightAtTreePos == 10000.0f) {
		return 0;
	}
	else {
		//treePosArg.y = terrainheightAtTreePos;
		return terrainheightAtTreePos;
	}

}

void TestGame::CheckTreeCollision()//6/3/20
{
	Vector3f *testPlayerPos = freeMoveObjects[0]->GetParent()->GetTransform()->GetPos();
	Vector3f playerPos(testPlayerPos->GetX(), testPlayerPos->GetY() - 1.0f, testPlayerPos->GetZ());
	for (int i = 0; i < 1000; i++) {
		if (abs(playerPos.GetX() - translations[i].x) < 5.0f + 5.0f / 2.0f) 
			if (abs(playerPos.GetZ() - translations[i].z) < 5.0f + 5.0f / 2.0f) {
				freeMoveObjects[0]->GetParent()->GetTransform()->SetPos(Vector3f(freeMoveObjects[0]->getOldPos()->GetX(), freeMoveObjects[0]->getOldPos()->GetY(), freeMoveObjects[0]->getOldPos()->GetZ()));
				return;
			}
	}
}

void TestGame::updateSunAngle()
{
	/*
	directionalLightObjects[0]->GetParent()->GetTransform()->GetRot()->SetX(directionalLightObjects[0]->GetParent()->GetTransform()->GetRot()->GetX() + 0.0001f);
	directionalLightObjects[0]->GetParent()->GetTransform()->GetRot()->SetY(directionalLightObjects[0]->GetParent()->GetTransform()->GetRot()->GetY() + 0.0001f);
	directionalLightObjects[0]->GetParent()->GetTransform()->GetRot()->SetZ(directionalLightObjects[0]->GetParent()->GetTransform()->GetRot()->GetZ() + 0.0001f);
	directionalLightObjects[0]->GetParent()->GetTransform()->GetRot()->SetW(directionalLightObjects[0]->GetParent()->GetTransform()->GetRot()->GetW() + 0.0001f);
	*/
	sunCount-=0.1f;
	if (sunCount <= -135.0f) {
		sunCount = -135.0f;
		directionalLightObjects[0]->SetIntensity(directionalLightObjects[0]->GetIntensity()-0.01f);
	}
	if (directionalLightObjects[0]->GetIntensity() <= 0) {
		sunCount = 0;
		directionalLightObjects[0]->SetIntensity(0.4f);
	}
	directionalLightObjects[0]->GetParent()->GetTransform()->SetRot(Quaternion(Vector3f(1, 0, 0), ToRadians(sunCount)));
	
}


#include <iostream>

int main()
{
	Testing::RunAllTests();

	TestGame game;
	Window window(800, 600, "3D Game Engine");
	RenderingEngine renderer(window);
	//window.SetFullScreen(true);
	CoreEngine engine(60, &window, &renderer, &game);//init called once here
	engine.Start();//process input, update and render called here every frame
	
	return 0;
}
