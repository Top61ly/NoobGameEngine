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

	void MoveTo(float x, float y);
	void MoveBy(float x, float y);

	void RotateTo(float rot);
	void RotateBy(float rot);

	void SetScale(float scale);
	void SetScale(float x, float y);
private:
	Texture m_Texture;

	float m_XPos;
	float m_YPos;
	float m_Rot;
	float m_XScale;
	float m_YScale;
};