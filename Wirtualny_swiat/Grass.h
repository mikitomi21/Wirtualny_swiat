#pragma once
#include "Plant.h"
#include <string>

#define GRASS_POWER 0

using namespace std;

class Grass : public Plant {
private:
public:
	//Grass(World& world, Point& position, const int& age = 0);
	Grass(World& world, Point& position, const int& age = 0, const int& initiative = PLANT_INITIATIVE, const int& power = GRASS_POWER,
		const bool& isAlive = true);
	string GetName() override;
	void Copulation(Point& position) override;
	void Action() override;
	void DeadMessage(Organism* attacker) override;
	~Grass();
};