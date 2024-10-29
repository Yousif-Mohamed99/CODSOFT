#include <iostream>
using namespace std;

class Calculator
{
public:
  double num1,num2;

  Calculator()
  {
    num1 = 0;
    num2 = 0;
  }

  Calculator(double num1 , double num2)
  {
    this->num1 = num1;
    this->num2 = num2;
  }

  double getNum1()
  {
    return num1;
  }

  double getNum2()
  {
    return num2;
  }

  double add()
  {
    return num1 + num2;
  }

  double subtract()
  {
    return num1 - num2;
  }

  double multiply()
  {
    return num1 * num2;
  }

  double divison()
  {
    if (num2 == 0)
      {
        cout << "Error: Division by zero is undefined.\n";
        return 0;
      }

    return num1 / num2;
  }

  void runCalcualtor();
};

void Calculator::runCalcualtor()
{
  cout << "\nPlease Enter The First Number: ";
  cin >> num1;

  cout << "\nPlease Enter The Second Number: ";
  cin >> num2;

  cout << "\nSelect From Options: \n";
  cout << "------------------------\n\n";

  cout << "  [1] Add\n";
  cout << "  [2] Subtract\n";
  cout << "  [3] Multiply\n";
  cout << "  [4] Diviosn\n";

  int select;
  cout << "\nSelect: ";
  cin >> select;

  do
  {
    switch(select)
    {
      case 1:
        cout << "\nResult of " << getNum1() << " + " << getNum2() << " = " << add();
        break;

      case 2:
        cout << "\nResult of " << getNum1() << " - " << getNum2() << " = " << subtract();
        break;

      case 3:
        cout << "\nResult of " << getNum1() << " * " << getNum2() << " = " << multiply();
        break;

      case 4:
        cout << "\nResult of "<< getNum1() << " / " << getNum2() << " = " << divison();
        break;

      default:
        cout << "Invalid Selection\n";
    }
  } while(select < 1 && select > 5);
  
}

int main()
{
  Calculator c;
  int choice;

  cout << "\t\tWelcome to My Calculator!\n";
  cout << "\t------------------------------------------\t\n\n";

  do
  {
    c.runCalcualtor();
    cout << "\n-----------------\n";
    cout << "Do You Want To Do Another Calculation?\n";
    cout << "(1) Yes\n";
    cout << "(2) No\n";

    do 
    {
      cout << "\nSelect: ";
      cin >> choice;
      if (choice != 1 && choice != 2)
      {
        cout << "Invalid selection. Please enter 1 for Yes or 2 for No.\n";
      }
    } while (choice != 1 && choice != 2);

    
  } while (choice == 1);

  cout << "Thank you for choosing our calculator\n";

  system("pause");
  return 0;
}