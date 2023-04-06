#pragma once
#include "Animal.h"
#include <string>

#define WOLF_POWER 9
#define WOLF_INITIATIVE 5

using namespace std;

class Wolf : public Animal {
private:
public:
	//Wolf(World& world, Point& position, const int& age=0);
	Wolf(World& world, Point& position, const int& age=0, const int& initiative = WOLF_INITIATIVE, const int& power = WOLF_POWER,
		const bool& isAlive = true);
	string GetName() override;
	void Action() override;
	void Collision(Organism* attacker) override;
	void Copulation(Point &position) override;
	void DeadMessage(Organism* attacker) override;
	~Wolf();
};