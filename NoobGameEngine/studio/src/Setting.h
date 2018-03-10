#pragma once
class Setting
{
public:
	Setting();
	~Setting();
public:
	void SetGravity(const float _gravity);
	static float Gravity();

private:
	static float m_Gravity;
};

float Setting::m_Gravity = 0;

Setting::Setting()
{

}

Setting::~Setting()
{

}

float Setting::Gravity()
{
	return m_Gravity;
}

void Setting::SetGravity(const float _gravity)
{
	m_Gravity = _gravity;
}