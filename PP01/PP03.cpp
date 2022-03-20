
#include <iostream>
#include <string>


using namespace std;
bool is_game_state;

class GameObject
{
public:
	GameObject()
	{
		cout << "���� ������Ʈ ����\n";
	}
	virtual ~GameObject()
	{
		cout << "���� ������Ʈ �Ҹ�\n";
	}

	virtual void Start()
	{
		cout << "���� ������Ʈ �ʱ�ȭ\n";
	}
	virtual void Update()
	{
		cout << "���� ������Ʈ ������Ʈ\n";
	}
};

class Player : public GameObject
{
public:
	int Hp = 30;
	Player()
	{
		cout << "������ ����\n";
	}
	~Player()
	{
		cout << "������ �Ҹ�\n";
	}

	void Start()
	{
		cout << "������ ��ŸƮ Hp("<<Hp<<")\n";
	}
	void Update()
	{
		cout << "������ ������Ʈ\n";
	}
};
class Enemy :public GameObject
{
public:
	int Hp = 100;

	Enemy()
	{
		cout << "�� ����\n";
	}
	~Enemy()
	{
		cout << "�� �Ҹ�\n";
	}

	void Start() 
	{
		cout << "�� ��ŸƮ Hp(" << Hp << ")\n";
	
	}
	void Update() 
	{
		cout << "�� ������Ʈ\n";
	
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
		cout << "�Է����ּ��� (1:�������� 2:���Ӱ��)";
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


