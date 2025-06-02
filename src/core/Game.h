#pragma once

#include "TEngine.h"
#include "Resources.h"
#include "Labyrinth.h"

#include <string>
#include <sstream>
#include <vector>
#include <filesystem>
#include <memory>


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

	private:
		std::shared_ptr<Labyrinth> p_labyrinthPtr;

		Vector2 viewportDimensions;
		Vector2 cameraPosition;
		bool isCameraClampedToPlayer;

		RenderTexture2D panelTexture;
	};
}