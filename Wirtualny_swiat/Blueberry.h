#pragma once
#include "Plant.h"
#include <string>

#define BLUEBERRY_POWER 99

using namespace std;

class Blueberry : public Plant {
private:
public:
	//Blueberry(World& world, Point& position, const int& age = 0);
	Blueberry(World& world, Point& position, const int& age = 0, const int& initiative = PLANT_INITIATIVE, const int& power = BLUEBERRY_POWER,
		const bool& isAlive = true);
	string GetName() override;
	void Copulation(Point& position) override;
	void Collision(Organism* attacker) override;
	void Action() override;
	void DeadMessage(Organism* attacker) override;
	~Blueberry();
};