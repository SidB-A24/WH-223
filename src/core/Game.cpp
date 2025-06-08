#include "Game.h"


WH_223::Game::Game() 
	: TEngine::Scene(TEngine::SceneParameters{ 1920, 1080, "WH 223", 60 })
{
	viewportDimensions = { 1920, 1080 };
	cameraPosition = Vector2{ 0, 0 };

}

void WH_223::Game::run_init()
{

	std::filesystem::path baseFolderPath;
	std::filesystem::path finalPath;
	//Loading the CSV data for our tilemaps.
	baseFolderPath = std::filesystem::current_path() / "../../../res/data/tilemaps"; //Path relative to the executable.
	
	

	for (const char* csvDataID : gameResources::tileMaps)
	{
		finalPath = baseFolderPath / csvDataID;
		finalPath.replace_extension(".csv");
		TEngine::Resourcer::Instance().load_csv(
			finalPath.string().c_str(),
			csvDataID
		);
	}
	//Loading textures
	baseFolderPath = std::filesystem::current_path() / "../../../res/assets";
	
	for (const char* subDirectory : gameResources::assetSubDirectories)
	{

	}

	InitWindow(m_windowWidth, m_windowHeight, m_sceneTitle);
	//Create the labyrinth class.
	p_labyrinthPtr = std::make_shared <Labyrinth>(Labyrinth());

	auto tileMap = p_labyrinthPtr->load_tileMap_from_csv("testing");
	p_labyrinthPtr->move_walls(tileMap);

	Vector2 mapDimensions = p_labyrinthPtr->get_map_size_in_pixels();
	panelTexture = LoadRenderTexture(mapDimensions.x, mapDimensions.y); //Implicit float to int conversion, however the get_map... is always going to be an integer number, so no hitches. 
	

	TEngine::Logger::Instance().info("Game class initialised for runtime.");
}

void WH_223::Game::update()
{
}

void WH_223::Game::draw()
{
	//std::cout << "." << std::endl;
	BeginTextureMode(panelTexture);
	ClearBackground(WHITE);

	//TODO: Player.draw
	p_labyrinthPtr->draw(); //There will be an implicit conversion from shared ptr to weak ptr. Good.

	EndTextureMode();

	//Drawing to viewport
	BeginDrawing();
	ClearBackground(YELLOW);
	
	Rectangle flippedViewportView = {
		0, 0,
		viewportDimensions.x, viewportDimensions.y
	}; //Gets us the rectangle that contains the map
	DrawTextureRec(
		panelTexture.texture, flippedViewportView,
		{ -cameraPosition.x, -cameraPosition.y }, WHITE
	); //Draws what our camera sees
	
	EndDrawing();
}

void WH_223::Game::cleanup()
{
	UnloadRenderTexture(panelTexture);
	CloseWindow();
}
