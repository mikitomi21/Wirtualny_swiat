#include "Sheep.h"
#include <string>

//Sheep::Sheep(World& world, Point& position, const int& age)
//	:Animal(world, SHEEP_POWER, SHEEP_INITIATIVE, position, isAlive, age)
//{
//}

Sheep::Sheep(World& world, Point& position, const int& age, const int& initiative, const int& power, const bool& isAlive)
	: Animal(world, SHEEP_POWER, SHEEP_INITIATIVE, position, isAlive, age)
{
}

string Sheep::GetName()
{
	return "Sheep";
}

void Sheep::Action()
{
	int x = this->position.GetX();
	int y = this->position.GetY();
	vector<vector<char>> currentMap = world.GetMap();
	int dir = rand() % 4;
	while (!CanMove(dir, x, y)) {
		dir = rand() % 4;
	}
	MoveAnimal(dir, x, y, currentMap);
}

void Sheep::Copulation(Point &position)
{
	int x = position.GetX();
	int y = position.GetY();
	if (CanMove(DOWN, position.GetX(), position.GetY()) && world.IsAnEmptyPosition(Point(x, y + 1))) {
		position.SetY(position.GetY() + 1);
	}
	else if (CanMove(UP, position.GetX(), position.GetY()) && world.IsAnEmptyPosition(Point(x, y - 1))) {
		position.SetY(position.GetY() - 1);
	}
	else if (CanMove(LEFT, position.GetX(), position.GetY()) && world.IsAnEmptyPosition(Point(x - 1, y))) {
		position.SetX(position.GetX() - 1);
	}
	else if (CanMove(RIGHT, position.GetX(), position.GetY()) && world.IsAnEmptyPosition(Point(x + 1, y))) {
		position.SetX(position.GetX() + 1);
	}
	else return;

	Organism* child = new Sheep(world, position, 0);
	world.AddOrganism(child, position);
	cout << GetName() << " rozmnozylo sie" << endl;
}

void Sheep::DeadMessage(Organism* attacker)
{
	cout << GetName() << " umarla przez " << attacker->GetName() << endl;
}

Sheep::~Sheep()
{
}
