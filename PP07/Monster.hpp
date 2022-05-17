#pragma once
#include "Color.hpp"
#include "BoxCollider.hpp"
#include "Vector2.hpp"
namespace Engine
{

	class Monster
	{
	public:
		Monster() { Initialize(0, 0); }
		Monster(double x, double y) { Initialize(x, y); }
		~Monster() {}
	public:
		Vector2 position;
		Color color;
		BoxCollider collider;

		double speed = 2.0;
		bool isDestroy = false;
	public:
		void Initialize(double x,double y)
		{
			position.SetPosition(x, y);
			collider.Initialize(0.02f);
			collider.SetCollider(position);			
			color.SetColor(255, 0, 0);
		}
		void Update() 
		{
			position.x = position.x - speed;
			if (position.x < -80) { isDestroy = true; }
		}
	public:

	};
}