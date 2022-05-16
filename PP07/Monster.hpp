#pragma once
#include "Color.hpp"
namespace Engine
{

	class Monster
	{
	public:
		Monster() { color.SetColor(240, 0, 0); }
		Monster(double x, double y) { this->x = x; this->y=y; color.SetColor(255, 0, 0);
		}
		~Monster() {}
	public:
		double x;
		double y;
		Color color;
		double speed = 2.0;
		bool isDestroy=false;
	public:
		void Update() 
		{
			x = x - speed;
			if (x < -80) { isDestroy = true; }
		}
	};
}