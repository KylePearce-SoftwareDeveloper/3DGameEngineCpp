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

#include "mesh.h"

#include "../core/profiling.h"

#include <GL/glew.h>
#include <iostream>

#include <vector>
#include <cassert>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

std::map<std::string, MeshData*> Mesh::s_resourceMap;
std::vector<Vector3f> meshVertices;//2/2/20 test
std::vector<int> meshVerticesX;//6/2/20 test
std::vector<int> meshVerticesZ;//6/2/20 test
std::vector<int> meshVerticesY;//15/2/20 test
//std::vector<unsigned int> meshIndices;//4/2/20 test
std::vector<Vector3i> meshVerticesInts;//17/2/20 -  new terrain collision method
//std::vector<Vector3f> meshVerticesFloats;//17/2/20 -  new terrain collision method (FLOAT VERSION)
//-------------------------------------------------------------float version-------------------16/2/20
std::vector<float> meshVerticesXFloat;//6/2/20 test
std::vector<float> meshVerticesZFloat;//6/2/20 test
std::vector<float> meshVerticesYFloat;//15/2/20 test

bool IndexedModel::IsValid() const
{
	return m_positions.size() == m_texCoords.size()
		&& m_texCoords.size() == m_normals.size()
		&& m_normals.size() == m_tangents.size();
}

void IndexedModel::AddVertex(const Vector3f& vert)
{
	m_positions.push_back(vert);
}

void IndexedModel::AddTexCoord(const Vector2f& texCoord)
{
	m_texCoords.push_back(texCoord);
}

void IndexedModel::AddNormal(const Vector3f& normal)
{
	m_normals.push_back(normal);
}
	
void IndexedModel::AddTangent(const Vector3f& tangent)
{
	m_tangents.push_back(tangent);
}

IndexedModel IndexedModel::Finalize()
{
	if(IsValid())
	{
		return *this;
	}
	
	if(m_texCoords.size() == 0)
	{
		for(unsigned int i = m_texCoords.size(); i < m_positions.size(); i++)
		{
			m_texCoords.push_back(Vector2f(0.0f, 0.0f));
		}
	}
	
	if(m_normals.size() == 0)
	{
		CalcNormals();
	}
	
	if(m_tangents.size() == 0)
	{
		CalcTangents();
	}
	
	return *this;
}

void IndexedModel::AddFace(unsigned int vertIndex0, unsigned int vertIndex1, unsigned int vertIndex2)
{
	m_indices.push_back(vertIndex0);
	m_indices.push_back(vertIndex1);
	m_indices.push_back(vertIndex2);
}

void IndexedModel::CalcNormals()
{
	m_normals.clear();
	m_normals.reserve(m_positions.size());
	
	for(unsigned int i = 0; i < m_positions.size(); i++)
		m_normals.push_back(Vector3f(0,0,0));

	for(unsigned int i = 0; i < m_indices.size(); i += 3)
	{
		int i0 = m_indices[i];
		int i1 = m_indices[i + 1];
		int i2 = m_indices[i + 2];
			
		Vector3f v1 = m_positions[i1] - m_positions[i0];
		Vector3f v2 = m_positions[i2] - m_positions[i0];
		
		Vector3f normal = v1.Cross(v2).Normalized();
		
		m_normals[i0] = m_normals[i0] + normal;
		m_normals[i1] = m_normals[i1] + normal;
		m_normals[i2] = m_normals[i2] + normal;
	}
	
	for(unsigned int i = 0; i < m_normals.size(); i++)
		m_normals[i] = m_normals[i].Normalized();
}

void IndexedModel::CalcTangents()
{
	m_tangents.clear();
	m_tangents.reserve(m_positions.size());
	
	for(unsigned int i = 0; i < m_positions.size(); i++)
		m_tangents.push_back(Vector3f(0,0,0));
		
	for(unsigned int i = 0; i < m_indices.size(); i += 3)
    {
		int i0 = m_indices[i];
		int i1 = m_indices[i + 1];
		int i2 = m_indices[i + 2];
    
        Vector3f edge1 = m_positions[i1] - m_positions[i0];
        Vector3f edge2 = m_positions[i2] - m_positions[i0];
        
        float deltaU1 = m_texCoords[i1].GetX() - m_texCoords[i0].GetX();
        float deltaU2 = m_texCoords[i2].GetX() - m_texCoords[i0].GetX();
        float deltaV1 = m_texCoords[i1].GetY() - m_texCoords[i0].GetY();
        float deltaV2 = m_texCoords[i2].GetY() - m_texCoords[i0].GetY();
        
        float dividend = (deltaU1 * deltaV2 - deltaU2 * deltaV1);
        float f = dividend == 0.0f ? 0.0f : 1.0f/dividend;
        
        Vector3f tangent = Vector3f(0,0,0);
        
        tangent.SetX(f * (deltaV2 * edge1.GetX() - deltaV1 * edge2.GetX()));
        tangent.SetY(f * (deltaV2 * edge1.GetY() - deltaV1 * edge2.GetY()));
        tangent.SetZ(f * (deltaV2 * edge1.GetZ() - deltaV1 * edge2.GetZ()));

//Bitangent example, in Java
//		Vector3f bitangent = new Vector3f(0,0,0);
//		
//		bitangent.setX(f * (-deltaU2 * edge1.getX() - deltaU1 * edge2.getX()));
//		bitangent.setX(f * (-deltaU2 * edge1.getY() - deltaU1 * edge2.getY()));
//		bitangent.setX(f * (-deltaU2 * edge1.getZ() - deltaU1 * edge2.getZ()));

		m_tangents[i0] += tangent;
		m_tangents[i1] += tangent;
		m_tangents[i2] += tangent;	
    }

    for(unsigned int i = 0; i < m_tangents.size(); i++)
		m_tangents[i] = m_tangents[i].Normalized();
}


MeshData::MeshData(const IndexedModel& model) : 
	ReferenceCounter(),
	m_drawCount(model.GetIndices().size())
{
	if(!model.IsValid())
	{
		std::cout << "Error: Invalid mesh! Must have same number of positions, texCoords, normals, and tangents! "
			<< "(Maybe you forgot to Finalize() your IndexedModel?)" << std::endl;
		assert(0 != 0);
	}
	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);

	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.GetPositions().size() * sizeof(model.GetPositions()[0]), &model.GetPositions()[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.GetTexCoords().size() * sizeof(model.GetTexCoords()[0]), &model.GetTexCoords()[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[NORMAL_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.GetNormals().size() * sizeof(model.GetNormals()[0]), &model.GetNormals()[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TANGENT_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.GetTangents().size() * sizeof(model.GetTangents()[0]), &model.GetTangents()[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.GetIndices().size() * sizeof(model.GetIndices()[0]), &model.GetIndices()[0], GL_STATIC_DRAW);
}

MeshData::~MeshData() 
{	
	glDeleteBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void MeshData::Draw() const
{
	glBindVertexArray(m_vertexArrayObject);
	
	#if PROFILING_DISABLE_MESH_DRAWING == 0
		glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0);
	#endif
}

void MeshData::DrawTree() const//1/3/20
{
	glBindVertexArray(m_vertexArrayObject);

#if PROFILING_DISABLE_MESH_DRAWING == 0
	glDrawElementsInstanced(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0, 1000);
#endif
}


Mesh::Mesh(const std::string& meshName, const IndexedModel& model) :
	m_fileName(meshName)
{
	std::map<std::string, MeshData*>::const_iterator it = s_resourceMap.find(meshName);
	if(it != s_resourceMap.end())
	{
		std::cout << "Error adding mesh " << meshName << ": Mesh already exists by the same name!" << std::endl;
		assert(0 != 0);
	}
	else
	{
		m_meshData = new MeshData(model);
		s_resourceMap.insert(std::pair<std::string, MeshData*>(meshName, m_meshData));
	}
}

Mesh::Mesh(const std::string& fileName) :
	m_fileName(fileName),
	m_meshData(0)
{
	std::map<std::string, MeshData*>::const_iterator it = s_resourceMap.find(fileName);
	if(it != s_resourceMap.end())
	{
		m_meshData = it->second;
		m_meshData->AddReference();
	}
	else
	{
		Assimp::Importer importer;
		
		const aiScene* scene = importer.ReadFile(("../res/models/" + fileName).c_str(), 
		                                         aiProcess_Triangulate |
		                                         aiProcess_GenSmoothNormals | 
		                                         aiProcess_FlipUVs |
		                                         aiProcess_CalcTangentSpace);
		
		if(!scene)
		{
			std::cout << "Mesh load failed!: " << fileName << std::endl;
			assert(0 == 0);
		}
		
		const aiMesh* model = scene->mMeshes[0];
		
		std::vector<Vector3f> positions;
		std::vector<Vector2f> texCoords;
		std::vector<Vector3f> normals;
		std::vector<Vector3f> tangents;
		std::vector<unsigned int> indices;

		const aiVector3D aiZeroVector(0.0f, 0.0f, 0.0f);
		for(unsigned int i = 0; i < model->mNumVertices; i++) 
		{
			const aiVector3D pos = model->mVertices[i];
			const aiVector3D normal = model->mNormals[i];
			const aiVector3D texCoord = model->HasTextureCoords(0) ? model->mTextureCoords[0][i] : aiZeroVector;
			const aiVector3D tangent = model->mTangents[i];

			positions.push_back(Vector3f(pos.x, pos.y, pos.z));
			texCoords.push_back(Vector2f(texCoord.x, texCoord.y));
			normals.push_back(Vector3f(normal.x, normal.y, normal.z));
			tangents.push_back(Vector3f(tangent.x, tangent.y, tangent.z));
		}

		for(unsigned int i = 0; i < model->mNumFaces; i++)
		{
			const aiFace& face = model->mFaces[i];
			assert(face.mNumIndices == 3);
			indices.push_back(face.mIndices[0]);
			indices.push_back(face.mIndices[1]);
			indices.push_back(face.mIndices[2]);
		}

		//17/2/20 -  new terrain collision method
		for (int i = 0; i < positions.size(); i++) {
			meshVerticesInts.push_back(Vector3i((int)positions[i].GetX(), (int)positions[i].GetY(), (int)positions[i].GetZ()));
		}
		//17/2/20 -  new terrain collision method (FLOAT VERSION)
		for (int i = 0; i < positions.size(); i++) {
			meshVerticesFloats.push_back(positions[i]);
		}

		//meshVertices = positions;//2/2/20 test
		for (Vector3f currentVertex : positions) {//2/2/20 test, bit more reliable than above approach
			meshVertices.push_back(currentVertex);
		}
		for (Vector3f currentVertex : meshVertices) {//6/2/20 
			meshVerticesX.push_back((int)currentVertex.GetX());
		}
		for (Vector3f currentVertex : meshVertices) {//6/2/20
			meshVerticesZ.push_back((int)currentVertex.GetZ());
		}
		for (Vector3f currentVertex : meshVertices) {//15/2/20
			meshVerticesY.push_back((int)currentVertex.GetY());
		}
		//-------------------------------------------------------------float version-------------------16/2/20
		for (Vector3f currentVertex : meshVertices) { 
			meshVerticesXFloat.push_back(currentVertex.GetX());
		}
		for (Vector3f currentVertex : meshVertices) {
			meshVerticesZFloat.push_back(currentVertex.GetZ());
		}
		for (Vector3f currentVertex : meshVertices) {
			meshVerticesYFloat.push_back(currentVertex.GetY());
		}

		/*
		for (int i = 0; i < meshVertices.size(); i++) {//5/2/20 test, bit more reliable than above approach
			meshVertices[i].SetX(meshVertices[i].GetX() * 2.0f);
			meshVertices[i].SetY(meshVertices[i].GetY() * 2.0f);
			meshVertices[i].SetZ(meshVertices[i].GetZ() * 2.0f);
		}
		*/
		//4/2/20 test
		/*
		for (unsigned int currentindex : indices) {//2/2/20 test, bit more reliable than above approach
			meshIndices.push_back(currentindex);
		}
		*/
		//5/2/20 test
		//for (unsigned int currentindex : model->mNumFaces) {//2/2/20 test, bit more reliable than above approach
			//meshIndices.push_back(currentindex);
		//}
		m_meshData = new MeshData(IndexedModel(indices, positions, texCoords, normals, tangents));
		s_resourceMap.insert(std::pair<std::string, MeshData*>(fileName, m_meshData));
	}
}

std::vector<Vector3f> Mesh::getMeshVertices()//2/2/20
{
	return meshVertices;
}
/*
Vector3f Mesh::checkMeshVertices(Vector3f* playerPos)//5/2/20
{
	return std::find(meshVertices.begin(), meshVertices.end(), playerPos) != meshVertices.end();//meshVertices.get(playerPos);
}
*/

/*
Vector3f& Mesh::checkMeshVertices(Vector3f* playerPos)
{
	auto it = std::find(meshVertices.begin(), meshVertices.end(), playerPos);
	if (it != meshVertices.end()) return *it;
	//else return nullptr;//throw std::out_of_range();
}
*/
bool Mesh::checkMeshVerticesX(int playerPosX)
{
	//auto it = std::find(meshVerticesX.begin(), meshVerticesX.end(), playerPosX);
	//if (it != meshVerticesX.end()) return *it;
	//else return nullptr;//throw std::out_of_range();
	return std::find(meshVerticesX.begin(), meshVerticesX.end(), playerPosX) != meshVerticesX.end();
}
bool Mesh::checkMeshVerticesZ(int playerPosZ)
{
	//auto it = std::find(meshVerticesZ.begin(), meshVerticesZ.end(), playerPosZ);
	//if (it != meshVerticesZ.end()) return *it;
	//else return nullptr;//throw std::out_of_range();
	return std::find(meshVerticesZ.begin(), meshVerticesZ.end(), playerPosZ) != meshVerticesZ.end();
}

int Mesh::getMeshYHeight(int playerXPos, int playerZPos) {//15/2/20
	auto iterX = std::find(meshVerticesX.begin(), meshVerticesX.end(), playerXPos);//std::find(meshVerticesX.begin(), meshVerticesX.end(), playerXPos) != meshVerticesX.end();
	auto iterZ = std::find(meshVerticesZ.begin(), meshVerticesZ.end(), playerZPos);//std::find(meshVerticesZ.begin(), meshVerticesZ.end(), playerZPos) != meshVerticesZ.end();
	if (iterX != meshVerticesX.end() & iterZ != meshVerticesZ.end()) {
		int indexX = std::distance(meshVerticesX.begin(), iterX);
		int indexZ = std::distance(meshVerticesZ.begin(), iterZ);
		if (indexX - indexZ >=-1 | indexX - indexZ <=1)//indexX == indexZ)
		{
			printf("Getting_Height\n");
			return meshVerticesY[indexX];//indexX];
		}
		else {
			printf("Not_Getting_Height_1\n");
			return 10000;//the terrain is never this height
		}
	}
	else {
		printf("Not_Getting_Height_2\n");
		return 10000;//the terrain is never this height
	}
}
//-------------------------------------------------------------float version------------------------------------------16/2/20
bool Mesh::checkMeshVerticesXFloat(float playerPosX)
{
	return std::find(meshVerticesX.begin(), meshVerticesX.end(), playerPosX<0.005f) != meshVerticesX.end();
}
bool Mesh::checkMeshVerticesZFloat(float playerPosZ)
{
	return std::find(meshVerticesZ.begin(), meshVerticesZ.end(), playerPosZ<0.005f) != meshVerticesZ.end();
}

float Mesh::getMeshYHeightFloat(float playerXPos, float playerZPos) {
	auto iterX = std::find(meshVerticesXFloat.begin(), meshVerticesXFloat.end(), playerXPos<0.005f);
	auto iterZ = std::find(meshVerticesZFloat.begin(), meshVerticesZFloat.end(), playerZPos<0.005f);
	if (iterX != meshVerticesXFloat.end() & iterZ != meshVerticesZFloat.end()) {
		int indexX = std::distance(meshVerticesXFloat.begin(), iterX);
		int indexZ = std::distance(meshVerticesZFloat.begin(), iterZ);
		if (indexX - indexZ >= -1 | indexX - indexZ <= 1)
		{
			//printf("gettingHeight");
			return meshVerticesYFloat[indexX];
		}
		else {
			printf("seccond if failed");
			return 10000.0f;
		}
	}
	else {
		printf("first if failed");
		return 10000.0f;
	}
}

//17/2/20 -  new terrain collision method
int Mesh::newTerrainheightFunc(Vector3i playerPos) {
	auto testIterator = std::find_if(meshVerticesInts.begin(), meshVerticesInts.end(), [&](Vector3i pos) {return pos.GetX() == playerPos.GetX() & pos.GetZ() == playerPos.GetZ(); });//return pos.GetX() == playerPos.GetX() & pos.GetZ() == playerPos.GetZ(); });
	if (testIterator != meshVerticesInts.end()) {
		int testIndex = std::distance(meshVerticesInts.begin(), testIterator);
		return meshVerticesInts[testIndex].GetY();
	}
	else {
		return 10000;//test value - no mesh vertex y value is ever 10000
	}
}

//17/2/20 -  new terrain collision method (FLOAT VERSION)
float Mesh::newTerrainHeightFuncFloat(Vector3f playerPos) {
	auto testIterator = std::find_if(meshVerticesFloats.begin(), meshVerticesFloats.end(), [&](Vector3f pos)
	{
		//check the X axis
		if (abs(playerPos.GetX() - pos.GetX()) < 5.0f + 5.0f / 2.0f) {
			//check the Z axis
			if (abs(playerPos.GetZ() - pos.GetZ()) < 5.0f + 5.0f / 2.0f) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	});
	if (testIterator != meshVerticesFloats.end()) {
		int testIndex = std::distance(meshVerticesFloats.begin(), testIterator);
		return meshVerticesFloats[testIndex].GetY();
		printf("GETTING_NEW_HEIGHT\n");
	}
	else {
		printf("NOT_GETTING_NEW_HEIGHT\n");
		return 10000.0f;//test value - no mesh vertex y value is ever 10000
	}
}

/*
std::vector<unsigned int> Mesh::getMeshIndices()//4/2/20
{
	return meshIndices;
}
*/
Mesh::Mesh(const Mesh& mesh) :
	m_fileName(mesh.m_fileName),
	m_meshData(mesh.m_meshData)
{
	m_meshData->AddReference();
}

Mesh::~Mesh()
{
	if(m_meshData && m_meshData->RemoveReference())
	{
		if(m_fileName.length() > 0)
		{
			s_resourceMap.erase(m_fileName);
		}
			
		delete m_meshData;
	}
}

void Mesh::Draw() const
{
	m_meshData->Draw();
}

void Mesh::DrawTree() const//1/3/20
{
	m_meshData->DrawTree();
}
