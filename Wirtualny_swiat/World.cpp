#include "World.h"

#include <typeinfo>


//Tutaj stworzyc lpik zeby includowa wszystkie klasy


#include "Wolf.h"
#include "Human.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "Milt.h"
#include "Guarana.h"
#include "Blueberry.h"
#include "Sosnowsky.h"

int randomNumber() {
	return rand() % SIZE_OF_MAP;
}

Point getNewPoisition(Point point) {
	point.SetX(randomNumber());
	point.SetY(randomNumber());
	return point;
}

World::World(int a)
{
	this->width = 0;
	this->height = 0;
	this->ture = 0;
}

World::World(int width, int height, int ture){
	this->width = width;
	this->height = height;
	this->ture = 0;
	CreateNewWorld();
}

int World::FindClassOfObject(Organism* newOrganism)
{
	if (typeid(*newOrganism) == typeid(Human)) return HUMAN;
	else if (typeid(*newOrganism) == typeid(Wolf)) return WOLF;
	else if (typeid(*newOrganism) == typeid(Sheep)) return SHEEP;
	else if (typeid(*newOrganism) == typeid(Fox)) return FOX;
	else if (typeid(*newOrganism) == typeid(Turtle)) return TURTLE;
	else if (typeid(*newOrganism) == typeid(Antelope)) return ANTELOPE;
	else if (typeid(*newOrganism) == typeid(Grass)) return GRASS;
	else if (typeid(*newOrganism) == typeid(Milt)) return MILT;
	else if (typeid(*newOrganism) == typeid(Guarana)) return GUARANA;
	else if (typeid(*newOrganism) == typeid(Blueberry)) return BLUEBERRY;
	else if (typeid(*newOrganism) == typeid(Sosnowsky)) return SOSNOWSKY;
	else return 0;
}


void World::AddOrganism(Organism* newOrganism, Point& position)
{
	organisms.push_back(newOrganism);
	map[position.GetX()][position.GetY()]=FindClassOfObject(newOrganism);
}

const vector<Organism*> World::GetOrganisms()
{
	return organisms;
}

const vector<vector<char>> World::GetMap()
{
	return map;
}

const int World::GetTure()
{
	return ture;
}

const int World::GetWidth()
{
	return width;
}

const int World::GetHeight()
{
	return height;
}

void World::SetOrganisms(vector<Organism*> organisms)
{
	this->organisms = organisms;
}

void World::SetTure(int ture)
{
	this->ture = ture;
}

void World::SetWidth(int width)
{
	this->width = width;
}

void World::SetHeight(int height)
{
	this->height = height;
}

/*void World::EraseOrganism(Organism* organism)
{
	vector <Organism*>::iterator it;
	it=organisms.begin();
	for (int i = 0; i < organisms.size(); i++)
	{
		if (organisms[i] != organism) it= organisms.begin()+i+1;
		else {
			organisms.erase(it);
			break;
		}
	}

}*/
//
//void World::DeleteCopies()
//{
//	for (int i = 0; i < organisms.size(); i++)
//	{
//		Point pi = organisms[i]->GetPosition();
//		for (int j = i+1; j < organisms.size(); j++)
//		{
//			Point pj = organisms[j]->GetPosition();
//			if (pi.GetX() == pj.GetX() && pi.GetY() == pj.GetY()) {
//				organisms[j]->SetIsAlive(false);
//			}
//		}
//	}
//	this->RefreashOrganism();
//}

void World::SortOrganisms()
{
	for (int i = 0; i < GetOrganisms().size(); i++)
	{
		for (int j = 1; j < GetOrganisms().size()-1; j++) //pêtla wewnêtrzna
			if ((GetOrganisms()[j - 1]->GetInitiative() >= GetOrganisms()[j]->GetInitiative()) ||
				(GetOrganisms()[j - 1]->GetInitiative() == GetOrganisms()[j]->GetInitiative() &&
					GetOrganisms()[j - 1]->GetAge() >= GetOrganisms()[j]->GetAge())) {
				vector<Organism*> org = GetOrganisms();
				Organism* tmp = org[j - 1];
				org[j - 1] = org[j];
				org[j] = tmp;
				SetOrganisms(org);
			}
	}
}

void World::RefreashOrganism()
{
	vector<Organism*> organismsNew;

	for (int i = 0; i < this->GetOrganisms().size(); i++)
	{
		Organism* org = this->GetOrganisms()[i];
		Point p = org->GetPosition();
		if (org->GetIsAlive()) organismsNew.push_back(org);
	}
	this->SetOrganisms(organismsNew);
}

void World::SetMap(vector<vector<char>> map)
{
	this->map = map;
}

void World::CreateMap()
{
	for (int i = 0; i < width; i++)
	{
		vector<char> tmp;
		for (int j = 0; j < height; j++)
		{
			tmp.push_back(EMPTY);
		}
		map.push_back(tmp);
	}
}

bool World::IsAnEmptyPosition(Point position)
{
	for (int i = 0; i < organisms.size(); i++)
	{
		Point organismPosition = organisms[i]->GetPosition();
		if (organismPosition.GetX() == position.GetX() &&
			organismPosition.GetY() == position.GetY()) {
			return false;
		}
	}
	return true;
}

void World::CreateNewWorld()
{
	CreateMap();
	//Tutaj ustawic tworzenie losowych zwierzat(chyba switch z inta) w losowych punktach

	int numberOfOrganism = rand() % 3 + 6; //zmienic na mniej
	Point position(randomNumber(), randomNumber());
	Organism* human = new Human(*this, position);
	AddOrganism(human, position);

	

	for (int i = 0; i < numberOfOrganism; i++)
	{
		while (!IsAnEmptyPosition(position)) {
			position=getNewPoisition(position);
		}
		Organism* wolf = new Wolf(*this, position);
		AddOrganism(wolf, position);
	}

	for (int i = 0; i < numberOfOrganism; i++)
	{
		while (!IsAnEmptyPosition(position)) {
			position = getNewPoisition(position);
		}
		Organism* sheep = new Sheep(*this, position);
		AddOrganism(sheep, position);
	}

	for (int i = 0; i < numberOfOrganism; i++)
	{
		while (!IsAnEmptyPosition(position)) {
			position = getNewPoisition(position);
		}
		Organism* fox = new Fox(*this, position);
		AddOrganism(fox, position);
	}

	for (int i = 0; i < numberOfOrganism; i++)
	{
		while (!IsAnEmptyPosition(position)) {
			position = getNewPoisition(position);
		}
		Organism* turtle = new Turtle(*this, position);
		AddOrganism(turtle, position);
	}

	for (int i = 0; i < numberOfOrganism; i++)
	{
		while (!IsAnEmptyPosition(position)) {
			position = getNewPoisition(position);
		}
		Organism* antelope = new Antelope(*this, position);
		AddOrganism(antelope, position);
	}

	for (int i = 0; i < numberOfOrganism; i++)
	{
		while (!IsAnEmptyPosition(position)) {
			position = getNewPoisition(position);
		}
		Organism* grass = new Grass(*this, position);
		AddOrganism(grass, position);
	}

	for (int i = 0; i < numberOfOrganism; i++)
	{
		while (!IsAnEmptyPosition(position)) {
			position = getNewPoisition(position);
		}
		Organism* milt = new Milt(*this, position);
		AddOrganism(milt, position);
	}

	for (int i = 0; i < numberOfOrganism; i++)
	{
		while (!IsAnEmptyPosition(position)) {
			position = getNewPoisition(position);
		}
		Organism* guarana = new Guarana(*this, position);
		AddOrganism(guarana, position);
	}

	for (int i = 0; i < numberOfOrganism; i++)
	{
		while (!IsAnEmptyPosition(position)) {
			position = getNewPoisition(position);
		}
		Organism* blueberry = new Blueberry(*this, position);
		AddOrganism(blueberry, position);
	}

	for (int i = 0; i < numberOfOrganism; i++)
	{
		while (!IsAnEmptyPosition(position)) {
			position = getNewPoisition(position);
		}
		Organism* sosnowsky = new Sosnowsky(*this, position);
		AddOrganism(sosnowsky, position);
	}
	
	//----------------------------------------------------------------------Test do kopulacji------------------------------------------------------------
	/*Point p1(0, 0);
	Point p2(1, 0);
	Point p3(0, 1);
	Point p4(3, 3);
	Organism* wolf1 = new Wolf(*this, p1);
	AddOrganism(wolf1, p1);
	Organism* wolf2 = new Wolf(*this, p2);
	AddOrganism(wolf2, p2);
	Organism* wolf3 = new Wolf(*this, p3);
	AddOrganism(wolf3, p3);
	Organism* wolf4 = new Wolf(*this, p4);
	AddOrganism(wolf4, p4);*/

}

void World::ExecuteRound()
{
	SortOrganisms();
	int size = organisms.size();
	for (int i = 0; i < size; i++)
	{
		organisms[i]->Action();
		if(organisms[i]->GetIsAlive()) organisms[i]->SetAge(organisms[i]->GetAge() + 1);
	}
	
	RefreashOrganism();

	ture++;
}

bool World::EndGame()
{
	for (size_t i = 0; i < organisms.size(); i++)
	{
		if (FindClassOfObject(organisms[i]) == HUMAN && organisms[i]->GetIsAlive()) {
			return false;
		}
	}
	return true;
	 
}

void World::DrawWorld()
{
	//DeleteCopies();
	vector<vector<char>> map = this->GetMap();
	cout << endl;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cout << map[j][i];
		}
		cout << endl;
	}
	cout << endl;
}

void World::SaveGame()
{
	fstream file;
	file.open("SavedWorld.txt", ios::out);
	file << width << endl;
	file << height << endl;
	file << ture << endl;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			file << map[j][i];
		}
		file << endl;
	}
	file << organisms.size() << endl;
	for (int i = 0; i < organisms.size(); i++)
	{
		int isAlive;
		if (organisms[i]->GetIsAlive()) isAlive = 1;
		else isAlive = 0;
		Point pos = organisms[i]->GetPosition();
		file << map[pos.GetX()][pos.GetY()] << " " << organisms[i]->GetPower() << " " << organisms[i]->GetInitiative() << " " <<
			pos.GetX() << " " << pos.GetY() << " " << isAlive << " " << organisms[i]->GetAge();
		if (map[pos.GetX()][pos.GetY()] == HUMAN) {
			file << " " << organisms[i]->GetAbilityActivated() << " " << organisms[i]->GetCanActivateAbility() << " " << organisms[i]->GetTureOfAbility();
		}
		file << endl;
	}

	file << '\n';
	file.close();
	cout << "Gra zostala zapisana" << endl;
}

void World::UploadGame()
{
	fstream file;
	file.open("SavedWorld.txt", ios::in);

	int width, height, ture;
	if (file.good()) {
		file >> width;
		file >> height;
		file >> ture;
		SetWidth(width);
		SetHeight(height);
		SetTure(ture);

		char c;
		vector<vector<char>> map;
		for (int i = 0; i < width; i++)
		{
			vector<char>tmp;
			for (int j = 0; j < height; j++)
			{
				if (j == 0)file.get(c);
				file.get(c);
				//file >> c;
				tmp.push_back(c);
			}
			map.push_back(tmp);
			//cout << endl;
		}
		SetMap(map);
		int size;
		file >> size;

		char org;
		int power, initiative, x, y;
		int alive;
		int age;
		bool abilityActivated, canActivateAbility;
		int tureOfAbility;
		for (int i = 0; i < size; i++)
		{
			file >> org;
			if (org == EMPTY) continue;
			file >> power;
			file >> initiative;
			file >> x;
			file >> y;
			file >> alive;
			file >> age;

			bool isAlive;
			if (alive) isAlive = true;
			else isAlive = false;

			Point pos(x, y);
			if (org == HUMAN) {
				file >> abilityActivated;
				file >> canActivateAbility;
				file >> tureOfAbility;
				Organism* organism = new Human(*this, pos, age, initiative, power, isAlive);
				AddOrganism(organism, pos);
			}
			else if (org == WOLF) {
				Organism* organism = new Wolf(*this, pos, age, initiative, power, isAlive);
				AddOrganism(organism, pos);
			}
			else if (org == SHEEP) {
				Organism* organism = new Sheep(*this, pos, age, initiative, power, isAlive);
				AddOrganism(organism, pos);
			}
			else if (org == FOX) {
				Organism* organism = new Fox(*this, pos, age, initiative, power, isAlive);
				AddOrganism(organism, pos);
			}
			else if (org == TURTLE) {
				Organism* organism = new Turtle(*this, pos, age, initiative, power, isAlive);
				AddOrganism(organism, pos);
			}
			else if (org == ANTELOPE) {
				Organism* organism = new Antelope(*this, pos, age, initiative, power, isAlive);
				AddOrganism(organism, pos);
			}
			else if (org == GRASS) {
				Organism* organism = new Grass(*this, pos, age, initiative, power, isAlive);
				AddOrganism(organism, pos);
			}
			else if (org == MILT) {
				Organism* organism = new Milt(*this, pos, age, initiative, power, isAlive);
				AddOrganism(organism, pos);
			}
			else if (org == GUARANA) {
				Organism* organism = new Guarana(*this, pos, age, initiative, power, isAlive);
				AddOrganism(organism, pos);
			}
			else if (org == BLUEBERRY) {
				Organism* organism = new Blueberry(*this, pos, age, initiative, power, isAlive);
				AddOrganism(organism, pos);
			}
			else if (org == SOSNOWSKY) {
				Organism* organism = new Sosnowsky(*this, pos, age, initiative, power, isAlive);
				AddOrganism(organism, pos);
			}
		}
	}
	
	file.close();
	
}


World::~World()
{
}
