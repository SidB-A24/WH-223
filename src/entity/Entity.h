#pragma once
#include "TEngine.h"

namespace WH_223
{
	class Entity
	{
	public:
		Entity();

		Vector2 get_quantised_position();
		Vector2 get_position();

		
		virtual void update();
		virtual void draw();

	private:
		Vector2 p_position;
		
		virtual void p_move_entity(Vector2 direction);
	};
}