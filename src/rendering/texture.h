/*
 * This engine was built upon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirely
 * created by Kyle Pearce.
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include "../core/referenceCounter.h"
#include <GL/glew.h>
#include <string>
#include <map>
//#include <ft2build.h>//10/3/20 - HUD
//#include FT_FREETYPE_H//10/3/20 - HUD
//#include <glm/glm.hpp>//11/3/20
//#include <glm/gtc/type_ptr.hpp>//11/3/20

class TextureData : public ReferenceCounter
{
public:
	TextureData(GLenum textureTarget, int width, int height, int numTextures, unsigned char** data, GLfloat* filters, GLenum* internalFormat, GLenum* format, bool clamp, GLenum* attachments);
	
	void Bind(int textureNum) const;
	void BindAsRenderTarget() const;
	
	inline int GetWidth()  const { return m_width; }
	inline int GetHeight() const { return m_height; }
	
	virtual ~TextureData();
protected:	
private:
	TextureData(TextureData& other) {}
	void operator=(TextureData& other) {}

	void InitTextures(unsigned char** data, GLfloat* filter, GLenum* internalFormat, GLenum* format, bool clamp);
	void InitRenderTargets(GLenum* attachments);

	GLuint* m_textureID;
	GLenum m_textureTarget;
	GLuint m_frameBuffer;
	GLuint m_renderBuffer;
	int m_numTextures;
	int m_width;
	int m_height;
};

class Texture
{
public:
	Texture(const std::string& fileName, GLenum textureTarget = GL_TEXTURE_2D, GLfloat filter = GL_LINEAR_MIPMAP_LINEAR, GLenum internalFormat = GL_RGBA, GLenum format = GL_RGBA, bool clamp = false, GLenum attachment = GL_NONE);
	Texture(int width = 0, int height = 0, unsigned char* data = 0, GLenum textureTarget = GL_TEXTURE_2D, GLfloat filter = GL_LINEAR_MIPMAP_LINEAR, GLenum internalFormat = GL_RGBA, GLenum format = GL_RGBA, bool clamp = false, GLenum attachment = GL_NONE);
	Texture(const Texture& texture);
	//Texture(bool isHUD);//11/3/20
	void operator=(Texture texture);
	virtual ~Texture();

	void Bind(unsigned int unit = 0) const;	
	void BindAsRenderTarget() const;
	
	inline int GetWidth()  const { return m_textureData->GetWidth(); }
	inline int GetHeight() const { return m_textureData->GetHeight(); }
	
	bool operator==(const Texture& texture) const { return m_textureData == texture.m_textureData; }
	bool operator!=(const Texture& texture) const { return !operator==(texture); }
	//virtual void setUpFreeType();//11/3/20
protected:
private:
	static std::map<std::string, TextureData*> s_resourceMap;

	TextureData* m_textureData;
	std::string m_fileName;
};

#endif
