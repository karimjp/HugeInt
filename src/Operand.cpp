/**
 * @file Operand.cpp
 * @author  Karim Jana <karimjana@gmail.com>
 * @date	July, 2015.
 * @version 1.0
 * @details Proffesor Doug Ferguson - C++ class
 *
 * @brief An interface to query the properties of each operand like sign and position in relation to the operator.

 */

#include "Operand.h"
Operand::Operand()
{
	setLeftOperand(false);
	setRightOperand(false);
	setHugeIntString("");
	setInteger(0);
	setSign(true);

}//end Operand()

bool Operand::isHugeIntString(Operand operand)
{
	bool value = false;
	//std::cout<< "operand value: " << operand.getHugeIntString() << std::endl;
	if (operand.getHugeIntString() != "")
	{
		value = true;
	}
	return value;
}//end isHugeIntString()


void Operand::checkOperandSign()
{
	std::string number;
	char sign;
	if (getInteger() != 0)
	{
		number = std::to_string(getInteger());
		//std::cout << "int first char: "<<number[0]<<std::endl;
	} else
	{
		number = getHugeIntString();
	}
	//std::cout << number << std::endl;
	sign = number[0];
	if (sign == '-')
	{
		//std::cout << "setting negative"<<std::endl;
		setSign(false);
	} else
	{
		//std::cout << "setting positive"<<std::endl;
		setSign(true);
	}
} //end checkOperandSign()

const std::string& Operand::getHugeIntString() const
{
	return hugeIntString;
}//end getHugeIntString

void Operand::setHugeIntString(const std::string& hugeIntString)
{
	this->hugeIntString = hugeIntString;
}//end setHugeIntString

int Operand::getInteger() const
{
	return integer;
}//end getInteger

void Operand::setInteger(int integer)
{
	this->integer = integer;
}//end setInteger

bool Operand::isLeftOperand() const
{
	return leftOperand;
}//end isLeftOperand

void Operand::setLeftOperand(bool leftOperand)
{
	this->leftOperand = leftOperand;
}//end setLeftOperand

bool Operand::isRightOperand() const
{
	return rightOperand;
}//end isRightOperand

void Operand::setRightOperand(bool rightOperand)
{
	this->rightOperand = rightOperand;
}//end setRightOperand

bool Operand::isSign() const
{
	return sign;
}//end isSign

void Operand::setSign(bool sign)
{
	this->sign = sign;
}//end setSign

bool Operand::getSign() const
{
	return sign;
}//end getSign
