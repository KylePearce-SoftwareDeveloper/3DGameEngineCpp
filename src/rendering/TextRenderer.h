/*
* The text rendering system was created
* entirely by Kyle Pearce
*/
#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H

#include <map>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "texture.h"
#include "shader.h"


/// Holds all state information relevant to a character as loaded using FreeType
struct Character {
	GLuint TextureID;   // ID handle of the glyph texture
	glm::ivec2 Size;    // Size of glyph
	glm::ivec2 Bearing; // Offset from baseline to left/top of glyph
	GLuint Advance;     // Horizontal offset to advance to next glyph
};

//std::string text = "TEST";
//GLfloat x = 50.0f;
//GLfloat y = 50.0f;
//GLfloat scale = 2.0f;
//Vector3f colour = Vector3f(0, 1, 0);


// A renderer class for rendering text displayed by a font loaded using the 
// FreeType library. A single font is loaded, processed into a list of Character
// items for later rendering.
class TextRenderer// : public EntityComponent
{
public:
	// Holds a list of pre-compiled Characters
	std::map<GLchar, Character> Characters;
	// Shader used for text rendering
	Shader TextShader;
	// Constructor
	TextRenderer();
	//default constructor
	//TextRenderer() = default;

	// Pre-compiles a list of characters from the given font
	void Load(std::string font, GLuint fontSize);
	// Renders a string of text using the precompiled list of characters
	void RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale);

	//virtual void Render(const Shader& shader, const RenderingEngine& renderingEngine, const Camera& camera) const;
	virtual void RenderTextRenderer(const Shader& shader, const RenderingEngine& renderingEngine, const Camera& camera);//12/3/20
	/*{
		RenderText("Lives:", 50.0f, 50.0f, 1.0f, Vector3f(0, 1, 0));
	}*/

	inline std::string getText() { return text; }//18/3/20
	inline void setText(std::string textArg) { text = textArg; }//18/3/20
	inline void setX(GLfloat xArg) { x = xArg; }//19/3/20
	inline void setY(GLfloat yArg) { y = yArg; }//19/3/20
private:
	// Render state
	GLuint VAO, VBO;
	Matrix4f ortho = Matrix4f().InitOrthographic(0.0f, 800.0f, 0.0f, 600.0f, 0, 10.0f);//17/3/20
	Vector3f colour = Vector3f(1, 1, 1);
	std::string text;//18/3/20
	GLfloat x;//19/3/20
	GLfloat y;//19/3/20
	//Material m_material;
};

#endif 