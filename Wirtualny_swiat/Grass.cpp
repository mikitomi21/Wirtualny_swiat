#include "Grass.h"
#include <string>
//
//Grass::Grass(World& world, Point& position, const int& age)
//	:Plant(world, GRASS_POWER, PLANT_INITIATIVE, position, isAlive, age)
//{
//}

Grass::Grass(World& world, Point& position, const int& age, const int& initiative, const int& power, const bool& isAlive)
	:Plant(world, GRASS_POWER, PLANT_INITIATIVE, position, isAlive, age)
{
}

string Grass::GetName()
{
	return "Grass";
}

void Grass::Copulation(Point& position)
{
	Organism* grass = new Grass(world, position);
	world.AddOrganism(grass, position);
	cout << GetName() << " rozmnozylo sie" << endl;
}

void Grass::Action()
{
	int attempt = rand() % CAN_COPULATION;
	if (attempt == COPULATION) {
		Point pos(rand() % world.GetWidth(), rand() % world.GetHeight());
		if (world.IsAnEmptyPosition(pos)) Copulation(pos);
	}
}

void Grass::DeadMessage(Organism* attacker)
{
	cout << GetName() << " umarla przez " << attacker->GetName() << endl;
}


Grass::~Grass()
{
}
