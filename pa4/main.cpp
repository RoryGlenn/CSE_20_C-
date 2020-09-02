#include "Player.h"
#include "Board.h"

int main()
{
	cout << "Welcome to TIC-TAC-TOE Game!" << endl;

	while(true)
	{
		Board board;

		Player player1("Alice", 'X');
		Player player2("Bill", 'O');

		bool turn = true;

		while(true)
		{
			board.Show();

			if(turn)
			{
				player1.Choose(&board);
				turn = false;
			}
			else
			{
				player2.Choose(&board);
				turn = true;
			}

			if(board.IsDone())
			{
				break;
			}
			
		}

		board.Show();

		if(board.GetWinner() == player1.GetSign())
		{
			cout << player1.GetName() << " is the winner!" << endl;
		}
		else if(board.GetWinner() == player2.GetSign())
		{
			cout << player2.GetName() << " is the winner!" << endl;
		}
		else
		{
			cout << "It is a tie!" << endl;
		}

		
		char ans;
		cout << "Would you like to play again? [Y/N] " << endl;
		
		cin >> ans;
		ans = toupper(ans);

		if(ans != 'Y')
		{
			break;
		}
	}

	cout << "Goodbye!" << endl;
}