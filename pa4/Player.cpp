#include "Player.h"
#include "Board.h"
#include <iostream>

Player::Player(string name, char sign)
{
	m_name = name;
	m_sign = sign;
}

char Player::GetSign()
{
	return m_sign;
}
string Player::GetName()
{
	return m_name;
}

void Player::Choose(Board* board)
{
	while(true)
	{
		string cellChoice;
		int isValidTurn;
		
		cout << m_name << ", " << m_sign << ';' << " Enter a cell [A-C][1-3]:" << endl;
		cin >> cellChoice;
		
		isValidTurn = board->GetTurns();
		
		board->Set(cellChoice, m_sign);

		if(isValidTurn < board->GetTurns())
		{
			break;
		}
	}
}