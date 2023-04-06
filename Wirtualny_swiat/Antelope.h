#pragma once
#include "Animal.h"
#include <string>

#define ANTELOPE_POWER 4
#define ANTELOPE_INITIATIVE 4
#define NUMBER_OF_MOVES 2
#define CAN_RUN_AWAY 1
#define ATTEMPT_TO_MOVE 15

using namespace std;

class Antelope : public Animal {
private:
public:
	//Antelope(World& world, Point& position, const int& age = 0);
	Antelope(World& world, Point& position, const int& age = 0, const int& initiative = ANTELOPE_INITIATIVE, const int& power = ANTELOPE_POWER,
		const bool& isAlive = true);
	string GetName() override;
	void Copulation(Point &position) override;
	void Action() override;
	void Collision(Organism* attacker) override;
	void DeadMessage(Organism* attacker) override;
	~Antelope();
};