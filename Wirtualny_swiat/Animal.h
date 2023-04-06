#pragma once
#include "Organism.h"

class Animal : public Organism {
public:
	Animal(World& world, const int& power, const int& initiative, const Point& position, const bool &isAlive, const int& age);
	void Action() override;
	void Collision(Organism* attacker) override;
	void Draw() override;
	void DeadMessage(Organism* attacker) override;
	void MoveAnimal(int dir, int x, int y, vector<vector<char>> &currentMap);
	bool CanMove(int dir, int x, int y) override;
	//void Copulation(Organism* organism, Point position);
	~Animal();
};