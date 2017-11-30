#include "texture.h"

Texture::Texture()
{
	m_Id = -1;
}

Texture::Texture(int id)
{
	m_Id = id;
	if (!GetTextureParams())
		cout << "Error loading imge with ID:" << id << endl;
}

Texture::Texture(string path)
{
	m_Id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,SOIL_FLAG_MULTIPLY_ALPHA|SOIL_FLAG_INVERT_Y);
	if (!GetTextureParams())
	{
		cout << "Error loading imges: " << path << endl;
	}
}

int Texture::GetId() const
{
	return m_Id;
}

int Texture::GetHeight() const
{
	return m_Height;
}

int Texture::GetWidth() const
{
	return m_Width;
}

bool Texture::GetTextureParams()
{

	if (m_Id > 0)
	{		
		int mipLevel = 0;
		glBindTexture(GL_TEXTURE_2D, m_Id);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &m_Width);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &m_Height);		
		return true;
	}

	return false;
}