#pragma once
#include "Plant.h"
#include <string>

#define SOSNOWSKY_POWER 10

using namespace std;

class Sosnowsky : public Plant {
private:
public:
	//Sosnowsky(World& world, Point& position, const int& age = 0);
	Sosnowsky(World& world, Point& position, const int& age = 0, const int& initiative = PLANT_INITIATIVE, const int& power = SOSNOWSKY_POWER,
		const bool& isAlive = true);
	string GetName() override;
	void Copulation(Point& position) override;
	void Action() override;
	void Collision(Organism* attacker) override;
	void DeadMessage(Organism* attacker) override;
	~Sosnowsky();
};
