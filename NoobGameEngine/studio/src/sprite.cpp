#include "sprite.h"

Sprite::Sprite()
	:m_XPos(0), m_YPos(0), m_Rot(0)
{	
	m_Texture = Texture();
}

Sprite::Sprite(string imagePath)
	: m_XPos(0), m_YPos(0), m_Rot(0)
{
	m_Texture = Texture(imagePath);
}

Sprite::Sprite(string imagePath, float xPos, float yPos)
	:m_XPos(xPos),m_YPos(yPos),m_Rot(0)
{
	m_Texture = Texture(imagePath);
}

void Sprite::Update()
{

}


void Sprite::MoveTo(float x, float y)
{
	m_XPos = x;
	m_YPos = y;
}

void Sprite::MoveBy(float x, float y)
{
	m_XPos += x;
	m_YPos += y;
}

void Sprite::RotateTo(float rot)
{
	m_Rot = rot;
}

void Sprite::RotateBy(float rot)
{
	m_Rot += rot;
}

void Sprite::SetScale(float scale)
{
	m_XScale = scale;
	m_YScale = scale;
}

void Sprite::SetScale(float x, float y)
{
	m_XScale = x;
	m_YScale = y;
}

void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_Texture.GetId());
	glLoadIdentity();

	//Translate rotate scale
	glTranslatef(m_XPos, m_YPos, 0);
	//glRotate
	glRotatef(m_Rot, 0, 0, 1);
	//glScale
	glScalef(m_XScale, m_YScale, 1);

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
