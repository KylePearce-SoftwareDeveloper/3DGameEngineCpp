/*
 * This engine was built uppon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirly
 * created by Kyle Pearce.
 */

#ifndef MESH_H
#define MESH_H

#include "../core/math3d.h"
#include "../core/referenceCounter.h"

#include <string>
#include <vector>
#include <map>
#include <GL/glew.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class IndexedModel
{
public:
	IndexedModel() {}
	IndexedModel(const std::vector<unsigned int> indices, const std::vector<Vector3f>& positions, const std::vector<Vector2f>& texCoords,
		const std::vector<Vector3f>& normals = std::vector<Vector3f>(), const std::vector<Vector3f>& tangents = std::vector<Vector3f>()) :
			m_indices(indices),
			m_positions(positions),
			m_texCoords(texCoords),
			m_normals(normals),
			m_tangents(tangents) {}

	bool IsValid() const;
	void CalcNormals();
	void CalcTangents();

	IndexedModel Finalize();

	void AddVertex(const Vector3f& vert);
	inline void AddVertex(float x, float y, float z) { AddVertex(Vector3f(x, y, z)); }
	
	void AddTexCoord(const Vector2f& texCoord);
	inline void AddTexCoord(float x, float y) { AddTexCoord(Vector2f(x, y)); }
	
	void AddNormal(const Vector3f& normal);
	inline void AddNormal(float x, float y, float z) { AddNormal(Vector3f(x, y, z)); }
	
	void AddTangent(const Vector3f& tangent);
	inline void AddTangent(float x, float y, float z) { AddTangent(Vector3f(x, y, z)); }
	
	void AddFace(unsigned int vertIndex0, unsigned int vertIndex1, unsigned int vertIndex2);

	inline const std::vector<unsigned int>& GetIndices() const { return m_indices; }
	inline const std::vector<Vector3f>& GetPositions()   const { return m_positions; }
	inline const std::vector<Vector2f>& GetTexCoords()   const { return m_texCoords; }
	inline const std::vector<Vector3f>& GetNormals()     const { return m_normals; }
	inline const std::vector<Vector3f>& GetTangents()    const { return m_tangents; }
private:
	std::vector<unsigned int> m_indices;
    std::vector<Vector3f> m_positions;
    std::vector<Vector2f> m_texCoords;
    std::vector<Vector3f> m_normals;
    std::vector<Vector3f> m_tangents;  
};

class MeshData : public ReferenceCounter
{
public:
	MeshData(const IndexedModel& model);
	virtual ~MeshData();
	
	void Draw() const;
	void DrawTree() const;//1/3/20
protected:	
private:
	MeshData(MeshData& other) {}
	void operator=(MeshData& other) {}

	enum
	{
		POSITION_VB,
		TEXCOORD_VB,
		NORMAL_VB,
		TANGENT_VB,
		
		INDEX_VB,
		
		NUM_BUFFERS
	};
	
	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	int m_drawCount;
};

class Mesh
{
public:
	Mesh(const std::string& fileName = "cube.obj");
	Mesh(const std::string& meshName, const IndexedModel& model);
	Mesh(const Mesh& mesh);
	virtual ~Mesh();

	void Draw() const;
	void DrawTree() const;//1/3/20
	//virtual std::vector<Vector3f> getMeshVertices();// {}//2/2/20 test
	//virtual std::vector<unsigned int> getMeshIndices();// {}//4/2/20 test
	//virtual Vector3f& checkMeshVertices(Vector3f* playerPos);//5/2/20
	//virtual bool checkMeshVerticesX(int playerPosX);//6/2/20
	//virtual bool checkMeshVerticesZ(int playerPosZ);//6/2/20
	//virtual int getMeshYHeight(int playerPosX, int playerPosZ);//15/2/20
	//--------------------------------------------------------------------float version-----------------------16/2/20
	//virtual bool checkMeshVerticesXFloat(float playerPosX);//6/2/20
	//virtual bool checkMeshVerticesZFloat(float playerPosZ);//6/2/20
	//virtual float getMeshYHeightFloat(float playerPosX, float playerPosZ);//15/2/20
	//virtual int newTerrainheightFunc(Vector3i playerPos);//17/2/20 -  new terrain collision method
	virtual float newTerrainHeightFuncFloat(Vector3f playerPos);//17/2/20 -  new terrain collision method (FLOAT VERSION)
	virtual bool checkCollisionWithMesh(Vector3f playerPos, Vector3f entityOffset);//19/3/20

	virtual void processNode(const aiNode *node, const aiScene *scene);//New Mesh Logic
	virtual void processMesh(const aiMesh *mesh, const aiScene *scene);//New Mesh Logic
protected:
private:
	static std::map<std::string, MeshData*> s_resourceMap;

	std::string m_fileName;
	MeshData* m_meshData;

	std::vector<Vector3f> meshVerticesFloats;//26/2/19 test

	std::vector<Vector3f> positions;//New Mesh Logic
	std::vector<Vector2f> texCoords;//New Mesh Logic
	std::vector<Vector3f> normals;//New Mesh Logic
	std::vector<Vector3f> tangents;//New Mesh Logic
	std::vector<unsigned int> indices;//New Mesh Logic
	
	void operator=(Mesh& mesh) {}
};

//class MeshBuilder
//{
//public:
//	MeshBuilder() {}
//	
//	void AddVertex(const Vector3f& vert);
////	inline void AddVertex(float x, float y, float z) { AddVertex(Vector3f(x, y, z)); }
//	
//	void AddTexCoord(const Vector2f& texCoord);
////	inline void AddTexCoord(float x, float y) { AddTexCoord(Vector2f(x, y)); }
//	
//	void AddFace(unsigned int vertIndex0, unsigned int vertIndex1, unsigned int vertIndex2);
//	
//	Mesh FinalizeMesh(const std::string& meshName);
//	
//	inline IndexedModel* GetModel() { return &m_model; }
//protected:
//private:
//	IndexedModel m_model;
//};

#endif
