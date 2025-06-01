#pragma once
#include "../tengine/Scene.h"

namespace WH_223
{
	class Game : public TEngine::Scene
	{
	public:
		Game();

		void run_init() override;
		
		void update() override; //Game Loop

		void draw() override; 

		void cleanup() override;
	};
}