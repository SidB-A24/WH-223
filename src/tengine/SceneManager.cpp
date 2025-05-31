#include "SceneManager.h"
#include "Scene.h"
#include "Logger.h"

#include <string>
#include <sstream>


namespace Engine {
	
	static SceneManager* s_Instance = nullptr;

	SceneManager::SceneManager() 
	{
		s_Instance = this;
	}

	SceneManager& SceneManager::Instance() 
	{
		if(s_Instance) 
		{
			return *s_Instance;
		}
		else 
		{
			Logger::Instance().error("<SceneManager> The SceneManager cannot be retrieved without initializing.");

			throw;
		}
	}

	SceneManager::~SceneManager()
	{
		//To ease shared ptr of Scene
		while (!m_scenes.empty())
		{
			m_scenes.pop();
		}

		s_Instance = nullptr;
	}

	void SceneManager::push_scene(const std::shared_ptr<Scene>& scene)
	{
		m_scenes.push(scene);

		std::stringstream message;
		message << "<SceneManager> Added Scene: '" << scene->get_sceneTitle() << "'";
		Logger::Instance().info(message.str().c_str());
	}

	void SceneManager::run() 
	{
		while (!m_scenes.empty()) 
		{
			m_currentScene = m_scenes.front();
			m_scenes.pop();

			m_currentScene->run();
			m_currentScene->cleanup();
		}
	}
}
