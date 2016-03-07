/**
 * @file main.cpp
 * @author  Karim Jana <karimjana@gmail.com>
 * @date	July, 2015.
 * @version 1.0
 * @details Proffesor Doug Ferguson - C++ class
 *
 * @brief Outputs the results for the different operations and sub cases of sign value.

 */
#include <iostream>
#include "HugeInt.h"
using namespace std;

int main()
{
	HugeInt result;
	HugeInt hugeNumber;
	int positiveInt = 2147483647;
	int negativeInt = -2147483647;
	//int positiveInt = 50;
	//int negativeInt = -50;
	hugeNumber.input();
	hugeNumber.setIntegers(hugeNumber.convertToVector(hugeNumber.getNumber()));

	/**
	 * Addition:
	 * Case 1: int + HugeInt
	 * Case 2: (-int) + HugeInt

	 * Case 3: HugeInt + int
	 * Case 4: HugeInt + (-int)
	 */
	result = positiveInt + hugeNumber;
	result.prettyPrint(positiveInt, hugeNumber, '+');

	result = negativeInt + hugeNumber;
	result.prettyPrint(negativeInt, hugeNumber, '+');

	result = hugeNumber + positiveInt;
	result.prettyPrint(hugeNumber, positiveInt, '+');

	result = hugeNumber + negativeInt;
	result.prettyPrint(hugeNumber, negativeInt, '+');

	/**
	 * Subtraction:
	 * Case 1: int - HugeInt
	 * Case 2: (-int) - HugeInt

	 * Case 3: HugeInt - int
	 * Case 4: HugeInt - (-int)
	 */
	result = positiveInt - hugeNumber;
	result.prettyPrint(positiveInt, hugeNumber, '-');

	result = negativeInt - hugeNumber;
	result.prettyPrint(negativeInt, hugeNumber, '-');

	result = hugeNumber - positiveInt;
	result.prettyPrint(hugeNumber, positiveInt, '-');

	result = hugeNumber - negativeInt;
	result.prettyPrint(hugeNumber, negativeInt, '-');

	/**
	 * Multiplication:
	 * Case 1: int * HugeInt
	 * Case 2: (-int) * HugeInt

	 * Case 3: HugeInt * int
	 * Case 4: HugeInt * (-int)
	 */
	result = positiveInt * hugeNumber;
	result.prettyPrint(positiveInt, hugeNumber, '*');

	result = negativeInt * hugeNumber;
	result.prettyPrint(negativeInt, hugeNumber, '*');

	result = hugeNumber * positiveInt;
	result.prettyPrint(hugeNumber, positiveInt, '*');

	result = hugeNumber * negativeInt;
	result.prettyPrint(hugeNumber, negativeInt, '*');

	/**
	 * Division:
	 * Multiplication:
	 * Case 1: int / HugeInt
	 * Case 2: (-int) / HugeInt

	 * Case 3: HugeInt / int
	 * Case 4: HugeInt / (-int)
	 */
	result = positiveInt / hugeNumber;
	result.prettyPrint(positiveInt, hugeNumber, '/');

	result = negativeInt / hugeNumber;
	result.prettyPrint(negativeInt, hugeNumber, '/');

	result = hugeNumber / positiveInt;
	result.prettyPrint(hugeNumber, positiveInt, '/');

	result = hugeNumber / negativeInt;
	result.prettyPrint(hugeNumber, negativeInt, '/');

	return 0;
}//end main()
