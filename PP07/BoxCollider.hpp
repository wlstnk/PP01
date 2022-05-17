#pragma once
#include "Vector2.hpp"
namespace Engine
{
	class BoxCollider
	{
	public:
		double size;

		Vector2 lb;
		Vector2 rt;
		Vector2 lt;
		Vector2 rb;

	public:
		void Initialize(double size)
		{
			this->size = size;
		}
		void SetCollider(Vector2 position)
		{
			lb.SetPosition(position.x - size, position.y - size);
			rt.SetPosition(position.x + size, position.y + size);
			lt.SetPosition(position.x - size, position.y + size);
			rb.SetPosition(position.x + size, position.y - size);
		}
		bool ColliderCheck(BoxCollider other) 
		{
			if (lb < other.lb)
			{
				if (rt > other.lb)
				{
					return true;
				}
			}
			if (lb < other.lt)
			{
				if (rt > other.lt)
				{
					return true;
				}
			}
			if (lb < other.rb)
			{
				if (rt > other.rb)
				{
					return true;
				}
			}
			if (lb < other.rt)
			{
				if (rt > other.rt)
				{
					return true;
				}
			}
			return false;
		}

	};
}