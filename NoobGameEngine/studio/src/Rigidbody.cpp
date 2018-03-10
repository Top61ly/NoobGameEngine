#include "Rigidbody.h"
#include "Setting.h"
#include "window.h"

Rigidbody::Rigidbody()
{
	m_Friction = 0.5f;
	m_Gravity = Setting::Gravity();
}

Rigidbody::~Rigidbody()
{

}

void Rigidbody::Initilaize(const float _friction, const float _gravity,
	Vector3* _position, float* _rot,
	Vector3* _scale, Vector3* _size)
{
	m_Friction = _friction;
	m_Gravity = _gravity;
	m_Position = _position;
	m_Rot = _rot;
	m_Scale = _scale;
	m_Size = _size;
}

void Rigidbody::Update()
{
	velocity.x *= m_Friction;
	velocity.y -= m_Gravity;

	*m_Position = *m_Position + velocity*Window::GetDeltaTime();
}

void Rigidbody::Render(const Vector3& c)
{
	glLoadIdentity();

	glTranslatef(m_Position->x, m_Position->y, m_Position->z);
	glRotatef(*m_Rot, 0, 0, 1);
	glScalef(m_Scale->x, m_Scale->y, m_Scale->z);

	//Rendering
	glColor4f(c.x,c.y,c.z, 1);
	glBegin(GL_LINES);
	{
		glVertex2i(0, 0);
		glVertex2i((int)m_Size->x, 0);

		glVertex2i((int)m_Size->x, 0);
		glVertex2i((int)m_Size->x, (int)m_Size->y);

		glVertex2i(0, (int)m_Size->y);
		glVertex2i(0, 0);

		glVertex2i((int)m_Size->x, (int)m_Size->y);
		glVertex2i(0, (int)m_Size->y);
	}
	glEnd();

}

void Rigidbody::AddForce(const Vector3& force)
{
	velocity = velocity + force;
}