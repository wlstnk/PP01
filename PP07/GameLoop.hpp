#pragma once
#include <chrono>
#include <thread>
#include <Windows.h>
#include <vector>
#include <iostream>
//#include "Player.hpp"
#pragma comment(lib,"OpenGL32")

#include "WindowManager.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include "BoxCollider.hpp"

using namespace std;

namespace Engine
{
	class GameLoop
	{
	private:
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;
		WindowManager m_windowManager;
		Player p;
		std::vector<Monster> m_monsters;
		int m_monsterCreateframe = 100;
		std::vector<GameObject> m_gameObjects;
		

	public:
		GameLoop() {}
		~GameLoop() {}
		void Run()
		{
			Initialize();

			startRenderTimePoint = chrono::system_clock::now();

			while (!m_windowManager.IsWindowClose())
			{
				Input();
				Update();
				ColliderCheck();
				Render();
				
			}
			Release();
		}
		void Stop()
		{

		}

	private:

		void Initialize()
		{
			m_windowManager.Initialize();
			m_gameObjects.push_back(Player());
		}
		void Release()
		{
			m_windowManager.Release();
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{
				p.IsKeyPressed();
			}
			else
			{
				p.IsKeyUnpressed();
			}

		}
		void Update()
		{
			m_monsterCreateframe++;

			if (m_monsterCreateframe >= 100) {
				m_monsters.push_back(Monster(80,0));
				m_monsterCreateframe = 0;
			}
			for(int i=0;i<m_monsters.size();i++)
			{
				m_monsters[i].Update();
				if(m_monsters[i].isDestroy){m_monsters.erase(m_monsters.begin() + i);}
			}
		}
		void ColliderCheck()
		{
			for(int i =0; i<m_gameObjects.size(); i++)
			{
				for (int j = 0; j < m_gameObjects.size(); j++)
				{
					if (i == j) { break; }
					if(BoxCollider::ColliderCheck(m_gameObjects[0].collider, m_gameObjects[1].collider))
					{
						m_gameObjects[i].OnCollisionEnter();
						m_gameObjects[j].OnCollisionEnter();
					}
				}
			}
		}
		void Render()
		{
			m_windowManager.RenderStart();
			m_windowManager.DrawSquare(p.position,0.03f,p.color);


			for (int i = 0; i < m_monsters.size(); i++)
			{
				m_windowManager.DrawTriangle(m_monsters[i].position, 0.02f,m_monsters[i].color);
			}

			m_windowManager.RenderEnd();

			//fps//
			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			startRenderTimePoint = chrono::system_clock::now();
			//string fps = "FPS : " + to_string(1.0 / renderDuration.count());

			this_thread::sleep_for(chrono::milliseconds(20));
		}
	};






}