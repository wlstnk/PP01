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
#include "GameObject.hpp"
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
		int m_monsterCreateframe = 100;
		std::vector<GameObject*> m_gameObjects;
		

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
			m_gameObjects.push_back(new Player());
		}
		void Release()
		{
			m_windowManager.Release();
		}

		void Input()
		{
			//if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			//{
			//	for (int i = 0; i < m_gameObjects.size(); i++)
			//	{
			//		m_gameObjects[i]->IsKeyPressed(Key::W);
			//		//m_gameObjects[i]->IsKeyPressed();
			//	}
			//}
			//else
			//{
			//	for (int i = 0; i < m_gameObjects.size(); i++)
			//	{
			//		m_gameObjects[i]->IsKeyPressed(Key::W);
			//		//m_gameObjects[i]->IsKeyUnpressed();
			//	}
			//}
			vector<Key> downKeys;
			vector<Key> upKeys;
			if (GetAsyncKeyState(0x57) & 0x8000 || GetAsyncKeyState(0x57) & 0x8001)
			{
				for (int i = 0; i < m_gameObjects.size(); i++)
				{
					m_gameObjects[i]->IsKeyPressed(Key::W);
				}
			}
			else
			{
				for (int i = 0; i < m_gameObjects.size(); i++)
				{
					m_gameObjects[i]->IsKeyUnpressed(Key::W);
				}
			}
			if (GetAsyncKeyState(0x41) & 0x8000 || GetAsyncKeyState(0x41) & 0x8001)
			{
				for (int i = 0; i < m_gameObjects.size(); i++)
				{
					m_gameObjects[i]->IsKeyPressed(Key::A);
				}
			}
			else
			{
				for (int i = 0; i < m_gameObjects.size(); i++)
				{
					m_gameObjects[i]->IsKeyUnpressed(Key::A);
				}
			}
			if (GetAsyncKeyState(0x53) & 0x8000 || GetAsyncKeyState(0x53) & 0x8001)
			{
				for (int i = 0; i < m_gameObjects.size(); i++)
				{
					m_gameObjects[i]->IsKeyPressed(Key::S);
				}
			}
			else
			{
				for (int i = 0; i < m_gameObjects.size(); i++)
				{
					m_gameObjects[i]->IsKeyUnpressed(Key::S);
				}
			}
			if (GetAsyncKeyState(0x44) & 0x8000 || GetAsyncKeyState(0x44) & 0x8001)
			{
				for (int i = 0; i < m_gameObjects.size(); i++)
				{
					m_gameObjects[i]->IsKeyPressed(Key::D);
				}
			}
			else
			{
				for (int i = 0; i < m_gameObjects.size(); i++)
				{
					m_gameObjects[i]->IsKeyUnpressed(Key::D);
				}
			}

		}
		void Update()
		{
			m_monsterCreateframe++;

			if (m_monsterCreateframe >= 100) {
				m_gameObjects.push_back(new Monster(80,0));
				m_monsterCreateframe = 0;
			}
			for(int i=0;i< m_gameObjects.size();i++)
			{
				m_gameObjects[i]->Update();
				if(m_gameObjects[i]->isDestroy)
				{ 
					delete(m_gameObjects[i]);
					m_gameObjects.erase(m_gameObjects.begin() + i);
				}
			}
		}
		void ColliderCheck()
		{
			for(int i =0; i<m_gameObjects.size(); i++)
			{
				for (int j = 0; j < m_gameObjects.size(); j++)
				{
					if (i == j) { break; }
					cout.precision(5);
					cout << m_gameObjects[i]->collider.left << " , " << m_gameObjects[i]->collider.right << " / ";
					cout << m_gameObjects[i]->collider.bottom << " , " << m_gameObjects[i]->collider.top << "\n";
					cout << "[P]" << m_gameObjects[j]->collider.left << " , " << m_gameObjects[j]->collider.right << " / ";
					cout << m_gameObjects[j]->collider.bottom <<" , "<< m_gameObjects[j]->collider.top << "\n\n";
					if(BoxCollider::ColliderCheck(m_gameObjects[i]->collider, m_gameObjects[j]->collider))
					{
						m_gameObjects[i]->OnCollisionEnter();
						m_gameObjects[j]->OnCollisionEnter();
					}
				}
			}
		}
		void Render()
		{
			m_windowManager.RenderStart();


			for (int i = 0; i < m_gameObjects.size(); i++)
			{
				switch (m_gameObjects[i]->type)
				{
				case Type::PLAYER:
					m_windowManager.DrawSquare(m_gameObjects[i]->position, 0.03f, m_gameObjects[i]->color);
					break;
				case Type::MONSTER:
					m_windowManager.DrawTriangle(m_gameObjects[i]->position, 0.02f, m_gameObjects[i]->color);
					break;

				default:
					break;
				}
			}
			//콜리전 디버그
			/*
			for (int i = 0; i < m_gameObjects.size(); i++)
			{
				Color collcolor;
				collcolor.SetColor(0, 0, 255);
				m_windowManager.DrawSquare(m_gameObjects[i]->collider.left / 100, m_gameObjects[i]->collider.right / 100, m_gameObjects[i]->collider.top / 100, m_gameObjects[i]->collider.bottom / 100, collcolor);

			}
			*/

			m_windowManager.RenderEnd();

			//fps//
			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			startRenderTimePoint = chrono::system_clock::now();
			//string fps = "FPS : " + to_string(1.0 / renderDuration.count());

			this_thread::sleep_for(chrono::milliseconds(20));
		}
	};






}