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
protected:
private:
	//Vector3f vertexPos;
	TestGame(const TestGame& other) {}
	void operator=(const TestGame& other) {}
	std::vector<FreeMove*> freeMoveObjects;// = new ArrayList<FreeMove>();
	std::vector<MeshRenderer*> terrainObjects;
	std::vector<Mesh*> meshObjects;
};

void TestGame::Init(const Window& window)
{
	Material bricks("bricks", Texture("bricks.jpg"), 0.0f, 0, 
			Texture("bricks_normal.jpg"), Texture("bricks_disp.png"), 0.03f, -0.5f);
	Material bricks2("bricks2", Texture("bricks2.jpg"), 0.0f, 0, 
			Texture("bricks2_normal.png"), Texture("bricks2_disp.jpg"), 0.04f, -1.0f);
	Material magenta("magenta", Texture("magenta.jpg"), 0.0f, 0, 
			Texture("magenta.jpg"), Texture("magenta_disp.jpg"), 0.04f, -1.0f);
	//Material magenta("magenta.jpg");
	/*
	IndexedModel square;
	{
		square.AddVertex(1.0f, -1.0f, 0.0f);  square.AddTexCoord(Vector2f(1.0f, 1.0f));
		square.AddVertex(1.0f, 1.0f, 0.0f);   square.AddTexCoord(Vector2f(1.0f, 0.0f));
		square.AddVertex(-1.0f, -1.0f, 0.0f); square.AddTexCoord(Vector2f(0.0f, 1.0f));
		square.AddVertex(-1.0f, 1.0f, 0.0f);  square.AddTexCoord(Vector2f(0.0f, 0.0f));
		square.AddFace(0, 1, 2); square.AddFace(2, 1, 3);
	}
	Mesh customMesh("square", square.Finalize());
	*/

	//AddToScene((new Entity(Vector3f(0, -1, 5), Quaternion(), 32.0f))
	//	->AddComponent(new MeshRenderer(Mesh("terrain02.obj"), Material("bricks"))));

	Entity *terrainObject = new Entity(Vector3f(0, 0, 0), Quaternion(), 1.0f);
	Mesh *terrainMesh = new Mesh("terrain02.obj");
	meshObjects.push_back(terrainMesh);
	Material *terraineMaterial = new Material("magenta");
	MeshRenderer *terrainRenderer = new MeshRenderer(*terrainMesh, *terraineMaterial);
	terrainObjects.push_back(terrainRenderer);
	terrainObject->AddComponent(terrainRenderer);
	AddToScene(terrainObject);
		
	//AddToScene((new Entity(Vector3f(7,0,7)))
		//->AddComponent(new PointLight(Vector3f(0,1,0), 0.4f, Attenuation(0,0,1))));
	
	//AddToScene((new Entity(Vector3f(20,-11.0f,5), Quaternion(Vector3f(1,0,0), ToRadians(-60.0f)) * Quaternion(Vector3f(0,1,0), ToRadians(90.0f))))
		//->AddComponent(new SpotLight(Vector3f(0,1,1), 0.4f, Attenuation(0,0,0.02f), ToRadians(91.1f), 7, 1.0f, 0.5f)));
	
	AddToScene((new Entity(Vector3f(), Quaternion(Vector3f(1,0,0), ToRadians(-45))))
		->AddComponent(new DirectionalLight(Vector3f(1,1,1), 0.4f, 10, 80.0f, 1.0f)));
	/*
	AddToScene((new Entity(Vector3f(0, 2, 0), Quaternion(Vector3f(0,1,0), 0.4f), 1.0f))
		->AddComponent(new MeshRenderer(Mesh("plane3.obj"), Material("bricks2")))
		->AddChild((new Entity(Vector3f(0, 0, 25)))
			->AddComponent(new MeshRenderer(Mesh("plane3.obj"), Material("bricks2")))
			->AddChild((new Entity())
				->AddComponent(new CameraComponent(Matrix4f().InitPerspective(ToRadians(70.0f), window.GetAspect(), 0.1f, 1000.0f)))
				->AddComponent(new FreeLook(window.GetCenter()))
				->AddComponent(new FreeMove(10.0f)))));
	*/

	AddToScene((new Entity(Vector3f(24,-12,5), Quaternion(Vector3f(0,1,0), ToRadians(30.0f))))
		->AddComponent(new MeshRenderer(Mesh("sphere.obj"), Material("bricks"))));
		
	//AddToScene((new Entity(Vector3f(0,0,7), Quaternion(), 1.0f))
		//->AddComponent(new MeshRenderer(Mesh("square"), Material("bricks2"))));


//	//TODO: Temporary Physics Engine Code!
//	PhysicsEngine physicsEngine;
//	
//	physicsEngine.AddObject(PhysicsObject(
//			new BoundingSphere(Vector3f(0.0f, 0.0f, 0.0f), 1.0f),
//		   	Vector3f(0.0f, 0.0f, 1.141f/2.0f)));
//
//	physicsEngine.AddObject(PhysicsObject(
//			new BoundingSphere(Vector3f(1.414f/2.0f * 7.0f, 0.0f, 1.414f/2.0f * 7.0f), 1.0f),
//			Vector3f(-1.414f/2.0f, 0.0f, -1.414f/2.0f))); 
//
//
//	PhysicsEngineComponent* physicsEngineComponent 
//		= new PhysicsEngineComponent(physicsEngine);
//
//	for(unsigned int i = 0; 
//		i < physicsEngineComponent->GetPhysicsEngine().GetNumObjects(); 
//		i++)
//	{
//		
//		AddToScene((new Entity(Vector3f(0,0,0), Quaternion(), 
//					1.0f))
//			->AddComponent(new PhysicsObjectComponent(
//					&physicsEngineComponent->GetPhysicsEngine().GetObject(i)))
//			->AddComponent(new MeshRenderer(Mesh("sphere.obj"), Material("bricks"))));
//	}
//
//	AddToScene((new Entity())
//		->AddComponent(physicsEngineComponent));

//	AddToScene((new Entity(Vector3f(), Quaternion(Vector3f(1,0,0), ToRadians(-45))))
//		->AddComponent(new DirectionalLight(Vector3f(1,1,1), 0.4f, 10, 80.0f, 1.0f)));

	//FreeMove playerMovement(10.0f);
	//freeMoveObjects.push_back(playerMovement);
	/*
	AddToScene((new Entity())
				->AddComponent(new CameraComponent(Matrix4f().InitPerspective(
							ToRadians(70.0f), window.GetAspect(), 0.1f, 1000.0f)))
				->AddComponent(new FreeLook(window.GetCenter()))
				->AddComponent(new FreeMove(10.0f)));//->AddComponent(playerMovement));//
    */
	//Now have handles for FreeMove and it is stored in array
	Entity *player = new Entity(Vector3f(0, 0, 0), Quaternion(), 1.0f);//Vector3f(10.0f, 10.0f, 10.0f), Quaternion(0, 0, 0, 1), 1.0f);// = new Entity();
	FreeMove *playerMovement = new FreeMove(0.3f);//5/2/20 (10.0f);
	freeMoveObjects.push_back(playerMovement);
	FreeLook *playerLook = new FreeLook(window.GetCenter());// (window.GetCenter());
	CameraComponent *playerCamera = new CameraComponent(Matrix4f().InitPerspective(ToRadians(70.0f), window.GetAspect(), 0.1f, 1000.0f));// (Matrix4f().InitPerspective(ToRadians(70.0f), window.GetAspect(), 0.1f, 1000.0f));
	player->AddComponent(playerMovement);
	player->AddComponent(playerLook);
	player->AddComponent(playerCamera);
	AddToScene(player);



	//static const int CUBE_SIZE = 3;

	//AddToScene((new Entity())
		//->AddComponent(new PointLight(Vector3f(1,1,1), 
				//(CUBE_SIZE * CUBE_SIZE) * 2, Attenuation(0,0,1))));

	/*
	for(int i = -CUBE_SIZE; i <= CUBE_SIZE; i++)
	{
		for(int j = -CUBE_SIZE; j <= CUBE_SIZE; j++)
		{
			for(int k = -CUBE_SIZE; k <= CUBE_SIZE; k++)
			{
				if(i == -CUBE_SIZE || i == CUBE_SIZE ||
				   j == -CUBE_SIZE || j == CUBE_SIZE ||
				   k == -CUBE_SIZE || k == CUBE_SIZE)
				{
					if(i == 0 || j == 0 || k == 0)
					{
						AddToScene((new Entity(Vector3f(i * 2, j * 2, k * 2)))
							->AddComponent(new MeshRenderer(Mesh("sphere.obj"), 
									Material("bricks"))));
					}
					else
					{
						AddToScene((new Entity(Vector3f(i * 2, j * 2, k * 2)))
							->AddComponent(new MeshRenderer(Mesh("cube.obj"), 
									Material("bricks2"))));
					}
			
				}
			}
		}
	}
	*/

}

void TestGame::CheckTerrainHeight() 
{
	//freeMoveObjects[0]->GetParent()->GetTransform()->GetPos()->SetY(100.0f);//this worked in setting me to height 100
	/*
	for (FreeMove *currentFreeMove : freeMoveObjects) {
		Vector3f *playerPos = currentFreeMove->GetParent()->GetTransform()->GetPos();//currentFreeMove.getParent().getTransform().getPos();
		float playerXPos = playerPos->GetX();//.getX();
		float playerZPos = playerPos->GetZ();//.getZ();

		//float terrainHeight = terrainObjects[0];//.get(0).getHeightOfTerraine(playerXPos, playerZPos);
		//currentFreeMove->GetParent()->GetTransform()->GetPos()->SetY(terrainHeight + 2.0f);//.getParent().getTransform().getPos().setY(terrainHeight + 2.0f);
		//for (Mesh *currentMesh : meshObjects) {
			//currentMesh->getMeshVertices();
		//}
		for (Vector3f currentVector : meshObjects[0]->getMeshVertices()) {
			if (currentVector.GetX() == playerXPos & currentVector.GetZ() == playerZPos) {
				currentFreeMove->GetParent()->GetTransform()->GetPos()->SetY(currentVector.GetY());
				printf("REVIEVED_NEW_HEIGHT");
			}
			
		}
	}
	*/
	/*current best
	Vector3f *playerPos = freeMoveObjects[0]->GetParent()->GetTransform()->GetPos();
	float playerXPos = playerPos->GetX();
	float playerZPos = playerPos->GetZ();
	int playerXPosInt = (int)playerXPos;
	int playerZPosInt = (int)playerZPos;
	//float epsilon = 0.0005f;
	
	for (Vector3f currentVector : meshObjects[0]->getMeshVertices()) {
		int meshHeightXInt = (int)currentVector.GetX();
		int meshHeightZInt = (int)currentVector.GetZ();
		if (meshHeightXInt == playerXPosInt & meshHeightZInt == playerZPosInt){//currentVector.GetX() <= playerXPos & currentVector.GetZ() <= playerZPos) {
			freeMoveObjects[0]->GetParent()->GetTransform()->GetPos()->SetY(currentVector.GetY());
			//printf("REVIEVED_NEW_HEIGHT");
		}

	}
	*/
	//4/2/20 tests
	/*
	std::vector<Vector3f> test = meshObjects[0]->getMeshVertices();
	test.size();
	std::vector<Vector3f> test2;
	for (Vector3f currentVector : meshObjects[0]->getMeshVertices()) {
		test2.push_back(currentVector);
	}
	test2.size();
	*/

	//current best 4/2/20
	//5/2/20 test
	/*
	float vertexPosX = currentVector.GetX() * 32.0f;
	float vertexPosY = currentVector.GetY() * 32.0f;
	float vertexPosZ = currentVector.GetZ() * 32.0f;
	Vector3f vertexPos(vertexPosX, vertexPosY, vertexPosZ);// = new Vector3f(vertexPosX, vertexPosY, vertexPosZ);
	*/

	//5/2/20(13:35) current best
	for (Vector3f currentVector : meshObjects[0]->getMeshVertices()) {
		Vector3f vertexPos = currentVector;
		Vector3f vertexScale(0.05f, 0.05f, 0.05f);
		Vector3f *testPlayerPos = freeMoveObjects[0]->GetParent()->GetTransform()->GetPos();
		Vector3f testPlayerScale(0.05f, 0.05f, 0.05f);

		Vector3f tmp(testPlayerPos->GetX(), testPlayerPos->GetY() - 1.0f, testPlayerPos->GetZ());
		//check the X axis
		if (abs(tmp.GetX() - vertexPos.GetX()) < testPlayerScale.GetX() + (vertexScale.GetX()) / 1.0f) {
				//check the Z axis
				if (abs(tmp.GetZ() - vertexPos.GetZ()) < testPlayerScale.GetZ() + (vertexScale.GetZ()) / 1.0f) {
					freeMoveObjects[0]->GetParent()->GetTransform()->GetPos()->SetY(vertexPos.GetY()+0.2f);
					//printf("colission");
				}
		}
	}
	
	/*5/2/20 int approach
	Vector3f *playerPos = freeMoveObjects[0]->GetParent()->GetTransform()->GetPos();
	float playerXPos = playerPos->GetX();
	float playerZPos = playerPos->GetZ();
	int playerXPosInt = (int)playerXPos;
	int playerZPosInt = (int)playerZPos;
	Vector3f testPlayerScale(1.0f, 1.0f, 1.0f);
	for (Vector3f currentVector : meshObjects[0]->getMeshVertices()) {
		int meshHeightXInt = (int)currentVector.GetX();
		int meshHeightZInt = (int)currentVector.GetZ();
		//check the X axis
		if (meshHeightXInt == playerXPosInt & meshHeightZInt == playerZPosInt){
            freeMoveObjects[0]->GetParent()->GetTransform()->GetPos()->SetY(currentVector.GetY());
        }
	}
	*/
	/*
	for (unsigned int currentVector : meshObjects[0]->getMeshIndices()) {
		Vector3f vertexPos = currentVector;
		Vector3f vertexScale(1.0f, 1.0f, 1.0f);//currentMeshRenderer.getScaleAttrib();//new Vector3f(2.0f, 2.0f, 2.0f);
		Vector3f *testPlayerPos = freeMoveObjects[0]->GetParent()->GetTransform()->GetPos();
		//Vector3f test = testPlayerPos;
		Vector3f testPlayerScale(1.0f, 1.0f, 1.0f);

		Vector3f tmp(testPlayerPos->GetX(), testPlayerPos->GetY() - 1.0f, testPlayerPos->GetZ());
		//check the X axis
		if (abs(tmp.GetX() - vertexPos.GetX()) < testPlayerScale.GetX() + (vertexScale.GetX()) / 1.0) {
			//check the Y axis
			//if (abs(tmp.GetY() - vertexPos.GetY()) < testPlayerScale.GetY() + (vertexScale.GetY()) / 1.0) {
				//check the Z axis
			if (abs(tmp.GetZ() - vertexPos.GetZ()) < testPlayerScale.GetZ() + (vertexScale.GetZ()) / 1.0) {
				freeMoveObjects[0]->GetParent()->GetTransform()->GetPos()->SetY(currentVector.GetY());
				//printf("colission");
			}
			//}
		}
	}
	*/
	/*
	//4/2/20 test
	for (Vector3f currentVector : meshObjects[0]->getMeshVertices()) {
		for (Vector3f currentFreeMove : freeMoveObjects[0]->GetParent()->GetTransform()->GetPos()) {
			Vector3f vertexPos = currentVector;
			Vector3f vertexScale(1.0f, 1.0f, 1.0f);//currentMeshRenderer.getScaleAttrib();//new Vector3f(2.0f, 2.0f, 2.0f);
			Vector3f testPlayerPos = currentFreeMove;//freeMoveObjects[0]->GetParent()->GetTransform()->GetPos();
			//Vector3f test = testPlayerPos;
			Vector3f testPlayerScale(1.0f, 1.0f, 1.0f);

			Vector3f tmp(testPlayerPos->GetX(), testPlayerPos->GetY() - 1.0f, testPlayerPos->GetZ());
			//check the X axis
			if (abs(tmp.GetX() - vertexPos.GetX()) < testPlayerScale.GetX() + (vertexScale.GetX()) / 1.0) {
				//check the Y axis
				//if (abs(tmp.GetY() - vertexPos.GetY()) < testPlayerScale.GetY() + (vertexScale.GetY()) / 1.0) {
					//check the Z axis
				if (abs(tmp.GetZ() - vertexPos.GetZ()) < testPlayerScale.GetZ() + (vertexScale.GetZ()) / 1.0) {
					freeMoveObjects[0]->GetParent()->GetTransform()->GetPos()->SetY(currentVector.GetY());
					printf("colission");
				}
				//}
			}
		}
	}
	*/
	/*
	for (std::vector<Vector3f> currentVector : meshObjects[0]->getMeshVertices()) {
		int meshHeightXInt = (int)currentVector.GetX();
		int meshHeightZInt = (int)currentVector.GetZ();
		if (meshHeightXInt == playerXPosInt & meshHeightZInt == playerZPosInt) {//currentVector.GetX() <= playerXPos & currentVector.GetZ() <= playerZPos) {
			freeMoveObjects[0]->GetParent()->GetTransform()->GetPos()->SetY(currentVector.GetY());
			//printf("REVIEVED_NEW_HEIGHT");
		}
		*/
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
	
	//window.SetFullScreen(false);

//	Window window(800, 600, "My Window");
//	RenderingEngine engine(window);
//	
//	Material bricks2("bricks2", Texture("bricks2.jpg"), 1, 8, Texture("bricks2_normal.png"), Texture("bricks2_disp.jpg"), 0.04f, -1.0f);
//	GameObject root;
//	Transform cameraTransform;
//	Camera camera(Matrix4f().InitPerspective(ToRadians(70.0f), window.GetAspect(), 0.1f, 1000.0f), &cameraTransform);
//	
//	root.AddChild((new GameObject(Vector3f(0, 2, 0), Quaternion(Vector3f(0,1,0), 0.4f), 1.0f))
//		->AddComponent(new MeshRenderer(Mesh("plane3.obj"), Material("bricks2")))
//		->AddChild((new GameObject(Vector3f(0, 0, 25)))
//			->AddComponent(new MeshRenderer(Mesh("plane3.obj"), Material("bricks2")))
//			//->AddChild((new GameObject())
//				->AddComponent(new FreeLook(window.GetCenter()))
//				->AddComponent(new FreeMove())));
//	
//	while(!window.IsCloseRequested())
//	{
//		window.Update();
//		root.ProcessInputAll(window.GetInput(), 0.01f);
//		root.UpdateAll(0.01f);
//		engine.Render(root, camera);
//		window.SwapBuffers();
//	}
	
	return 0;
}
