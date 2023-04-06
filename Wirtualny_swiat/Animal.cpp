#include "Animal.h"

Animal::Animal(World& world, const int& power, const int& initiative, const Point& position, const bool &isAlive, const int& age)
	: Organism(world, power, initiative, position, isAlive, age)
{
}

void Animal::Action()
{
}

void Animal::Collision(Organism* attacker)
{
}

void Animal::Draw()
{
	cout << "Draw" << endl;
}

bool Animal::CanMove(int dir, int x, int y)
{
	if (dir == DOWN && y < world.GetHeight()-1) return true;
	else if (dir == UP && y > 0) return true;
	else if (dir == LEFT && x > 0) return true;
	else if (dir == RIGHT && x < world.GetWidth()-1) return true;
	else return false;
}

//void Animal::Copulation(Organism * organism, Point position)
//{
//	
//	/*Organism* child = organism;
//	child->SetAge(0);
//	while (!world.IsAnEmptyPosition(position)) {
//		if(CanMove(DOWN, position.GetX(), position.GetY())) position.SetY(position.GetY() + 1);
//		else if(CanMove(UP, position.GetX(), position.GetY())) position.SetY(position.GetY() - 1);
//		else if(CanMove(LEFT, position.GetX(), position.GetY())) position.SetX(position.GetX() - 1);
//		else if(CanMove(RIGHT, position.GetX(), position.GetY())) position.SetX(position.GetX() + 1);
//	}
//	world.AddOrganism(child, position);*/
//}

void Animal::MoveAnimal(int dir, int x, int y, vector<vector<char>> &currentMap)
{
	Point newPos(x, y);
	if (dir == DOWN) newPos.SetY(y + 1);
	else if (dir == UP) newPos.SetY(y - 1);
	else if (dir == LEFT) newPos.SetX(x - 1);
	else if (dir == RIGHT) newPos.SetX(x + 1);

	int size = world.GetOrganisms().size();
	for (int i = 0; i < size; i++)
	{
		if (!this->GetIsAlive() || !world.GetOrganisms()[i]->GetIsAlive() || world.GetOrganisms()[i] == this) continue;

		Point orgPos= world.GetOrganisms()[i]->GetPosition();

		if (orgPos.GetX() == newPos.GetX() &&
			orgPos.GetY() == newPos.GetY()) {
			if (world.FindClassOfObject(this) == world.FindClassOfObject(world.GetOrganisms()[i])) {
				this->Copulation(newPos);
				return;
			}
			else {
				world.GetOrganisms()[i]->Collision(this);
				Fight(this, world.GetOrganisms()[i]);
				break;
			}
		}
	}
	this->SetPosition(newPos);
	currentMap[x][y] = EMPTY;
	currentMap[newPos.GetX()][newPos.GetY()] = world.FindClassOfObject(this);

	world.SetMap(currentMap);
	/*Point newPoint(x,y);
	if (dir == DOWN) newPoint.SetY(y+1);
	else if (dir == UP) newPoint.SetY(y - 1);
	else if (dir == LEFT) newPoint.SetX(x - 1);
	else if (dir == RIGHT) newPoint.SetX(x + 1);

	int size = world.GetOrganisms().size();
	for (int i = 0; i < size; i++)
	{
		Point organismPoint = world.GetOrganisms()[i]->GetPosition();
		if (organismPoint.GetX() == newPoint.GetX() &&
			organismPoint.GetY() == newPoint.GetY()) {
			if (world.FindClassOfObject(this) == world.FindClassOfObject(world.GetOrganisms()[i])) {
				world.GetOrganisms()[i]->Copulation(newPoint);
				return;
			}
			else {
				this->Fight(this, world.GetOrganisms()[i]);
				break;
			}
			
			break;
		}
	}
	this->SetPosition(newPoint);
	currentMap[x][y] = EMPTY;
	currentMap[newPoint.GetX()][newPoint.GetY()]=world.FindClassOfObject(this);
	
	world.SetMap(currentMap);*/
}

void Animal::DeadMessage(Organism* attacker)
{
}

Animal::~Animal()
{
}
