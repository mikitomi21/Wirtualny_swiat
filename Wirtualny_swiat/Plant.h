#pragma once
#include "Organism.h"


#define PLANT_INITIATIVE 0
#define COPULATION 1
#define CAN_COPULATION 20

class Plant : public Organism {
public:
	Plant(World& world, const int& power, const int& initiative, const Point& position, const bool isAlive, const int& age);
	void Action() override;
	void Collision(Organism* attacker) override;
	void Draw() override;
	void Copulation(Point& position) override;
	void DeadMessage(Organism* attacker) override;
	bool CanMove(int dir, int x, int y) override;
	~Plant();
};
