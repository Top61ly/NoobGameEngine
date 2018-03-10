#pragma once
#include "sprite.h"
#include "Rigidbody.h"

class Flapper
{
public:
	Flapper();
	Flapper(const Sprite& _sprite);
	~Flapper();

	void Update();
	void Render();

	Sprite& GetSprite();
	Rigidbody& GetRigidbody();

private:
	Sprite m_Sprite;
	Rigidbody m_RigidBody;
};

