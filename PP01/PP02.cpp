
#include <iostream>
#include <string>


using namespace std;

class Player
{
public:
	Player()
	{
		cout << "1�÷��̾� ����!" << endl;
	}
	~Player()
	{
		cout << "1�÷��̾� �Ҹ�!" << endl;
	}
private:


};
class Player2
{
public:
	Player2()
	{
		cout << "2�÷��̾� ����!" << endl;
	}
	~Player2()
	{
		cout << "2�÷��̾� �Ҹ�!" << endl;
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


