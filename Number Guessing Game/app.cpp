#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player
{
  string PlayerName;
public:

  Player()
  {
    PlayerName = "";
  }

  Player(string PlayerName)
  {
    this->PlayerName = PlayerName;
  }

  void SetPlayerName(string PlayerName)
  {
    this->PlayerName = PlayerName;
  }

  string getPlayerName()
  {
    return PlayerName;
  }

};


class Game
{
  int randomNumber;
  int range;
  int attempts;
  int difficult;
  int guess;
public:

  void setDifficulty(int difficult)
  {
    this->difficult = difficult;
    
    if (difficult == 1) // Easy
    {
      range = 10;
    }
    else if (difficult == 2) // Medium
    {
      range = 50;
    }
    else if (difficult == 3) // Hard
    {
      range = 100;
    }
    else
    {
      cout << "Please chosse between 1 and 3\n";
    }
    generateNumber();
  }

  int getDifficult()
  {
    return difficult;
  }

  void generateNumber()
  {
    srand(static_cast<unsigned int>(time(0)));
    randomNumber = (rand() % range) + 1;
  }

  string checkGuess(int guess)
  {
    if(guess > randomNumber )
    {
      return "Too high";
    }
    else if(guess < randomNumber)
    {
      return "Too low";
    }
    else 
    {
      return "Correct";
    }
  }

  void Play()
  {
    guess = 0;
    attempts = 0;
    while (guess != randomNumber)
    {
      cout << "Enter your Guess Number: ";
      cin >> guess;
      attempts++;
      string feedback = checkGuess(guess);
      cout << feedback << endl;

      if(difficult == 1 && attempts == 3)
      {
        cout << "Hint!, The range is between 1 to 10\n";
      }
      else if(difficult == 2 && attempts == 3)
      {
        cout << "Hint!, The range is between 1 to 50\n";
      }
      else if(difficult == 3 && attempts == 3)
      {
        cout << "Hint!, The range is between 1 to 100\n";
      }

      if (feedback == "Correct") 
      {
        cout << "You guessed the number in " << attempts << " attempts!" << endl;
        break;
      }
    }
  }
};

void runGame(Player& p1, Game& g1)
{
    cout << "Please Enter Your Name: ";
    string name;
    cin >> name;
    p1.SetPlayerName(name);

    cout << "----------------\n";
    cout << "Please Select The Difficulty: \n";
    cout << "    (1) Easy\n";
    cout << "    (2) Medium\n";
    cout << "    (3) Hard\n";
    cout << "\nEnter Your Choice: ";

    int difficulty;
    cin >> difficulty;
    g1.setDifficulty(difficulty);

    cout << "----------------\n";
    g1.Play();
}

int main()
{
  Player p1;
  Game g1;
  cout << "\t\t\t\tWelcome to Number Guessing Game!\n";
  cout << "\t\t\t------------------------------------------------\t\t\n\n";

  runGame(p1, g1);

  cout << "\n------------\n";

  cout << "Select: \n";
  cout << "(1) Play Again\n";
  cout << "(2) Exit Game\n";

  int choice;
  cin >> choice;
  while(choice != 2)
  {
    runGame(p1, g1);
    cout << "\n------------\n";
    cout << "Select: \n";
    cout << "(1) Play Again\n";
    cout << "(2) Exit Game\n";
    cin >> choice;
  }

  cout << "Thank you " << p1.getPlayerName() << " For Choosing our Game\n\n";

  system("pause");
  return 0;
}