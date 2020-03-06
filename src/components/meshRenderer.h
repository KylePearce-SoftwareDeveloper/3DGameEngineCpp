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

#ifndef MESHRENDERER_H_INCLUDED
#define MESHRENDERER_H_INCLUDED

#include "../core/entityComponent.h"
#include "../rendering/mesh.h"

class MeshRenderer : public EntityComponent
{
public:
	MeshRenderer(const Mesh& mesh, const Material& material)://, bool isDynamicRender) :
		m_mesh(mesh),
		m_material(material) {}
	//{
	//	SetDynamicRender(isDynamicRender);//28/2/20
	//}

	virtual void Render(const Shader& shader, const RenderingEngine& renderingEngine, const Camera& camera) const
	{
		shader.Bind();
		//shader.UpdateUniforms(GetTransform(), m_material, renderingEngine, camera);//5/3/20
		if (isTree) {//1/3/20
			shader.UpdateUniforms(GetTransform(), m_material, renderingEngine, camera, true, translations);//6/3/20
			m_mesh.DrawTree();
		}
		else {
			shader.UpdateUniforms(GetTransform(), m_material, renderingEngine, camera, false, NULL);//6/3/20
			m_mesh.Draw();
		}
	}

	virtual void setIsTree(bool isTreeArg) {//1/3/20
		isTree = isTreeArg;
	}

	virtual void setTranslations(glm::vec3 translationsArg[]) {//6/3/20
		//translations = translationsArg;
		for (int i = 0; i < 1000; i++) {
			translations[i] = translationsArg[i];
		}
	}
protected:
private:
	Mesh m_mesh;
	Material m_material;
	bool isTree = false;//1/3/20
	glm::vec3 translations[1000];//6/3/20
};

#endif // MESHRENDERER_H_INCLUDED
