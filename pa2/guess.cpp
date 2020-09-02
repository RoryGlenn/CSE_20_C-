
/*
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
	bool done = true;
	unsigned short count = 0;
	srand( (unsigned) time(0) );
	unsigned short random_num;
	cout << "Play a game: Guess My Number." << endl;

	while (done)
	{
		if(count == 0)
		{
			random_num = 1 + rand() % 10;
			cout << "You have three attempts to guess my number." << endl;
			cout << "Please enter a number from 1 to 10" << endl;
		}
		
		if (count != 3)
		{
			unsigned short num;
			cin >> num;

			if (num < random_num)
			{
				cout << "You guessed wrong. Your number is smaller than mine." << endl;
				cout << "Guess again. Please enter a number:" << endl;
				count++;
			}
			else if( num > random_num)
			{
				cout << "You guessed wrong. Your number is larger than mine." << endl;
				cout << "Guess again. Please enter a number:" << endl;
				count++;
			}
			else if(num == random_num)
			{
				char play_again;
				cout << "You guessed right. Congratulations you won!" << endl;
				cout << "Would you like to play again [Y/N]?" << endl;
				cin >> play_again;

				if (play_again == 'Y' || play_again == 'y')
				{
					count = 0;
				}
				else if( play_again == 'N' || play_again == 'n')
				{
					cout << "Goodbye!" << endl;
					done = false;
				}
			}
		}
		else if(count == 3)
		{
			char play_again;
			cout << "Sorry, you lost. My number is " << random_num << "." << endl;
			cout << "Would you like to play again [Y\\N]?" << endl;
			cin >> play_again;

			if (play_again == 'Y' || play_again == 'y')
			{
				count = 0;
			}
			else if (play_again == 'N' || play_again == 'n')
			{
				cout << "Goodbye!" << endl;
				done = false;
			}
		}
	}
}
*/