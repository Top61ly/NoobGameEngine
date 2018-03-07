#pragma once
class Vector3
{
public:
	Vector3();
	Vector3(const Vector3& other);
	Vector3(float _x);
	Vector3(float _x, float _y);
	Vector3(float _x, float _y, float _z);
	~Vector3();

	Vector3& operator=(const Vector3& other);
	Vector3 operator+(const Vector3& other);
	Vector3 operator-(const Vector3& other);
	Vector3 operator*(const Vector3& other);
	Vector3 operator/(const Vector3& other);
	Vector3 operator*(const float other);
	Vector3 operator/(const float other);

	bool operator==(const Vector3& other) const;
	bool operator!=(const Vector3& other) const;

public:
	float x;
	float y;
	float z;
};
