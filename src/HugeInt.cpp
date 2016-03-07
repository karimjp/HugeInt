/**
 * @file HugeInt.cpp
 * @author  Karim Jana <karimjana@gmail.com>
 * @date	July, 2015.
 * @version 1.0
 * @details Proffesor Doug Ferguson - C++ class
 *
 * @brief Allows doing operations commutatively between HugeInt and int types.  Converts the numbers to crunch on to vectors and from vectors to strings.
 */
#include "HugeInt.h"
#include "Operand.h"
#include <algorithm>

HugeInt::HugeInt()
{
	setNumber("");
	setCarry(0);
	setBothPositive(false);
	setNegativeAndPositive(false);
	setPositiveAndNegative(false);
	setBothNegative(false);
	getLeftOperand().setInteger(0);
	getRightOperand().setInteger(0);
	getLeftOperand().setHugeIntString("");
	getRightOperand().setHugeIntString("");
	getLeftOperand().setSign(false);
	getRightOperand().setSign(false);

} //end HugeInt()

Operand HugeInt::getLeftOperand()
{
	return this->leftOperand;
}//end getLeftOperand()

Operand HugeInt::getRightOperand()
{
	return this->rightOperand;
}//end getRightOperand()

void HugeInt::setLeftOperand(const Operand &leftOperand)
{
	this->leftOperand = leftOperand;
}//end setLeftOperand()

void HugeInt::setRightOperand(const Operand &rightOperand)
{
	this->rightOperand = rightOperand;
} //end setRightOperand()

std::string HugeInt::getNumber()
{
	return this->number;
}//end getNumber()

void HugeInt::setNumber(std::string number)
{
	this->number = number;
}//end setNumber()

std::vector<int> HugeInt::getIntegers()
{
	return this->integers;
}//end getIntegers()

void HugeInt::setIntegers(std::vector<int> integers)
{
	this->integers = integers;
}//end setIntegers()

void HugeInt::setBothPositive(bool value)
{
	this->bothPositive = value;
}//end setBothPositive()

bool HugeInt::getBothPositive()
{
	return this->bothPositive;
}//end getBothPositive()

void HugeInt::setNegativeAndPositive(bool value)
{
	this->negativeAndPositive = value;
}//end setNegativeAndPositive()

bool HugeInt::getNegativeAndPositive()
{
	return this->negativeAndPositive;
}//end getNegativeAndPositive()

void HugeInt::setPositiveAndNegative(bool value)
{
	this->positiveAndNegative = value;
}//end setPositiveAndNegative()

bool HugeInt::getPositiveAndNegative()
{
	return this->positiveAndNegative;
}//end getPositiveAndNegative()

void HugeInt::setBothNegative(bool value)
{
	this->bothNegative = value;
}//end setBothNegative()

bool HugeInt::getBothNegative()
{
	return this->bothNegative;
}//end getBothNegative()

int HugeInt::getCarry()
{
	return this->carry;
}//end getCarry()

void HugeInt::setCarry(int carry)
{
	this->carry = carry;
}//end setCarry()

int HugeInt::calculateCarry(int presum)
{
	return presum / 10;
}//end caculateCarry()

void HugeInt::input()
{
	// takes in the number
	std::string number, x;
	std::cout << "Typed in a number no less than 60 digits long: " << std::endl;
	std::getline(std::cin, number);
	setNumber(number);
}//end input()

/**convertToString
 * converts a vector of integers to a string.
 * @param integers
 * @return std::string output
 */
std::string HugeInt::convertToString(std::vector<int> integers)
{
	std::string output = "";
	for (int i = 0; i < integers.size(); i++)
	{
		if (integers[i] == -1)
		{
			output += "-";
		} else
		{
			output += std::to_string(integers[i]);
		}
	}
	return output;
}//end convertToString()

/**
 * convertToVector
 * converts a string representing an integer to a vector
 * @param number
 * @return std::vector<int> integers
 */
std::vector<int> HugeInt::convertToVector(std::string number)
{
	std::vector<int> integers;
	int int_number;
	std::string string_number;
	char sign = number[0];
	if (sign == '-')
	{
		integers.push_back(-1);
		number.erase(0, 1);
	}
	//std::cout<<"stats:"<< number << " "<< number.size() << " "<< integers.size()<<std::endl;
	for (int i = 0; i < number.size(); i++)
	{

		string_number = number[i];
		int_number = std::stoi(string_number);

		integers.push_back(int_number);
		//std::cout<< "pushed: "<<string_number<< " "<< integers.size()<<std::endl;
	}
	return integers;
}//end convertToVector()

void HugeInt::prettyPrint(int numberOperand, HugeInt hugeIntOperand,
		char operatorKeyword)
{
	std::string operatorSymbol;
	switch (operatorKeyword)
	{
		case '+':
			operatorSymbol = " + ";
			break;
		case '-':
			operatorSymbol = " - ";
			break;
		case '*':
			operatorSymbol = " * ";
			break;
		case '/':
			operatorSymbol = " / ";
			break;
		default:
			operatorSymbol = "$$$UNKNOWN$$$";
			break;
	}

	std::cout << "Result:  integer" << operatorSymbol << "hugeIntNumber = "
			<< numberOperand << operatorSymbol << hugeIntOperand.getNumber()
			<< " = " << convertToString(getIntegers()) << std::endl;
}//end prettyPrint()

void HugeInt::prettyPrint(HugeInt hugeIntOperand, int numberOperand,
		char operatorKeyword)
{
	std::string operatorSymbol;
	switch (operatorKeyword)
	{
		case '+':
			operatorSymbol = " + ";
			break;
		case '-':
			operatorSymbol = " - ";
			break;
		case '*':
			operatorSymbol = " * ";
			break;
		case '/':
			operatorSymbol = " / ";
			break;
		default:
			operatorSymbol = "$$$UNKNOWN$$$";
			break;
	}
	std::cout << "Result:  hugeIntNumber" << operatorSymbol << "integer = "
			<< hugeIntOperand.getNumber() << operatorSymbol << numberOperand
			<< " = " << convertToString(getIntegers()) << std::endl;
}//end prettyPrint()

/**
 * divisionController
 * controller for division. Prepares the numbers for division
 * for 4 possible cases: bothPositive, negativeAndPositive,
 * PositiveAndNegative, and bothNegative.
 * @param hugeInt
 * @return std::vector<int> result
 */
std::vector<int> HugeInt::divisionController(HugeInt hugeInt)
{

	std::vector<int> result;
	std::vector<int> number1;
	std::vector<int> leftOperandNumber;
	std::vector<int> rightOperandNumber;
	std::vector<int> number2;
	bool isIntegerRightOperand;
	getOperandsSignValues();
	setIntegerAndHugeIntVectors(number1, number2, hugeInt,
			isIntegerRightOperand);
	setRightAndLeftOperandVectors(isIntegerRightOperand, rightOperandNumber,
			leftOperandNumber, number1, number2);

	numberZeroBalancer(leftOperandNumber, rightOperandNumber);
	//printTwoVectors(leftOperandNumber, rightOperandNumber);

	if (getBothPositive())
	{
		//std::cout <<"Both positive multiplication"<<std::endl;
		result = vectorDivision(leftOperandNumber, rightOperandNumber);

	} else if (getNegativeAndPositive() || getPositiveAndNegative())
	{
		if (leftOperandNumber[0] == -1)
		{
			leftOperandNumber.erase(leftOperandNumber.begin());
		}
		if (rightOperandNumber[0] == -1)
		{
			rightOperandNumber.erase(rightOperandNumber.begin());
		}
		result = vectorDivision(leftOperandNumber, rightOperandNumber);

		//add negative sign to result
		result.insert(result.begin(), -1);

	} else if (getBothNegative())
	{
		//remove negative signs
		leftOperandNumber.erase(leftOperandNumber.begin());
		rightOperandNumber.erase(rightOperandNumber.begin());

		result = vectorDivision(leftOperandNumber, rightOperandNumber);

	} else
	{
		std::cout << "none of the above";
	}
	//remove negative from result if = 0
	if (result[0] == -1 && result[1] == 0)
	{
		result.erase(result.begin());
	}

	return result;
}//end divisionController()

/**
 * vectorDivision
 * Performs an inefficient vector integer division.
 * Subtracts the numerator by the denominator and
 * adds 1 to a quotient while denominator < numerator.
 * @param number1
 * @param number2
 * @return std::vector<int> quotientVector
 */
std::vector<int> HugeInt::vectorDivision(std::vector<int> number1,
		std::vector<int> number2)
{
	//printTwoVectors(number1, number2);
	//A vector of int vectors for each of the multiplications per digit
	std::vector<int> subResult;
	HugeInt result;
	std::vector<int> quotientAdd { 1 };
	std::string quotientString;
	std::vector<int> temp;
	std::vector<int> quotientVector;
	numberZeroBalancer(number1, number2);

	if (getGreatestVector(number1, number2) != number1)
	{
		//std::cout<<"division is zero"<<std::endl;
		quotientVector.push_back(0);

	} else
	{

		subResult = vectorSubtraction(number1, number2);
		numberZeroBalancer(quotientVector, quotientAdd);
		quotientVector = vectorSum(quotientVector, quotientAdd);

		//printTwoVectors(subResult, number2);
		while (number2 < subResult)
		{
			numberZeroBalancer(subResult, number2);
			numberZeroBalancer(quotientVector, quotientAdd);
			//printTwoVectors(quotientVector, quotientAdd);
			subResult = vectorSubtraction(subResult, number2);
			quotientVector = vectorSum(quotientVector, quotientAdd);
			quotientVector = convertToVector(convertToString(quotientVector));
		}
	}
	std::vector<int>().swap(subResult);
	return quotientVector;

}//end vectorDivision()

/**
 * multiplicationController
 * controller for multiplication. Prepares the numbers for division
 * for 4 possible cases: bothPositive, negativeAndPositive,
 * PositiveAndNegative, and bothNegative.
 * @param hugeInt
 * @return std::vector<int> result
 */
std::vector<int> HugeInt::multiplicationController(HugeInt hugeInt)
{

	std::vector<int> result;
	std::vector<int> number1;
	std::vector<int> number2;
	bool isIntegerRightOperand;
	getOperandsSignValues();
	setIntegerAndHugeIntVectors(number1, number2, hugeInt,
			isIntegerRightOperand);

	numberZeroBalancer(number1, number2);
	//printTwoVectors(number1, number2);

	if (getBothPositive())
	{
		//std::cout <<"Both positive multiplication"<<std::endl;
		result = vectorMultiplication(number1, number2);

	} else if (getNegativeAndPositive() || getPositiveAndNegative())
	{
		if (number1[0] == -1)
		{
			number1.erase(number1.begin());
		}
		if (number2[0] == -1)
		{
			number2.erase(number2.begin());
		}
		result = vectorMultiplication(number1, number2);

		//add negative sign to result
		result.insert(result.begin(), -1);

	} else if (getBothNegative())
	{
		//remove negative signs
		number1.erase(number1.begin());
		number2.erase(number2.begin());

		result = vectorMultiplication(number1, number2);

	} else
	{
		std::cout << "none of the above";
	}

	return result;
}//end multiplicationController()

/**
 * vectorMultiplication
 * creates a 2 dimensional vector array that is
 * process by addVectors() to add the result of the multiplications.
 * @param number1
 * @param number2
 * @return std::vector<int> addedVectors
 */
std::vector<int> HugeInt::vectorMultiplication(std::vector<int> number1,
		std::vector<int> number2)
{
	//printTwoVectors(number1, number2);
	//A vector of int vectors for each of the multiplications per digit
	std::vector<std::vector<int>> results;
	int unitResult = 0;
	int carry;
	std::vector<int> temp;
	//numberZeroBalancer(number1, number2);

	for (int i = number1.size() - 1; i >= 0; i--)
	{
		for (int j = number2.size() - 1; j >= 0; j--)
		{
			unitResult = (number1[i] * number2[j]) + getCarry();
			carry = calculateCarry(unitResult);
			setCarry(carry);
			//add result to current vector
			temp.insert(temp.begin(), unitResult);
		}
		results.push_back(temp);
		temp.clear();

		//zero indents to be added to the next vector
		//that adds results
		for (int z = 0; z < results.size(); z++)
		{
			temp.push_back(0);
		}

	}
	return addVectors(results);
}

std::vector<int> HugeInt::addVectors(std::vector<std::vector<int>> results)
{
	int unitResult;
	std::vector<int> temp;
	std::vector<int> result;
	std::vector<int> row;

	//add results vector by vector
	for (int i = 0; i < results.size(); i++)
	{
		row = results[i];
		//std::cout << "sum: " << i <<std::endl;
		numberZeroBalancer(row, temp);
		//printTwoVectors(row,temp);

		for (int j = row.size() - 1; j >= 0; j--)
		{
			//std::cout << row[j] << " " << temp[j] <<std::endl;
			unitResult = row[j] + temp[j];
			temp[j] = unitResult;
		}
	}
	//remove leading 0's
	if (temp[0] == 0)
	{
		result = temp;
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == 0)
			{
				result.erase(result.begin());
			} else
			{
				break;
			}
		}
		temp = result;
	}

	return temp;
}//end addVectors()

/**
 * subtractionController
 * controller for subtraction. Prepares the numbers for division
 * for 4 possible cases: bothPositive, negativeAndPositive,
 * PositiveAndNegative, and bothNegative.
 * @param hugeInt
 * @return std::vector<int> result
 */
std::vector<int> HugeInt::subtractionController(HugeInt hugeInt)
{

	std::vector<int> greatestVector;
	std::vector<int> result;
	std::vector<int> rightOperandNumber;
	std::vector<int> leftOperandNumber;
	std::vector<int> number1;
	std::vector<int> number2;
	bool isIntegerRightOperand;

	getOperandsSignValues();

	setIntegerAndHugeIntVectors(number1, number2, hugeInt,
			isIntegerRightOperand);

	setRightAndLeftOperandVectors(isIntegerRightOperand, rightOperandNumber,
			leftOperandNumber, number1, number2);

	numberZeroBalancer(leftOperandNumber, rightOperandNumber);

	//printTwoVectors(leftOperandNumber, rightOperandNumber);

	//std::cout << std::endl;
	if (bothPositive)
	{

		bothPositiveSubtractionLogic(leftOperandNumber, rightOperandNumber,
				result);

	}
	//under both different signs numbers -- this is equivalent to an addition
	//with sign changes when appropriate to match subtraction rules
	else if (negativeAndPositive || positiveAndNegative)
	{
		//std::cout << "inside negative or positive "<<std::endl;

		//right operand is negative
		//removes negative sign if found
		// - (-9) = +9  || - (+9) = -9
		if (rightOperandNumber[0] != -1)
		{
			//std::cout<<"LeftNegativeRightPositive"<<std::endl;
			rightOperandNumber.insert(rightOperandNumber.begin(), -1);
			numberZeroBalancer(leftOperandNumber, rightOperandNumber);
			//printTwoVectors(leftOperandNumber, rightOperandNumber);

			//both will be negative at this point
			sumBothNegative(leftOperandNumber, rightOperandNumber, result);
		} else
		{
			//std::cout<<"LeftPositiveRightNegative"<<std::endl;
			rightOperandNumber.erase(rightOperandNumber.begin());
			rightOperandNumber.insert(rightOperandNumber.begin(), 0);
			//right operand was negative but now is not
			//left operand is positive
			//adding two positive numbers
			result = vectorSum(leftOperandNumber, rightOperandNumber);
		}

		//printTwoVectors(rightOperandNumber, leftOperandNumber);

	} else if (bothNegative)
	{

		//std::cout <<"both negative"<<std::endl;

		//change the right operand sign to positive
		//by rule of subtraction
		rightOperandNumber.erase(rightOperandNumber.begin());
		rightOperandNumber.insert(rightOperandNumber.begin(), 0);

		//At this point the left operand is positive
		//and the right operand is positive
		sumNegativeAndPositiveOrPositiveAndNegativeLogic(leftOperandNumber,
				rightOperandNumber, result);
	}

	return result;
}//end subtractionController()

std::vector<int> HugeInt::vectorSubtraction(std::vector<int> number1,
		std::vector<int> number2)
{
	int presub;
	std::vector<int> subtractionResult;
	std::vector<int> temp;
	//check if rebalancing is needed
	if (number1[0] == 0 && number2[0] == 0)
	{
		temp = number1;
		for (int i = 0; i < number1.size(); i++)
		{
			if (number1[i] == 0)
			{
				temp.erase(temp.begin());
			} else
			{
				break;
			}
		}
		number1 = temp;
		temp = number2;
		for (int i = 0; i < number2.size(); i++)
		{
			if (number2[i] == 0)
			{
				temp.erase(temp.begin());
			} else
			{
				break;
			}
		}
		number2 = temp;
		numberZeroBalancer(number1, number2);
		std::vector<int>().swap(temp);
	}

	for (int i = number1.size() - 1; i >= 0; i--)
	{
		for (int j = number2.size() - 1; j >= 0; j--)
		{
			presub = number1[i] - number2[j];
			if (presub < 0)
			{
				presub += 10;
				number1[i - 1]--;
			}
			if ((number2.size() != 0) && (j != 0 || presub != 0))
			{
				subtractionResult.insert(subtractionResult.begin(), presub);
			}
			i--;
		}
	}
	std::vector<int>().swap(number1);
	return subtractionResult;
}//end vectorSubtraction()

void HugeInt::bothPositiveSubtractionLogic(std::vector<int> &leftOperandNumber,
		std::vector<int> &rightOperandNumber, std::vector<int> &result)
{

	//std::cout<<"inside bothPositiveSubtractionLogic"<<std::endl;
	std::vector<int> greatestVector;
	HugeInt helper;
	greatestVector = getGreatestVector(leftOperandNumber, rightOperandNumber);

	//left operand is greater than right operand:
	//under both positive numbers -- subtract left as upper and right as lower
	if (greatestVector == leftOperandNumber)
	{
		result = vectorSubtraction(leftOperandNumber, rightOperandNumber);

	}
	//right operand is greater than left operand
	//under both positive numbers -- this is equivalent to an addition
	//of an unknown signed left operand and negatively signed rightOperand
	//if the left operand is positive the result will be negative
	//if the left operand is negative the result will be negative
	//adding negative and positive result solves this case
	else if (greatestVector == rightOperandNumber)
	{
		std::vector<int> lowestVector;

		//change sign of right Operand
		//this case prevents right Operand from being negative
		if (rightOperandNumber[0] != -1)
		{
			rightOperandNumber.insert(rightOperandNumber.begin(), -1);
		}
		//rebalance left and right operand
		numberZeroBalancer(leftOperandNumber, rightOperandNumber);

		sumNegativeAndPositiveOrPositiveAndNegativeLogic(rightOperandNumber,
				leftOperandNumber, result);

		//printTwoVectors(greatestVector,lowestVector);

	}
	//if left operand and right operand equal not implemented
}//end bothPositiveSubtractionLogic()

/**
 * sumController
 * controller for sum. Prepares the numbers for division
 * for 4 possible cases: bothPositive, negativeAndPositive,
 * PositiveAndNegative, and bothNegative.
 * @param hugeInt
 * @return std::vector<int> result
 */
std::vector<int> HugeInt::sumController(HugeInt hugeInt)
{
	std::vector<int> result;
	std::vector<int> number1;
	std::vector<int> number2;
	bool isIntegerRightOperand;
	getOperandsSignValues();
	setIntegerAndHugeIntVectors(number1, number2, hugeInt,
			isIntegerRightOperand);

	numberZeroBalancer(number1, number2);
	//printTwoVectors(number1, number2);

	if (getBothPositive())
	{
		//std::cout <<"both positive"<<std::endl;
		result = vectorSum(number1, number2);

	} else if (getNegativeAndPositive() || getPositiveAndNegative())
	{

		sumNegativeAndPositiveOrPositiveAndNegativeLogic(number1, number2,
				result);

	} else if (getBothNegative())
	{
		sumBothNegative(number1, number2, result);

	} else
	{
		std::cout << "none of the above";
	}

	return result;
}//end sumController()

std::vector<int> HugeInt::vectorSum(std::vector<int> number1,
		std::vector<int> number2)
{
	int presum;
	int carry;
	std::string rightMostNumber;
	const int LAST = 0;
	int calculation_position;
	std::vector<int> sumResult;
	for (int i = number1.size() - 1; i >= 0; i--)
	{
		for (int j = number2.size() - 1; j >= 0; j--)
		{
			presum = number1[i] + number2[j] + getCarry();
			//std::cout << number1[i] <<" "<< number2[j] << " "<<getCarry() <<std::endl;
			//std::cout << presum <<std::endl;
			carry = calculateCarry(presum);
			calculation_position = i;
			if (calculation_position != LAST)
			{
				if (carry != 0)
				{
					rightMostNumber = std::to_string(presum)[1];
					presum = std::stoi(rightMostNumber);
				}
			}
			//std::cout << carry <<std::endl;
			setCarry(carry);
			if ((number2.size() != 0) && (j != 0 || presum != 0))
			{
				sumResult.insert(sumResult.begin(), presum);
			}
			i--;
		}
	}
	setCarry(0);
	return sumResult;
}//end vectorSum()

void HugeInt::sumBothNegative(std::vector<int> number1,
		std::vector<int> number2, std::vector<int> &result)
{
	//std::cout <<"both negative"<<std::endl;
	if (number1[0] == -1 || number1[0] == 0)
		number1.erase(number1.begin());
	if (number2[0] == -1 || number2[0] == 0)
		number2.erase(number2.begin());
	result = vectorSum(number1, number2);
	result.insert(result.begin(), -1);
}//end sumBothNegative()

void HugeInt::sumNegativeAndPositiveOrPositiveAndNegativeLogic(
		std::vector<int> number1, std::vector<int> number2,
		std::vector<int> &result)
{
	//std::cout <<"one negative"<<std::endl;
	bool setNegative = false;
	std::vector<int> greatestVector;
	std::vector<int> lowestVector;
	HugeInt helper;

	greatestVector = helper.getGreatestVector(number1, number2);

	//set lowest and greatest vector
	if (greatestVector != number1)
	{
		lowestVector = number1;
	} else
	{
		lowestVector = number2;
	}

	if (greatestVector[0] == -1)
	{
		setNegative = true;
		greatestVector.erase(greatestVector.begin());
		greatestVector.insert(greatestVector.begin(), 0);
	}

	if (lowestVector[0] == -1)
	{
		lowestVector.erase(lowestVector.begin());
		lowestVector.insert(lowestVector.begin(), 0);
	}

	helper.setIntegers(vectorSubtraction(greatestVector, lowestVector));
	result = helper.getIntegers();
	if (setNegative)
	{
		result.insert(result.begin(), -1);
	}
}//end sumNegativeAndPositiveOrPositiveAndNegativeLogic()

void HugeInt::printTwoVectors(std::vector<int> &number1,
		std::vector<int> &number2)
{
	std::cout << std::endl;
	std::cout << "number1: ";
	std::cout << number1.size();
	std::cout << std::endl;
	for (int i = 0; i < number1.size(); i++)
	{
		std::cout << number1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "number2: ";
	std::cout << number2.size();
	std::cout << std::endl;
	for (int i = 0; i < number2.size(); i++)
	{
		std::cout << number2[i] << " ";
	}
	std::cout << std::endl;
}//end printTwoVectors()


void HugeInt::setIntegerAndHugeIntVectors(std::vector<int> &number1,
		std::vector<int> &number2, HugeInt hugeInt, bool &isIntegerRightOperand)
{
	Operand helper;
	int integerOperand;
	std::string hugeIntNumber;

	if (helper.isHugeIntString(hugeInt.getRightOperand()))
	{
		//std::cout << "In if."<<std::endl;
		integerOperand = hugeInt.getLeftOperand().getInteger();
		isIntegerRightOperand = false;
		hugeIntNumber = hugeInt.getRightOperand().getHugeIntString();
		//std::cout << hugeIntNumber << " | " << integerOperand;
	} else
	{
		integerOperand = hugeInt.getRightOperand().getInteger();
		isIntegerRightOperand = true;
		hugeIntNumber = hugeInt.getLeftOperand().getHugeIntString();
		//std::cout << "In else."<<std::endl;
		//std::cout << hugeIntNumber << " | " << integerOperand;
	}

	std::string stringNumberInt = std::to_string(integerOperand);
	std::string stringNumberHuge = hugeIntNumber;
	//std::cout << hugeIntNumber << "---" << integerOperand;
	number2 = convertToVector(stringNumberInt);
	number1 = convertToVector(stringNumberHuge);

}//end setIntegerAndHugeIntVectors()

//set position of operand as vectors
void HugeInt::setRightAndLeftOperandVectors(bool isIntegerRightOperand,
		std::vector<int> &rightOperandNumber,
		std::vector<int> &leftOperandNumber, std::vector<int> number1,
		std::vector<int> number2)
{
	if (isIntegerRightOperand)
	{
		//std::cout<<"integer is right operand" <<std::endl;
		rightOperandNumber = number2;
		leftOperandNumber = number1;

	} else
	{
		//std::cout<<"integer is left operand" <<std::endl;
		rightOperandNumber = number1;
		leftOperandNumber = number2;
	}
	//printTwoVectors(leftOperandNumber, rightOperandNumber);
}//end setRightAndLeftOperandsVectors()

void HugeInt::getOperandsSignValues()
{
	bothPositive = ((rightOperand.getSign() == true)
			&& (leftOperand.getSign() == true));
	negativeAndPositive = ((rightOperand.getSign() == false)
			&& (leftOperand.getSign() == true));
	positiveAndNegative = ((rightOperand.getSign() == true)
			&& (leftOperand.getSign() == false));
	bothNegative = ((rightOperand.getSign() == false)
			&& (leftOperand.getSign() == false));

	setBothPositive(bothPositive);
	setNegativeAndPositive(negativeAndPositive);
	setPositiveAndNegative(positiveAndNegative);
	setBothNegative(bothNegative);
}//end getOperandsSignValues()


void HugeInt::numberZeroBalancer(std::vector<int> &number1,
		std::vector<int> &number2)
{

	//insert zeroes to number2 vector
	if (number1.size() > number2.size())
	{
		//std::cout<<"number1 size greater."<<std::endl;
		int diffNumber1 = number1.size() - number2.size();

		for (int i = 0; i < diffNumber1; i++)
		{
			if (number2.size() == 0)
			{
				number2.push_back(0);
			}
			if (number2[0] == -1)
			{
				number2.insert(number2.begin() + 1, 0);
			} else
			{
				number2.insert(number2.begin(), 0);
			}
		}
	}
	//insert zeroes to number1 vector
	if (number1.size() < number2.size())
	{
		//std::cout<<"number2 size greater."<<std::endl;
		int diffNumber2 = number2.size() - number1.size();
		for (int i = 0; i < diffNumber2; i++)
		{
			if (number1.size() == 0)
			{
				number1.push_back(0);
			}
			if (number1[0] == -1)
			{
				number1.insert(number1.begin() + 1, 0);
			} else
			{
				number1.insert(number1.begin(), 0);
			}
		}
	}
	//printTwoVectors(number1, number2);
}//end numberZeroBalancer()

std::vector<int> HugeInt::getGreatestVector(std::vector<int> numbers1,
		std::vector<int> numbers2)
{
	std::vector<int> firstRowNumbers;
	std::vector<int> secondRowNumbers;

	firstRowNumbers = numbers1;
	secondRowNumbers = numbers2;

	for (int i = 0; i < firstRowNumbers.size(); i++)
	{
		for (int j = 0; j < secondRowNumbers.size(); j++)
		{
			if (firstRowNumbers[i] == -1 || secondRowNumbers[j] == -1)
			{
				if (firstRowNumbers[i] > 0)
					return firstRowNumbers;
				if (secondRowNumbers[i] > 0)
					return secondRowNumbers;

				//std::cout<<"ignoring"<<std::endl;
				i = i + 1;
				//std::cout<<"increasing i " << i<<std::endl;
				//ignore negative sign
				continue;
			} else if (firstRowNumbers[i] > secondRowNumbers[j])
			{
				//std::cout<<"first num greater"<<std::endl;
				return firstRowNumbers;

			} else if (firstRowNumbers[i] < secondRowNumbers[j])
			{
				//std::cout<<"second num greater"<<std::endl;
				return secondRowNumbers;

			}

			i = i + 1;
			//std::cout<<"increasing i " << i<<std::endl;
		}

	}
	return firstRowNumbers;
}//end getGreatestVector()

//member addition function
HugeInt HugeInt::operator+(int intRightOperand)
{
	if (getLeftOperand().getInteger() == 0)
	{
		//std::cout<<"IntRightOperand"<<std::endl;
		Operand operand1;
		operand1.setInteger(intRightOperand);
		operand1.checkOperandSign();
		Operand operand2;
		operand2.setHugeIntString(this->getNumber());
		operand2.checkOperandSign();
		setLeftOperand(operand2);
		setRightOperand(operand1);
	}
	//std::cout <<"IntLeftOperand:"<<std::endl;

	HugeInt result;
	HugeInt *hugeInt = this;
	std::vector<int> vectorResult = sumController(*hugeInt);
	result.setIntegers(vectorResult);
	//std::cout << std::endl;
	return result;

}//end operator+()

//member subtraction function
HugeInt HugeInt::operator-(int intRightOperand)
{
	if (getLeftOperand().getInteger() == 0)
	{
		//std::cout<<"IntRightOperand"<<std::endl;
		Operand operand1;
		operand1.setInteger(intRightOperand);
		operand1.checkOperandSign();
		Operand operand2;
		operand2.setHugeIntString(this->getNumber());
		operand2.checkOperandSign();
		setLeftOperand(operand2);
		setRightOperand(operand1);
	}
	HugeInt result;
	HugeInt *hugeInt = this;
	std::vector<int> vectorResult = subtractionController(*hugeInt);
	result.setIntegers(vectorResult);
	//std::cout << std::endl;
	return result;

}//end operator-()

//member multiplication function
HugeInt HugeInt::operator*(int intRightOperand)
{
	if (getLeftOperand().getInteger() == 0)
	{
		//	std::cout<<"IntRightOperand"<<std::endl;
		Operand operand1;
		operand1.setInteger(intRightOperand);
		operand1.checkOperandSign();
		Operand operand2;
		operand2.setHugeIntString(this->getNumber());
		operand2.checkOperandSign();
		setLeftOperand(operand2);
		setRightOperand(operand1);
	}
	//std::cout <<"IntLeftOperand:"<<std::endl;

	HugeInt result;
	HugeInt *hugeInt = this;
	std::vector<int> vectorResult = multiplicationController(*hugeInt);
	result.setIntegers(vectorResult);
	//std::cout << std::endl;
	return result;

}//end operator*()

//member division function
HugeInt HugeInt::operator/(int intRightOperand)
{
	if (getLeftOperand().getInteger() == 0)
	{
		//std::cout<<"IntRightOperand"<<std::endl;
		Operand operand1;
		operand1.setInteger(intRightOperand);
		operand1.checkOperandSign();
		Operand operand2;
		operand2.setHugeIntString(this->getNumber());
		operand2.checkOperandSign();
		setLeftOperand(operand2);
		setRightOperand(operand1);
	}
	//std::cout <<"IntLeftOperand:"<<std::endl;

	HugeInt result;
	HugeInt *hugeInt = this;
	std::vector<int> vectorResult = divisionController(*hugeInt);
	result.setIntegers(vectorResult);
	//std::cout << std::endl;
	return result;

}//end operator/()

//non-member function:swaps its arguments and calls member function
HugeInt operator+(int intLeftOperand, HugeInt HugeIntRightOperand)
{
	Operand operand1;
	operand1.setInteger(intLeftOperand);
	operand1.checkOperandSign();
	Operand operand2;
	operand2.setHugeIntString(HugeIntRightOperand.getNumber());
	operand2.checkOperandSign();
	HugeIntRightOperand.setLeftOperand(operand1);
	HugeIntRightOperand.setRightOperand(operand2);

	return HugeIntRightOperand.operator+(intLeftOperand);

}//end operator+()

HugeInt operator-(int intLeftOperand, HugeInt HugeIntRightOperand)
{
	Operand operand1;
	operand1.setInteger(intLeftOperand);
	operand1.checkOperandSign();

	Operand operand2;
	operand2.setHugeIntString(HugeIntRightOperand.getNumber());
	operand2.checkOperandSign();

	HugeIntRightOperand.setLeftOperand(operand1);
	HugeIntRightOperand.setRightOperand(operand2);

	return HugeIntRightOperand.operator-(intLeftOperand);

}//end operator-()

HugeInt operator*(int intLeftOperand, HugeInt HugeIntRightOperand)
{
	Operand operand1;
	operand1.setInteger(intLeftOperand);
	operand1.checkOperandSign();
	Operand operand2;
	operand2.setHugeIntString(HugeIntRightOperand.getNumber());
	operand2.checkOperandSign();
	HugeIntRightOperand.setLeftOperand(operand1);
	HugeIntRightOperand.setRightOperand(operand2);

	return HugeIntRightOperand.operator*(intLeftOperand);

}//end operator*()

HugeInt operator/(int intLeftOperand, HugeInt HugeIntRightOperand)
{
	Operand operand1;
	operand1.setInteger(intLeftOperand);
	operand1.checkOperandSign();
	Operand operand2;
	operand2.setHugeIntString(HugeIntRightOperand.getNumber());
	operand2.checkOperandSign();
	HugeIntRightOperand.setLeftOperand(operand1);
	HugeIntRightOperand.setRightOperand(operand2);

	return HugeIntRightOperand.operator/(intLeftOperand);

}//end operator/()

