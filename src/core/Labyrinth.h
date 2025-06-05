#pragma once
/*
This controls the world, the walls and floor and the visuals of the actual scene. 
*/

#include <memory>
#include <string>
#include <unordered_map>

#include "TEngine.h"
#include "../entity/Player.h"
#include "../entity/Narrator.h"
#include "Resources.h"

namespace WH_223
{
	class Labyrinth
	{
	//INITIALISATION METHODS
	public:
		Labyrinth();

	//MAP METHODS
	private:


	//PUBLIC METHODS
	public:
		void move_walls(std::unordered_map<Vector2, std::string> tileMap); //This will implement changes made due to story progression
		
		/*
		We store a copy of the tile under the player, and note which floor tile it is. Then render only that rooms floor tiles and nothing else. All wall tiles will always be rendered.
		Rooms will always be fully lit, and walls that aren't in contact with the tiles of this room will be darkened? maybe.
		Hallways will be dimmed with a gradient vignette effect.
		*/
		void draw(); //Draws the world based on the player position. 

		void update(std::weak_ptr<Entity> player, std::weak_ptr<Narrator> narrator); //Updates the world using requests from the narrator.

		std::unordered_map<Vector2, std::string> load_tileMap_from_csv(const char* identifier); //Loads a given tilemap from csv files.
		Vector2 get_map_size_in_pixels();

	//PRIVATE METHODS
	private:
		//If in hallway the camera will follow the player and we will add some vignette. 
		//Else, the camera is fixed to the center of the room.  
		bool p_is_player_in_hallway(std::weak_ptr<Entity> player);

		bool p_can_player_move_to_position(std::weak_ptr<Entity> player, Vector2 newPos); //Checks if player input will result in player translation.

	//PRIVATE VARIABLES
	private:
		std::unordered_map<Vector2, std::string> p_tileMap;  //Here the vector points to the location of a given tile and the string is the character present at that position.
		//If the tile is a floor tile: F_1 or F_3. 
		Vector2 p_mapDimensions; //In tiles. Will be set when loading tilemap from csv.
	};


}