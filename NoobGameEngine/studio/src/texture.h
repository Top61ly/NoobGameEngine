#pragma once

#include "GLFW\glfw3.h"
#include "SOIL\SOIL.h"

#include <iostream>
#include <string>

using namespace std;

class Texture
{
public:
	Texture();
	Texture(int id);
	Texture(string path);

	int GetId() const;
	int GetWidth() const;
	int GetHeight() const;

private:
	bool GetTextureParams();

private:
	int m_Id;
	int m_Width;
	int m_Height;
};