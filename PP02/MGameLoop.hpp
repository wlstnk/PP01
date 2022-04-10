#pragma once

namespace Musoeun
{
	MCommand* key[5];

	void Initialize()
	{
		key[0] = new LeftCommand();
		key[1] = new RightCommand();
		key[2] = new DownCommand();
		key[3] = new JumpCommand();
		key[4] = new RunCommand();
		//std::cout << "�ʱ�ȭ ��...\n";
	}

	void Input()
	{
		int input;
		std::cin >> input;

		key[input]->Execute();
		
		//std::cout << "�Է� ��...\n";
		
	}

	void Update()
	{
		//std::cout << "Update ��...\n";
	}

	void Render()
	{
		//std::cout << "Rendering ��...\n";
	}

	void Release()
	{
		//std::cout << "���� ��...\n";

		for (size_t i = 0; i < 5; i++)
		{
			delete(key[i]);
		}
		
	}

	class MGameLoop
	{
	public:
		bool isGameRunning = false;

		MGameLoop() {}
		~MGameLoop() {}

		void Run()
		{
			isGameRunning = true;

			Initialize();

			while (isGameRunning)
			{
				Input();
				Update();
				Render();
			}
			
			Release();
		}
	};
}