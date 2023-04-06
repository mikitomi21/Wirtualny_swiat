#pragma once
#include "Plant.h"
#include <string>

#define MILT_POWER 0
#define ATTEMPTS_TO_COPULATION 3

using namespace std;

class Milt : public Plant {
private:
public:
	//Milt(World& world, Point& position, const int& age = 0);
	Milt(World& world, Point& position, const int& age = 0, const int& initiative = PLANT_INITIATIVE, const int& power = MILT_POWER,
		const bool& isAlive = true);
	string GetName() override;
	void Copulation(Point& position) override;
	void Action() override;
	void DeadMessage(Organism* attacker) override;
	~Milt();
};