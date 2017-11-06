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

}