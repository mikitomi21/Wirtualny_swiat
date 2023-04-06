#include "Fox.h"
#include <string>

//Fox::Fox(World& world, Point& position, const int& age)
//	:Animal(world, FOX_POWER, FOX_INITIATIVE, position, isAlive, age)
//{
//}
//
Fox::Fox(World& world, Point& position, const int& age, const int& initiative, const int& power, const bool& isAlive)
	: Animal(world, FOX_POWER, FOX_INITIATIVE, position, isAlive, age)
{
}

string Fox::GetName()
{
	return "Fox";
}

void Fox::Copulation(Point &position)
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

	Organism* child = new Fox(world, position, 0);
	world.AddOrganism(child, position);
	cout << GetName() << " rozmnozylo sie" << endl;
}

void Fox::Action()
{
	int x = this->position.GetX();
	int y = this->position.GetY();
	vector<vector<char>> currentMap = world.GetMap();
	int dir = rand() % 4;
	//jezeli nie uda sie ruszyc tzn ze wokol niego same silniejsze zwierzeta i lis sie nie porusz
	for (int i = 0; i < ATTEMPT_TO_MOVE; i++)
	{
		while (!CanMove(dir, x, y)) {
			dir = rand() % 4;
		}
		if (GetPower() >= PowerOfEnemyOrganism(dir, x, y)) {
			MoveAnimal(dir, x, y, currentMap);
			return;
		}

	}
}

void Fox::DeadMessage(Organism* attacker)
{
	cout << GetName() << " umarla przez " << attacker->GetName() << endl;
}

int Fox::PowerOfEnemyOrganism(int dir, int x, int y)
{
	Point newPos(x, y);
	if (dir == DOWN) newPos.SetY(y + 1);
	else if (dir == UP) newPos.SetY(y - 1);
	else if (dir == LEFT) newPos.SetX(x - 1);
	else if (dir == RIGHT) newPos.SetX(x + 1);

	for (int i = 0; i < world.GetOrganisms().size(); i++)
	{
		if (!this->GetIsAlive() || !world.GetOrganisms()[i]->GetIsAlive() || world.GetOrganisms()[i] == this) continue;

		Point orgPos = world.GetOrganisms()[i]->GetPosition();

		if (orgPos.GetX() == newPos.GetX() &&
			orgPos.GetY() == newPos.GetY()) {
			return world.GetOrganisms()[i]->GetPower();
		}
	}
	return 0;
}

Fox::~Fox()
{
}
