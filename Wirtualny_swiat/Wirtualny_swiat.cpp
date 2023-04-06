#include <iostream>
#include "World.h"
#include "Human.h"

using namespace std;

int main()
{
	srand(time(NULL));
	World NewWorld(EMPTY);
	cout << "Wcisnij 'u' lub 'U' aby wczytaj poprzedni stan gry, lub dowolny inny przycisk, aby zaczac gre od nowa" << endl;
	char game;
	cin >> game;
	if (int(game) == KEY_UPLOAD_UPPERCASE || int(game) == KEY_UPLOAD) NewWorld.UploadGame();
	else {
		NewWorld.SetHeight(20);
		NewWorld.SetWidth(20);
		NewWorld.CreateNewWorld();
	}
	
	while (!NewWorld.EndGame())
	{
		NewWorld.DrawWorld();
		NewWorld.ExecuteRound();
	}

    return 0;
}