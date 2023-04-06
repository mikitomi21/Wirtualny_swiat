#pragma once
#include "Animal.h"
#include <string>

#define SHEEP_POWER 4
#define SHEEP_INITIATIVE 5

using namespace std;

class Sheep : public Animal {
private:
public:
	//Sheep(World& world, Point& position, const int& age = 0);
	Sheep(World& world, Point& position, const int& age = 0, const int& initiative = SHEEP_INITIATIVE, const int& power = SHEEP_POWER,
		const bool& isAlive = true);
	string GetName() override;
	void Action() override;
	void Copulation(Point &position) override;
	void DeadMessage(Organism* attacker) override;
	~Sheep();
};