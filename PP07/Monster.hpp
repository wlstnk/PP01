#pragma once
#include "GameObject.hpp"
namespace Engine
{

	class Monster : public GameObject
	{
	public:
		Monster() { Init(0, 0); }
		Monster(double x, double y) { Init(x, y); }
		~Monster() {}
	public:
		double speed = 2.0;
	public:
		void Init(double x,double y)
		{
			type = Type::MONSTER;
			position.SetPosition(x, y);
			collider.Initialize(3);
			collider.SetCollider(position);			
			color.SetColor(255, 0, 0);
		}
		void Update() 
		{
			position.x = position.x - speed;
			if (position.x < -80) { isDestroy = true; }
			collider.SetCollider(position);
		}
	public:
		void OnCollisionEnter() { std::cout << "\n\nm_hit\n\n"; }

	};
}