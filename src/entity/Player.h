#pragma once

#include "Entity.h"

namespace WH_223
{
	class Player : public Entity
	{
	public:
		Player();

		void update() override;
		void draw() override;
	};
}