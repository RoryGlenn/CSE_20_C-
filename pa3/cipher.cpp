#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
using namespace std;

void PrintList(list<char> list_)
{
	// prints the list
	list<char>::const_iterator pos;
	for (pos = list_.begin(); pos != list_.end(); ++pos)
	{
		cout << *pos << ' ';
	}
	cout << endl;
}

list<char> ReadFile(string readFileName)
{
	string line;
	ifstream readFile;
	list<char> listReadIn;

	try
	{
		readFile.open(readFileName, ios::out | ios::in);
	}
	catch (int error)
	{
		cout << "An exception occurred. Exception number: " << error << endl;
		exit(EXIT_FAILURE);
	}

	// iterate over each line of readFileName
	while (getline(readFile, line))
	{
		// iterate over each character in line
		for (int i = 0; i < line.size(); i++)
		{
			char charInLine = toupper(line[i]);
			listReadIn.push_back(charInLine);
		}
	}

	readFile.close();

	return listReadIn;
}

void WriteFile(string writeFileName, list<char> inList)
{
	string line;
	ofstream writeFile;
	list<char> listReadIn;
	list<char>::const_iterator character;

	writeFile.open(writeFileName);

	for (character = inList.begin(); character != inList.end(); ++character)
	{
		writeFile << *character;
	}

	writeFile.close();
}

list<char> Encrypt(list<char> inList)
{
	list<char> outList;
	list<char>::const_iterator character;

	for (character = inList.begin(); character != inList.end(); ++character)
	{
		if ((*character < 'A' || *character > 'Z') && (*character < 'a' || *character > 'z'))
		{
			outList.push_back(*character);
		}
		else if (*character >= 'A' && *character <= 'Z')
		{
			int offset = *character - 65;
			offset = (offset + 3) % 26;
			int converted = offset + 65;
			outList.push_back(static_cast<char>(converted));
		}
	}
	return outList;
}

list<char> Decrypt(list<char> inList)
{
	list<char> outList;
	list<char>::const_iterator character;

	for (character = inList.begin(); character != inList.end(); ++character)
	{
		if ((*character < 'A' || *character > 'Z') && (*character < 'a' || *character > 'z'))
		{
			outList.push_back(*character);
		}
		else if (*character >= 'A' && *character <= 'Z')
		{
			int offset = *character - 65; // 65 - 65 = 0
			offset = (offset - 3) % 26; // 0 - 3 % 26 = -3

			if (offset < 0)
			{
				offset = offset + 26; //  -3 + 26 = 23
			}

			char converted = offset + 65; // 23 + 65 = 88
			outList.push_back(converted);
		}
	}

	return outList;
}

int main()
{
	bool done = false;

	while (!done)
	{
		char choice;
		cout << "Would you like to encode or decode the message?" << endl;
		cout << "Type E to encode, D to decode, or Q to quit: " << endl;

		cin >> choice;

		if (toupper(choice) == 'E')
		{
			string readFileName;
			string writeFileName;
			string line;
			list<char> readFile;

			cout << "Please enter a file for reading: " << endl;
			cin >> readFileName;

			cout << "Please enter a file for writing: " << endl;
			cin >> writeFileName;

			readFile = ReadFile(readFileName);

			cout << "Plaintext:" << endl;

			PrintList(readFile);

			cout << "Encrypted:" << endl;
			list<char> encryptedList = Encrypt(readFile);
			PrintList(encryptedList);

			WriteFile(writeFileName, encryptedList);
		}

		else if (toupper(choice) == 'D')
		{
			string readFileName;
			string writeFileName;
			string line;
			list<char> readFile;
			list<char> decryptedList;

			cout << "Please enter a file for reading: " << endl;
			cin >> readFileName;

			cout << "Please enter a file for writing: " << endl;
			cin >> writeFileName;

			readFile = ReadFile(readFileName);

			cout << "Plaintext:" << endl;
			PrintList(readFile);

			cout << "Decrypted:" << endl;
			decryptedList = Decrypt(readFile);
			PrintList(decryptedList);

			WriteFile(writeFileName, decryptedList);
		}

		else if (toupper(choice) == 'Q')
		{
			cout << "Goodbye!" << endl;
			done = true;
		}
	}
}
