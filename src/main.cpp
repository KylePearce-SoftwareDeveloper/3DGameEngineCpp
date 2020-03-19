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
	virtual void CheckCollisionWithModel();//19/3/20
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
	std::vector<Mesh*> buildingMeshes;//19/3/20
	std::vector<MeshRenderer*> meshRendererCollisionObjects;//19/3/20
	std::vector<Vector3f> meshRendererCollisionScales;//19/3/20
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
	Material red("red", Texture("red.png"), 0.0f, 0,
		Texture("red.png"), Texture("red_disp.png"), 0.04f, -1.0f);

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
	/*Entity *houseObject = new Entity(Vector3f(-75, 10, -200), Quaternion(Vector3f(0, 1, 0), ToRadians(-60.0f)), 1.0f);
	Mesh *houseMesh = new Mesh("MyHouse4.obj");
	buildingMeshes.push_back(houseMesh);
	Material *houseMaterial = new Material("grey");
	MeshRenderer *houseRenderer = new MeshRenderer(*houseMesh, *houseMaterial);
	houseObject->AddComponent(houseRenderer);
	AddToScene(houseObject);
	Entity *doorObject = new Entity(Vector3f(-65.75, 10, -184), Quaternion(Vector3f(0, 1, 0), ToRadians(-60.0f)), 1.0f);
	Mesh *doorMesh = new Mesh("MyHouseDoor.obj");
	buildingMeshes.push_back(doorMesh);
	Material *doorMaterial = new Material("grey");
	MeshRenderer *doorRenderer = new MeshRenderer(*doorMesh, *doorMaterial);
	doorObject->AddComponent(doorRenderer);
	AddToScene(doorObject);*/
	meshRendererCollisionScales.push_back(Vector3f(45, 10, 1));//wallType1.obj
	meshRendererCollisionScales.push_back(Vector3f(45, 10, 1));//wallType1.obj
	meshRendererCollisionScales.push_back(Vector3f(1, 10, 30));//wallType2.obj
	//meshRendererCollisionScales.push_back(Vector3f());//roof.obj
	meshRendererCollisionScales.push_back(Vector3f(1, 10, 12));//door.obj
	meshRendererCollisionScales.push_back(Vector3f(1, 10, 12));//door.obj

	Material *houseMaterial = new Material("grey");

	Mesh *wall1Mesh = new Mesh("wallType1.obj");
	Mesh *wall2Mesh = new Mesh("wallType1.obj");
	Mesh *wallType2Mesh = new Mesh("wallType2.obj");
	Mesh *roofMesh = new Mesh("roof.obj");
	Mesh *door1Mesh = new Mesh("door.obj");
	Mesh *door2Mesh = new Mesh("door.obj");

	MeshRenderer *wall1Renderer = new MeshRenderer(*wall1Mesh, *houseMaterial);
	meshRendererCollisionObjects.push_back(wall1Renderer);
	MeshRenderer *wall2Renderer = new MeshRenderer(*wall2Mesh, *houseMaterial);
	meshRendererCollisionObjects.push_back(wall2Renderer);
	MeshRenderer *wall3Renderer = new MeshRenderer(*wallType2Mesh, *houseMaterial);
	meshRendererCollisionObjects.push_back(wall3Renderer);
	MeshRenderer *roofRenderer = new MeshRenderer(*roofMesh, *houseMaterial);
	//meshRendererCollisionObjects.push_back();
	MeshRenderer *door1Renderer = new MeshRenderer(*door1Mesh, *houseMaterial);
	meshRendererCollisionObjects.push_back(door1Renderer);
	MeshRenderer *door2Renderer = new MeshRenderer(*door2Mesh, *houseMaterial);
	meshRendererCollisionObjects.push_back(door2Renderer);

	Entity *wall1Entity = new Entity(Vector3f(-75, 10, -229), Quaternion(), 1.0f);
	wall1Entity->AddComponent(wall1Renderer);
	//AddToScene(wall1Entity);
	Entity *wall2Entity = new Entity(Vector3f(-75, 10, -171), Quaternion(), 1.0f);
	wall2Entity->AddComponent(wall2Renderer);
	//AddToScene(wall2Entity);
	Entity *wall3Entity = new Entity(Vector3f(-119, 10, -200), Quaternion(), 1.0f);
	wall3Entity->AddComponent(wall3Renderer);
	//AddToScene(wall3Entity);
	Entity *roofEntity = new Entity(Vector3f(-75, 19, -200), Quaternion(), 1.0f);
	roofEntity->AddComponent(roofRenderer);
	//AddToScene(roofEntity);
	Entity *door1Entity = new Entity(Vector3f(-31, 10, -218), Quaternion(), 1.0f);
	door1Entity->AddComponent(door1Renderer);
	//AddToScene(door1Entity);
	Entity *door2Entity = new Entity(Vector3f(-31, 10, -182), Quaternion(), 1.0f);
	door2Entity->AddComponent(door2Renderer);
	//AddToScene(door2Entity);

	AddToScene(wall1Entity);
	AddToScene(wall2Entity);
	AddToScene(wall3Entity);
	AddToScene(roofEntity);
	AddToScene(door1Entity);
	AddToScene(door2Entity);
	

	//19/3/20 - Wall Pannels
	Material *engineCoreMaterial = new Material("red");
	Mesh *engineCore1Mesh = new Mesh("wallPannelType1.obj");
	Mesh *engineCore2Mesh = new Mesh("wallPannelType1.obj");
	Mesh *engineCore3Mesh = new Mesh("wallPannelType1.obj");
	Mesh *engineCore4Mesh = new Mesh("wallPannelType1.obj");
	Mesh *engineCore5Mesh = new Mesh("wallPannelType1.obj");
	Mesh *engineCore6Mesh = new Mesh("wallPannelType1.obj");
	Mesh *engineCore7Mesh = new Mesh("wallPannelType2.obj");
	Mesh *engineCore8Mesh = new Mesh("wallPannelType2.obj");
	MeshRenderer *engineCore1Renderer = new MeshRenderer(*engineCore1Mesh, *engineCoreMaterial);
	MeshRenderer *engineCore2Renderer= new MeshRenderer(*engineCore2Mesh, *engineCoreMaterial);
	MeshRenderer *engineCore3Renderer = new MeshRenderer(*engineCore3Mesh, *engineCoreMaterial);
	MeshRenderer *engineCore4Renderer = new MeshRenderer(*engineCore4Mesh, *engineCoreMaterial);
	MeshRenderer *engineCore5Renderer = new MeshRenderer(*engineCore5Mesh, *engineCoreMaterial);
	MeshRenderer *engineCore6Renderer = new MeshRenderer(*engineCore6Mesh, *engineCoreMaterial);
	MeshRenderer *engineCore7Renderer = new MeshRenderer(*engineCore7Mesh, *engineCoreMaterial);
	MeshRenderer *engineCore8Renderer = new MeshRenderer(*engineCore8Mesh, *engineCoreMaterial);
	Entity *engineCore1Entity = new Entity(Vector3f(-50, 8, -227), Quaternion(), 1.0f);
	engineCore1Entity->AddComponent(engineCore1Renderer);
	Entity *engineCore2Entity = new Entity(Vector3f(-75, 8, -227), Quaternion(), 1.0f);
	engineCore2Entity->AddComponent(engineCore2Renderer);
	Entity *engineCore3Entity = new Entity(Vector3f(-100, 8, -227), Quaternion(), 1.0f);
	engineCore3Entity->AddComponent(engineCore3Renderer);
	Entity *engineCore4Entity = new Entity(Vector3f(-50, 8, -173), Quaternion(), 1.0f);
	engineCore4Entity->AddComponent(engineCore4Renderer);
	Entity *engineCore5Entity = new Entity(Vector3f(-75, 8, -173), Quaternion(), 1.0f);
	engineCore5Entity->AddComponent(engineCore5Renderer);
	Entity *engineCore6Entity = new Entity(Vector3f(-100, 8, -173), Quaternion(), 1.0f);
	engineCore6Entity->AddComponent(engineCore6Renderer);
	Entity *engineCore7Entity = new Entity(Vector3f(-117, 8, -189), Quaternion(), 1.0f);
	engineCore7Entity->AddComponent(engineCore7Renderer);
	Entity *engineCore8Entity = new Entity(Vector3f(-117, 8, -215), Quaternion(), 1.0f);
	engineCore8Entity->AddComponent(engineCore8Renderer);
	AddToScene(engineCore1Entity);
	AddToScene(engineCore2Entity);
	AddToScene(engineCore3Entity);
	AddToScene(engineCore4Entity);
	AddToScene(engineCore5Entity);
	AddToScene(engineCore6Entity);
	AddToScene(engineCore7Entity);
	AddToScene(engineCore8Entity);

	/*Entity *engineCoreEntity = new Entity(Vector3f(-75, 10, -200), Quaternion(), 1.0f);
	Mesh *engineCoreMesh = new Mesh("wallPannelBigger.obj");
	MeshRenderer *engineCoreRenderer = new MeshRenderer(*engineCoreMesh, *engineCoreMaterial);
	engineCoreEntity->AddComponent(engineCoreRenderer);
	AddToScene(engineCoreEntity);*/
	

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

void TestGame::CheckCollisionWithModel()//19/3/20
{
	/*Vector3f *testPlayerPos = freeMoveObjects[0]->GetParent()->GetTransform()->GetPos();
	Vector3f playerPos(testPlayerPos->GetX(), testPlayerPos->GetY() - 1.0f, testPlayerPos->GetZ());
	Vector3f playerScale(1.0f, 1.0f, 1.0f);*/
	/*bool isCollision1 = buildingMeshes[0]->checkCollisionWithMesh(playerPos, Vector3f(-75, 10, -200));
	bool isCollision2 = buildingMeshes[1]->checkCollisionWithMesh(playerPos, Vector3f(-65.75, 10, -184));
	if (isCollision1) {
		freeMoveObjects[0]->GetParent()->GetTransform()->SetPos(Vector3f(freeMoveObjects[0]->getOldPos()->GetX(), freeMoveObjects[0]->getOldPos()->GetY(), freeMoveObjects[0]->getOldPos()->GetZ()));
		return;
	}
	else if (isCollision2) {
		freeMoveObjects[0]->GetParent()->GetTransform()->SetPos(Vector3f(freeMoveObjects[0]->getOldPos()->GetX(), freeMoveObjects[0]->getOldPos()->GetY(), freeMoveObjects[0]->getOldPos()->GetZ()));
		return;
	}
	else {
		return;
	}*/

	//19/3/20
	Vector3f *testPlayerPos = freeMoveObjects[0]->GetParent()->GetTransform()->GetPos();
	Vector3f playerPos(testPlayerPos->GetX(), testPlayerPos->GetY() - 1.0f, testPlayerPos->GetZ());
	Vector3f playerScale(0.5f, 0.5f, 0.5f);
	for (int i = 0; i < meshRendererCollisionObjects.size(); i++) {
		Vector3f* meshPos = meshRendererCollisionObjects[i]->GetParent()->GetTransform()->GetPos();
		if (abs(playerPos.GetX() - meshPos->GetX()) < playerScale.GetX() + meshRendererCollisionScales[i].GetX() / 1.0f)
			if (abs(playerPos.GetZ() - meshPos->GetZ()) < playerScale.GetZ() + meshRendererCollisionScales[i].GetZ() / 1.0f) {
				freeMoveObjects[0]->GetParent()->GetTransform()->SetPos(Vector3f(freeMoveObjects[0]->getOldPos()->GetX(), freeMoveObjects[0]->getOldPos()->GetY(), freeMoveObjects[0]->getOldPos()->GetZ()));
				return;
			}
	}
	
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
