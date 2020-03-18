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
#include "rendering/TextRenderer.h"

class TestGame : public Game
{
public:
	TestGame() {}
	
	virtual void Init(const Window& window);
	virtual void CheckTerrainHeight(); 
	virtual void checkTreeHeight(Entity* treePos);
	virtual void updateSunAngle();
	virtual float checkTreeHeightForShader(glm::vec3 treePos);
	virtual void CheckTreeCollision();
	virtual void ChangeText();//18/3/20
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
	glm::vec3 translations[1000];
	TextRenderer  *textRenderer;//18/3/20
	Vector3f *textChangePos = new Vector3f(-75, 10, -200);
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
	Material grey("grey", Texture("grey.png"), 0.0f, 0,
		Texture("grey.png"), Texture("grey_disp.png"), 0.04f, -1.0f);

	//24/2/20 test - new terrain
	Entity *newTerrainObject = new Entity(Vector3f(0, 0, 0), Quaternion(), 1.0f);
	Mesh *newTerrainMesh = new Mesh("terrainFinished.obj");
	meshObjects.push_back(newTerrainMesh);
	Material *terraineMaterial = new Material("magenta");
	MeshRenderer *newTerrainRenderer = new MeshRenderer(*newTerrainMesh, *terraineMaterial);
	terrainObjects.push_back(newTerrainRenderer);
	newTerrainObject->AddComponent(newTerrainRenderer);
	AddToScene(newTerrainObject);

	//25/2/20 test - water
	Entity *waterObject = new Entity(Vector3f(0, -5.0f, 0), Quaternion(), 1.0f);
	Mesh *waterMesh = new Mesh("water19.obj");
	Material *waterMaterial = new Material("cyan");
	MeshRenderer *waterRenderer = new MeshRenderer(*waterMesh, *waterMaterial);
	waterObject->AddComponent(waterRenderer);
	AddToScene(waterObject);

	//Directional light handel
	Entity *sun = new Entity(Vector3f(), Quaternion(Vector3f(1, 0, 0), ToRadians(0)));
	DirectionalLight *directionalLight = new DirectionalLight(Vector3f(1, 1, 1), 0.4f, 10, 320.0f, 1.0f);//, 0.4f, 0.4f);
	directionalLightObjects.push_back(directionalLight);
	sun->AddComponent(directionalLight);
	AddToScene(sun);

	AddToScene((new Entity(Vector3f(24, -12, 5), Quaternion(Vector3f(0, 1, 0), ToRadians(30.0f))))
		->AddComponent(new MeshRenderer(Mesh("sphere.obj"), Material("bricks"))));
		
	Entity *player = new Entity(Vector3f(0, 0, 0), Quaternion(), 1.0f);
	FreeMove *playerMovement = new FreeMove(50.0f);
	freeMoveObjects.push_back(playerMovement);
	FreeLook *playerLook = new FreeLook(window.GetCenter());
	CameraComponent *playerCamera = new CameraComponent(Matrix4f().InitPerspective(ToRadians(70.0f), window.GetAspect(), 0.1f, 1000.0f));
	player->AddComponent(playerMovement);
	player->AddComponent(playerLook);
	player->AddComponent(playerCamera);
	AddToScene(player);

	for (int i = 0; i < 1000; i++) {
		translations[i] = glm::vec3(-550 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (550 - (-550)))), 0, -550 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (550 - (-550)))));
		float height = checkTreeHeightForShader(translations[i]);
		translations[i].y = height;
	}

	Entity *treeObject = new Entity(Vector3f(0, 0, 0), Quaternion(), 1.0f);
	Mesh *treeMesh = new Mesh("Lowpoly_tree_sample.obj");
	Material *treeMaterial = new Material("black");
	MeshRenderer *treeRenderer = new MeshRenderer(*treeMesh, *treeMaterial);
	treeRenderer->setTranslations(translations);
	treeRenderer->setIsTree(true);
	checkTreeHeight(treeObject);
	treeObject->AddComponent(treeRenderer);
	AddToScene(treeObject);

	//18/3/20 - House
	Entity *houseObject = new Entity(Vector3f(-75, 10, -200), Quaternion(Vector3f(0, 1, 0), ToRadians(-60.0f)), 1.0f);
	Mesh *houseMesh = new Mesh("MyHouse4.obj");
	Material *houseMaterial = new Material("grey");
	MeshRenderer *houseRenderer = new MeshRenderer(*houseMesh, *houseMaterial);
	houseObject->AddComponent(houseRenderer);
	AddToScene(houseObject);
	Entity *doorObject = new Entity(Vector3f(-65.75, 10, -184), Quaternion(Vector3f(0, 1, 0), ToRadians(-60.0f)), 1.0f);
	Mesh *doorMesh = new Mesh("MyHouseDoor.obj");
	Material *doorMaterial = new Material("grey");
	MeshRenderer *doorRenderer = new MeshRenderer(*doorMesh, *doorMaterial);
	doorObject->AddComponent(doorRenderer);
	AddToScene(doorObject);

	//18/3/20 - Point Light
	Entity *lightBulb = new Entity(Vector3f(-75, 10, -200), Quaternion(), 1.0f);
	PointLight *pointLight = new PointLight(Vector3f(1, 1, 1), 40, Attenuation(0, 0, 1));//, 0.4f, 0.4f);
	lightBulb->AddComponent(pointLight);
	AddToScene(lightBulb);

	//18/3/20
	textRenderer = new TextRenderer();
	textRenderer->Load("Gputeks-Regular.ttf", 25);
	textRenderer->setText("Objective: Visit the Engine Learning Center");
	AddTextOnScreen(textRenderer);
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

float TestGame::checkTreeHeightForShader(glm::vec3 treePosArg)
{
	Vector3f treePos(treePosArg.x, treePosArg.y, treePosArg.z);
	float terrainheightAtTreePos = meshObjects[0]->newTerrainHeightFuncFloat(treePos);
	if (terrainheightAtTreePos == 10000.0f) {
		return 0;
	}
	else {
		return terrainheightAtTreePos;
	}

}

void TestGame::CheckTreeCollision()
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

void TestGame::ChangeText()//18/3/20
{
	Vector3f *testPlayerPos = freeMoveObjects[0]->GetParent()->GetTransform()->GetPos();
	Vector3f playerPos(testPlayerPos->GetX(), testPlayerPos->GetY() - 1.0f, testPlayerPos->GetZ());
	if (abs(playerPos.GetX() - textChangePos->GetX()) < 5.0f + 5.0f / 2.0f)
		if (abs(playerPos.GetZ() - textChangePos->GetZ()) < 5.0f + 5.0f / 2.0f)
			textRenderer->setText("WELCOME");
}

void TestGame::updateSunAngle()
{
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
