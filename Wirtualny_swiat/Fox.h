#pragma once
#include "Animal.h"
#include <string>

#define FOX_POWER 3
#define FOX_INITIATIVE 7
#define ATTEMPT_TO_MOVE 15

using namespace std;

class Fox : public Animal {
private:
public:
	//Fox(World& world, Point& position, const int& age = 0);
	Fox(World& world, Point& position, const int& age = 0, const int& initiative = FOX_INITIATIVE, const int& power = FOX_POWER,
		const bool& isAlive = true);
	string GetName() override;
	void Copulation(Point &position) override;
	void Action() override;
	void DeadMessage(Organism* attacker) override;
	int PowerOfEnemyOrganism(int dir, int x, int y);
	~Fox();
};