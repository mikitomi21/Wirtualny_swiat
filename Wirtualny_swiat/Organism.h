#pragma once
#include <iostream>
#include "Point.h"
#include "World.h"

using namespace std;

class World;

class Organism {
protected:
	int age;
	int power;
	int initiative;
	Point position;
	World & world;
	bool isAlive;
	bool abilityActivated; //teraz jest aktywna
	bool canActivateAbility; //czy mozna odpalic umiejetnosc
	int tureOfAbility; //ilosc tur aktywna
public:
	Organism(World& world, const int& power, const int& initiative, const Point& position, const bool &isAlive, const int& age);
	virtual void Action() = 0;
	virtual void Collision(Organism* attacker) = 0;
	virtual void Draw() = 0;
	virtual void Copulation(Point &position) = 0;
	virtual void DeadMessage(Organism * attacker) = 0;
	virtual bool CanMove(int dir, int x, int y) = 0;
	const int GetAge();
	const int GetPower();
	const int GetInitiative();
	const Point GetPosition();
	const bool GetIsAlive();
	virtual string GetName() = 0;
	void Fight(Organism* first, Organism* second);
	const void SetPosition(Point position);
	const void SetAge(int age);
	const void SetIsAlive(bool alive);
	const void SetPower(int power);

	void SetTureOfAbility(int tureOfAbility);
	void SetAbilityActivated(int abilityActivated);
	void SetCanActivateAbility(int canActivateAbility);

	int GetTureOfAbility();
	bool GetAbilityActivated();
	bool GetCanActivateAbility();

	virtual ~Organism();
};