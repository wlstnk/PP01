#pragma once
#include "GameObject.hpp"
#include "Player.hpp"	
#include "Monster.hpp"	
#include <queue>

class GameObjectManager
{
public:
	GameObject** gameObjectList;
	std::queue<int> emptyKey;
	int keyPoint;
	int playerKey;
private:
	int fps;
public:
	GameObjectManager() 
	{
		gameObjectList = new GameObject*;
		playerKey = 0;
		keyPoint = 0;
		fps = 0;
	}
	~GameObjectManager() {}
public:
	template <typename T>
	void Create(T* gameObject)
	{
		//?//
		if(emptyKey.size()>0)
		{
			int key = emptyKey.front();
			emptyKey.pop();
			gameObjectList[key] = gameObject;
			gameObjectList[key]->Initialize();
			gameObjectList[key]->key = key;
		}
		else
		{
			gameObjectList[keyPoint] = gameObject;
			gameObjectList[keyPoint]->Initialize();
			gameObjectList[keyPoint]->key = keyPoint;
			keyPoint++;
		}
		
	}
	template <typename T>
	void Destroy(T* gameObject)
	{
		int key = gameObject->key;
		delete(gameObjectList[key]);
		gameObjectList[key] = nullptr;
		emptyKey.push(key);
	}
public:
	void Initialize()
	{
		
		Create(new Player());
		Create(new Monster());

		for (int i = 0; i < keyPoint; i++)
		{
			if (gameObjectList[i] != nullptr)
			{
				gameObjectList[i]->Initialize();
			}
		}

	}
	void Update()
	{
		fps++;
		if(fps>15)
		{
			Create(new Monster());
			fps = 0;
		}

		for (int i=0; i < keyPoint; i++)
		{
			if (gameObjectList[i] != nullptr)
			{
				gameObjectList[i]->Update();
				if(gameObjectList[i]->bDistroy == true)
				{
					Destroy(gameObjectList[i]);
				}
			}
		}
	}
public:
	GameObject* GetPlayer()
	{
		return gameObjectList[playerKey];
	}
};