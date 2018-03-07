#pragma once

#include "GLFW\glfw3.h"
#include "texture.h"
#include "Vector3.h"

#include <iostream>
#include <string>

using namespace std;

class Sprite
{
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, const Vector3& position);

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
	Vector3 m_Position;
	Vector3 m_Scale;
	float m_Rot;
};