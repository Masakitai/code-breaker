//code breaker by Christian Mangione
//inclusions
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
//namespace
using namespace std;
//start program
int main()
{
	//enumeration fields
	enum fields { code, hint, codeAmount };
	//array amounts
	const int puzzleAmount = 10;
	//array of words and hints
	const string HINTS[puzzleAmount][codeAmount] =
	{
		{ "america","Land of the free and home of the brave" },
	    { "sheep","Little bo peep lost all of her mes"},
		{ "sword","A shield and I work well together" },
		{ "horse","Epona is the same species" },
		{ "nose","Mucinex helps me when I'm sick" },
		{ "light","The first half of a distance in space" },
		{ "home","This is where I belong with you" },
		{ "wood","I sound like would" },
		{ "water","You drink me and I'm 95% of you" },
		{ "lemon","The half of a sprite that DOESN'T go in a coconut" }
	};
	//game start
	cout << "\t\t\tWelcome to Code Breaker!\n\n";
	cout << "Unscramble the letters to make a word. You have 3 codes to find.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	int count = 0;
	int guesses = 0;
	string playAgain = "yes";
	//game loop
	while (playAgain == "yes")
	{
		while (count < 3)
		{
			//random number
			srand(static_cast<unsigned int>(time(0)));
			int randomNumber = (rand() % puzzleAmount);
			//random code
			string theCode = HINTS[randomNumber][code];
			//random hint
			string theHint = HINTS[randomNumber][hint];
			//Jumble word
			string jumble = theCode;
			int length = jumble.size();
			for (int i = 0; i < length; ++i)
			{
				//temp variable switching
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}
			//Show jumble
			cout << "The Secret is: " << jumble;
			//create input
			string guess;
			cout << "\n\nYour readings:";
			cin >> guess;
			while ((guess != theCode) && (guess != "quit"))
			{
				//hint
				if (guess == "hint")
				{
					cout << theHint;
				}
				//fail
				else {
					cout << "Sorry, that's not it.";
					guesses++;
				}
				cout << "\n\nYour readings: ";
				cin >> guess;
			}
			//pass
			if (guess == theCode)
			{
				cout << "\nThat's it! You guessed it!\n";
				count++;
				guesses++;
			}
		}
		cout << "\nWe've taken down the soviet union!\n";
		cout << "\n It took this spy " << guesses << " attempts to solve the code!\n";
		cout << "\nWould you like to play again? yes/no \n";
		guesses = 0;
		count = 0;
		cin >> playAgain;

	}

		std::system("pause");
	return 0;
}

