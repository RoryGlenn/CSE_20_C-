#pragma once
#include "Board.h"
#include <string>
using namespace std;

class Player
{

private:
	string m_name;
	char m_sign;
	char m_cell = ' ';

public:
	Player(string name, char sign);

	char GetSign();
	string GetName();
	void Choose(Board* board);
};

