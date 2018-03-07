#pragma once

#include "Vector3.h"

class Rigidbody
{
public:
	
	Rigidbody();
	~Rigidbody();

private:
	void Initilaize(float _friction, float _gravity, Vector3* _position, float _rot, Vector3* _scale);

	void Update();
	void Render(const Vector3& c);

	void AddForce(const Vector3& force);

public:
	bool isKinematic;
	Vector3 velocity;

private:
	Vector3* m_Position;
	float* rot;
	Vector3* m_Scale;

	float gravity;
	float friction;
};