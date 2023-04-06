#include "Blueberry.h"
#include <string>

//Blueberry::Blueberry(World& world, Point& position, const int& age)
//	:Plant(world, BLUEBERRY_POWER, PLANT_INITIATIVE, position, isAlive, age)
//{
//}

Blueberry::Blueberry(World& world, Point& position, const int& age, const int& initiative, const int& power, const bool& isAlive)
	: Plant(world, BLUEBERRY_POWER, PLANT_INITIATIVE, position, isAlive, age)
{
}

string Blueberry::GetName()
{
	return "Blueberry";
}

void Blueberry::Copulation(Point& position)
{
	Organism* blueberry = new Blueberry(world, position);
	world.AddOrganism(blueberry, position);
	cout << GetName() << " rozmnozylo sie" << endl;
}

void Blueberry::Action()
{
	int attempt = rand() % CAN_COPULATION;
	if (attempt == COPULATION) {
		Point pos(rand() % world.GetWidth(), rand() % world.GetHeight());
		if (world.IsAnEmptyPosition(pos)) Copulation(pos);
	}
}

void Blueberry::Collision(Organism* attacker)
{
	vector<vector<char>> map = world.GetMap();
	Point attPos = attacker->GetPosition();
	attacker->SetIsAlive(false);
	attacker->DeadMessage(this);

	map[attPos.GetX()][attPos.GetY()] = EMPTY;
	world.SetMap(map);

}

void Blueberry::DeadMessage(Organism* attacker)
{
	cout << GetName() << " umarla przez " << attacker->GetName() << endl;
}


Blueberry::~Blueberry()
{
}
