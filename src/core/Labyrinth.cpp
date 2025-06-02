#include "Labyrinth.h"

Vector2 WH_223::Labyrinth::get_map_size_in_pixels()
{
    return Vector2Scale(p_mapDimensions, gameParameters::tileSize); //Yes there is an implicit conversion from float to int, shush.
}
