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
	virtual void checkCollectableHeight(Entity* collectbaleObject);
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

	int timmer = 2000;
	bool checkCollisionsWithEnergyComponents = false;

	bool checkTime = true;
	bool checkTime2 = true;
	bool checkTime3 = true;
	bool checkTime4 = true;
	bool checkTime5 = true;
	bool checkTime6 = true;
	bool checkTime7 = true;
	bool checkTime8 = true;


	bool gameplayOneFinished = false;//test, put back to false
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
	bool startGameplayTwo = false;//test, put back to false
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
	Material yellow("yellow", Texture("yellow.jpg"), 0.0f, 0,
		Texture("yellow.jpg"), Texture("yellow_disp.jpg"), 0.04f, -1.0f);

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
		
	Entity *player = new Entity(Vector3f(575, 0, -575), Quaternion(), 1.0f);
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
	energyCubeEntity = new Entity(Vector3f(125, 0, -335), Quaternion(), 1.0f);//Entity *firstEnergyCubeEntity = new Entity(Vector3f(0, 5, 0), Quaternion(), 1.0f);
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
	Material *energyComponentMaterial = new Material("yellow");
	Mesh *enemyCube1Mesh = new Mesh("energyCore.obj");
	Mesh *enemyCube2Mesh = new Mesh("energyCore.obj");
	Mesh *enemyCube3Mesh = new Mesh("energyCore.obj");
	Mesh *enemyCube4Mesh = new Mesh("energyCore.obj");
	Mesh *enemyCube5Mesh = new Mesh("energyCore.obj");
	enemyCube1Renderer = new MeshRenderer(*enemyCube1Mesh, *energyComponentMaterial);
	enemyCube1Renderer->setDraw(false);
	enemyCube2Renderer = new MeshRenderer(*enemyCube2Mesh, *energyComponentMaterial);
	enemyCube2Renderer->setDraw(false);
	enemyCube3Renderer = new MeshRenderer(*enemyCube3Mesh, *energyComponentMaterial);
	enemyCube3Renderer->setDraw(false);
	enemyCube4Renderer = new MeshRenderer(*enemyCube4Mesh, *energyComponentMaterial);
	enemyCube4Renderer->setDraw(false);
	enemyCube5Renderer = new MeshRenderer(*enemyCube5Mesh, *energyComponentMaterial);
	enemyCube5Renderer->setDraw(false);
	enemyCube1Entity = new Entity(Vector3f(130, 0, -425), Quaternion(), 1.0f);
	enemyCube1Entity->AddComponent(enemyCube1Renderer);
	enemyCube2Entity = new Entity(Vector3f(100, 0, -565), Quaternion(), 1.0f);
	enemyCube2Entity->AddComponent(enemyCube2Renderer);
	enemyCube3Entity = new Entity(Vector3f(-50, 0, -530), Quaternion(), 1.0f);
	enemyCube3Entity->AddComponent(enemyCube3Renderer);
	enemyCube4Entity = new Entity(Vector3f(-250, 0, -525), Quaternion(), 1.0f);
	enemyCube4Entity->AddComponent(enemyCube4Renderer);
	enemyCube5Entity = new Entity(Vector3f(-500, 0, -400), Quaternion(), 1.0f);
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
	textRenderer->setText("Click inside the game window for the game to capture the;"
		                  "focus of your mouse. Use 'W', 'A', 'S', and 'D' keys to move.;"
	                      "OBJECTIVE: Visit the Engine Learning Center");
	textRenderer->setX(10);//19/3/20
	textRenderer->setY(100);//19/3/20
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

void TestGame::checkCollectableHeight(Entity* collectableObject)
{
	Vector3f *testCollectablePos = collectableObject->GetTransform()->GetPos();
	Vector3f collectablePos(testCollectablePos->GetX(), testCollectablePos->GetY() - 1.0f, testCollectablePos->GetZ());
	float terraineHeightAtCollectablePos = meshObjects[0]->newTerrainHeightFuncFloat(collectablePos);
	if (terraineHeightAtCollectablePos == 10000.0f) {
		printf("collectable height not found");
		return;
	}
	else {
		collectableObject->GetTransform()->GetPos()->SetY(terraineHeightAtCollectablePos + 5);
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
		if (abs(playerPos.GetX() - translations[i].x) < 3.0f + 3.0f / 2.0f) 
			if (abs(playerPos.GetZ() - translations[i].z) < 3.0f + 3.0f / 2.0f) {
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
				textRenderer->setText("Welcome to the Engine Learning Center - As you can see;"
									  "on the walls are eight Learning cores, all of which are;"
									  "currently offline. You must enteract with then one by;"
									  "one in a clockwise manner turning them back online to;"
									  "then gain the information thay have stored about the;"
									  "Game Engine.");
				textRenderer->setY(200);
				textRenderer->setX(10);
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
						textRenderer->setX(350);
						touchedOnce = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Go collect Energy cube to put this Engine Core online");
							textRenderer->setY(30);
							textRenderer->setX(45);
							engineCore1Renderer->setUseSeccondaryMaterial(true);
							pressedFirstButton = true;
							checkCollectableHeight(energyCubeEntity);
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
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if(energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							checkCollectableHeight(enemyCube1Entity);
							enemyCube1Renderer->setDraw(true);
							checkCollectableHeight(enemyCube2Entity);
							enemyCube2Renderer->setDraw(true);
							checkCollectableHeight(enemyCube3Entity);
							enemyCube3Renderer->setDraw(true);
							checkCollectableHeight(enemyCube4Entity);
							enemyCube4Renderer->setDraw(true);
							checkCollectableHeight(enemyCube5Entity);
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime) {
						textRenderer->setText("Now collect the energy components - Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					//printf("test");
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if(enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
							//checkTime = false;
							//textRenderer->setText("Well done, head back to the learning center");
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime = false;
						timmer = 2000;
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
						textRenderer->setText("Now the Core is back online! Go up and touch it to learn;"
											  "the information it holds about the engine.");
						textRenderer->setY(60);
						textRenderer->setX(20);
						hasHadPostGameplayOneMessage = true;
					}
			}
			if (hasHadPostGameplayOneMessage) {
				if (abs(playerPos.GetX() - firstPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - firstPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(200);
							touchedOncePostGamePlayOne = true;
							if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
								SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
								textRenderer->setY(550);
								textRenderer->setX(10);
								textRenderer->setText("                   MESH RENDERING SYSTEM                   ;"
									                  "A 'Mesh Renderer' is one type of component that can be     ;"
									                  "added to a game object. The Mesh Renderer holds two        ;"
													  "things, a Texture object and a Mesh object. The Mesh       ;"
													  "object is simply a Mesh, in that it is a collection of     ;"
													  "vertex, texture, normals and tangent coordinates, these    ;"
													  "meshes are typically created and exported from Blender, a  ;"
													  "3D moddeling software. The Texture object simply holds     ;"
													  "data belonging to a specified .png or .jpg file that will  ;"
													  "escentially be stretched over the previously mentioned     ;"
													  "mesh object. Once a Mesh Renderer component has been       ;"
													  "added to a game object, it will be drawn every frame,      ;"
													  "and OpenGL will use all the data from the mesh object      ;"
													  "(its vertices etc.) cobined with the Texture to draw the   ;"
													  "final Mesh Renderer into the world. Examples of mesh       ;"
													  "renderers you can see around you are the                   ;"
													  "Engine learning cernter, the Learning Cores on the walls,  ;"
													  "The Terrain outside allong with all the trees and the water;"
													  "surrounding this island. As a rule of thunb, if you can see;"
													  "it and collide with it, it's a Mesh Renderer.;"
													  "              Press 'R' to close Learning Core              ");
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
							textRenderer->setX(350);
							touchedOnce2 = true;
							if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
								SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
								//gameplayTwoCurrentlyHappening = true;
								textRenderer->setText("Go collect Energy cube to put this Engine Core online");
								textRenderer->setY(30);
								textRenderer->setX(45);
								engineCore2Renderer->setUseSeccondaryMaterial(true);
								pressedSeccondButton = true;
								energyCubeEntity->GetTransform()->SetPos(Vector3f(-275, 0, -200));
								checkCollectableHeight(energyCubeEntity);
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
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Entity->GetTransform()->SetPos(Vector3f(-220, 0, -100));
							checkCollectableHeight(enemyCube1Entity);
							enemyCube1Renderer->setDraw(true);
							enemyCube2Entity->GetTransform()->SetPos(Vector3f(-250, 0, 0));
							checkCollectableHeight(enemyCube2Entity);
							enemyCube2Renderer->setDraw(true);
							enemyCube3Entity->GetTransform()->SetPos(Vector3f(-300, 0, 50));
							checkCollectableHeight(enemyCube3Entity);
							enemyCube3Renderer->setDraw(true);
							enemyCube4Entity->GetTransform()->SetPos(Vector3f(-350, 0, 150));
							checkCollectableHeight(enemyCube4Entity);
							enemyCube4Renderer->setDraw(true);
							enemyCube5Entity->GetTransform()->SetPos(Vector3f(-400, 0, 300));
							checkCollectableHeight(enemyCube5Entity);
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime2) {
						textRenderer->setText("Now collect the energy components - Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					//printf("test");
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
							//checkTime = false;
							//textRenderer->setText("Well done, head back to the learning center");
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime2 = false;
						timmer = 2000;
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
						textRenderer->setText("Now the Core is back online! Go up and touch it to learn;"
							                  "the information it holds about the engine.");
						textRenderer->setY(60);
						textRenderer->setX(20);
						hasHadPostGameplayTwoMessage = true;
					}
			}
			if (hasHadPostGameplayTwoMessage) {
				if (abs(playerPos.GetX() - seccondPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - seccondPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(200);
							touchedOncePostGamePlayTwo = true;
						}
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E) && !currentlyLearning) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                    LIGHTING AND SHADOWS                   ;"
									              "In this game engine there are three types of lights that   ;"
									              "light the game world. The first of which is the directional;"
											      "light, this simulates the sun, it exists as a 3D directional;"
												  "vector that is cast through every point on every mesh in   ;"
												  "the game world, lighting any surfaces it touches. The      ;"
												  "seccond type Of light is our point light, which simulates  ;"
												  "a light bulb, it is behind you in this room. It exists as  ;"
												  "a 3D point in space, from this point is casts rays in all  ;"
											      "directions and lights any surfaces it touches, with the    ;"
												  "light diminishing over distance, unlike the directional    ;"
												  "light. And finally the last light is the ambient light, this;"
												  "is simply a number value that is used to light every object ;"
												  "in the scene by a very small amount, so that if the rays   ;"
												  "cast from the other lights dont reach a point in the world ;"
												  "it atleast is lit by the small ambient light value so that ;"
												  "it is not completely black. Notice that the direction  of  ;"
												  "the directional light (sun) changes every frame to simulate;"
												  "time passing, go look at a trees shadow to see this. Also, ;"
												  "if a ray for anyone of the lights has to pass through an   ;"
								                  "object to reach a point, the engine knows not to light that;"
												  "point, thus creating shadows. Press 'R' to close core;");
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
						textRenderer->setX(350);
						touchedOnce3 = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Go collect Energy cube to put this Engine Core online");
							textRenderer->setY(30);
							textRenderer->setX(45);
							engineCore3Renderer->setUseSeccondaryMaterial(true);
							pressedThirdButton = true;
							energyCubeEntity->GetTransform()->SetPos(Vector3f(-50, 0, 10));
							checkCollectableHeight(energyCubeEntity);
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
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Entity->GetTransform()->SetPos(Vector3f(-100, 0, 150));
							checkCollectableHeight(enemyCube1Entity);
							enemyCube1Renderer->setDraw(true);
							enemyCube2Entity->GetTransform()->SetPos(Vector3f(-150, 0, 250));
							checkCollectableHeight(enemyCube2Entity);
							enemyCube2Renderer->setDraw(true);
							enemyCube3Entity->GetTransform()->SetPos(Vector3f(-155, 0, 350));
							checkCollectableHeight(enemyCube3Entity);
							enemyCube3Renderer->setDraw(true);
							enemyCube4Entity->GetTransform()->SetPos(Vector3f(-150, 0, 450));
							checkCollectableHeight(enemyCube4Entity);
							enemyCube4Renderer->setDraw(true);
							enemyCube5Entity->GetTransform()->SetPos(Vector3f(0, 0, 475));
							checkCollectableHeight(enemyCube5Entity);
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime3) {
						textRenderer->setText("Now collect the energy components - Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime3 = false;
						timmer = 2000;
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
						textRenderer->setText("Now the Core is back online! Go up and touch it to learn;"
							                  "the information it holds about the engine.");
						textRenderer->setY(60);
						textRenderer->setX(20);
						hasHadPostGameplayThreeMessage = true;
					}
			}
			if (hasHadPostGameplayThreeMessage) {
				if (abs(playerPos.GetX() - thirdPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - thirdPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(200);
							touchedOncePostGamePlayThree = true;
						}
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E) && !currentlyLearning) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                  COLLISION DETECTION SYSTEM               ;"
									              "There are 5 things in total in this game world you can     ;"
									              "collide with, the terrain, the trees, the Engine Learning  ;"
												  "Center, the Learning Cores on the wall, and finally the    ;"
												  "collectable items such as the energy cubes and their       ;"
												  "energy cores. In the case of the terrain, the engine stores;"
												  "every vertex of its mesh and checks every frame if the     ;"
												  "players X and Z position collides with one the vertices X  ;"
												  "and Z position, if so the players Y (height) position      ;"
												  "becomes that vertices Y (height) position. This allows you ;"
												  "to traverse around the world up and down the hills and     ;"
												  "have the appropriate height value while doing so based on  ;"
												  "the ground of the terrain you are currently standing on.   ;"
												  "In the case of the Engine Learning Center walls, trees,    ;"
												  "Learning Cores and the collectable items, the engine has   ;"
												  "the position and scale value of each in 3D space and each  ;"
												  "frame checks to see if the players current position and    ;"
												  "scale values in 3D space is touching them, if so engine    ;"
												  "stops the players movement, or in the case of the Learning ;"
												  "Cores allows the user to press the interact button.        ;"
												  "               Press 'R' to close learning Core             ");
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
						textRenderer->setX(350);
						touchedOnce4 = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Go collect Energy cube to put this Engine Core online");
							textRenderer->setY(30);
							textRenderer->setX(45);
							engineCore4Renderer->setUseSeccondaryMaterial(true);
							pressedFourthButton = true;
							energyCubeEntity->GetTransform()->SetPos(Vector3f(50, 0, 450));
							checkCollectableHeight(energyCubeEntity);
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
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Entity->GetTransform()->SetPos(Vector3f(50, 0, 400));
							checkCollectableHeight(enemyCube1Entity);
							enemyCube1Renderer->setDraw(true);
							enemyCube2Entity->GetTransform()->SetPos(Vector3f(75, 0, 300));
							checkCollectableHeight(enemyCube2Entity);
							enemyCube2Renderer->setDraw(true);
							enemyCube3Entity->GetTransform()->SetPos(Vector3f(100, 0, 200));
							checkCollectableHeight(enemyCube3Entity);
							enemyCube3Renderer->setDraw(true);
							enemyCube4Entity->GetTransform()->SetPos(Vector3f(0, 0, 200));
							checkCollectableHeight(enemyCube4Entity);
							enemyCube4Renderer->setDraw(true);
							enemyCube5Entity->GetTransform()->SetPos(Vector3f(-100, 0, 150));
							checkCollectableHeight(enemyCube5Entity);
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime4) {
						textRenderer->setText("Now collect the energy components - Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime4 = false;
						timmer = 2000;
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
						textRenderer->setText("Now the Core is back online! Go up and touch it to learn;"
							                  "the information it holds about the engine.");
						textRenderer->setY(60);
						textRenderer->setX(20);
						hasHadPostGameplayFourMessage = true;
					}
			}
			if (hasHadPostGameplayFourMessage) {
				if (abs(playerPos.GetX() - fourthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - fourthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(200);
							touchedOncePostGamePlayFour = true;
						}
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E) && !currentlyLearning) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                   Text Rendering System                   ;"
									              "This engine uses the 'FreeType' library to help with       ;"
									              "rendering text to the screen as OpenGL (the library this   ;"
												  "engine uses for graphics rendering) does not directly      ;"
												  "support the rendering of glyphs (letters and symbols) to   ;"
												  "the screen. Simply put, this engine has a 'Text Renderer'  ;"
												  "object that is added to the scene, this object consists of ;"
												  "a 2D point in space (so that it is stuck flat to the       ;"
											      "players screen) and a string of text, you are reading the  ;"
												  "Text Renderer object right now! The FreeType library loads ;"
												  "all the glyphs of a chosen font and then renders them onto ;"
												  "quads that OpenGL can then draw, the quads enable 'blend'  ;"
												  "so that when the drawing is complete only the letters are  ;"
												  "visiable, thus allowing you to read this text.             ;"
												  "This Text Renderer object is the only one in the engine    ;"
												  "and will have its position and string of text changed      ;"
												  "depending on actions from the player.                      ;"
												  "Go ahead and press the 'R' key to watch the Text Renderer  ;"
												  "object change its position and string of text in real time!;"
												  "                                                           ;"
												  "              Press 'R' to close Learning Core              ");
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
						textRenderer->setX(350);
						touchedOnce5 = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Go collect Energy cube to put this Engine Core online");
							textRenderer->setY(30);
							textRenderer->setX(45);
							engineCore5Renderer->setUseSeccondaryMaterial(true);
							pressedFifthButton = true;
							energyCubeEntity->GetTransform()->SetPos(Vector3f(400, 0, 100));
							checkCollectableHeight(energyCubeEntity);
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
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Entity->GetTransform()->SetPos(Vector3f(475, 0, 0));
							checkCollectableHeight(enemyCube1Entity);
							enemyCube1Renderer->setDraw(true);
							enemyCube2Entity->GetTransform()->SetPos(Vector3f(475, 0, -100));
							checkCollectableHeight(enemyCube2Entity);
							enemyCube2Renderer->setDraw(true);
							enemyCube3Entity->GetTransform()->SetPos(Vector3f(475, 0, -200));
							checkCollectableHeight(enemyCube3Entity);
							enemyCube3Renderer->setDraw(true);
							enemyCube4Entity->GetTransform()->SetPos(Vector3f(475, 0, -300));
							checkCollectableHeight(enemyCube4Entity);
							enemyCube4Renderer->setDraw(true);
							enemyCube5Entity->GetTransform()->SetPos(Vector3f(400, 0, -390));
							checkCollectableHeight(enemyCube5Entity);
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime5) {
						textRenderer->setText("Now collect the energy components - Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime5 = false;
						timmer = 2000;
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
						textRenderer->setText("Now the Core is back online! Go up and touch it to learn;"
							                  "the information it holds about the engine.");
						textRenderer->setY(60);
						textRenderer->setX(20);
						hasHadPostGameplayFiveMessage = true;
					}
			}
			if (hasHadPostGameplayFiveMessage) {
				if (abs(playerPos.GetX() - fifthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - fifthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(200);
							touchedOncePostGamePlayFive = true;
						}
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E) && !currentlyLearning) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                     USER INPUT SYSTEM                     ;"
									              "This engine has a 'Input' object, this object holds all    ;"
									              "the key bindings of the standard computer keyboard. This   ;"
												  "object also holds a list of all the keys that are being    ;"
												  "pressed and another list of all the keys that have been    ;"
												  "released, it also has functions that can query all of this ;"
												  "information. Therefore this engine has a simple way to see ;"
												  "if a button is currently being pressed, what exactly the   ;"
												  "button is and what should happen as a result.              ;"
												  "This input object also tracks the players                  ;"
												  "mouse and will update the players cameras pitch and yaw    ;"
												  "values appropriately.                                      ;"
												  "                                                           ;"
												  "It is this simple Input object and the other game objects  ;"
												  "that query against it that make it possible for the engine ;"
												  "to react when you press a button. This logic allows the    ;"
												  "player to move and look around the world freely, and       ;"
												  "interact with the Learning Cores.                          ;"
												  "                                                           ;"
												  "                                                           ;"
												  "              Press 'R' to close Learning Core              ");
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
						textRenderer->setX(350);
						touchedOnce6 = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Go collect Energy cube to put this Engine Core online");
							textRenderer->setY(30);
							textRenderer->setX(45);
							engineCore6Renderer->setUseSeccondaryMaterial(true);
							pressedSixthButton = true;
							energyCubeEntity->GetTransform()->SetPos(Vector3f(-575, 0, -575));
							checkCollectableHeight(energyCubeEntity);
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
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Entity->GetTransform()->SetPos(Vector3f(-595, 0, -475));
							checkCollectableHeight(enemyCube1Entity);
							enemyCube1Renderer->setDraw(true);
							enemyCube2Entity->GetTransform()->SetPos(Vector3f(-595, 0, -275));
							checkCollectableHeight(enemyCube2Entity);
							enemyCube2Renderer->setDraw(true);
							enemyCube3Entity->GetTransform()->SetPos(Vector3f(-575, 0, -75));
							checkCollectableHeight(enemyCube3Entity);
							enemyCube3Renderer->setDraw(true);
							enemyCube4Entity->GetTransform()->SetPos(Vector3f(-475, 0, 75));
							checkCollectableHeight(enemyCube4Entity);
							enemyCube4Renderer->setDraw(true);
							enemyCube5Entity->GetTransform()->SetPos(Vector3f(-375, 0, 175));
							checkCollectableHeight(enemyCube5Entity);
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime6) {
						textRenderer->setText("Now collect the energy components - Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime6 = false;
						timmer = 2000;
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
						textRenderer->setText("Now the Core is back online! Go up and touch it to learn;"
							                  "the information it holds about the engine.");
						textRenderer->setY(60);
						textRenderer->setX(20);
						hasHadPostGameplaySixMessage = true;
					}
			}
			if (hasHadPostGameplaySixMessage) {
				if (abs(playerPos.GetX() - sixthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - sixthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(200);
							touchedOncePostGamePlaySix = true;
						}
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E) && !currentlyLearning) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                        AUDIO SYSTEM                       ;"
									              "Much like the Text Rendering system, Audio is not directly ;"
									              "supported by OpenGL. Therefore this engine uses a library  ;"
												  "called 'IrrKlang'. This library is very easy to use, to    ;"
												  "start with this engine creates a 'Sound Engine' object from;"
												  "the IrrKlang library, then the engine when it's initialized;"
												  "tells this new Sound Engine object to play our background  ;"
												  "music on an infinite loop at a specified volume.           ;"
												  "                                                           ;"
												  "This same Sound Engine object is once again told to play   ;"
												  "audio (not on a loop) when certain things in the game      ;"
												  "happen, for example, when activating and enteracting with  ;"
												  "the Learning Cores, collecting the energy cubes and each of;"
												  "their energy components the Sound Engine object will play  ;"
												  "different audio scores.                                    ;"
												  "                                                           ;"
												  "Using IrrKlang, the addition of audio into this engine is  ;"
												  "easy. Audio is very important in an engine as it makes the ;"
												  "game world come alive and create a more enjoyable and      ;"
												  "immersive experience for the player.                       ;"
												  "            Press 'R' to close the Learning Core           ");
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
						textRenderer->setX(350);
						touchedOnce7 = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Go collect Energy cube to put this Engine Core online");
							textRenderer->setY(30);
							textRenderer->setX(45);
							engineCore7Renderer->setUseSeccondaryMaterial(true);
							pressedSeventhButton = true;
							energyCubeEntity->GetTransform()->SetPos(Vector3f(600, 0, 600));
							checkCollectableHeight(energyCubeEntity);
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
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Entity->GetTransform()->SetPos(Vector3f(400, 0, 575));
							checkCollectableHeight(enemyCube1Entity);
							enemyCube1Renderer->setDraw(true);
							enemyCube2Entity->GetTransform()->SetPos(Vector3f(200, 0, 575));
							checkCollectableHeight(enemyCube2Entity);
							enemyCube2Renderer->setDraw(true);
							enemyCube3Entity->GetTransform()->SetPos(Vector3f(0, 0, 575));
							checkCollectableHeight(enemyCube3Entity);
							enemyCube3Renderer->setDraw(true);
							enemyCube4Entity->GetTransform()->SetPos(Vector3f(-200, 0, 500));
							checkCollectableHeight(enemyCube4Entity);
							enemyCube4Renderer->setDraw(true);
							enemyCube5Entity->GetTransform()->SetPos(Vector3f(-400, 0, 400));
							checkCollectableHeight(enemyCube5Entity);
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime7) {
						textRenderer->setText("Now collect the energy components - Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime7 = false;
						timmer = 2000;
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
						textRenderer->setText("Now the Core is back online! Go up and touch it to learn;"
							                  "the information it holds about the engine.");
						textRenderer->setY(60);
						textRenderer->setX(20);
						hasHadPostGameplaySevenMessage = true;
					}
			}
			if (hasHadPostGameplaySevenMessage) {
				if (abs(playerPos.GetX() - seventhPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - seventhPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(200);
							touchedOncePostGamePlaySeven = true;
						}
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E) && !currentlyLearning) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                     THE PLAYER OBJECT                     ;"
									              "You are the Player Object! you are one of the many objects ;"
									              "added into the game world. Much like the Mesh Renderer     ;"
												  "object that had two components (Mesh & Texture) the        ;"
												  "player object is also made up of different components.     ;"
												  "Three components in total make up the player object, a     ;"
												  "'FreeMove' component, 'FreeLook' component and a 'Camera'  ;"
												  "component. The FreeMove component interacts with the       ;"
												  "Input object and detects when the user presses any of the  ;"
												  "W,A,S or D keys and moves the game world in the oposite    ;"
												  "direction, this simulates that the player is moving in the ;"
												  "world. The FreeLook component similarly interacts with the ;"
												  "Input object to detect when the user moves the mouse and   ;"
												  "in response update the cameras pitch and yaw values.       ;"
												  "And finally the camera component shows the player the      ;"
												  "world through its viewport, this view port is moved by the ;"
												  "FreeMove component and the view ports pitch&yaw values     ;"
												  "are changed by the FreeLook component. All together these  ;"
												  "three components allow the Player Object to move and look  ;"
												  "around the game world freely.                              ;"
												  "            Press 'R' to close the learning core            ");
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
						textRenderer->setX(350);
						touchedOnce8 = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("Go collect Energy cube to put this Engine Core online");
							textRenderer->setY(30);
							textRenderer->setX(45);
							engineCore8Renderer->setUseSeccondaryMaterial(true);
							pressedEighthButton = true;
							energyCubeEntity->GetTransform()->SetPos(Vector3f(360, 0, 380));
							checkCollectableHeight(energyCubeEntity);
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
					if (abs(playerPos.GetX() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)
						if (abs(playerPos.GetZ() - energyCubeRenderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (energyCubeRenderer->getDraw())
								SoundEngine->play2D("../res/music/bleep.mp3", GL_FALSE);//AUDIO
							energyCubeRenderer->setDraw(false);
							enemyCube1Entity->GetTransform()->SetPos(Vector3f(200, 0, 200));
							checkCollectableHeight(enemyCube1Entity);
							enemyCube1Renderer->setDraw(true);
							enemyCube2Entity->GetTransform()->SetPos(Vector3f(100, 0, 100));
							checkCollectableHeight(enemyCube2Entity);
							enemyCube2Renderer->setDraw(true);
							enemyCube3Entity->GetTransform()->SetPos(Vector3f(0, 0, -100));
							checkCollectableHeight(enemyCube3Entity);
							enemyCube3Renderer->setDraw(true);
							enemyCube4Entity->GetTransform()->SetPos(Vector3f(-100, 0, -300));
							checkCollectableHeight(enemyCube4Entity);
							enemyCube4Renderer->setDraw(true);
							enemyCube5Entity->GetTransform()->SetPos(Vector3f(-200, 0, -400));
							checkCollectableHeight(enemyCube5Entity);
							enemyCube5Renderer->setDraw(true);
							checkCollisionsWithEnergyComponents = true;
						}
				}
				if (checkCollisionsWithEnergyComponents) {
					if (checkTime8) {
						textRenderer->setText("Now collect the energy components - Time Left: " + std::to_string(timmer));
						--timmer;
						if (timmer <= 0)
							exit(0);
					}
					if (abs(playerPos.GetX() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube1
						if (abs(playerPos.GetZ() - enemyCube1Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube1Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube1Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube2
						if (abs(playerPos.GetZ() - enemyCube2Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube2Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube2Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube3
						if (abs(playerPos.GetZ() - enemyCube3Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube3Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube3Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube4
						if (abs(playerPos.GetZ() - enemyCube4Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube4Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube4Renderer->setDraw(false);
						}
					if (abs(playerPos.GetX() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetX()) < 2.0f + 2.0f / 1.0f)//cube5
						if (abs(playerPos.GetZ() - enemyCube5Renderer->GetParent()->GetTransform()->GetPos()->GetZ()) < 2.0f + 2.0f / 1.0f) {
							if (enemyCube5Renderer->getDraw())
								SoundEngine->play2D("../res/music/powerup.wav", GL_FALSE);//AUDIO
							enemyCube5Renderer->setDraw(false);
						}
					if (!enemyCube1Renderer->getDraw() & !enemyCube2Renderer->getDraw() & !enemyCube3Renderer->getDraw() & !enemyCube4Renderer->getDraw() & !enemyCube5Renderer->getDraw()) {
						checkTime8 = false;
						timmer = 2000;
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
						textRenderer->setText("Now the Core is back online! Go up and touch it to learn;"
							                  "the information it holds about the engine.");
						textRenderer->setY(60);
						textRenderer->setX(20);
						hasHadPostGameplayEightMessage = true;
					}
			}
			if (hasHadPostGameplayEightMessage) {
				if (abs(playerPos.GetX() - eighthPannelPos.GetX()) < 1.0f + 3.0f / 1.0f) {
					if (abs(playerPos.GetZ() - eighthPannelPos.GetZ()) < 1.0f + 3.0f / 1.0f) {
						if (!currentlyLearning) {
							textRenderer->setText("Press 'E' to open learning core.");
							textRenderer->setY(300);
							textRenderer->setX(200);
							touchedOncePostGamePlayEight = true;
						}
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E) && !currentlyLearning) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                  HOW IT ALL FITS TOGETHER                 ;"
									              "You have just learned about some of the key things in the  ;"
									              "world around you, but how does it all fit together? Well,  ;"
												  "the game world is a 'scene' in the engine, this scene has  ;"
												  "Game Objects added into it (drawn in it), and each of these;"
												  "Game Objects has one or more Game Components. So, this     ;"
												  "game world (scene) has Mesh Renderers added to it          ;"
												  "(the terrain, water, trees, Learning Center, Learning      ;"
												  "Cores, and all the collectables), Lighting has been added  ;"
												  "into our scene (directional light, point light and ambient ;"
												  "light) that in turn create shadows. The collision detection;"
												  "system ensures that the player collides with all the things;"
												  "in the scene as desired, the Text Rendering object guides  ;"
												  "the player through the world and acts as the narrative and ;"
												  "the Input system detects any buttons or mouses touched     ;"
												  "by the player and acts acordingly when done so. The Audio  ;"
												  "system plays background music and tones when the user      ;"
												  "interacts with the world. Finally the player object moves  ;"
												  "and looks around the world with the goal of hopefully      ;"
												  "learning something about Game Engine Design!               ;"
												  "              Press 'R' to close Learning Core              ");
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
						textRenderer->setX(200);
						touchedOncePostGamePlayOne = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                   MESH RENDERING SYSTEM                   ;"
									                  "A 'Mesh Renderer' is one type of component that can be     ;"
									                  "added to a game object. The Mesh Renderer holds two        ;"
													  "things, a Texture object and a Mesh object. The Mesh       ;"
													  "object is simply a Mesh, in that it is a collection of     ;"
													  "vertex, texture, normals and tangent coordinates, these    ;"
													  "meshes are typically created and exported from Blender, a  ;"
													  "3D moddeling software. The Texture object simply holds     ;"
													  "data belonging to a specified .png or .jpg file that will  ;"
													  "escentially be stretched over the previously mentioned     ;"
													  "mesh object. Once a Mesh Renderer component has been       ;"
													  "added to a game object, it will be drawn every frame,      ;"
													  "and OpenGL will use all the data from the mesh object      ;"
													  "(its vertices etc.) cobined with the Texture to draw the   ;"
													  "final Mesh Renderer into the world. Examples of mesh       ;"
													  "renderers you can see around you are the                   ;"
													  "Engine learning cernter, the Learning Cores on the walls,  ;"
													  "The Terrain outside allong with all the trees and the water;"
													  "surrounding this island. As a rule of thunb, if you can see;"
													  "it and collide with it, it's a Mesh Renderer.;"
								                      "              Press 'R' to close Learning Core              ");
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
						textRenderer->setX(200);
						touchedOncePostGamePlayTwo = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                    LIGHTING AND SHADOWS                   ;"
									              "In this game engine there are three types of lights that   ;"
									              "light the game world. The first of which is the directional;"
											      "light, this simulates the sun, it exists as a 3D directional;"
												  "vector that is cast through every point on every mesh in   ;"
												  "the game world, lighting any surfaces it touches. The      ;"
												  "seccond type Of light is our point light, which simulates  ;"
												  "a light bulb, it is behind you in this room. It exists as  ;"
												  "a 3D point in space, from this point is casts rays in all  ;"
											      "directions and lights any surfaces it touches, with the    ;"
												  "light diminishing over distance, unlike the directional    ;"
												  "light. And finally the last light is the ambient light, this;"
												  "is simply a number value that is used to light every object ;"
												  "in the scene by a very small amount, so that if the rays   ;"
												  "cast from the other lights dont reach a point in the world ;"
												  "it atleast is lit by the small ambient light value so that ;"
												  "it is not completely black. Notice that the direction  of  ;"
												  "the directional light (sun) changes every frame to simulate;"
												  "time passing, go look at a trees shadow to see this. Also, ;"
												  "if a ray for anyone of the lights has to pass through an   ;"
								                  "object to reach a point, the engine knows not to light that;"
								                  "point, thus creating shadows. Press 'R' to close core;");
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
						textRenderer->setX(200);
						touchedOncePostGamePlayThree = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                  COLLISION DETECTION SYSTEM               ;"
									              "There are 5 things in total in this game world you can     ;"
									              "collide with, the terrain, the trees, the Engine Learning  ;"
												  "Center, the Learning Cores on the wall, and finally the    ;"
												  "collectable items such as the energy cubes and their       ;"
												  "energy cores. In the case of the terrain, the engine stores;"
												  "every vertex of its mesh and checks every frame if the     ;"
												  "players X and Z position collides with one the vertices X  ;"
												  "and Z position, if so the players Y (height) position      ;"
												  "becomes that vertices Y (height) position. This allows you ;"
												  "to traverse around the world up and down the hills and     ;"
												  "have the appropriate height value while doing so based on  ;"
												  "the ground of the terrain you are currently standing on.   ;"
												  "In the case of the Engine Learning Center walls, trees,    ;"
												  "Learning Cores and the collectable items, the engine has   ;"
												  "the position and scale value of each in 3D space and each  ;"
												  "frame checks to see if the players current position and    ;"
												  "scale values in 3D space is touching them, if so engine    ;"
												  "stops the players movement, or in the case of the Learning ;"
												  "Cores allows the user to press the interact button.        ;"
								                  "               Press 'R' to close learning Core             ");
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
						textRenderer->setX(200);
						touchedOncePostGamePlayFour = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                   Text Rendering System                   ;"
									              "This engine uses the 'FreeType' library to help with       ;"
									              "rendering text to the screen as OpenGL (the library this   ;"
												  "engine uses for graphics rendering) does not directly      ;"
												  "support the rendering of glyphs (letters and symbols) to   ;"
												  "the screen. Simply put, this engine has a 'Text Renderer'  ;"
												  "object that is added to the scene, this object consists of ;"
												  "a 2D point in space (so that it is stuck flat to the       ;"
											      "players screen) and a string of text, you are reading the  ;"
												  "Text Renderer object right now! The FreeType library loads ;"
												  "all the glyphs of a chosen font and then renders them onto ;"
												  "quads that OpenGL can then draw, the quads enable 'blend'  ;"
												  "so that when the drawing is complete only the letters are  ;"
												  "visiable, thus allowing you to read this text.             ;"
												  "This Text Renderer object is the only one in the engine    ;"
												  "and will have its position and string of text changed      ;"
												  "depending on actions from the player.                      ;"
												  "Go ahead and press the 'R' key to watch the Text Renderer  ;"
												  "object change its position and string of text in real time!;"
												  "                                                           ;"
								                  "              Press 'R' to close Learning Core              ");
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
						textRenderer->setX(200);
						touchedOncePostGamePlayFive = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                     USER INPUT SYSTEM                     ;"
									              "This engine has a 'Input' object, this object holds all    ;"
									              "the key bindings of the standard computer keyboard. This   ;"
												  "object also holds a list of all the keys that are being    ;"
												  "pressed and another list of all the keys that have been    ;"
												  "released, it also has functions that can query all of this ;"
												  "information. Therefore this engine has a simple way to see ;"
												  "if a button is currently being pressed, what exactly the   ;"
												  "button is and what should happen as a result.              ;"
												  "This input object also tracks the players                  ;"
												  "mouse and will update the players cameras pitch and yaw    ;"
												  "values appropriately.                                      ;"
												  "                                                           ;"
												  "It is this simple Input object and the other game objects  ;"
												  "that query against it that make it possible for the engine ;"
												  "to react when you press a button. This logic allows the    ;"
												  "player to move and look around the world freely, and       ;"
												  "interact with the Learning Cores.                          ;"
												  "                                                           ;"
												  "                                                           ;"
								                  "              Press 'R' to close Learning Core              ");
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
						textRenderer->setX(200);
						touchedOncePostGamePlaySix = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                        AUDIO SYSTEM                       ;"
									              "Much like the Text Rendering system, Audio is not directly ;"
									              "supported by OpenGL. Therefore this engine uses a library  ;"
												  "called 'IrrKlang'. This library is very easy to use, to    ;"
												  "start with this engine creates a 'Sound Engine' object from;"
												  "the IrrKlang library, then the engine when it's initialized;"
												  "tells this new Sound Engine object to play our background  ;"
												  "music on an infinite loop at a specified volume.           ;"
												  "                                                           ;"
												  "This same Sound Engine object is once again told to play   ;"
												  "audio (not on a loop) when certain things in the game      ;"
												  "happen, for example, when activating and enteracting with  ;"
												  "the Learning Cores, collecting the energy cubes and each of;"
												  "their energy components the Sound Engine object will play  ;"
												  "different audio scores.                                    ;"
												  "                                                           ;"
												  "Using IrrKlang, the addition of audio into this engine is  ;"
												  "easy. Audio is very important in an engine as it makes the ;"
												  "game world come alive and create a more enjoyable and      ;"
												  "immersive experience for the player.                       ;"
								                  "            Press 'R' to close the Learning Core           ");
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
						textRenderer->setX(200);
						touchedOncePostGamePlaySeven = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                     THE PLAYER OBJECT                     ;"
									              "You are the Player Object! you are one of the many objects ;"
									              "added into the game world. Much like the Mesh Renderer     ;"
												  "object that had two components (Mesh & Texture) the        ;"
												  "player object is also made up of different components.     ;"
												  "Three components in total make up the player object, a     ;"
												  "'FreeMove' component, 'FreeLook' component and a 'Camera'  ;"
												  "component. The FreeMove component interacts with the       ;"
												  "Input object and detects when the user presses any of the  ;"
												  "W,A,S or D keys and moves the game world in the oposite    ;"
												  "direction, this simulates that the player is moving in the ;"
												  "world. The FreeLook component similarly interacts with the ;"
												  "Input object to detect when the user moves the mouse and   ;"
												  "in response update the cameras pitch and yaw values.       ;"
												  "And finally the camera component shows the player the      ;"
												  "world through its viewport, this view port is moved by the ;"
												  "FreeMove component and the view ports pitch&yaw values     ;"
												  "are changed by the FreeLook component. All together these  ;"
												  "three components allow the Player Object to move and look  ;"
												  "around the game world freely.                              ;"
								                  "            Press 'R' to close the learning core            ");
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
						textRenderer->setX(200);
						touchedOncePostGamePlayEight = true;
						if (freeMoveObjects[0]->GetParent()->GetEngine()->GetWindow()->GetInput().GetKey(Input::KEY_E)) {
							SoundEngine->play2D("../res/music/bleep.wav", GL_FALSE);//AUDIO
							textRenderer->setText("                  HOW IT ALL FITS TOGETHER                 ;"
									              "You have just learned about some of the key things in the  ;"
									              "world around you, but how does it all fit together? Well,  ;"
												  "the game world is a 'scene' in the engine, this scene has  ;"
												  "Game Objects added into it (drawn in it), and each of these;"
												  "Game Objects has one or more Game Components. So, this     ;"
												  "game world (scene) has Mesh Renderers added to it          ;"
												  "(the terrain, water, trees, Learning Center, Learning      ;"
												  "Cores, and all the collectables), Lighting has been added  ;"
												  "into our scene (directional light, point light and ambient ;"
												  "light) that in turn create shadows. The collision detection;"
												  "system ensures that the player collides with all the things;"
												  "in the scene as desired, the Text Rendering object guides  ;"
												  "the player through the world and acts as the narrative and ;"
												  "the Input system detects any buttons or mouses touched     ;"
												  "by the player and acts acordingly when done so. The Audio  ;"
												  "system plays background music and tones when the user      ;"
												  "interacts with the world. Finally the player object moves  ;"
												  "and looks around the world with the goal of hopefully      ;"
												  "learning something about Game Engine Design!               ;"
								                  "              Press 'R' to close Learning Core              ");
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
