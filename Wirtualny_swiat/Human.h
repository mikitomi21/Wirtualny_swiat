#pragma once
#include "Animal.h"
#include <string>

#define HUMAN_POWER 5
#define HUMAN_INITIATIVE 4
#define MAX_TURE_OF_ABILITY 5

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_ABILITY_UPPERCASE 65
#define KEY_ABILITY 97
#define KEY_SAVE_UPPERCASE 83
#define KEY_SAVE 115
#define KEY_UPLOAD_UPPERCASE 85
#define KEY_UPLOAD 117

using namespace std;

class Human : public Animal {
private:
public:
	Human(World& world, Point& position, const int& age = 0, const int& tureOfAbility = 0,
		const bool& canActivateAbility = true, const bool& abilityActivated = false);
	string GetName() override;
	void Action() override;
	void Collision(Organism* attacker) override;
	int KeyDown();
	void ActivateAbility();
	void StopAbility();
	void Copulation(Point &position) override;
	void DeadMessage(Organism* attacker) override;

	
	~Human();
};