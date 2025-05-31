#pragma once

#include <raylib.h>
#include <queue>
#include <memory>

#include "Scene.h"

namespace Engine {
	class SceneManager {
	public:
		//Ensuring no copying
		SceneManager();
		static SceneManager& Instance();

		~SceneManager();

	public:
		void push_scene(const std::shared_ptr<Scene>& scene);
		void run();

	private:
		std::queue<std::shared_ptr<Scene>> m_scenes;
		std::shared_ptr<Scene> m_currentScene;
	};
}