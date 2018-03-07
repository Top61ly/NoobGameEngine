#include "Vector3.h"

Vector3::~Vector3()
{

}

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}


Vector3::Vector3(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}

Vector3::Vector3(float _x)
{
	x = _x;
	y = 0;
	z = 0;
}

Vector3::Vector3(float _x, float _y)
{
	x = _x;
	y = _y;
	z = 0;
}

Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}
 
Vector3& Vector3::operator=(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;

	return *this;
}

Vector3 Vector3::operator+(const Vector3& other)
{
	Vector3 ret(other);
	ret.x += x;
	ret.y += y;
	ret.z += z;
	
	return ret;
}

Vector3 Vector3::operator-(const Vector3& other)
{
	Vector3 ret;
	ret.x = x - other.x;
	ret.y = y - other.y;
	ret.z = z - other.z;

	return ret;
}

Vector3 Vector3::operator*(const Vector3& other)
{
	Vector3 ret;

	ret.x = x*other.x;
	ret.y = y*other.y;
	ret.z = z*other.z;

	return ret;
}

Vector3 Vector3::operator/(const Vector3& other)
{
	Vector3 ret;
	ret.x = x / other.x;
	ret.y = y / other.y;
	ret.z = z / other.z;
	return ret;
}

Vector3 Vector3::operator*(const float other)
{
	Vector3 ret;
	ret.x = x*other;
	ret.y = y*other;
	ret.z = z*other;
	return ret;
}

Vector3 Vector3::operator/(const float other)
{
	Vector3 ret;
	ret.x = x / other;
	ret.y = y / other;
	ret.z = z / other;

	return ret;
}

bool Vector3::operator==(const Vector3& other) const
{
	return x == other.x && y == other.y && z == other.z;
}

bool Vector3::operator!=(const Vector3& other) const
{
	return !operator == (other);
}





