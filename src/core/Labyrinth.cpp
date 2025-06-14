#include "Labyrinth.h"

WH_223::Labyrinth::Labyrinth()
{
}

void WH_223::Labyrinth::move_walls(std::unordered_map<Vector2, std::string> tileMap)
{
    p_tileMap = tileMap; //This will have much more going on maybe in the future.
}

void WH_223::Labyrinth::draw()
{
    //std::cout << "." << std::endl;

    for (auto i = p_tileMap.begin(); i != p_tileMap.end(); i++)
    {
        Vector2 tilePosition = i->first;
        DrawRectangleGradientH(tilePosition.x * gameParameters::tileSize, tilePosition.y * gameParameters::tileSize,
            gameParameters::tileSize, gameParameters::tileSize,
            PURPLE, BLUE
        );
        //std::cout << i->first.x << std::endl;
    }
}

std::unordered_map<Vector2, std::string> WH_223::Labyrinth::load_tileMap_from_csv(const char* identifier)
{
    auto csvWeakDataPtr = TEngine::Resourcer::Instance().fetch_csv(identifier);
    auto csvDataPtr = csvWeakDataPtr.lock();

    std::unordered_map<Vector2, std::string> tileMap;

    for (size_t i = 0; i < csvDataPtr->size(); i++)
    {
        for (size_t j = 0; j < csvDataPtr->at(i).size(); j++)
        {
            std::string currentTile = csvDataPtr->at(i).at(j);
            
            tileMap.insert({ Vector2{static_cast<float>(i), static_cast<float>(j)},
                currentTile });

            std::cout << "Hello World";
        }
    }

    p_mapDimensions = {
        static_cast<float>(csvDataPtr->size()),
        static_cast<float>(csvDataPtr->at(0).size())
    };

    csvDataPtr.reset();

    return tileMap;
}

Vector2 WH_223::Labyrinth::get_map_size_in_pixels()
{
    return p_mapDimensions*gameParameters::tileSize; //Yes there is an implicit conversion from float to int, shush.
}
