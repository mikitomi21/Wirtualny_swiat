#pragma once
#include "Plant.h"
#include <string>
#include "Blueberry.h"

#define GUARANA_POWER 0

using namespace std;

class Guarana : public Plant {
private:
public:
	//Guarana(World& world, Point& position, const int& age = 0);
	Guarana(World& world, Point& position, const int& age = 0, const int& initiative = PLANT_INITIATIVE, const int& power = GUARANA_POWER,
		const bool& isAlive = true);
	string GetName() override;
	void Copulation(Point& position) override;
	void Collision(Organism* attacker) override;
	void Action() override;
	void DeadMessage(Organism* attacker) override;
	~Guarana();
};