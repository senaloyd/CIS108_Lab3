#include "Calculator.h"
#include <iostream>

using namespace std;
double memory;

//Addition function.
double Calculator::add(double number_1, double number_2)
{
	return (number_1 + number_2);
}

//Subtraction function.
double Calculator::subtract(double number_1, double number_2)
{
	return (number_1 - number_2);
}

//Division function.
double Calculator::divide(double number_1, double number_2)
{
	return (number_1 / number_2);
}

//Multiplication function.
double Calculator::multiply(double number_1, double number_2)
{
	return (number_1 * number_2);
}

//Memory recall function.
double Calculator::memory_Recall()
{
	return memory;
}

//Memory store function.
void Calculator::memory_Store(double input_number)
{
	memory = input_number;
}

//Memory clear function.
void Calculator::memory_Clear()
{
	memory = 0;
}

//Power function.
double Calculator::power_Function(double number_1, double number_2)
{
	return pow(number_1, number_2); 
}

//Invert function
double Calculator::invert(double input_number)
{
	return 0.0 - input_number;
}
