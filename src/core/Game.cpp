#include "Game.h"


WH_223::Game::Game() 
	: TEngine::Scene(TEngine::SceneParameters{ 1920, 1080, "WH 223", 60 })
{


}

void WH_223::Game::run_init()
{
	cameraPosition = Vector2{ 0, 0 };

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

	//Create the labyrinth class.
	p_labyrinthPtr = std::make_shared <Labyrinth>(Labyrinth());

	auto tileMap = p_labyrinthPtr->load_tileMap_from_csv("testing");
	p_labyrinthPtr->move_walls(tileMap);

	Vector2 mapDimensions = p_labyrinthPtr->get_map_size_in_pixels();
	panelTexture = LoadRenderTexture(mapDimensions.x, mapDimensions.y); //Implicit float to int conversion, however the get_map... is always going to be an integer number, so no hitches. 

}

void WH_223::Game::update()
{
}

void WH_223::Game::draw()
{
	BeginTextureMode(panelTexture);
	ClearBackground(BLACK);

	p_labyrinthPtr->draw(); //There will be an implicit conversion from shared ptr to weak ptr. Good.
	//TODO: Player.draw

	EndTextureMode();

	//Drawing to viewport
	BeginDrawing();
	ClearBackground(BLACK);

	Rectangle flippedViewportView = {
		cameraPosition.x, cameraPosition.y,
		viewportDimensions.x, viewportDimensions.y
	}; //Gets us the rectangle that contains the map
	DrawTextureRec(
		panelTexture.texture, flippedViewportView,
		{ 0, 0 }, WHITE
	); //Draws what our camera sees

	EndDrawing();
}

void WH_223::Game::cleanup()
{
	UnloadRenderTexture(panelTexture);
	CloseWindow();
}
