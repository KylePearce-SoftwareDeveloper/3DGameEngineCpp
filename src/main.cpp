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
//#include <ft2build.h>//10/3/20 - HUD
//#include FT_FREETYPE_H//10/3/20 - HUD

//10/3/20 - HUD
//struct Character {
//	GLuint     TextureID;  // ID handle of the glyph texture
//	glm::ivec2 Size;       // Size of glyph
//	glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
//	GLuint     Advance;    // Offset to advance to next glyph
//};
//std::map<GLchar, Character> Characters;

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
	//virtual void renderText();//11/3/20
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
	//TextRenderer  *Text;//11/3/20
	//std::vector<TextRenderer*> textRendererObjects;//11/3/20
};

void TestGame::Init(const Window& window)
{
	//10/3/20 - HUD ------------------------------------------------------------------------------------------------------------------------------------------
	//FT_Library ft;
	//if (FT_Init_FreeType(&ft))
	//	printf("ERROR::FREETYPE: Could not init FreeType Library\n");//std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

	//FT_Face face;
	//if (FT_New_Face(ft, "font/arial.ttf", 0, &face))
	//	printf("ERROR::FREETYPE: Failed to load font\n");//std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

	//FT_Set_Pixel_Sizes(face, 0, 48);

	//if (FT_Load_Char(face, 'X', FT_LOAD_RENDER))
	//	printf("ERROR::FREETYTPE: Failed to load Glyph\n");//std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;

	//glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Disable byte-alignment restriction

	//for (GLubyte c = 0; c < 128; c++)
	//{
	//	// Load character glyph 
	//	if (FT_Load_Char(face, c, FT_LOAD_RENDER))
	//	{
	//		printf("ERROR::FREETYTPE: Failed to load Glyph\n");//std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
	//		continue;
	//	}
	//	// Generate texture
	//	GLuint texture;
	//	glGenTextures(1, &texture);
	//	glBindTexture(GL_TEXTURE_2D, texture);
	//	glTexImage2D(
	//		GL_TEXTURE_2D,
	//		0,
	//		GL_RED,
	//		face->glyph->bitmap.width,
	//		face->glyph->bitmap.rows,
	//		0,
	//		GL_RED,
	//		GL_UNSIGNED_BYTE,
	//		face->glyph->bitmap.buffer
	//	);
	//	// Set texture options
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//	// Now store character for later use
	//	Character character = {
	//		texture,
	//		glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
	//		glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
	//		face->glyph->advance.x
	//	};
	//	Characters.insert(std::pair<GLchar, Character>(c, character));
	//}
	//FT_Done_Face(face);
	//FT_Done_FreeType(ft);
	//10/3/20 - HUD ------------------------------------------------------------------------------------------------------------------------------------------
	//Texture hudTexture = Texture(true);
	//Material HUD("bricks", hudTexture, 0.0f, 0,
		//hudTexture, hudTexture, 0.03f, -0.5f);

	////11/3/20
	//Entity *textRendererObject = new Entity(Vector3f(0, 0, 0), Quaternion(), 1.0f);
	//Text = new TextRenderer(50, 50);
	//Text->Load("font/arial.ttf", 5);
	////Vector3f colour = Vector3f(0,1,0);
	////Text->RenderText("Lives:", 50.0f, 50.0f, 1.0f, colour);
	////textRendererObjects.push_back(Text);
	//textRendererObject->AddComponent(Text);
	//AddToScene(textRendererObject);

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
	MeshRenderer *treeRenderer = new MeshRenderer(*treeMesh, *treeMaterial);
	treeRenderer->setTranslations(translations);//6/3/20
	treeRenderer->setIsTree(true);
	checkTreeHeight(treeObject);
	treeObject->AddComponent(treeRenderer);
	AddToScene(treeObject);

	//7/3/20 - tree shells for shadows
	/*
	trees.reserve(1000);
	treeObjects.reserve(1000);
	for (int i = 0; i < 1000; i++) {
		trees.push_back(new MeshRenderer(Mesh("Lowpoly_tree_sample.obj"), Material("black"), false));
	}

	for (int i = 0; i < 1000; i++) {
		treeObjects.push_back((new Entity(Vector3f(translations[i].x, translations[i].y, translations[i].z), Quaternion(), 1.0f))->AddComponent(trees[i]));
	}
	for (int i = 0; i < 1000; i++) {
		AddToScene(treeObjects[i]);
	}
	*/

	//14/3/20
	/*Entity *textRendererObject = new Entity(Vector3f(0, 0, 0), Quaternion(), 1.0f);
	Text = new TextRenderer(50, 50);
	Text->Load("font/arial.ttf", 5);
	textRendererObject->AddComponent(Text);
	AddToScene(textRendererObject);*/

	//15/3/20
	TextRenderer *textRenderer = new TextRenderer();
	textRenderer->Load("arial.ttf", 50);
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

//void TestGame::renderText() {
//	textRendererObjects[0]->RenderText("Lives:", 50.0f, 50.0f, 1.0f, Vector3f(0,1,0));
//	//printf("IN_RENDER_TEXT");
//}

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
