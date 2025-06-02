#include "Entity.h"

Vector2 WH_223::Entity::get_position()
{
    return p_position;
}

void WH_223::Entity::update()
{
}

void WH_223::Entity::draw()
{
}

void WH_223::Entity::p_move_entity(Vector2 direction)
{
    p_position = Vector2Add(direction, p_position);
}

Vector2 WH_223::Entity::get_quantised_position()
{
    return Vector2{ floorf(p_position.x) , floorf(p_position.y) };
}