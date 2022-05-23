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
		Player* p;
		Monster* m;
		

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
			p = new Player();
			m = new Monster(30,0);
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
					p->IsKeyPressed(Key::W);
			}
			else
			{
					p->IsKeyUnpressed(Key::W);
			}
			if (GetAsyncKeyState(0x41) & 0x8000 || GetAsyncKeyState(0x41) & 0x8001)
			{
					p->IsKeyPressed(Key::A);
			}
			else
			{
				p->IsKeyUnpressed(Key::A);
			}
			if (GetAsyncKeyState(0x53) & 0x8000 || GetAsyncKeyState(0x53) & 0x8001)
			{
				p->IsKeyPressed(Key::S);
			}
			else
			{
				p->IsKeyUnpressed(Key::S);
			}
			if (GetAsyncKeyState(0x44) & 0x8000 || GetAsyncKeyState(0x44) & 0x8001)
			{
				p->IsKeyPressed(Key::D);
			}
			else
			{
				p->IsKeyUnpressed(Key::D);
			}

		}
		void Update()
		{
			p->Update();
			m->Update();
		}
		void ColliderCheck()
		{
			if(BoxCollider::ColliderCheck(p->collider, m->collider))
			{
				p->OnCollisionEnter();
				m->OnCollisionEnter();
			}
		}
		void Render()
		{
			m_windowManager.RenderStart();

			m_windowManager.DrawTriangle(m->position, 0.02f, m->color);
			m_windowManager.DrawSquare(p->position, 0.03f, p->color);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE);
			m_windowManager.DrawTriangle(m->position, 0.02f, m->color);

			/*Color collcolor;
			collcolor.SetColor(0, 0, 255);
			Color collcolor2;
			collcolor2.SetColor(0, 255, 0);
			Vector2 testposition;
			testposition.SetPosition(3, 3);
			Vector2 testposition2;
			testposition2.SetPosition(5, 5);
			m_windowManager.DrawSquare(testposition, 0.03f, collcolor);
			m_windowManager.DrawSquare(testposition2, 0.03f, collcolor2);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE);
			m_windowManager.DrawSquare(testposition, 0.03f, collcolor);
			glDisable(GL_BLEND);*/

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