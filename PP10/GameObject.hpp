#pragma once
#include <iostream>
#include "Color.hpp"
#include "Vector2.hpp"
#include "BoxCollider.hpp"
namespace Engine
{
	enum Type
	{
		GAMEOBJECT, PLAYER, MONSTER
	};
	enum Key
	{
		W, A, S, D
	};
	interface GameObject
	{
	public:
		virtual ~GameObject() {}

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
		virtual void IsKeyPressed(Key key) {}
		virtual void IsKeyUnpressed(Key key) {}
	public:
		virtual void OnCollisionEnter() {}
	};
}