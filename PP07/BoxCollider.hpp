#pragma once
#include "Vector2.hpp"
namespace Engine
{
	class BoxCollider
	{
	public:
		double size;

		double left;
		double right;
		double bottom;
		double top;

	public:
		void Initialize(double size)
		{
			this->size = size;
		}
		void SetCollider(Vector2 position)
		{
			left = position.x - size;
			right = position.x + size;
			bottom = position.y - size;
			top = position.y + size;
			
			/*lt.SetPosition(position.x - size, position.y + size);
			rb.SetPosition(position.x + size, position.y - size);*/
		}
		bool static ColliderCheck(BoxCollider a,BoxCollider b) 
		{
			return a.right > b.left
				&& a.left < b.right
				&& a.top > b.bottom
				&& a.bottom < b.top;
		}

	};
}