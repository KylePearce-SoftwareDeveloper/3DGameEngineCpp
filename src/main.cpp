/*
 * This engine was built upon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirely
 * created by Kyle Pearce.
 */

#include "3DEngine.h"
#include "testing.h"

#include "components/freeLook.h"
#include "components/freeMove.h"
#include "components/physicsEngineComponent.h"
#include "components/physicsObjectComponent.h"
#include "physics/boundingSphere.h"
#include "rendering/TextRenderer.h"
#include <irrKlang.h>//AUDIO
using namespace irrklang;//AUDIO


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

	ISoundEngine *SoundEngine = createIrrKlangDevice();//AUDIO

	std::vector<FreeMove*> freeMoveObjects;
	std::vector<MeshRenderer*> trees;
	std::vector<Entity*> treeObjects;
	std::vector<MeshRenderer*> terrainObjects;
	std::vector<Mesh*> meshObjects;
	std::vector<DirectionalLight*> directionalLightObjects;
	float sunCount = 0;
	glm::vec3 translations[1000];
	TextRenderer  *textRenderer;//18/3/20
	std::vector<Mesh*> buildingMeshes;//19/3/20
	std::vector<MeshRenderer*> meshRendererCollisionObjects;//19/3/20
	std::vector<Vector3f> meshRendererCollisionScales;//19/3/20

	Vector3f *entranceToLearninCenterPos = new Vector3f(-31, 10, -200);
	Vector3f firstPannelPos =  Vector3f(-50, 8, -228);
	Vector3f seccondPannelPos = Vector3f(-75, 8, -228);
	Vector3f thirdPannelPos = Vector3f(-100, 8, -228);
	Vector3f fourthPannelPos = Vector3f(-118, 8, -215);
	Vector3f fifthPannelPos = Vector3f(-118, 8, -189);
	Vector3f sixthPannelPos = Vector3f(-100, 8, -172);
	Vector3f seventhPannelPos = Vector3f(-75, 8, -172);
	Vector3f eighthPannelPos = Vector3f(-50, 8, -172);
	/*Vector3f fourthPannelPos = Vector3f(-50, 8, -172);
	Vector3f fifthPannelPos = Vector3f(-75, 8, -172);
	Vector3f sixthPannelPos = Vector3f(-100, 8, -172);
	Vector3f seventhPannelPos = Vector3f(-118, 8, -189);
	Vector3f eightPannelPos = Vector3f(-118, 8, -215);*/

	bool hasHadWelcomeMessage = false;
	bool touchedOnce = false;
	bool touchedOnce2 = false;
	bool touchedOnce3 = false;
	bool touchedOnce4 = false;
	bool touchedOnce5 = false;
	bool touchedOnce6 = false;
	bool touchedOnce7 = false;
	bool touchedOnce8 = false;

	bool pressedFirstButton = false;
	bool pressedSeccondButton = false;
	bool pressedThirdButton = false;
	bool pressedFourthButton = false;
	bool pressedFifthButton = false;
	bool pressedSixthButton = false;
	bool pressedSeventhButton = false;
	bool pressedEighthButton = false;


	bool spawnFirstEnergyCube = false;

	MeshRenderer *engineCore1Renderer;
	MeshRenderer *engineCore2Renderer;
	MeshRenderer *engineCore3Renderer;
	MeshRenderer *engineCore4Renderer;
	MeshRenderer *engineCore5Renderer;
	MeshRenderer *engineCore6Renderer;
	MeshRenderer *engineCore7Renderer;
	MeshRenderer *engineCore8Renderer;


	MeshRenderer *energyCubeRenderer;
	//MeshRenderer *seccondEnergyCubeRenderer;

	MeshRenderer *enemyCube1Renderer;
	MeshRenderer *enemyCube2Renderer;
	MeshRenderer *enemyCube3Renderer;
	MeshRenderer *enemyCube4Renderer;
	MeshRenderer *enemyCube5Renderer;

	int timmer = 1000;
	bool checkCollisionsWithEnergyComponents = false;

	bool checkTime = true;
	bool checkTime2 = true;
	bool checkTime3 = true;
	bool checkTime4 = true;
	bool checkTime5 = true;
	bool checkTime6 = true;
	bool checkTime7 = true;
	bool checkTime8 = true;


	bool gameplayOneFinished = false;
	bool gameplayTwoFinished = false;
	bool gameplayThreeFinished = false;
	bool gameplayFourFinished = false;
	bool gameplayFiveFinished = false;
	bool gameplaySixFinished = false;
	bool gameplaySevenFinished = false;
	bool gameplayEightFinished = false;

	bool hasHadPostGameplayOneMessage = false;
	bool hasHadPostGameplayTwoMessage = false;
	bool hasHadPostGameplayThreeMessage = false;
	bool hasHadPostGameplayFourMessage = false;
	bool hasHadPostGameplayFiveMessage = false;
	bool hasHadPostGameplaySixMessage = false;
	bool hasHadPostGameplaySevenMessage = false;
	bool hasHadPostGameplayEightMessage = false;

	bool touchedOncePostGamePlayOne = false;
	bool touchedOncePostGamePlayTwo = false;
	bool touchedOncePostGamePlayThree = false;
	bool touchedOncePostGamePlayFour = false;
	bool touchedOncePostGamePlayFive = false;
	bool touchedOncePostGamePlaySix = false;
	bool touchedOncePostGamePlaySeven = false;
	bool touchedOncePostGamePlayEight = false;

	bool currentlyLearning = false;

	bool startGameplayOne = true;
	bool startGameplayTwo = false;
	bool startGameplayThree = false;
	bool startGameplayFour = false;
	bool startGameplayFive = false;
	bool startGameplaySix = false;
	bool startGameplaySeven = false;
	bool startGameplayEight = false;

	bool gameplayOneDead = false;
	bool gameplayTwoDead = false;
	bool gameplayThreeDead = false;
	bool gameplayFourDead = false;
	bool gameplayFiveDead = false;
	bool gameplaySixDead = false;
	bool gameplaySevenDead = false;
	bool gameplayEightDead = false;
	bool gameplayOneCurrentlyHappening = false;
	bool gameplayTwoCurrentlyHappening = false;
	bool gameplayThreeCurrentlyHappening = false;
	bool gameplayFourCurrentlyHappening = false;
	bool gameplayFiveCurrentlyHappening = false;
	bool gameplaySixCurrentlyHappening = false;
	bool gameplaySevenCurrentlyHappening = false;
	bool gameplayEightCurrentlyHappening = false;

	bool currentlyTouchingPannelOne = false;
	bool currentlyTouchingPannelTwo = false;
	bool currentlyTouchingPannelThree = false;
	bool currentlyTouchingPannelFour = false;
	bool currentlyTouchingPannelFive = false;
	bool currentlyTouchingPannelSix = false;
	bool currentlyTouchingPannelSeven = false;
	bool currentlyTouchingPannelEight = false;

	Entity *energyCubeEntity;
	Entity *enemyCube1Entity;
	Entity *enemyCube2Entity;
	Entity *enemyCube3Entity;
	Entity *enemyCube4Entity;
	Entity *enemyCube5Entity;
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
	Material white("white", Texture("white.jpg"), 0.0f, 0,
		Texture("white.jpg"), Texture("white.jpg"), 0.04f, -1.0f);
	Material green("green", Texture("green.png"), 0.0f, 0,
		Texture("green.png"), Texture("green.png"), 0.04f, -1.0f);

	//24/2/20 test - new terrain
	Entity *newTerrainObject = new Entity(Vector3f(0, 0, 0), Quaternion(), 1.0f);
	Mesh *newTerrainMesh = new Mesh("smootherTerrainTest2.obj");
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
	Material *engineCoreSeccondaryMaterial = new Material("white");
	Material *engineCoreThirdMaterial = new Material("green");
	Mesh *engineCore1Mesh = new Mesh("wallPannelType1.obj");
	Mesh *engineCore2Mesh = new Mesh("wallPannelType1.obj");
	Mesh *engineCore3Mesh = new Mesh("wallPannelType1.obj");
	Mesh *engineCore4Mesh = new Mesh("wallPannelType2.obj");
	Mesh *engineCore5Mesh = new Mesh("wallPannelType2.obj");
	Mesh *engineCore6Mesh = new Mesh("wallPannelType1.obj");
	Mesh *engineCore7Mesh = new Mesh("wallPannelType1.obj");
	Mesh *engineCore8Mesh = new Mesh("wallPannelType1.obj");
	engineCore1Renderer = new MeshRenderer(*engineCore1Mesh, *engineCoreMaterial, *engineCoreSeccondaryMaterial, *engineCoreThirdMaterial);
	engineCore2Renderer= new MeshRenderer(*engineCore2Mesh, *engineCoreMaterial, *engineCoreSeccondaryMaterial, *engineCoreThirdMaterial);
	engineCore3Renderer = new MeshRenderer(*engineCore3Mesh, *engineCoreMaterial, *engineCoreSeccondaryMaterial, *engineCoreThirdMaterial);
	engineCore4Renderer = new MeshRenderer(*engineCore4Mesh, *engineCoreMaterial, *engineCoreSeccondaryMaterial, *engineCoreThirdMaterial);
	engineCore5Renderer = new MeshRenderer(*engineCore5Mesh, *engineCoreMaterial, *engineCoreSeccondaryMaterial, *engineCoreThirdMaterial);
	engineCore6Renderer = new MeshRenderer(*engineCore6Mesh, *engineCoreMaterial, *engineCoreSeccondaryMaterial, *engineCoreThirdMaterial);
	engineCore7Renderer = new MeshRenderer(*engineCore7Mesh, *engineCoreMaterial, *engineCoreSeccondaryMaterial, *engineCoreThirdMaterial);
	engineCore8Renderer = new MeshRenderer(*engineCore8Mesh, *engineCoreMaterial, *engineCoreSeccondaryMaterial, *engineCoreThirdMaterial);
	Entity *engineCore1Entity = new Entity(firstPannelPos, Quaternion(), 1.0f);
	engineCore1Entity->AddComponent(engineCore1Renderer);
	Entity *engineCore2Entity = new Entity(seccondPannelPos, Quaternion(), 1.0f);
	engineCore2Entity->AddComponent(engineCore2Renderer);
	Entity *engineCore3Entity = new Entity(thirdPannelPos, Quaternion(), 1.0f);
	engineCore3Entity->AddComponent(engineCore3Renderer);
	Entity *engineCore4Entity = new Entity(fourthPannelPos, Quaternion(), 1.0f);
	engineCore4Entity->AddComponent(engineCore4Renderer);
	Entity *engineCore5Entity = new Entity(fifthPannelPos, Quaternion(), 1.0f);
	engineCore5Entity->AddComponent(engineCore5Renderer);
	Entity *engineCore6Entity = new Entity(sixthPannelPos, Quaternion(), 1.0f);
	engineCore6Entity->AddComponent(engineCore6Renderer);
	Entity *engineCore7Entity = new Entity(seventhPannelPos, Quaternion(), 1.0f);
	engineCore7Entity->AddComponent(engineCore7Renderer);
	Entity *engineCore8Entity = new Entity(eighthPannelPos, Quaternion(), 1.0f);
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
	
	//Energy Cube
	Material *energyCubeMaterial = new Material("green");
	energyCubeEntity = new Entity(Vector3f(0, 5, 0), Quaternion(), 1.0f);//Entity *firstEnergyCubeEntity = new Entity(Vector3f(0, 5, 0), Quaternion(), 1.0f);
	Mesh *firstEnergyCubeMesh = new Mesh("energyCore.obj");
	energyCubeRenderer = new MeshRenderer(*firstEnergyCubeMesh, *energyCubeMaterial);
	energyCubeRenderer->setDraw(false);
	energyCubeEntity->AddComponent(energyCubeRenderer);
	AddToScene(energyCubeEntity);
	/*Entity *seccondEnergyCubeEntity = new Entity(Vector3f(10, 5, 10), Quaternion(), 1.0f);
	Mesh *seccondEnergyCubeMesh = new Mesh("energyCore.obj");
	seccondEnergyCubeRenderer = new MeshRenderer(*seccondEnergyCubeMesh, *energyCubeMaterial);
	seccondEnergyCubeRenderer->setDraw(false);
	seccondEnergyCubeEntity->AddComponent(seccondEnergyCubeRenderer);
	AddToScene(seccondEnergyCubeEntity);*/

	//Enemy Cubes
	Mesh *enemyCube1Mesh = new Mesh("energyCore.obj");
	Mesh *enemyCube2Mesh = new Mesh("energyCore.obj");
	Mesh *enemyCube3Mesh = new Mesh("energyCore.obj");
	Mesh *enemyCube4Mesh = new Mesh("energyCore.obj");
	Mesh *enemyCube5Mesh = new Mesh("energyCore.obj");
	enemyCube1Renderer = new MeshRenderer(*enemyCube1Mesh, *engineCoreMaterial);//red cube
	enemyCube1Renderer->setDraw(false);
	enemyCube2Renderer = new MeshRenderer(*enemyCube2Mesh, *engineCoreMaterial);//red cube
	enemyCube2Renderer->setDraw(false);
	enemyCube3Renderer = new MeshRenderer(*enemyCube3Mesh, *engineCoreMaterial);//red cube
	enemyCube3Renderer->setDraw(false);
	enemyCube4Renderer = new MeshRenderer(*enemyCube4Mesh, *engineCoreMaterial);//red cube
	enemyCube4Renderer->setDraw(false);
	enemyCube5Renderer = new MeshRenderer(*enemyCube5Mesh, *engineCoreMaterial);//red cube
	enemyCube5Renderer->setDraw(false);
	enemyCube1Entity = new Entity(Vector3f(10, 5, 0), Quaternion(), 1.0f);
	enemyCube1Entity->AddComponent(enemyCube1Renderer);
	enemyCube2Entity = new Entity(Vector3f(20, 5, 0), Quaternion(), 1.0f);
	enemyCube2Entity->AddComponent(enemyCube2Renderer);
	enemyCube3Entity = new Entity(Vector3f(30, 5, 0), Quaternion(), 1.0f);
	enemyCube3Entity->AddComponent(enemyCube3Renderer);
	enemyCube4Entity = new Entity(Vector3f(40, 5, 0), Quaternion(), 1.0f);
	enemyCube4Entity->AddComponent(enemyCube4Renderer);
	enemyCube5Entity = new Entity(Vector3f(50, 5, 0), Quaternion(), 1.0f);
	enemyCube5Entity->AddComponent(enemyCube5Renderer);
	AddToScene(enemyCube1Entity);
	AddToScene(enemyCube2Entity);
	AddToScene(enemyCube3Entity);
	AddToScene(enemyCube4Entity);
	AddToScene(enemyCube5Entity);

	//18/3/20 - Point Light
	Entity *lightBulb = new Entity(Vector3f(-75, 10, -200), Quaternion(), 1.0f);
	PointLight *pointLight = new PointLight(Vector3f(1, 1, 1), 40, Attenuation(0, 0, 1));//, 0.4f, 0.4f);
	lightBulb->AddComponent(pointLight);
	AddToScene(lightBulb);

	//18/3/20
	textRenderer = new TextRenderer();
	textRenderer->Load("Gputeks-Regular.ttf", 25);
	textRenderer->setText("Objective: Visit the Engine Learning Center");
	textRenderer->setX(20);//19/3/20
	textRenderer->setY(25);//19/3/20
	AddTextOnScreen(textRenderer);

	//irrklang::ISound::setVolume(0.5);
	irrklang::ISound* snd = SoundEngine->play2D("../res/music/multiverse.mp3", GL_TRUE, GL_FALSE, GL_TRUE);
	snd->setVolume(0.04);
	//SoundEngine->play2D("../res/music/multiverse.mp3", GL_TRUE);//AUDIO
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
	if (!hasHadWelcomeMessage) {
		if (abs(playerPos.GetX() - entranceToLearninCenterPos->GetX()) < 2.0f + 2.0f / 1.0f)
			if (abs(playerPos.GetZ() - entranceToLearninCenterPos->GetZ()) < 2.0f + 2.0f / 1.0f) {
				textRenderer->setText("Welcome to the Learning Center - Explains stuff");
				textRenderer->setY(200);
				hasHadWelcomeMessage = true;
			}
	}

	//------------------------------------------------------------------------------------------------------------GAMEPLAY_ONE
	if (!gameplayOneDead) {
		if (startGameplayOne && !currentlyLearning) {
			if (!pressedFirstButton) {
				if (abs(playerPos.GetX() - firstPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - firstPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						gameplayOneCurrentlyHappening = true;//LOCKED INTO THIS GAMEPLAY
						textRenderer->setText("Press 'E'");
						textRenderer->setY(300);
						textRenderer->setX(100);
						touchedOnce = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Go collect Energy cube to put this Engine Core online");
							textRenderer->setY(100);
							textRenderer->setX(50);
							engineCore1Renderer->setUseSeccondaryMaterial(true);
							pressedFirstButton = true;
							energyCubeRenderer->setDraw(true);
						}
					}
					else {
						if (touchedOnce)
							if (!pressedFirstButton)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOnce)
						if (!pressedFirstButton)
							textRenderer->setText(" ");
				}
			}
			if (energyCubeRenderer->getDraw() || checkCollisionsWithEnergyComponents) {
				if (!checkCollisionsWithEnergyComponents) {
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if(energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Renderer->setDraw(true);
							enemyCube2Renderer->setDraw(true);
							enemyCube3Renderer->setDraw(true);
							enemyCube4Renderer->setDraw(true);
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime) {
						textRenderer->setText("Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					//printf("test");
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if(enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
							//checkTime = false;
							//textRenderer->setText("Well done, head back to the learning center");
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime = false;
						timmer = 1000;
						textRenderer->setText("Well done, head back to the learning center");
						engineCore1Renderer->setUseThirdMaterial(true);
						checkCollisionsWithEnergyComponents = false;
						gameplayOneFinished = true;
					}
				}
			}
			if (gameplayOneFinished & !hasHadPostGameplayOneMessage) {
				if (abs(playerPos.GetX() - entranceToLearninCenterPos->GetX()) < 2.0f + 2.0f / 1.0f)
					if (abs(playerPos.GetZ() - entranceToLearninCenterPos->GetZ()) < 2.0f + 2.0f / 1.0f) {
						textRenderer->setText("Now the Core is online! Touch it to learn about that part of the engine");
						textRenderer->setY(200);
						textRenderer->setX(5);
						hasHadPostGameplayOneMessage = true;
					}
			}
			if (hasHadPostGameplayOneMessage) {
				if (abs(playerPos.GetX() - firstPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - firstPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(5);
							touchedOncePostGamePlayOne = true;
							if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
								SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
								textRenderer->setY(550);
								textRenderer->setX(10);
								textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
								currentlyLearning = true;
								startGameplayTwo = true;
								gameplayOneCurrentlyHappening = false;
								gameplayOneDead = true;
							}
						}
					}
					else {
						if (touchedOncePostGamePlayOne)
							if (!currentlyLearning)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOncePostGamePlayOne)
						if (!currentlyLearning)
							textRenderer->setText(" ");
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------------GAMEPLAY TWO
	if (!gameplayTwoDead) {
		//printf("***---___InFirst___---***");
		if (startGameplayTwo && !currentlyLearning) {
			//printf("***---___InSeccond___---***");
			if (!pressedSeccondButton) {
				//printf("***---___InThird___---***");
				if (abs(playerPos.GetX() - seccondPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					//printf("***---___InFirst___---***");
					if (abs(playerPos.GetZ() - seccondPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						//printf("***---___InSeccodn___---***");
						    gameplayTwoCurrentlyHappening = true;
							textRenderer->setText("Press 'E'");
							textRenderer->setY(300);
							textRenderer->setX(100);
							touchedOnce2 = true;
							if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
								SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
								//gameplayTwoCurrentlyHappening = true;
								textRenderer->setText("Go collect Energy cube to put this Engine Core online");
								textRenderer->setY(100);
								textRenderer->setX(50);
								engineCore2Renderer->setUseSeccondaryMaterial(true);
								pressedSeccondButton = true;
								energyCubeEntity->GetTransform()->SetPos(Vector3f(5, 3, 5));
								energyCubeRenderer->setDraw(true);
							}
					}
					else {
						if (touchedOnce2)
							if (!pressedSeccondButton)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOnce2)
						if (!pressedSeccondButton)
							textRenderer->setText(" ");
				}
			}
			if (energyCubeRenderer->getDraw() || checkCollisionsWithEnergyComponents) {
				if (!checkCollisionsWithEnergyComponents) {
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Entity->GetTransform()->SetPos(Vector3f(10, 5, 10));
							enemyCube1Renderer->setDraw(true);
							enemyCube2Entity->GetTransform()->SetPos(Vector3f(20, 5, 20));
							enemyCube2Renderer->setDraw(true);
							enemyCube3Entity->GetTransform()->SetPos(Vector3f(30, 5, 30));
							enemyCube3Renderer->setDraw(true);
							enemyCube4Entity->GetTransform()->SetPos(Vector3f(40, 5, 40));
							enemyCube4Renderer->setDraw(true);
							enemyCube5Entity->GetTransform()->SetPos(Vector3f(50, 5, 50));
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime2) {
						textRenderer->setText("Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					//printf("test");
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
							//checkTime = false;
							//textRenderer->setText("Well done, head back to the learning center");
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime2 = false;
						timmer = 1000;
						textRenderer->setText("Well done, head back to the learning center");
						engineCore2Renderer->setUseThirdMaterial(true);
						checkCollisionsWithEnergyComponents = false;
						gameplayTwoFinished = true;
					}
				}
			}
			if (gameplayTwoFinished & !hasHadPostGameplayTwoMessage) {
				if (abs(playerPos.GetX() - entranceToLearninCenterPos->GetX()) < 2.0f + 2.0f / 1.0f)
					if (abs(playerPos.GetZ() - entranceToLearninCenterPos->GetZ()) < 2.0f + 2.0f / 1.0f) {
						textRenderer->setText("Now the Core is online! Touch it to learn about that part of the engine");
						textRenderer->setY(200);
						textRenderer->setX(5);
						hasHadPostGameplayTwoMessage = true;
					}
			}
			if (hasHadPostGameplayTwoMessage) {
				if (abs(playerPos.GetX() - seccondPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - seccondPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(5);
							touchedOncePostGamePlayTwo = true;
						}
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E) && !currentlyLearning) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
							startGameplayThree = true;
							gameplayTwoCurrentlyHappening = false;
							gameplayTwoDead = true;
						}
					}
					else {
						if (touchedOncePostGamePlayTwo)
							if (!currentlyLearning)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOncePostGamePlayTwo)
						if (!currentlyLearning)
							textRenderer->setText(" ");
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------------GAMEPLAY THREE
	if (!gameplayThreeDead) {
		if (startGameplayThree && !currentlyLearning) {
			if (!pressedThirdButton) {
				if (abs(playerPos.GetX() - thirdPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - thirdPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						gameplayThreeCurrentlyHappening = true;
						textRenderer->setText("Press 'E'");
						textRenderer->setY(300);
						textRenderer->setX(100);
						touchedOnce3 = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Go collect Energy cube to put this Engine Core online");
							textRenderer->setY(100);
							textRenderer->setX(50);
							engineCore3Renderer->setUseSeccondaryMaterial(true);
							pressedThirdButton = true;
							energyCubeEntity->GetTransform()->SetPos(Vector3f(15, 5, 15));
							energyCubeRenderer->setDraw(true);
						}
					}
					else {
						if (touchedOnce3)
							if (!pressedThirdButton)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOnce3)
						if (!pressedThirdButton)
							textRenderer->setText(" ");
				}
			}
			if (energyCubeRenderer->getDraw() || checkCollisionsWithEnergyComponents) {
				if (!checkCollisionsWithEnergyComponents) {
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Entity->GetTransform()->SetPos(Vector3f(20, 5, 20));
							enemyCube1Renderer->setDraw(true);
							enemyCube2Entity->GetTransform()->SetPos(Vector3f(30, 5, 30));
							enemyCube2Renderer->setDraw(true);
							enemyCube3Entity->GetTransform()->SetPos(Vector3f(40, 5, 40));
							enemyCube3Renderer->setDraw(true);
							enemyCube4Entity->GetTransform()->SetPos(Vector3f(50, 5, 50));
							enemyCube4Renderer->setDraw(true);
							enemyCube5Entity->GetTransform()->SetPos(Vector3f(60, 5, 60));
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime3) {
						textRenderer->setText("Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime3 = false;
						timmer = 1000;
						textRenderer->setText("Well done, head back to the learning center");
						engineCore3Renderer->setUseThirdMaterial(true);
						checkCollisionsWithEnergyComponents = false;
						gameplayThreeFinished = true;
					}
				}
			}
			if (gameplayThreeFinished & !hasHadPostGameplayThreeMessage) {
				if (abs(playerPos.GetX() - entranceToLearninCenterPos->GetX()) < 2.0f + 2.0f / 1.0f)
					if (abs(playerPos.GetZ() - entranceToLearninCenterPos->GetZ()) < 2.0f + 2.0f / 1.0f) {
						textRenderer->setText("Now the Core is online! Touch it to learn about that part of the engine");
						textRenderer->setY(200);
						textRenderer->setX(5);
						hasHadPostGameplayThreeMessage = true;
					}
			}
			if (hasHadPostGameplayThreeMessage) {
				if (abs(playerPos.GetX() - thirdPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - thirdPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(5);
							touchedOncePostGamePlayThree = true;
						}
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E) && !currentlyLearning) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
							startGameplayFour = true;
							gameplayThreeCurrentlyHappening = false;
							gameplayThreeDead = true;
						}
					}
					else {
						if (touchedOncePostGamePlayThree)
							if (!currentlyLearning)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOncePostGamePlayThree)
						if (!currentlyLearning)
							textRenderer->setText(" ");
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------------GAMEPLAY FOUR
	if (!gameplayFourDead) {
		if (startGameplayFour && !currentlyLearning) {
			if (!pressedFourthButton) {
				if (abs(playerPos.GetX() - fourthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - fourthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						gameplayFourCurrentlyHappening = true;
						textRenderer->setText("Press 'E'");
						textRenderer->setY(300);
						textRenderer->setX(100);
						touchedOnce4 = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Go collect Energy cube to put this Engine Core online");
							textRenderer->setY(100);
							textRenderer->setX(50);
							engineCore4Renderer->setUseSeccondaryMaterial(true);
							pressedFourthButton = true;
							energyCubeEntity->GetTransform()->SetPos(Vector3f(25, 5, 25));
							energyCubeRenderer->setDraw(true);
						}
					}
					else {
						if (touchedOnce4)
							if (!pressedFourthButton)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOnce4)
						if (!pressedFourthButton)
							textRenderer->setText(" ");
				}
			}
			if (energyCubeRenderer->getDraw() || checkCollisionsWithEnergyComponents) {
				if (!checkCollisionsWithEnergyComponents) {
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Entity->GetTransform()->SetPos(Vector3f(30, 5, 30));
							enemyCube1Renderer->setDraw(true);
							enemyCube2Entity->GetTransform()->SetPos(Vector3f(40, 5, 40));
							enemyCube2Renderer->setDraw(true);
							enemyCube3Entity->GetTransform()->SetPos(Vector3f(50, 5, 50));
							enemyCube3Renderer->setDraw(true);
							enemyCube4Entity->GetTransform()->SetPos(Vector3f(60, 5, 60));
							enemyCube4Renderer->setDraw(true);
							enemyCube5Entity->GetTransform()->SetPos(Vector3f(70, 5, 70));
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime4) {
						textRenderer->setText("Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime4 = false;
						timmer = 1000;
						textRenderer->setText("Well done, head back to the learning center");
						engineCore4Renderer->setUseThirdMaterial(true);
						checkCollisionsWithEnergyComponents = false;
						gameplayFourFinished = true;
					}
				}
			}
			if (gameplayFourFinished & !hasHadPostGameplayFourMessage) {
				if (abs(playerPos.GetX() - entranceToLearninCenterPos->GetX()) < 2.0f + 2.0f / 1.0f)
					if (abs(playerPos.GetZ() - entranceToLearninCenterPos->GetZ()) < 2.0f + 2.0f / 1.0f) {
						textRenderer->setText("Now the Core is online! Touch it to learn about that part of the engine");
						textRenderer->setY(200);
						textRenderer->setX(5);
						hasHadPostGameplayFourMessage = true;
					}
			}
			if (hasHadPostGameplayFourMessage) {
				if (abs(playerPos.GetX() - fourthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - fourthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(5);
							touchedOncePostGamePlayFour = true;
						}
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E) && !currentlyLearning) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
							startGameplayFive = true;
							gameplayFourCurrentlyHappening = false;
							gameplayFourDead = true;
						}
					}
					else {
						if (touchedOncePostGamePlayFour)
							if (!currentlyLearning)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOncePostGamePlayFour)
						if (!currentlyLearning)
							textRenderer->setText(" ");
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------------GAMEPLAY FIVE
	if (!gameplayFiveDead) {
		if (startGameplayFive && !currentlyLearning) {
			if (!pressedFifthButton) {
				if (abs(playerPos.GetX() - fifthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - fifthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						gameplayFiveCurrentlyHappening = true;
						textRenderer->setText("Press 'E'");
						textRenderer->setY(300);
						textRenderer->setX(100);
						touchedOnce5 = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Go collect Energy cube to put this Engine Core online");
							textRenderer->setY(100);
							textRenderer->setX(50);
							engineCore5Renderer->setUseSeccondaryMaterial(true);
							pressedFifthButton = true;
							energyCubeEntity->GetTransform()->SetPos(Vector3f(35, 5, 35));
							energyCubeRenderer->setDraw(true);
						}
					}
					else {
						if (touchedOnce5)
							if (!pressedFifthButton)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOnce5)
						if (!pressedFifthButton)
							textRenderer->setText(" ");
				}
			}
			if (energyCubeRenderer->getDraw() || checkCollisionsWithEnergyComponents) {
				if (!checkCollisionsWithEnergyComponents) {
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Entity->GetTransform()->SetPos(Vector3f(40, 5, 40));
							enemyCube1Renderer->setDraw(true);
							enemyCube2Entity->GetTransform()->SetPos(Vector3f(50, 5, 50));
							enemyCube2Renderer->setDraw(true);
							enemyCube3Entity->GetTransform()->SetPos(Vector3f(60, 5, 60));
							enemyCube3Renderer->setDraw(true);
							enemyCube4Entity->GetTransform()->SetPos(Vector3f(70, 5, 70));
							enemyCube4Renderer->setDraw(true);
							enemyCube5Entity->GetTransform()->SetPos(Vector3f(80, 5, 80));
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime5) {
						textRenderer->setText("Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime5 = false;
						timmer = 1000;
						textRenderer->setText("Well done, head back to the learning center");
						engineCore5Renderer->setUseThirdMaterial(true);
						checkCollisionsWithEnergyComponents = false;
						gameplayFiveFinished = true;
					}
				}
			}
			if (gameplayFiveFinished & !hasHadPostGameplayFiveMessage) {
				if (abs(playerPos.GetX() - entranceToLearninCenterPos->GetX()) < 2.0f + 2.0f / 1.0f)
					if (abs(playerPos.GetZ() - entranceToLearninCenterPos->GetZ()) < 2.0f + 2.0f / 1.0f) {
						textRenderer->setText("Now the Core is online! Touch it to learn about that part of the engine");
						textRenderer->setY(200);
						textRenderer->setX(5);
						hasHadPostGameplayFiveMessage = true;
					}
			}
			if (hasHadPostGameplayFiveMessage) {
				if (abs(playerPos.GetX() - fifthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - fifthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(5);
							touchedOncePostGamePlayFive = true;
						}
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E) && !currentlyLearning) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
							startGameplaySix = true;
							gameplayFiveCurrentlyHappening = false;
							gameplayFiveDead = true;
						}
					}
					else {
						if (touchedOncePostGamePlayFive)
							if (!currentlyLearning)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOncePostGamePlayFive)
						if (!currentlyLearning)
							textRenderer->setText(" ");
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------------GAMEPLAY SIX
	if (!gameplaySixDead) {
		if (startGameplaySix && !currentlyLearning) {
			if (!pressedSixthButton) {
				if (abs(playerPos.GetX() - sixthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - sixthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						gameplaySixCurrentlyHappening = true;
						textRenderer->setText("Press 'E'");
						textRenderer->setY(300);
						textRenderer->setX(100);
						touchedOnce6 = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Go collect Energy cube to put this Engine Core online");
							textRenderer->setY(100);
							textRenderer->setX(50);
							engineCore6Renderer->setUseSeccondaryMaterial(true);
							pressedSixthButton = true;
							energyCubeEntity->GetTransform()->SetPos(Vector3f(40, 5, 40));
							energyCubeRenderer->setDraw(true);
						}
					}
					else {
						if (touchedOnce6)
							if (!pressedSixthButton)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOnce6)
						if (!pressedSixthButton)
							textRenderer->setText(" ");
				}
			}
			if (energyCubeRenderer->getDraw() || checkCollisionsWithEnergyComponents) {
				if (!checkCollisionsWithEnergyComponents) {
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Entity->GetTransform()->SetPos(Vector3f(50, 5, 50));
							enemyCube1Renderer->setDraw(true);
							enemyCube2Entity->GetTransform()->SetPos(Vector3f(60, 5, 60));
							enemyCube2Renderer->setDraw(true);
							enemyCube3Entity->GetTransform()->SetPos(Vector3f(70, 5, 70));
							enemyCube3Renderer->setDraw(true);
							enemyCube4Entity->GetTransform()->SetPos(Vector3f(80, 5, 80));
							enemyCube4Renderer->setDraw(true);
							enemyCube5Entity->GetTransform()->SetPos(Vector3f(90, 5, 90));
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime6) {
						textRenderer->setText("Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime6 = false;
						timmer = 1000;
						textRenderer->setText("Well done, head back to the learning center");
						engineCore6Renderer->setUseThirdMaterial(true);
						checkCollisionsWithEnergyComponents = false;
						gameplaySixFinished = true;
					}
				}
			}
			if (gameplaySixFinished & !hasHadPostGameplaySixMessage) {
				if (abs(playerPos.GetX() - entranceToLearninCenterPos->GetX()) < 2.0f + 2.0f / 1.0f)
					if (abs(playerPos.GetZ() - entranceToLearninCenterPos->GetZ()) < 2.0f + 2.0f / 1.0f) {
						textRenderer->setText("Now the Core is online! Touch it to learn about that part of the engine");
						textRenderer->setY(200);
						textRenderer->setX(5);
						hasHadPostGameplaySixMessage = true;
					}
			}
			if (hasHadPostGameplaySixMessage) {
				if (abs(playerPos.GetX() - sixthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - sixthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(5);
							touchedOncePostGamePlaySix = true;
						}
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E) && !currentlyLearning) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
							startGameplaySeven = true;
							gameplaySixCurrentlyHappening = false;
							gameplaySixDead = true;
						}
					}
					else {
						if (touchedOncePostGamePlaySix)
							if (!currentlyLearning)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOncePostGamePlaySix)
						if (!currentlyLearning)
							textRenderer->setText(" ");
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------------GAMEPLAY SEVEN
	if (!gameplaySevenDead) {
		if (startGameplaySeven && !currentlyLearning) {
			if (!pressedSeventhButton) {
				if (abs(playerPos.GetX() - seventhPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - seventhPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						gameplaySevenCurrentlyHappening = true;
						textRenderer->setText("Press 'E'");
						textRenderer->setY(300);
						textRenderer->setX(100);
						touchedOnce7 = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Go collect Energy cube to put this Engine Core online");
							textRenderer->setY(100);
							textRenderer->setX(50);
							engineCore7Renderer->setUseSeccondaryMaterial(true);
							pressedSeventhButton = true;
							energyCubeEntity->GetTransform()->SetPos(Vector3f(55, 5, 55));
							energyCubeRenderer->setDraw(true);
						}
					}
					else {
						if (touchedOnce7)
							if (!pressedSeventhButton)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOnce7)
						if (!pressedSeventhButton)
							textRenderer->setText(" ");
				}
			}
			if (energyCubeRenderer->getDraw() || checkCollisionsWithEnergyComponents) {
				if (!checkCollisionsWithEnergyComponents) {
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Entity->GetTransform()->SetPos(Vector3f(60, 5, 60));
							enemyCube1Renderer->setDraw(true);
							enemyCube2Entity->GetTransform()->SetPos(Vector3f(70, 5, 70));
							enemyCube2Renderer->setDraw(true);
							enemyCube3Entity->GetTransform()->SetPos(Vector3f(80, 5, 80));
							enemyCube3Renderer->setDraw(true);
							enemyCube4Entity->GetTransform()->SetPos(Vector3f(90, 5, 90));
							enemyCube4Renderer->setDraw(true);
							enemyCube5Entity->GetTransform()->SetPos(Vector3f(100, 5, 100));
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime7) {
						textRenderer->setText("Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime7 = false;
						timmer = 1000;
						textRenderer->setText("Well done, head back to the learning center");
						engineCore7Renderer->setUseThirdMaterial(true);
						checkCollisionsWithEnergyComponents = false;
						gameplaySevenFinished = true;
					}
				}
			}
			if (gameplaySevenFinished & !hasHadPostGameplaySevenMessage) {
				if (abs(playerPos.GetX() - entranceToLearninCenterPos->GetX()) < 2.0f + 2.0f / 1.0f)
					if (abs(playerPos.GetZ() - entranceToLearninCenterPos->GetZ()) < 2.0f + 2.0f / 1.0f) {
						textRenderer->setText("Now the Core is online! Touch it to learn about that part of the engine");
						textRenderer->setY(200);
						textRenderer->setX(5);
						hasHadPostGameplaySevenMessage = true;
					}
			}
			if (hasHadPostGameplaySevenMessage) {
				if (abs(playerPos.GetX() - seventhPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - seventhPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(5);
							touchedOncePostGamePlaySeven = true;
						}
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E) && !currentlyLearning) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
							startGameplayEight = true;
							gameplaySevenCurrentlyHappening = false;
							gameplaySevenDead = true;
						}
					}
					else {
						if (touchedOncePostGamePlaySeven)
							if (!currentlyLearning)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOncePostGamePlaySeven)
						if (!currentlyLearning)
							textRenderer->setText(" ");
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------------GAMEPLAY EIGHT
	if (!gameplayEightDead) {
		if (startGameplayEight && !currentlyLearning) {
			if (!pressedEighthButton) {
				if (abs(playerPos.GetX() - eighthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - eighthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						gameplayEightCurrentlyHappening = true;
						textRenderer->setText("Press 'E'");
						textRenderer->setY(300);
						textRenderer->setX(100);
						touchedOnce8 = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Go collect Energy cube to put this Engine Core online");
							textRenderer->setY(100);
							textRenderer->setX(50);
							engineCore8Renderer->setUseSeccondaryMaterial(true);
							pressedEighthButton = true;
							energyCubeEntity->GetTransform()->SetPos(Vector3f(65, 5, 65));
							energyCubeRenderer->setDraw(true);
						}
					}
					else {
						if (touchedOnce8)
							if (!pressedEighthButton)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOnce8)
						if (!pressedEighthButton)
							textRenderer->setText(" ");
				}
			}
			if (energyCubeRenderer->getDraw() || checkCollisionsWithEnergyComponents) {
				if (!checkCollisionsWithEnergyComponents) {
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Entity->GetTransform()->SetPos(Vector3f(70, 5, 70));
							enemyCube1Renderer->setDraw(true);
							enemyCube2Entity->GetTransform()->SetPos(Vector3f(80, 5, 80));
							enemyCube2Renderer->setDraw(true);
							enemyCube3Entity->GetTransform()->SetPos(Vector3f(90, 5, 90));
							enemyCube3Renderer->setDraw(true);
							enemyCube4Entity->GetTransform()->SetPos(Vector3f(100, 5, 100));
							enemyCube4Renderer->setDraw(true);
							enemyCube5Entity->GetTransform()->SetPos(Vector3f(110, 5, 110));
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime8) {
						textRenderer->setText("Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 1.0f + 1.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 1.0f + 1.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime8 = false;
						timmer = 1000;
						textRenderer->setText("Well done, head back to the learning center");
						engineCore8Renderer->setUseThirdMaterial(true);
						checkCollisionsWithEnergyComponents = false;
						gameplayEightFinished = true;
					}
				}
			}
			if (gameplayEightFinished & !hasHadPostGameplayEightMessage) {
				if (abs(playerPos.GetX() - entranceToLearninCenterPos->GetX()) < 2.0f + 2.0f / 1.0f)
					if (abs(playerPos.GetZ() - entranceToLearninCenterPos->GetZ()) < 2.0f + 2.0f / 1.0f) {
						textRenderer->setText("Now the Core is online! Touch it to learn about that part of the engine");
						textRenderer->setY(200);
						textRenderer->setX(5);
						hasHadPostGameplayEightMessage = true;
					}
			}
			if (hasHadPostGameplayEightMessage) {
				if (abs(playerPos.GetX() - eighthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - eighthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(5);
							touchedOncePostGamePlayEight = true;
						}
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E) && !currentlyLearning) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
							gameplayEightCurrentlyHappening = false;
							gameplayEightDead = true;
						}
					}
					else {
						if (touchedOncePostGamePlayEight)
							if (!currentlyLearning)
								textRenderer->setText(" ");
					}
				}
				else {
					if (touchedOncePostGamePlayEight)
						if (!currentlyLearning)
							textRenderer->setText(" ");
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------------GENERIC LOGIC
	if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_R) && currentlyLearning) {
		//textRenderer->setText(" ");
		currentlyLearning = false;
	}
	//GAMEPLAY 1 ENDGAME
	if (hasHadPostGameplayOneMessage && gameplayOneDead) {
		if (!gameplayTwoCurrentlyHappening & !gameplayThreeCurrentlyHappening & !gameplayFourCurrentlyHappening & !gameplayFiveCurrentlyHappening & !gameplaySixCurrentlyHappening & !gameplaySevenCurrentlyHappening & !gameplayEightCurrentlyHappening) {
			if (abs(playerPos.GetX() - firstPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
				if (abs(playerPos.GetZ() - firstPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
					if (!currentlyLearning) {
						currentlyTouchingPannelOne = true;
						textRenderer->setText("Press 'E' to open learning core.");
						textRenderer->setY(300);
						textRenderer->setX(5);
						touchedOncePostGamePlayOne = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
						}
					}
				}
				else {
					currentlyTouchingPannelOne = false;
					if (touchedOncePostGamePlayOne)
						if(!currentlyTouchingPannelTwo & !currentlyTouchingPannelThree & !currentlyTouchingPannelFour & !currentlyTouchingPannelFive & !currentlyTouchingPannelSix & !currentlyTouchingPannelSeven & !currentlyTouchingPannelEight)
							if (!currentlyLearning)
								textRenderer->setText(" ");
				}
			}
			else {
				currentlyTouchingPannelOne = false;
				if (touchedOncePostGamePlayOne)
					if (!currentlyTouchingPannelTwo & !currentlyTouchingPannelThree & !currentlyTouchingPannelFour & !currentlyTouchingPannelFive & !currentlyTouchingPannelSix & !currentlyTouchingPannelSeven & !currentlyTouchingPannelEight)
						if (!currentlyLearning)
							textRenderer->setText(" ");
			}
		}
	}
	//GAMEPLAY 2 ENDGAME
	if (hasHadPostGameplayTwoMessage && gameplayTwoDead) {
		if (!gameplayOneCurrentlyHappening & !gameplayThreeCurrentlyHappening & !gameplayFourCurrentlyHappening & !gameplayFiveCurrentlyHappening & !gameplaySixCurrentlyHappening & !gameplaySevenCurrentlyHappening & !gameplayEightCurrentlyHappening) {
			if (abs(playerPos.GetX() - seccondPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
				if (abs(playerPos.GetZ() - seccondPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
					if (!currentlyLearning) {
						currentlyTouchingPannelTwo = true;
						textRenderer->setText("Press 'E' to open learning core.");
						textRenderer->setY(300);
						textRenderer->setX(5);
						touchedOncePostGamePlayTwo = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
						}
					}
				}
				else {
					currentlyTouchingPannelTwo = false;
					if (touchedOncePostGamePlayTwo)
						if (!currentlyTouchingPannelOne & !currentlyTouchingPannelThree & !currentlyTouchingPannelFour & !currentlyTouchingPannelFive & !currentlyTouchingPannelSix & !currentlyTouchingPannelSeven & !currentlyTouchingPannelEight)
							if (!currentlyLearning)
								textRenderer->setText(" ");
				}
			}
			else {
				currentlyTouchingPannelTwo = false;
				if (touchedOncePostGamePlayTwo)
					if (!currentlyTouchingPannelOne & !currentlyTouchingPannelThree & !currentlyTouchingPannelFour & !currentlyTouchingPannelFive & !currentlyTouchingPannelSix & !currentlyTouchingPannelSeven & !currentlyTouchingPannelEight)
						if (!currentlyLearning)
							textRenderer->setText(" ");
			}
		}
	}
	//GAMEPLAY 3 ENDGAME
	if (hasHadPostGameplayThreeMessage && gameplayThreeDead) {
		if (!gameplayOneCurrentlyHappening & !gameplayTwoCurrentlyHappening & !gameplayFourCurrentlyHappening & !gameplayFiveCurrentlyHappening & !gameplaySixCurrentlyHappening & !gameplaySevenCurrentlyHappening & !gameplayEightCurrentlyHappening) {
			if (abs(playerPos.GetX() - thirdPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
				if (abs(playerPos.GetZ() - thirdPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
					if (!currentlyLearning) {
						currentlyTouchingPannelThree = true;
						textRenderer->setText("Press 'E' to open learning core.");
						textRenderer->setY(300);
						textRenderer->setX(5);
						touchedOncePostGamePlayThree = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
						}
					}
				}
				else {
					currentlyTouchingPannelThree = false;
					if (touchedOncePostGamePlayThree)
						if (!currentlyTouchingPannelOne & !currentlyTouchingPannelTwo & !currentlyTouchingPannelFour & !currentlyTouchingPannelFive & !currentlyTouchingPannelSix & !currentlyTouchingPannelSeven & !currentlyTouchingPannelEight)
							if (!currentlyLearning)
								textRenderer->setText(" ");
				}
			}
			else {
				currentlyTouchingPannelThree = false;
				if (touchedOncePostGamePlayThree)
					if (!currentlyTouchingPannelOne & !currentlyTouchingPannelTwo & !currentlyTouchingPannelFour & !currentlyTouchingPannelFive & !currentlyTouchingPannelSix & !currentlyTouchingPannelSeven & !currentlyTouchingPannelEight)
						if (!currentlyLearning)
							textRenderer->setText(" ");
			}
		}
	}
	//GAMEPLAY 4 ENDGAME
	if (hasHadPostGameplayFourMessage && gameplayFourDead) {
		if (!gameplayOneCurrentlyHappening & !gameplayTwoCurrentlyHappening & !gameplayThreeCurrentlyHappening & !gameplayFiveCurrentlyHappening & !gameplaySixCurrentlyHappening & !gameplaySevenCurrentlyHappening & !gameplayEightCurrentlyHappening) {
			if (abs(playerPos.GetX() - fourthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
				if (abs(playerPos.GetZ() - fourthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
					if (!currentlyLearning) {
						currentlyTouchingPannelFour = true;
						textRenderer->setText("Press 'E' to open learning core.");
						textRenderer->setY(300);
						textRenderer->setX(5);
						touchedOncePostGamePlayFour = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
						}
					}
				}
				else {
					currentlyTouchingPannelFour = false;
					if (touchedOncePostGamePlayFour)
						if (!currentlyTouchingPannelOne & !currentlyTouchingPannelTwo & !currentlyTouchingPannelThree & !currentlyTouchingPannelFive & !currentlyTouchingPannelSix & !currentlyTouchingPannelSeven & !currentlyTouchingPannelEight)
							if (!currentlyLearning)
								textRenderer->setText(" ");
				}
			}
			else {
				currentlyTouchingPannelFour = false;
				if (touchedOncePostGamePlayFour)
					if (!currentlyTouchingPannelOne & !currentlyTouchingPannelTwo & !currentlyTouchingPannelThree & !currentlyTouchingPannelFive & !currentlyTouchingPannelSix & !currentlyTouchingPannelSeven & !currentlyTouchingPannelEight)
						if (!currentlyLearning)
							textRenderer->setText(" ");
			}
		}
	}
	//GAMEPLAY 5 ENDGAME
	if (hasHadPostGameplayFiveMessage && gameplayFiveDead) {
		if (!gameplayOneCurrentlyHappening & !gameplayTwoCurrentlyHappening & !gameplayThreeCurrentlyHappening & !gameplayFourCurrentlyHappening & !gameplaySixCurrentlyHappening & !gameplaySevenCurrentlyHappening & !gameplayEightCurrentlyHappening) {
			if (abs(playerPos.GetX() - fifthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
				if (abs(playerPos.GetZ() - fifthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
					if (!currentlyLearning) {
						currentlyTouchingPannelFive = true;
						textRenderer->setText("Press 'E' to open learning core.");
						textRenderer->setY(300);
						textRenderer->setX(5);
						touchedOncePostGamePlayFive = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
						}
					}
				}
				else {
					currentlyTouchingPannelFive = false;
					if (touchedOncePostGamePlayFive)
						if (!currentlyTouchingPannelOne & !currentlyTouchingPannelTwo & !currentlyTouchingPannelThree & !currentlyTouchingPannelFour & !currentlyTouchingPannelSix & !currentlyTouchingPannelSeven & !currentlyTouchingPannelEight)
							if (!currentlyLearning)
								textRenderer->setText(" ");
				}
			}
			else {
				currentlyTouchingPannelFive = false;
				if (touchedOncePostGamePlayFive)
					if (!currentlyTouchingPannelOne & !currentlyTouchingPannelTwo & !currentlyTouchingPannelThree & !currentlyTouchingPannelFour & !currentlyTouchingPannelSix & !currentlyTouchingPannelSeven & !currentlyTouchingPannelEight)
						if (!currentlyLearning)
							textRenderer->setText(" ");
			}
		}
	}
	//GAMEPLAY 6 ENDGAME
	if (hasHadPostGameplaySixMessage && gameplaySixDead) {
		if (!gameplayOneCurrentlyHappening & !gameplayTwoCurrentlyHappening & !gameplayThreeCurrentlyHappening & !gameplayFourCurrentlyHappening & !gameplayFiveCurrentlyHappening & !gameplaySevenCurrentlyHappening & !gameplayEightCurrentlyHappening) {
			if (abs(playerPos.GetX() - sixthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
				if (abs(playerPos.GetZ() - sixthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
					if (!currentlyLearning) {
						currentlyTouchingPannelSix = true;
						textRenderer->setText("Press 'E' to open learning core.");
						textRenderer->setY(300);
						textRenderer->setX(5);
						touchedOncePostGamePlaySix = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
						}
					}
				}
				else {
					currentlyTouchingPannelSix = false;
					if (touchedOncePostGamePlaySix)
						if (!currentlyTouchingPannelOne & !currentlyTouchingPannelTwo & !currentlyTouchingPannelThree & !currentlyTouchingPannelFour & !currentlyTouchingPannelFive & !currentlyTouchingPannelSeven & !currentlyTouchingPannelEight)
							if (!currentlyLearning)
								textRenderer->setText(" ");
				}
			}
			else {
				currentlyTouchingPannelSix = false;
				if (touchedOncePostGamePlaySix)
					if (!currentlyTouchingPannelOne & !currentlyTouchingPannelTwo & !currentlyTouchingPannelThree & !currentlyTouchingPannelFour & !currentlyTouchingPannelFive & !currentlyTouchingPannelSeven & !currentlyTouchingPannelEight)
						if (!currentlyLearning)
							textRenderer->setText(" ");
			}
		}
	}
	//GAMEPLAY 7 ENDGAME
	if (hasHadPostGameplaySevenMessage && gameplaySevenDead) {
		if (!gameplayOneCurrentlyHappening & !gameplayTwoCurrentlyHappening & !gameplayThreeCurrentlyHappening & !gameplayFourCurrentlyHappening & !gameplayFiveCurrentlyHappening & !gameplaySixCurrentlyHappening & !gameplayEightCurrentlyHappening) {
			if (abs(playerPos.GetX() - seventhPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
				if (abs(playerPos.GetZ() - seventhPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
					if (!currentlyLearning) {
						currentlyTouchingPannelSeven = true;
						textRenderer->setText("Press 'E' to open learning core.");
						textRenderer->setY(300);
						textRenderer->setX(5);
						touchedOncePostGamePlaySeven = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
						}
					}
				}
				else {
					currentlyTouchingPannelSeven = false;
					if (touchedOncePostGamePlaySeven)
						if (!currentlyTouchingPannelOne & !currentlyTouchingPannelTwo & !currentlyTouchingPannelThree & !currentlyTouchingPannelFour & !currentlyTouchingPannelFive & !currentlyTouchingPannelSix & !currentlyTouchingPannelEight)
							if (!currentlyLearning)
								textRenderer->setText(" ");
				}
			}
			else {
				currentlyTouchingPannelSeven = false;
				if (touchedOncePostGamePlaySeven)
					if (!currentlyTouchingPannelOne & !currentlyTouchingPannelTwo & !currentlyTouchingPannelThree & !currentlyTouchingPannelFour & !currentlyTouchingPannelFive & !currentlyTouchingPannelSix & !currentlyTouchingPannelEight)
						if (!currentlyLearning)
							textRenderer->setText(" ");
			}
		}
	}
	//GAMEPLAY 8 ENDGAME
	if (hasHadPostGameplayEightMessage && gameplayEightDead) {
		if (!gameplayOneCurrentlyHappening & !gameplayTwoCurrentlyHappening & !gameplayThreeCurrentlyHappening & !gameplayFourCurrentlyHappening & !gameplayFiveCurrentlyHappening & !gameplaySixCurrentlyHappening & !gameplaySevenCurrentlyHappening) {
			if (abs(playerPos.GetX() - eighthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
				if (abs(playerPos.GetZ() - eighthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
					if (!currentlyLearning) {
						currentlyTouchingPannelEight = true;
						textRenderer->setText("Press 'E' to open learning core.");
						textRenderer->setY(300);
						textRenderer->setX(5);
						touchedOncePostGamePlayEight = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
									                  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff;"
													  "Learning Stuff Learning Stuff Learning Stuff Learning Stuff");
							textRenderer->setY(550);
							textRenderer->setX(10);
							currentlyLearning = true;
						}
					}
				}
				else {
					currentlyTouchingPannelEight = false;
					if (touchedOncePostGamePlayEight)
						if (!currentlyTouchingPannelOne & !currentlyTouchingPannelTwo & !currentlyTouchingPannelThree & !currentlyTouchingPannelFour & !currentlyTouchingPannelFive & !currentlyTouchingPannelSix & !currentlyTouchingPannelSeven)
							if (!currentlyLearning)
								textRenderer->setText(" ");
				}
			}
			else {
				currentlyTouchingPannelEight = false;
				if (touchedOncePostGamePlayEight)
					if (!currentlyTouchingPannelOne & !currentlyTouchingPannelTwo & !currentlyTouchingPannelThree & !currentlyTouchingPannelFour & !currentlyTouchingPannelFive & !currentlyTouchingPannelSix & !currentlyTouchingPannelSeven)
						if (!currentlyLearning)
							textRenderer->setText(" ");
			}
		}
	}
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
	Vector3f playerScale(1.0f, 1.0f, 1.0f);
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
