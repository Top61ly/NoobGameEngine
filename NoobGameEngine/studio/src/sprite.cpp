#include "sprite.h"

Sprite::Sprite()

{	
	m_Texture = Texture();
	m_Position = Vector3();
	m_Scale = Vector3(1, 1, 1);
	m_Size = Vector3();
	m_Rot = 0;
}

Sprite::Sprite(string imagePath)
{
	m_Texture = Texture(imagePath);
	m_Position = Vector3();
	m_Size = Vector3((float)m_Texture.GetWidth(), (float)m_Texture.GetHeight() , 1);
	m_Scale = Vector3(1,1,1);
}

Sprite::Sprite(string imagePath,const Vector3& position)	
{
	m_Texture = Texture(imagePath);
	m_Position = position;
	m_Scale = Vector3(1, 1, 1);
	m_Size = Vector3((float)m_Texture.GetWidth(), (float)m_Texture.GetHeight(), 1);
	m_Rot = 0;
}

void Sprite::Update()
{

}


void Sprite::MoveTo(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Sprite::MoveBy(float x, float y)
{
	m_Position.x += x;
	m_Position.y += y;
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
	m_Scale.x = scale;
	m_Scale.y = scale;
}

void Sprite::SetScale(float x, float y)
{
	m_Scale.x = x;
	m_Scale.y = y;
}

void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_Texture.GetId());
	glLoadIdentity();

	//Translate rotate scale
	glTranslatef(m_Position.x, m_Position.y, 0);
	//glRotate
	glRotatef(m_Rot, 0, 0, 1);
	//glScale
	glScalef(m_Scale.x, m_Scale.y, m_Scale.z);

	//Rendering
	glColor4f(1,1,1,1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);	glVertex2i(0, 0);
	glTexCoord2f(1, 0);	glVertex2i(m_Texture.GetWidth(),0);
	glTexCoord2f(1, 1);	glVertex2i(m_Texture.GetWidth(),m_Texture.GetHeight());
	glTexCoord2f(0, 1);	glVertex2i(0, m_Texture.GetHeight());
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

Vector3* Sprite::GetPos()
{
	return &m_Position;
}

float* Sprite::GetRot()
{
	return &m_Rot;
}

Vector3* Sprite::GetSize()
{
	return &m_Size;
}

Vector3* Sprite::GetScale()
{
	return &m_Scale;
}