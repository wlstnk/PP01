#pragma once

namespace Engine
{

	class Color
	{
	public:
		Color() {}
		~Color() {}
	public:
		float r =0;
		float g =0;
		float b =0;
	public:
		void SetColor(float r, float g, float b) 
		{ 
			this->r = r * 0.00392f; 
			this->g = g * 0.00392f;
			this->b = b * 0.00392f;
		}
	};
}