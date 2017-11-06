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

private:
	Texture texture;
	float xPos;
	float yPos;

};