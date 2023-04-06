#include "Guarana.h"
#include <string>

//Guarana::Guarana(World& world, Point& position, const int& age)
//	:Plant(world, GUARANA_POWER, PLANT_INITIATIVE, position, isAlive, age)
//{
//}

Guarana::Guarana(World& world, Point& position, const int& age, const int& initiative, const int& power, const bool& isAlive)
	: Plant(world, GUARANA_POWER, PLANT_INITIATIVE, position, isAlive, age)
{
}

string Guarana::GetName()
{
	return "Guarana";
}

void Guarana::Copulation(Point& position)
{
	Organism* guarana = new Guarana(world, position);
	world.AddOrganism(guarana, position);
	cout << GetName() << " rozmnozylo sie" << endl;
}

void Guarana::Action()
{
	int attempt = rand() % CAN_COPULATION;
	if (attempt == COPULATION) {
		Point pos(rand() % world.GetWidth(), rand() % world.GetHeight());
		if (world.IsAnEmptyPosition(pos)) Copulation(pos);
	}
}

void Guarana::Collision(Organism* attacker)
{
	attacker->SetPower(attacker->GetPower() + 3);
}

void Guarana::DeadMessage(Organism* attacker)
{
	cout << GetName() << " umarla przez " << attacker->GetName() << endl;
}


Guarana::~Guarana()
{
}
