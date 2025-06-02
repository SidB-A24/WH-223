#include "WH_223.h"

int main()
{
	std::cout << "Hello CMake!" << std::endl;

	//TEngine::SceneManager* sceneManager = new TEngine::SceneManager;
	//Initializing sceneManager as a static class. It can now be used via TEngine::SceneManager.instance();

	TEngine::SceneManager sceneManager;
	TEngine::Resourcer resourcer;

	std::shared_ptr < TEngine::Scene > gameScene = std::make_shared <TEngine::Scene> (WH_223::Game());

	sceneManager.push_scene(gameScene);
	sceneManager.run();

	std::cout << "Goodbye CMake." << std::endl;

	return 0;
}
