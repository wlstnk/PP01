#pragma once

namespace Engine
{
	class Vector2
	{
	public:
		double x;
		double y;

	public:
		void SetPosition(double x, double y)
		{
			this->x = x;
			this->y = y;
		}
		void Move(double x_movement, double y_movement)
		{
			this->x += x_movement;
			this->y += y_movement;
		}
	public:
		bool operator<(Vector2& other)
		{
			if (x < other.x)
			{
				if (y < other.y)
				{
					return true;
				}
			}
			return false;
		}
		bool operator>(Vector2& other)
		{
			if (x > other.x)
			{
				if (y > other.y)
				{
					return true;
				}
			}
			return false;
		}

	};
}