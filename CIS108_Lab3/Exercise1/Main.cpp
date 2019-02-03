#include <iostream>
#include "Calculator.h"
#include "conio.h"
#include <string>

//Include namespace std and Calculator.
using namespace std;
using namespace Calculator;

char char_calculate;
double number_1;
double number_2;
int number_int = 1;
char operation;
string key_1 = "";
string key_2 = "";

int main()
{
	//Prompt the user to enter data with the >.
	cout << "> ";
	//Once prompted, do the following:
	do
	{
		//Using the (_getch()) from the conio.h as directed in assignment. #include conio.h is also above.
		char_calculate = char(_getch());
		switch (char_calculate)
		{
			case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0': case '.':
				cout << char_calculate;
				if (number_int == 1)
					key_1 += char_calculate;
				else 
					key_2 += char_calculate;
				break;
			//Perform operation.
			case '*': case '+': case '/': case '-': case '^':
				if (number_int == 1)
				{
					number_1 = stod(key_1);
					number_int = 2;
					key_1 = "";
					key_2 = "";
				}
				cout << char_calculate;
				operation = char_calculate;
				break;
			//Memory store.
			case 's': case 'S':
				memory_Store(number_1);
				break;
			//Memory recall.
			case 'r': case 'R':
				number_1 = memory_Recall();
				cout << endl << number_1;
				break;
			//Memory clear.
			case 'm': case 'M':
				memory_Clear();
				break;
			//Invert.
			case 'i': case 'I':
				number_1 = invert(stod(key_1));
				cout << endl << number_1;
				break;
			//Clear.
			case 'c': case 'C':
				cout << endl << "> ";
				key_1 = "";
				key_2 = "";
				number_1 = 0;
				number_2 = 0;
				number_int = 1;
				break;

				//If second number perform requested operation by case.
				case char(13):
					cout << endl;
					if (key_2 != "")
						{
							number_2 = stod(key_2);
							switch (operation)
							{
								case '+':
									number_1 = add(number_1, number_2);
									break;
								case '-':
									number_1 = subtract(number_1, number_2);
									break;
								case '/':
									number_1 = divide(number_1, number_2);
									break;
								case '*':
									number_1 = multiply(number_1, number_2);
									break;
								case '^':
									number_1 = power_Function(number_1, number_2);
									break;
								default:
									break;
							}
						}
					cout << number_1 << endl << "> ";
					key_1 = to_string(number_1);
					key_2 = "";
					number_int = 1;
					break;
				default:
					break;
		}
		//To exit the program.
	} while (char_calculate != 'x' && char_calculate != 'X');
	//Return 0 when program not functioning as it should.
	return 0;
}