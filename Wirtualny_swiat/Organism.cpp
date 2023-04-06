#include "Organism.h"

Organism::Organism(World& world, const int& power, const int& initiative, const Point& position, const bool &isAlive, const int& age)
	: world(world), power(power), initiative(initiative), position(position), isAlive(isAlive), age(age)
{
}

const int Organism::GetAge()
{
	return age;
}

const int Organism::GetPower()
{
	return power;
}

string Organism::GetName()
{
	return string();
}

bool Organism::CanMove(int dir, int x, int y)
{
	return false;
}

const int Organism::GetInitiative()
{
	return initiative;
}

const Point Organism::GetPosition()
{
	return position;
}

void Organism::Fight(Organism* attacker, Organism* defender)
{
	Organism* loser, *winner;
	if (attacker->GetPower() >= defender->GetPower()) {
		loser = defender;
		winner = attacker;
	}
	else {
		loser = attacker;
		winner = defender;
	}/*
	if (attacker->GetName() == "Human" && loser->GetName() == "Human") {
		cout << "a";
	}*/
	loser->SetIsAlive(false);
	loser->DeadMessage(winner);

	//world.RefreashOrganism();
}

const bool Organism::GetIsAlive()
{
	return isAlive;
}

const void Organism::SetPosition(Point position)
{
	this->position = position;
}

const void Organism::SetAge(int age) {
	this->age = age;
}

const void Organism::SetIsAlive(bool alive) {
	this->isAlive = alive;
}

const void Organism::SetPower(int power) {
	this->power = power;
}

int Organism::GetTureOfAbility()
{
	return tureOfAbility;
}

bool Organism::GetAbilityActivated()
{
	return abilityActivated;
}

bool Organism::GetCanActivateAbility()
{
	return canActivateAbility;
}

void Organism::SetTureOfAbility(int tureOfAbility)
{
	this->tureOfAbility = tureOfAbility;
}

void Organism::SetAbilityActivated(int abilityActivated)
{
	this->abilityActivated = abilityActivated;
}

void Organism::SetCanActivateAbility(int canActivateAbility)
{
	this->canActivateAbility = canActivateAbility;
}


Organism::~Organism(){}