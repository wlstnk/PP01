#pragma once

class Vector2
{
public:
	short x;
	short y;
public:
	Vector2()
	{
		x = 0;
		y = 0;
	}
	Vector2(short x, short y)
	{
		SetPosition(x, y);
	}
	~Vector2() {};

public:
	void SetPosition(short x, short y)
	{
		this->x = x;
		this->y = y;
	}
	void Move(short x_value, short y_value)
	{
		this->x += x_value;
		this->y += y_value;
	}

};