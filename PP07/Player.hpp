#pragma once
#include "Color.hpp"
#include "Vector2.hpp"
#include "BoxCollider.hpp"
namespace Engine
{

	class Player
	{
	public:
		Player() { Initialize(); }
		~Player() {}

	public:
		Vector2 position;
		Color color;
		BoxCollider collider;
	public:
		void Initialize()
		{
			position.SetPosition(0, 0);
			collider.Initialize(0.03f);
			collider.SetCollider(position);
			color.SetColor(207, 255, 229);
		}
		void Update() {}
	public:
		void IsKeyPressed() { position.y = 20.0; }
		void IsKeyUnpressed() { position.y = 0.0; }
	};
}