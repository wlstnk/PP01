#pragma once
#include "Color.hpp"
namespace Engine
{

	class Player
	{
	public:
		Player() { color.SetColor(207, 255, 229); }
		~Player() {}

	public:
		double x;
		double y;
		Color color;
	public:

	public:
		void isKeyPressed() { y = 20.0; }
		void isKeyUnpressed() { y = 0.0; }
	};
}