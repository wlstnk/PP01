#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include "GameObjectManager.hpp"
#include <queue>

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private :
		bool _isGameRunning;	
		MConsoleRenderer cRenderer;
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;
		GameObjectManager GOManager;
		Vector2 fpsDrawPosition;
		
	public :
		MGameLoop() 	{	_isGameRunning = false;		}
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

			startRenderTimePoint = chrono::system_clock::now();
			while (_isGameRunning)
			{
				
				Input();
				Update();
				Render();
				
			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}

	private :
		void Initialize()
		{
			GOManager.Initialize();
			fpsDrawPosition.SetPosition(10,20);
		}
		void Release() 
		{
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{ 
				GOManager.GetPlayer()->isKeyPressed();
			}
			else 
			{
				GOManager.GetPlayer()->isKeyUnpressed();
			}

		}
		void Update()
		{
			GOManager.Update();
		}
		void Render()
		{

			cRenderer.Clear();

			//cRenderer.MoveCursor(GOManager.GetPlayer()->position);
			//cRenderer.DrawString(GOManager.GetPlayer()->mesh);
			
			for (int i = 0; i < GOManager.keyPoint; i++)
			{
				if (GOManager.gameObjectList[i] != nullptr)
				{
					cRenderer.MoveCursor(GOManager.gameObjectList[i]->position);
					cRenderer.DrawString(GOManager.gameObjectList[i]->mesh);
				}
			}
			
			
			//Draw FPS
			cRenderer.MoveCursor(fpsDrawPosition);
			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			startRenderTimePoint = chrono::system_clock::now();
			string fps = "FPS : " + to_string(1.0 / renderDuration.count());
			cRenderer.DrawString(to_string(GOManager.keyPoint));
			//cRenderer.DrawString(fps);
			this_thread::sleep_for(chrono::milliseconds(20));
		}


			////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

			//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
			//if (remainingFrameTime > 0)
			//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
		

				
		
	};

	


	

}