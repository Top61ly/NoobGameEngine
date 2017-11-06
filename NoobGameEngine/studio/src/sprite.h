#pragma once

#include "GLFW\glfw3.h"
#include "texture.h"

#include <iostream>
#include <string>

using namespace std;

class Sprite
{
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, float xPos, float yPos);

	void Update();
	void Render();

private:
	Texture m_Texture;
	float m_XPos;
	float m_YPos;

};