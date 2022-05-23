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
		double m_speed = 1 ;
	public:
		void Init(double x,double y)
		{
			type = Type::PLAYER;
			position.SetPosition(0, 0);
			collider.Initialize(3);
			collider.SetCollider(position);
			color.SetColor(207, 255, 229);
		}
		void Update() 
		{
			collider.SetCollider(position);
		
		}
	public:
		void IsKeyPressed(Key key)
		{ 
			switch (key)
			{
			case Key::W:
				position.y += m_speed;
				break;
			case Key::S:
				position.y -= m_speed;
				break;
			case Key::A:
				position.x -= m_speed;
				break;
			case Key::D:
				position.x += m_speed;
				break;
			default:
				break;
			}
		}
		void IsKeyUnpressed(Key key) 
		{ 
		}
	public:
		void OnCollisionEnter() {}
	};
}