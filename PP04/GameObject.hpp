#pragma once
#include "Vector2.hpp"
#include <string>

class GameObject
{
public:
	int key;
	std::string mesh;
	Vector2 position;
	bool bDistroy;
public:
	GameObject() 
	{
		key = 0;
		mesh = "G";
		position.SetPosition(0, 0);
		bDistroy = false;
	}
	virtual ~GameObject() {}
public:
	virtual void Initialize() {}
	virtual void Update() {}
public:
	virtual void isKeyPressed() {}
	virtual void isKeyUnpressed() {}

};