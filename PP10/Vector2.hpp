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

	};
}