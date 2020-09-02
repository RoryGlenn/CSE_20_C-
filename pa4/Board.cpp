#include "Board.h"

Board::Board()
{
	// initialize board with empty spaces
	for(int i = 0; i < size(m_grid); i++)
	{
		m_grid[i] = ' ';
	}
}


int Board::GetSize()
{
	return m_size;
}

char Board::GetWinner()
{
	return m_winner;
}

int Board::GetTurns()
{
	return m_turns;
}

void Board::Set(string cell, char sign)
{
	int convertedCell = ConvertCell(cell);

	if(convertedCell != -1)
	{
		if(IsEmpty(convertedCell))
		{
			m_grid[convertedCell] = sign;
			m_turns++;
		}
		else
		{
			cout << "You did not choose correctly." << endl;
		}
	}
}

bool Board::IsEmpty(int i)
{
	if (m_grid[i] != ' ')
	{
		return false;
	}

	return true;
}

void Board::Show()
{
	cout << "   A   B   C " << endl;
	cout << " +---+---+---+" << endl;
	cout << "1| " << m_grid[0] << " | " << m_grid[1] << " | " << m_grid[2] << " |" << endl;
	cout << " +---+---+---+" << endl;
	cout << "2| " << m_grid[3] << " | " << m_grid[4] << " | " << m_grid[5] << " |" << endl;
	cout << " +---+---+---+" << endl;
	cout << "3| " << m_grid[6] << " | " << m_grid[7] << " | " << m_grid[8] << " |" << endl;
	cout << " +---+---+---+" << endl;
}


int Board::ConvertCell(string cell)
{
	
	string::const_iterator character;
	string temp = "";

	for (character = cell.begin(); character != cell.end(); ++character)
	{
		temp += toupper(*character);
	}

	cell = temp;

	if (cell == "A1")
	{
		return 0;
	}
	else if (cell == "B1")
	{
		return 1;
	}
	else if (cell == "C1")
	{
		return 2;
	}
	else if (cell == "A2")
	{
		return 3;
	}
	else if (cell == "B2")
	{
		return 4;
	}
	else if (cell == "C2")
	{
		return 5;
	}
	else if (cell == "A3")
	{
		return 6;
	}
	else if (cell == "B3")
	{
		return 7;
	}
	else if (cell == "C3")
	{
		return 8;
	}
	else
	{
		cout << "You did not choose correctly" << endl;
	}

	return -1;

}

bool Board::IsDone()
{
	CheckRows();
	CheckColumns();
	CheckDiagonals();
	CheckTie();

	if (m_tie)
	{
		return true;
	}

	if (m_winner != ' ')
	{
		return true;
	}

	return false;
}

void Board::CheckRows()
{
	if(m_grid[0] == 'X' && m_grid[1] == 'X' && m_grid[2] == 'X')
	{
		m_winner = 'X';
	}
	else if (m_grid[3] == 'X' && m_grid[4] == 'X' && m_grid[5] == 'X')
	{
		m_winner = 'X';
	}
	else if (m_grid[6] == 'X' && m_grid[7] == 'X' && m_grid[8] == 'X')
	{
		m_winner = 'X';
	}


	else if (m_grid[0] == 'O' && m_grid[1] == 'O' && m_grid[2] == 'O')
	{
		m_winner = 'O';
	}
	else if (m_grid[3] == 'O' && m_grid[4] == 'O' && m_grid[5] == 'O')
	{
		m_winner = 'O';
	}
	else if (m_grid[6] == 'O' && m_grid[7] == 'O' && m_grid[8] == 'O')
	{
		m_winner = 'O';
	}
	
}


void Board::CheckColumns()
{
	if (m_grid[0] == 'X' && m_grid[3] == 'X' && m_grid[6] == 'X')
	{
		m_winner = 'X';
	}
	else if (m_grid[1] == 'X' && m_grid[4] == 'X' && m_grid[7] == 'X')
	{
		m_winner = 'X';
	}
	else if (m_grid[2] == 'X' && m_grid[5] == 'X' && m_grid[8] == 'X')
	{
		m_winner = 'X';
	}


	else if (m_grid[0] == 'O' && m_grid[3] == 'O' && m_grid[6] == 'O')
	{
		m_winner = 'O';
	}
	else if (m_grid[1] == 'O' && m_grid[4] == 'O' && m_grid[7] == 'O')
	{
		m_winner = 'O';
	}
	else if (m_grid[2] == 'O' && m_grid[5] == 'O' && m_grid[8] == 'O')
	{
		m_winner = 'O';
	}
	
}

void Board::CheckDiagonals()
{
	if(m_grid[0] == 'X' && m_grid[4] == 'X' && m_grid[8] == 'X')
	{
		m_winner = 'X';
	}
	else if (m_grid[2] == 'X' && m_grid[4] == 'X' && m_grid[6] == 'X')
	{
		m_winner = 'X';
	}


	else if (m_grid[0] == 'O' && m_grid[4] == 'O' && m_grid[8] == 'O')
	{
		m_winner = 'O';
	}
	else if (m_grid[2] == 'O' && m_grid[4] == 'O' && m_grid[6] == 'O')
	{
		m_winner = 'O';
	}
}

void Board::CheckTie()
{
	if(m_turns == 9 && m_winner == ' ')
	{
		m_tie = true;
	}
}

char* Board::GetBoard()
{
	return m_grid;
}
