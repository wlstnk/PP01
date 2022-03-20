
#include <iostream>
#include <string>


using namespace std;
bool is_game_state;

class GameObject
{
public:
	GameObject()
	{
		cout << "게임 오브젝트 생성\n";
	}
	virtual ~GameObject()
	{
		cout << "게임 오브젝트 소멸\n";
	}

	virtual void Start()
	{
		cout << "게임 오브젝트 초기화\n";
	}
	virtual void Update()
	{
		cout << "게임 오브젝트 업데이트\n";
	}
};

class Player : public GameObject
{
public:
	int Hp = 30;
	Player()
	{
		cout << "박진수 생성\n";
	}
	~Player()
	{
		cout << "박진수 소멸\n";
	}

	void Start()
	{
		cout << "박진수 스타트 Hp("<<Hp<<")\n";
	}
	void Update()
	{
		cout << "박진수 업데이트\n";
	}
};
class Enemy :public GameObject
{
public:
	int Hp = 100;

	Enemy()
	{
		cout << "적 생성\n";
	}
	~Enemy()
	{
		cout << "적 소멸\n";
	}

	void Start() 
	{
		cout << "적 스타트 Hp(" << Hp << ")\n";
	
	}
	void Update() 
	{
		cout << "적 업데이트\n";
	
	}
};


int main()
{
	is_game_state = true;
	GameObject* p = new Player();
	GameObject* e = new Enemy();

	p->Start();
	e->Start();

	while (is_game_state) 
	{
		p->Update();
		e->Update();
		cout << "입력해주세요 (1:게임종료 2:게임계속)";
		int input;
		cin >> input;

		if (input == 1) 
		{
			is_game_state = false;
		}
	}

	delete(p);
	delete(e);

	return 0;
}


