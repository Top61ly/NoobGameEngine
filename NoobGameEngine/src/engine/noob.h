#pragma once


namespace Noob
{

	struct Entity
	{
		int index;
		bool operator == (const Entity& rhs) const { return rhs.index == index; };
		bool operator <(const Entity& rhs) const { return rhs.index < index; };
		bool operator > (const Entity& rhs) const { return rhs.index > index; };
		bool operator != (const Entity& rhs) const { return rhs.index != index; };
		bool IsValid() const { return index >= 0; }
	};

}