#include "Game.h"
#include "Resources.h"
#include "../tengine/Resourcer.h"

#include <string>
#include <sstream>
#include <vector>
#include <filesystem>

WH_223::Game::Game() 
	: TEngine::Scene(TEngine::SceneParameters{ 1920, 1080, "WH 223", 60 })
{


}

void WH_223::Game::run_init()
{
	std::filesystem::path baseFolderPath;
	//Loading the CSV data for our tilemaps.
	baseFolderPath = "../../res/data/tilemaps";

	for (const char* csvDataID : gameResources::tileMaps)
	{

		TEngine::Resourcer::Instance().load_csv(
			(baseFolderPath / csvDataID / ".csv").string().c_str(),
			csvDataID
		);

	}
	//Loading textures
	baseFolderPath = "../../res/assets";
	
	for (const char* subDirectory : gameResources::assetSubDirectories)
	{

	}



}
