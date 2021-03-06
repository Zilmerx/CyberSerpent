/*
Cree par Jean-Philippe Doyon,

Le 15 Septembre 2015.
*/

#include <iostream>
#include <chrono>

#include "CyberSerpent.h"

int main()
{
	//MainTestKeyBoard();

	CyberSerpent jeu{};

	jeu.Initialize();

	jeu.Start();

	std::this_thread::sleep_for(std::chrono::seconds(5));
}

#pragma region MainTestKeyBoard
///////////////////////////////////////////

void FonctionHERP()
{
	std::cout << "HERP";
}

void FonctionDERP()
{
	std::cout << "DERP";
}

int MainTestKeyBoard()
{
	KeyboardReader reader;

	reader.setFunction(75, FonctionHERP);
	reader.setFunction(75, FonctionDERP);

	reader.setFunction(77, FonctionDERP);
	reader.setFunction(77, FonctionHERP);

	reader.start();

	std::cout << "DEBUT" << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(3));

	std::cout << "CLEAR" << std::endl;

	reader.clearFunction(75);

	std::this_thread::sleep_for(std::chrono::seconds(3));

	std::cout << "FIN" << std::endl;

	reader.stop();

	return 0;
}
#pragma endregion