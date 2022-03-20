
#include <iostream>
#include <string>


using namespace std;

class Player
{
public:
	Player()
	{
		cout << "1플레이어 생성!" << endl;
	}
	~Player()
	{
		cout << "1플레이어 소멸!" << endl;
	}
private:


};
class Player2
{
public:
	Player2()
	{
		cout << "2플레이어 생성!" << endl;
	}
	~Player2()
	{
		cout << "2플레이어 소멸!" << endl;
	}
private:


};

void Player2Create()
{
	Player2 pl;
}

int main()
{
	Player2Create();
	Player *player = new Player();
	delete(player);
	return 0;
}


