#pragma once
#include "GameObject.hpp"
#include <random>
class Monster :public GameObject
{
	double spawnCounter;
public:
	Monster()
	{
		spawnCounter = 0;
	}
	~Monster()
	{

	}
public:
	void Initialize() 
	{
		mesh = "M"; 
		
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0, 1);

		switch (dis(gen)) 
		{
		case 1:
			position.SetPosition(40, 7);
			break;
		default:
			position.SetPosition(40, 5);
			break;
		}
	}
	void Update()
	{
		position.Move(-1, 0);
		if (position.x <= 3)
		{
			bDistroy = true;
		}
	}

};