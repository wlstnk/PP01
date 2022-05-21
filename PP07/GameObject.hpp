#pragma once
#include <iostream>
#include "Color.hpp"
#include "Vector2.hpp"
#include "BoxCollider.hpp"
namespace Engine
{
	class GameObject
	{
	public:
		GameObject()
		{
			Init(0, 0);
		}
		GameObject(double x,double y)
		{
			Init(x, y);
		}
		virtual ~GameObject() {}

		enum Type
		{
			GAMEOBJECT, PLAYER, MONSTER
		};
	public:
		Vector2 position;
		Color color;
		BoxCollider collider;
		Type type;
		bool isDestroy = false;
	public:
		virtual void Init(double x, double y) 
		{
			type = Type::GAMEOBJECT;
		}
		virtual void Update() {}
	public:
		virtual void IsKeyPressed() {}
		virtual void IsKeyUnpressed() {}
	public:
		virtual void OnCollisionEnter() {}
	};
}