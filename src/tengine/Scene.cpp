#include "Scene.h"
#include "SceneManager.h"
#include "Logger.h"

#include <raylib.h>
#include <iostream>

namespace Engine
{
	Scene::Scene(SceneParameters params)
		:m_windowHeight(params.windowHeight), m_windowWidth(params.windowWidth), m_sceneTitle(params.sceneTitle), m_targetFPS(params.targetFPS)
	{
		
	}

	void Scene::run_init()
	{
		InitWindow(m_windowWidth, m_windowHeight, m_sceneTitle);
		SetTargetFPS(m_targetFPS);

		//Other Scene Initialisation Code
	}

	void Scene::run()
	{
		run_init();

		float lastPerSecondTime = 0.0f;

		while (!WindowShouldClose()) {

			update();

			/**
			Here, GetTime() get's the time since the start of the window
			if lastPerSecondTime is less than get time by a factor of one second, then per second is called
			lastPerSecondTime is incrememnted
			**/
			while (GetTime() - lastPerSecondTime > 1.0f)
			{
				per_second();

				lastPerSecondTime++;
			}
			
			draw();
		}

		
	}

	void Scene::update()
	{
		//Updates Once Per Frame
	}

	void Scene::per_second()
	{
		//Updates Once Per Second
	}

	void Scene::draw()
	{
		BeginDrawing();

		//Draw Code Goes Here

		EndDrawing();
	}

	void Scene::cleanup()
	{
		CloseWindow();
	}
}