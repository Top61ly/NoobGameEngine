#include "sprite.h"

Sprite::Sprite()
	:m_XPos(0), m_YPos(0)
{	
	m_Texture = Texture();
}

Sprite::Sprite(string imagePath)
	:m_XPos(0),m_YPos(0)
{
	m_Texture = Texture(imagePath);
}

Sprite::Sprite(string imagePath, float xPos, float yPos)
	:m_XPos(xPos),m_YPos(yPos)
{
	m_Texture = Texture(imagePath);
}

void Sprite::Update()
{

}

void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_Texture.GetId());
	glLoadIdentity();

	//Translate rotate scale
	glTranslatef(m_XPos, m_YPos, 0);
	//glRotate
	//glScale

	//Rendering
	glColor4f(1,1,1,1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);	glVertex2f(m_XPos, m_YPos);
	glTexCoord2f(1, 0);	glVertex2f(m_XPos+m_Texture.GetWidth(), m_YPos);
	glTexCoord2f(1, 1);	glVertex2f(m_XPos + m_Texture.GetWidth(), m_YPos+m_Texture.GetHeight());
	glTexCoord2f(0, 1);	glVertex2f(m_XPos, m_YPos + m_Texture.GetHeight());
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::SetPos(float x, float y)
{
	m_XPos = x;
	m_YPos = y;
}