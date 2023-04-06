#include "Human.h"
#include <string>

Human::Human(World& world, Point& position, const int& age, const int& tureOfAbility,
	const bool& canActivateAbility, const bool& abilityActivated)
	:Animal(world, HUMAN_POWER, HUMAN_INITIATIVE, position, isAlive, age)
{
	this->tureOfAbility = tureOfAbility;
	this->canActivateAbility = canActivateAbility;
	this->abilityActivated = abilityActivated;
}

string Human::GetName()
{
	return "Human";
}

void Human::Action()
{
	int dir = KeyDown();
	Point pos = this->GetPosition();
	vector<vector<char>> currentMap = world.GetMap();
	this->MoveAnimal(dir, pos.GetX(), pos.GetY(), currentMap);
	if(abilityActivated) tureOfAbility++;
	StopAbility();
}

void Human::Collision(Organism* attacker)
{
	if (abilityActivated) {
		int x = this->position.GetX();
		int y = this->position.GetY();
		vector<vector<char>> currentMap = world.GetMap();
		int dir = rand() % 4;
		//jezeli nie uda sie ruszyc tzn ze wokol niego same silniejsze zwierzeta i lis sie nie porusz
		while (!CanMove(dir, x, y)) {
			dir = rand() % 4;
		}
		MoveAnimal(dir, x, y, currentMap);
	}
}

int Human::KeyDown()
{
	Point currentPos = this->GetPosition();
	while (true) {
		switch (_getch()) {
		case KEY_UP: {
			if (this->CanMove(UP, currentPos.GetX(), currentPos.GetY())) return UP;
		}
		case KEY_DOWN: {
			if (this->CanMove(DOWN, currentPos.GetX(), currentPos.GetY())) return DOWN;
		}
		case KEY_RIGHT: {
			if (this->CanMove(RIGHT, currentPos.GetX(), currentPos.GetY())) return RIGHT;
		}
		case KEY_LEFT: {
			if (this->CanMove(LEFT, currentPos.GetX(), currentPos.GetY())) return LEFT;
		}
		case KEY_ABILITY: {
			if(canActivateAbility) ActivateAbility();
			break;
		}
		case KEY_ABILITY_UPPERCASE: {
			if (canActivateAbility) ActivateAbility();
			break;
		}
		case KEY_SAVE_UPPERCASE: {
			world.SaveGame();
			break;
		}
		case KEY_SAVE: {
			world.SaveGame();
			break;
		}
		/*case KEY_UPLOAD_UPPERCASE: {
			world.UploadGame();
			break;
		}
		case KEY_UPLOAD: {
			world.UploadGame();
			break;
		}*/
		}
	}
	//return false;
}

void Human::ActivateAbility()
{
	abilityActivated = true;
	canActivateAbility = false;
	cout << "Aktywowano umiejetnosc" << endl;
}

void Human::StopAbility()
{
	if (tureOfAbility >= MAX_TURE_OF_ABILITY) {
		tureOfAbility = 0;
		abilityActivated = false;
		cout << "Koniec umiejetnosci" << endl;
	}
}

void Human::Copulation(Point &position)
{
}

void Human::DeadMessage(Organism* attacker)
{
	cout << GetName() << " umarla przez " << attacker->GetName() << endl;
}



Human::~Human()
{
}
