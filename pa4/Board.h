#pragma once
#include <iostream>
using namespace std;

class Board
{
	
private:
	char m_sign = ' ';
	char m_winner = ' ';
	int  m_size = 3;
	int  m_turns = 0;
	bool m_tie = false;
	char m_grid[9];

public:
	Board();
	int  GetSize();
	char GetWinner();
	int GetTurns();
	void Set(string cell, char sign);
	bool IsEmpty(int i);
	void Show();
	int  ConvertCell(string cell);
	bool IsDone();
	void CheckRows();
	void CheckColumns();
	void CheckDiagonals();
	void CheckTie();
	char* GetBoard();
};

