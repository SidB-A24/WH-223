#pragma once

#include <raylib.h>

namespace Engine
{
	struct SceneParameters {
		int windowWidth = 1920;
		int windowHeight = 1080;
		const char* sceneTitle = "Scene";
		int targetFPS = 60;
	};

	class Scene {
	public:
		Scene(SceneParameters params);

		virtual void run_init(); //Called at the start of run
		virtual void run(); //Starts running the Scene
		
		virtual void update(); //Called within run loop once per frame
		virtual void per_second(); //Called once per second from the run loop
		
		virtual void draw(); //Performs rendering

		virtual void cleanup(); //Called when the Scene exits

	public:
		int get_windowHeight() const
		{
			return m_windowHeight;
		}
		int get_windowWidth() const
		{
			return m_windowWidth;
		}
		const char* get_sceneTitle() const
		{
			return m_sceneTitle;
		}

	protected:
		const int m_windowHeight;
		const int m_windowWidth;
		const char* const m_sceneTitle;
		const int m_targetFPS; //Raylib window FPS limit
	

	};

}
