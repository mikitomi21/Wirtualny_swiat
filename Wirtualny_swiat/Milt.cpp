#include "Milt.h"
#include <string>

//Milt::Milt(World& world, Point& position, const int& age)
//	:Plant(world, MILT_POWER, PLANT_INITIATIVE, position, isAlive, age)
//{
//}

Milt::Milt(World& world, Point& position, const int& age, const int& initiative, const int& power, const bool& isAlive)
	: Plant(world, MILT_POWER, PLANT_INITIATIVE, position, isAlive, age)
{
}

string Milt::GetName()
{
	return "Milt";
}

void Milt::Copulation(Point& position)
{
	Organism* milt = new Milt(world, position);
	world.AddOrganism(milt, position);
	cout << GetName() << " rozmnozylo sie" << endl;
}

void Milt::Action()
{
	for (int i = 0; i < ATTEMPTS_TO_COPULATION; i++)
	{
		int attempt = rand() % CAN_COPULATION;
		if (attempt == COPULATION) {
			Point pos(rand() % world.GetWidth(), rand() % world.GetHeight());
			if (world.IsAnEmptyPosition(pos)) Copulation(pos);
		}
	}
}

void Milt::DeadMessage(Organism* attacker)
{
	cout << GetName() << " umarla przez " << attacker->GetName() << endl;
}


Milt::~Milt()
{
}
