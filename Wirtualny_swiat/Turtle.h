#pragma once
#include "Animal.h"
#include <string>

#define TURTLE_POWER 2
#define TURTLE_INITIATIVE 1
#define CAN_MOVE 3

using namespace std;

class Turtle : public Animal {
private:
public:
	//Turtle(World& world, Point& position, const int& age = 0);
	Turtle(World& world, Point& position, const int& age = 0, const int& initiative = TURTLE_INITIATIVE, const int& power = TURTLE_POWER,
		const bool& isAlive = true);
	string GetName() override;
	void Copulation(Point &position) override;
	void Action() override;
	void Collision(Organism* attacker) override;
	void DeadMessage(Organism* attacker) override;
	~Turtle();
};