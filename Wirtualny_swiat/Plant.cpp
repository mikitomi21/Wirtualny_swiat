#include "Plant.h"

Plant::Plant(World& world, const int& power, const int& initiative, const Point& position, const bool isAlive, const int& age)
	: Organism(world, power, initiative, position, isAlive, age)
{
}

void Plant::Action()
{
}

void Plant::Collision(Organism* attacker)
{
}

void Plant::Draw()
{
}

void Plant::Copulation(Point& position)
{
}

void Plant::DeadMessage(Organism* attacker)
{
}

bool Plant::CanMove(int dir, int x, int y)
{
	return false;
}

Plant::~Plant()
{
}
