#include "Antelope.h"
#include <string>

//Antelope::Antelope(World& world, Point& position, const int& age)
//	:Animal(world, ANTELOPE_POWER, ANTELOPE_INITIATIVE, position, isAlive, age)
//{
//}

Antelope::Antelope(World& world, Point& position, const int& age, const int& initiative, const int& power, const bool& isAlive)
	: Animal(world, ANTELOPE_POWER, ANTELOPE_INITIATIVE, position, isAlive, age)
{
}

string Antelope::GetName()
{
	return "Antelope";
}

void Antelope::Copulation(Point &position)
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

	Organism* child = new Antelope(world, position, 0);
	world.AddOrganism(child, position);
	cout << GetName() << " rozmnozylo sie" << endl;
}

void Antelope::Action()
{
	for (int i = 0; i < NUMBER_OF_MOVES; i++)
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
}

void Antelope::Collision(Organism* attacker)
{
	int run_away = rand() % 2;
	if (run_away == CAN_RUN_AWAY) {
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
			MoveAnimal(dir, x, y, currentMap);
			return;

		}
	}
	
}

void Antelope::DeadMessage(Organism* attacker)
{
	cout << GetName() << " umarla przez " << attacker->GetName() << endl;
}

Antelope::~Antelope()
{
}
