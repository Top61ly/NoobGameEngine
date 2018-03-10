#include "Flapper.h"

Flapper::Flapper()
{

}

Flapper::Flapper(const Sprite& _sprite)
{
	m_Sprite = _sprite;
	m_RigidBody.Initilaize(0, 0, m_Sprite.GetPos(), m_Sprite.GetRot()
		,m_Sprite.GetScale(),m_Sprite.GetSize());
}

Flapper::~Flapper()
{

}

void Flapper::Update()
{
	m_Sprite.Update();
	m_RigidBody.Update();
}

Sprite& Flapper::GetSprite()
{
	return m_Sprite;
}

Rigidbody& Flapper::GetRigidbody()
{
	return m_RigidBody;
}

void Flapper::Render()
{
	m_Sprite.Render();
	m_RigidBody.Render(Vector3(0));
}