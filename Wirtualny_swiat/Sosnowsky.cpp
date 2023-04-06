#include "Sosnowsky.h"
#include <string>

//Sosnowsky::Sosnowsky(World& world, Point& position, const int& age)
//	:Plant(world, SOSNOWSKY_POWER, PLANT_INITIATIVE, position, isAlive, age)
//{
//}

Sosnowsky::Sosnowsky(World& world, Point& position, const int& age, const int& initiative, const int& power, const bool& isAlive)
	: Plant(world, SOSNOWSKY_POWER, PLANT_INITIATIVE, position, isAlive, age)
{
}

string Sosnowsky::GetName()
{
	return "Sosnowsky";
}

void Sosnowsky::Copulation(Point& position)
{
	Organism* sosnowsky = new Sosnowsky(world, position);
	world.AddOrganism(sosnowsky, position);
	cout << GetName() << " rozmnozylo sie" << endl;
}

void Sosnowsky::Collision(Organism* attacker)
{
	vector<vector<char>> map = world.GetMap();
	Point attPos = attacker->GetPosition();
	attacker->SetIsAlive(false);
	attacker->DeadMessage(this);

	map[attPos.GetX()][attPos.GetY()] = EMPTY;
	world.SetMap(map);

}

void Sosnowsky::Action()
{
	vector<vector<char>> map = world.GetMap();
	Point pos = GetPosition();
	Point sosPos(pos.GetX(), pos.GetY());

	for (int i = 0; i < world.GetOrganisms().size(); i++)
	{
		if (!this->GetIsAlive() || !world.GetOrganisms()[i]->GetIsAlive() || world.GetOrganisms()[i] == this) continue;

		Point orgPos = world.GetOrganisms()[i]->GetPosition();

		if ((orgPos.GetX() == (sosPos.GetX() + 1) && orgPos.GetY() == sosPos.GetY()) ||
			(orgPos.GetX() == (sosPos.GetX() - 1) && orgPos.GetY() == sosPos.GetY()) || 
			(orgPos.GetX() == sosPos.GetX() && orgPos.GetY() == (sosPos.GetY() + 1 )) || 
			(orgPos.GetX() == sosPos.GetX() && orgPos.GetY() == (sosPos.GetY() - 1))) {
			world.GetOrganisms()[i]->SetIsAlive(false);
			cout << world.GetOrganisms()[i]->GetName() << " umarla przez " << GetName() << endl;
			map[orgPos.GetX()][orgPos.GetY()] = EMPTY;
		}
	}
	world.SetMap(map);

	int attempt = rand() % CAN_COPULATION;
	if (attempt == COPULATION) {
		Point pos(rand() % world.GetWidth(), rand() % world.GetHeight());
		if (world.IsAnEmptyPosition(pos)) Copulation(pos);
	}
}

void Sosnowsky::DeadMessage(Organism* attacker)
{
	cout << GetName() << " umarla przez " << attacker->GetName() << endl;
}


Sosnowsky::~Sosnowsky()
{
}
