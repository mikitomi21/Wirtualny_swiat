#include "Turtle.h"
#include <string>

//Turtle::Turtle(World& world, Point& position, const int& age)
//	:Animal(world, TURTLE_POWER, TURTLE_INITIATIVE, position, isAlive, age)
//{
//}

Turtle::Turtle(World& world, Point& position, const int& age, const int& initiative, const int& power, const bool& isAlive)
	: Animal(world, TURTLE_POWER, TURTLE_INITIATIVE, position, isAlive, age)
{
}

string Turtle::GetName()
{
	return "Turtle";
}

void Turtle::Copulation(Point &position)
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

	Organism* child = new Turtle(world, position, 0);
	world.AddOrganism(child, position);
	cout << GetName() << " rozmnozylo sie" << endl;
}

void Turtle::Action()
{
	int attempt = rand() % 4;
	if (attempt == CAN_MOVE) {
		int x = this->position.GetX();
		int y = this->position.GetY();
		vector<vector<char>> currentMap = world.GetMap();
		int dir = rand() % 4;
		while (!CanMove(dir, x, y)) {
			dir = rand() % 4;
		}
		MoveAnimal(dir, x, y, currentMap);
	}
	
}

void Turtle::Collision(Organism* attacker)
{
	if (attacker->GetPower() < 5) {
		attacker->Action();
	}
}

void Turtle::DeadMessage(Organism* attacker)
{
	cout << GetName() << " umarla przez " << attacker->GetName() << endl;
}

Turtle::~Turtle()
{
}
