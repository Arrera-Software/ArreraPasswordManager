#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

class CGestionFichier
{
public:
	CGestionFichier();
	~CGestionFichier();
	int ecriture(string app, string mdp);
	int lecture();
	int rechercheMot(string mot);
	int effacer();
	
private:
	string nomFichier = "output.txt";
};

