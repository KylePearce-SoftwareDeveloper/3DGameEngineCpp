/*
 * This engine was built uppon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirly
 * created by Kyle Pearce.
 */

#ifndef MESHRENDERER_H_INCLUDED
#define MESHRENDERER_H_INCLUDED

#include "../core/entityComponent.h"
#include "../rendering/mesh.h"

class MeshRenderer : public EntityComponent
{
public:
	MeshRenderer(const Mesh& mesh, const Material& material):
		m_mesh(mesh),
		m_material(material){}

	MeshRenderer(const Mesh& mesh, const Material& material, const Material& secccondaryMaterialArg, const Material& thirdMaterialArg) ://20/3/20
		m_mesh(mesh),
		m_material(material),
		seccondary_material(secccondaryMaterialArg),
		third_material(thirdMaterialArg) {}//20/3/20

	virtual void Render(const Shader& shader, const RenderingEngine& renderingEngine, const Camera& camera) const
	{
		shader.Bind();
		if (draw) {//19/3/20
			if (isTree) {
				shader.UpdateUniforms(GetTransform(), m_material, renderingEngine, camera, true, translations);
				m_mesh.DrawTree();
			}
			else {
				if (useSeccondaryMaterial) {
					shader.UpdateUniforms(GetTransform(), seccondary_material, renderingEngine, camera, false, NULL);
				}
				else if (useThirdMaterial) {
					shader.UpdateUniforms(GetTransform(), third_material, renderingEngine, camera, false, NULL);
				}
				else {
					shader.UpdateUniforms(GetTransform(), m_material, renderingEngine, camera, false, NULL);
				}
				m_mesh.Draw();
			}
		}
	}

	virtual void setIsTree(bool isTreeArg) {
		isTree = isTreeArg;
	}

	virtual void setTranslations(glm::vec3 translationsArg[]) {
		for (int i = 0; i < 1000; i++) {
			translations[i] = translationsArg[i];
		}
	}

	virtual void setUseSeccondaryMaterial(bool arg) { useSeccondaryMaterial = arg; }//19/3/20
	virtual void setUseThirdMaterial(bool arg) { useThirdMaterial = arg; useSeccondaryMaterial = false; }//20/3/20
	virtual void setDraw(bool drawArg) { draw = drawArg; }//19/3/20
	virtual bool getDraw() { return draw; }//20/3/20

protected:
private:
	Mesh m_mesh;
	Material m_material;
	Material seccondary_material;//19/3/20
	Material third_material;//20/3/20
	bool isTree = false;
	bool useSeccondaryMaterial = false;
	bool useThirdMaterial = false;
	glm::vec3 translations[1000];
	bool draw = true;//19/3/20
};

#endif // MESHRENDERER_H_INCLUDED
