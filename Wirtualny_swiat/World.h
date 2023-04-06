#pragma once
#include "Organism.h"
#include "Point.h"
#include <stdlib.h>
#include <time.h> 
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>



using namespace std;

#define EMPTY ' '
#define HUMAN 'H'
#define WOLF 'W'
#define SHEEP 'S'
#define FOX 'F'
#define TURTLE 'T'
#define ANTELOPE 'A'
#define GRASS 'G'
#define MILT 'M'
#define GUARANA 'U'
#define BLUEBERRY 'B'
#define SOSNOWSKY 'O'

#define SIZE_OF_MAP 20

enum move {
	DOWN,
	UP,
	LEFT,
	RIGHT
};

class Organism;

class World {
private:
	vector<Organism*> organisms;
	vector<vector<char>> map;
	int ture;
	int width;
	int height;
public:
	World(int a);
	World(int width, int height, int ture=0);
	void AddOrganism(Organism* organism, Point & position);
	const vector<Organism*> GetOrganisms();
	const vector<vector<char>> GetMap();
	const int GetTure();
	const int GetWidth();
	const int GetHeight();
	//void EraseOrganism(Organism* organism);
	void SortOrganisms();
	void RefreashOrganism();
	void SetMap(vector<vector<char>> map);
	void SetOrganisms(vector<Organism*> organisms);
	void SetTure(int ture);
	void SetWidth(int width);
	void SetHeight(int height);
	void CreateNewWorld();
	void CreateMap();
	bool IsAnEmptyPosition(Point position);
	int FindClassOfObject(Organism* organism);
	void ExecuteRound();
	bool EndGame();
	void DrawWorld();
	void SaveGame();
	void UploadGame();
	~World();
};
