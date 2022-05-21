#pragma once
#include "GameObject.hpp"
namespace Engine
{

	class Player : public GameObject
	{
	public:
		Player() { Init(0, 0); }
		Player(double x,double y) { Init(x, y); }
		~Player() {}
	public:
		void Init(double x,double y)
		{
			type = Type::PLAYER;
			position.SetPosition(0, 0);
			collider.Initialize(0.03f);
			collider.SetCollider(position);
			color.SetColor(207, 255, 229);
		}
		void Update() 
		{
			collider.SetCollider(position);
		
		}
	public:
		void IsKeyPressed() { position.y = 20.0; }
		void IsKeyUnpressed() { position.y = 0.0; }
	public:
		void OnCollisionEnter() { std::cout << "p_hit"; }
	};
}