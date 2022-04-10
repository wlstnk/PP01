#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "MTimer.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private :
		bool _isGameRunning;	
		MConsoleRenderer cRenderer;

	private:
		chrono::system_clock::time_point prevTimePoint ;
		chrono::duration<double> loopDuration;
		double deltaTime = 0.0;
		int fps = 0;
		string fpsStr;
		
	public :
		MGameLoop() 	{	_isGameRunning = false;		}
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

			while (_isGameRunning)
			{
				loopDuration = chrono::system_clock::now() - prevTimePoint;
				prevTimePoint = chrono::system_clock::now();
				deltaTime = loopDuration.count();
				Input();
				Update();
				Render();
				fps++;
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
			deltaTime = 0.0;
		}
		void Release() 
		{
		}

		void Input()
		{
		/*	if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{ 
		
			}
			else 
			{
			
			}*/

		}
		void Update()
		{
			
		}
		void Render()
		{
			static double oneSecCounter = 0.0;

			oneSecCounter += deltaTime;
			if (oneSecCounter >= 1)
			{
				oneSecCounter = 0;
				fpsStr = "FPS : " + to_string(fps);
				fps = 0;
			}

			cRenderer.DrawString(fpsStr);
			system("cls");
			cRenderer.MoveCursor(10, 20);
		}
	};
}