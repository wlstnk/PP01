#pragma once
#include "MCommand.hpp"

class JumpCommand : public Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "�ѽ� ����!!";
	}
};
class RunCommand : public Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "�ѽ� �޸���!!";
	}
};
class LeftCommand : public Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "�ѽ� ����!!";
	}
};
class RightCommand : public Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "�����̾� ������!!";
	}
};
class DownCommand : public Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "������ ���� ���� ������!!";
	}
};