#pragma once

#include "Vector3.h"

class Rigidbody
{
public:
	
	Rigidbody();
	~Rigidbody();

public:
	void Initilaize(const float _friction, const float _gravity,
		Vector3* _position, float* _rot, 
		Vector3* _scale,Vector3* _size);

	void Update();
	void Render(const Vector3& c);

	void AddForce(const Vector3& force);

public:
	bool isKinematic;
	Vector3 velocity;

protected:
	Vector3* m_Position;
	float* m_Rot;
	Vector3* m_Scale;
	Vector3* m_Size;

	float m_Gravity;
	float m_Friction;
};