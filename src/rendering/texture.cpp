/*
 * This engine was built upon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirely
 * created by Kyle Pearce.
 */

#include "texture.h"

#include "../core/math3d.h"
#include "../core/profiling.h"

#include "../staticLibs/stb_image.h"

#include <iostream>
#include <cassert>
#include <cstring>

std::map<std::string, TextureData*> Texture::s_resourceMap;

////11/3/20
//struct Character {
//	GLuint     TextureID;  // ID handle of the glyph texture
//	glm::ivec2 Size;       // Size of glyph
//	glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
//	GLuint     Advance;    // Offset to advance to next glyph
//};
//std::map<GLchar, Character> Characters;

TextureData::TextureData(GLenum textureTarget, int width, int height, int numTextures, unsigned char** data, GLfloat* filters, GLenum* internalFormat, GLenum* format, bool clamp, GLenum* attachments)
{
	m_textureID = new GLuint[numTextures];
	m_textureTarget = textureTarget;
	m_numTextures = numTextures;
	
	#if PROFILING_SET_2x2_TEXTURE == 0
		m_width = width;
		m_height = height;
	#else
		m_width = 2;
		m_height = 2;
	#endif
	m_frameBuffer = 0;
	m_renderBuffer = 0;
	
	InitTextures(data, filters, internalFormat, format, clamp);
	InitRenderTargets(attachments);
}

TextureData::~TextureData()
{
	if(*m_textureID) glDeleteTextures(m_numTextures, m_textureID);
	if(m_frameBuffer) glDeleteFramebuffers(1, &m_frameBuffer);
	if(m_renderBuffer) glDeleteRenderbuffers(1, &m_renderBuffer);
	if(m_textureID) delete[] m_textureID;
}

void TextureData::InitTextures(unsigned char** data, GLfloat* filters, GLenum* internalFormat, GLenum* format, bool clamp)
{
	glGenTextures(m_numTextures, m_textureID);
	for(int i = 0; i < m_numTextures; i++)
	{
		glBindTexture(m_textureTarget, m_textureID[i]);
			
		glTexParameterf(m_textureTarget, GL_TEXTURE_MIN_FILTER, filters[i]);
		glTexParameterf(m_textureTarget, GL_TEXTURE_MAG_FILTER, filters[i]);
		
		if(clamp)
		{
			glTexParameterf(m_textureTarget, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameterf(m_textureTarget, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		}
		
		glTexImage2D(m_textureTarget, 0, internalFormat[i], m_width, m_height, 0, format[i], GL_UNSIGNED_BYTE, data[i]);
		
		if(filters[i] == GL_NEAREST_MIPMAP_NEAREST ||
			filters[i] == GL_NEAREST_MIPMAP_LINEAR ||
			filters[i] == GL_LINEAR_MIPMAP_NEAREST ||
			filters[i] == GL_LINEAR_MIPMAP_LINEAR)
		{
			glGenerateMipmap(m_textureTarget);
			GLfloat maxAnisotropy;
			glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropy);
			glTexParameterf(m_textureTarget, GL_TEXTURE_MAX_ANISOTROPY_EXT, Clamp(0.0f, 8.0f, maxAnisotropy));
		}
		else
		{
			glTexParameteri(m_textureTarget, GL_TEXTURE_BASE_LEVEL, 0);
			glTexParameteri(m_textureTarget, GL_TEXTURE_MAX_LEVEL, 0);
		}
	}
}

void TextureData::InitRenderTargets(GLenum* attachments)
{
	if(attachments == 0)
		return;

	GLenum drawBuffers[32];      //32 is the max number of bound textures in OpenGL
	assert(m_numTextures <= 32); //Assert to be sure no buffer overrun should occur

	bool hasDepth = false;
	for(int i = 0; i < m_numTextures; i++)
	{
		if(attachments[i] == GL_DEPTH_ATTACHMENT)
		{
			drawBuffers[i] = GL_NONE;
			hasDepth = true;
		}
		else
			drawBuffers[i] = attachments[i];
	
		if(attachments[i] == GL_NONE)
			continue;
		
		if(m_frameBuffer == 0)
		{
			glGenFramebuffers(1, &m_frameBuffer);
			glBindFramebuffer(GL_FRAMEBUFFER, m_frameBuffer);
		}
		
		glFramebufferTexture2D(GL_FRAMEBUFFER, attachments[i], m_textureTarget, m_textureID[i], 0);
	}
	
	if(m_frameBuffer == 0)
		return;
	
	if(!hasDepth)
	{
		glGenRenderbuffers(1, &m_renderBuffer);
		glBindRenderbuffer(GL_RENDERBUFFER, m_renderBuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, m_width, m_height);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_renderBuffer);
	}
	
	glDrawBuffers(m_numTextures, drawBuffers);
	
	//glDrawBuffer(GL_NONE);
	//glReadBuffer(GL_NONE);
	
	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		std::cerr << "Framebuffer creation failed!" << std::endl;
		assert(false);
	}
	
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void TextureData::Bind(int textureNum) const
{
	glBindTexture(m_textureTarget, m_textureID[textureNum]);
}

void TextureData::BindAsRenderTarget() const
{
	glBindTexture(GL_TEXTURE_2D,0);
	glBindFramebuffer(GL_FRAMEBUFFER, m_frameBuffer);
	
	#if PROFILING_SET_1x1_VIEWPORT == 0
		glViewport(0, 0, m_width, m_height);
	#else
		glViewport(0, 0, 1, 1);
	#endif
}

Texture::Texture(const std::string& fileName, GLenum textureTarget, GLfloat filter, GLenum internalFormat, GLenum format, bool clamp, GLenum attachment)
{
 	m_fileName = fileName;

		std::map<std::string, TextureData*>::const_iterator it = s_resourceMap.find(fileName);
		if (it != s_resourceMap.end())
		{
			m_textureData = it->second;
			m_textureData->AddReference();
		}
		else
		{
			int x, y, bytesPerPixel;
			unsigned char* data = stbi_load(("../res/textures/" + fileName).c_str(), &x, &y, &bytesPerPixel, 4);

			if (data == NULL)
			{
				std::cerr << "Unable to load texture: " << fileName << std::endl;
			}

			m_textureData = new TextureData(textureTarget, x, y, 1, &data, &filter, &internalFormat, &format, clamp, &attachment);
			stbi_image_free(data);

			s_resourceMap.insert(std::pair<std::string, TextureData*>(fileName, m_textureData));
		}
}

Texture::Texture(int width, int height, unsigned char* data, GLenum textureTarget, GLfloat filter, GLenum internalFormat, GLenum format, bool clamp, GLenum attachment)
{
	m_fileName = "";
	m_textureData = new TextureData(textureTarget, width, height, 1, &data, &filter, &internalFormat, &format, clamp, &attachment);
}

Texture::Texture(const Texture& texture) :
	m_textureData(texture.m_textureData),
	m_fileName(texture.m_fileName)
{
	m_textureData->AddReference();
}

//Texture::Texture(bool isHUD) {//11/3/20
//		FT_Library ft;
//		if (FT_Init_FreeType(&ft))
//			printf("ERROR::FREETYPE: Could not init FreeType Library\n");//std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
//
//		FT_Face face;
//		if (FT_New_Face(ft, "font/arial.ttf", 0, &face))
//			printf("ERROR::FREETYPE: Failed to load font\n");//std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
//
//		FT_Set_Pixel_Sizes(face, 0, 48);
//
//		if (FT_Load_Char(face, 'X', FT_LOAD_RENDER))
//			printf("ERROR::FREETYTPE: Failed to load Glyph\n");//std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
//
//		glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Disable byte-alignment restriction
//
//		for (GLubyte c = 0; c < 128; c++)
//		{
//			// Load character glyph 
//			if (FT_Load_Char(face, c, FT_LOAD_RENDER))
//			{
//				printf("ERROR::FREETYTPE: Failed to load Glyph\n");//std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
//				continue;
//			}
//			// Generate texture
//			GLuint texture;
//			glGenTextures(1, &texture);
//			glBindTexture(GL_TEXTURE_2D, texture);
//			glTexImage2D(
//				GL_TEXTURE_2D,
//				0,
//				GL_RED,
//				face->glyph->bitmap.width,
//				face->glyph->bitmap.rows,
//				0,
//				GL_RED,
//				GL_UNSIGNED_BYTE,
//				face->glyph->bitmap.buffer
//			);
//			// Set texture options
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//			// Now store character for later use
//			Character character = {
//				texture,
//				glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
//				glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
//				face->glyph->advance.x
//			};
//			Characters.insert(std::pair<GLchar, Character>(c, character));
//		}
//		FT_Done_Face(face);
//		FT_Done_FreeType(ft);
//		printf("FREE_TYPE_SET-UP");
//}

void Texture::operator=(Texture texture)
{
	char* temp[sizeof(Texture)/sizeof(char)];
	memcpy(temp, this, sizeof(Texture));
	memcpy(this, &texture, sizeof(Texture));
	memcpy(&texture, temp, sizeof(Texture));
}

Texture::~Texture()
{
	if(m_textureData && m_textureData->RemoveReference())
	{
		if(m_fileName.length() > 0)
			s_resourceMap.erase(m_fileName);
			
		delete m_textureData;
	}
}

void Texture::Bind(unsigned int unit) const
{
	assert(unit >= 0 && unit <= 31);
	glActiveTexture(GL_TEXTURE0 + unit);
	m_textureData->Bind(0);
}

void Texture::BindAsRenderTarget() const
{
	m_textureData->BindAsRenderTarget();
}

//void Texture::setUpFreeType() {//11/3/20
//	FT_Library ft;
//	if (FT_Init_FreeType(&ft))
//		printf("ERROR::FREETYPE: Could not init FreeType Library\n");//std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
//
//	FT_Face face;
//	if (FT_New_Face(ft, "font/arial.ttf", 0, &face))
//		printf("ERROR::FREETYPE: Failed to load font\n");//std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
//
//	FT_Set_Pixel_Sizes(face, 0, 48);
//
//	if (FT_Load_Char(face, 'X', FT_LOAD_RENDER))
//		printf("ERROR::FREETYTPE: Failed to load Glyph\n");//std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
//
//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Disable byte-alignment restriction
//
//	for (GLubyte c = 0; c < 128; c++)
//	{
//		// Load character glyph 
//		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
//		{
//			printf("ERROR::FREETYTPE: Failed to load Glyph\n");//std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
//			continue;
//		}
//		// Generate texture
//		GLuint texture;
//		glGenTextures(1, &texture);
//		glBindTexture(GL_TEXTURE_2D, texture);
//		glTexImage2D(
//			GL_TEXTURE_2D,
//			0,
//			GL_RED,
//			face->glyph->bitmap.width,
//			face->glyph->bitmap.rows,
//			0,
//			GL_RED,
//			GL_UNSIGNED_BYTE,
//			face->glyph->bitmap.buffer
//		);
//		// Set texture options
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//		// Now store character for later use
//		Character character = {
//			texture,
//			glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
//			glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
//			face->glyph->advance.x
//		};
//		Characters.insert(std::pair<GLchar, Character>(c, character));
//	}
//	FT_Done_Face(face);
//	FT_Done_FreeType(ft);
//}
