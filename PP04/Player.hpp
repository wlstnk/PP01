#pragma once
#include "GameObject.hpp"
class Player : public GameObject
{
public : 
	Player()
	{
	}
	~Player()
	{

	}

public:
	void Initialize()
	{
		mesh = "P";
		position.SetPosition(20,7);
	}
	void Update()
	{
	}

public:
	void isKeyPressed()
	{
		position.y = 5;
	}

	void isKeyUnpressed()
	{
		position.y = 7;
	}

};