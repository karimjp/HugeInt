/**
 * @file Operand.h
 * @author  Karim Jana <karimjana@gmail.com>
 * @date	July, 2015.
 * @version 1.0
 * @details Proffesor Doug Ferguson - C++ class
 *
 * @brief This is my Operand definition file.
 *
 */

#ifndef OPERAND_H_
#define OPERAND_H_

#include<iostream>

class Operand
{
public:
	Operand();
	bool isHugeIntString(Operand operand);

	void checkOperandSign();
	const std::string& getHugeIntString() const;
	void setHugeIntString(const std::string& hugeIntString);
	int getInteger() const;
	void setInteger(int integer);
	bool isLeftOperand() const;
	void setLeftOperand(bool leftOperand);
	bool isRightOperand() const;
	void setRightOperand(bool rightOperand);
	bool isSign() const;
	void setSign(bool sign);
	bool getSign() const;

private:
	bool sign; //false is negative, true is positive
	bool rightOperand;
	bool leftOperand;
	int integer;
	std::string hugeIntString;

}; //end class Operand

#endif /* OPERAND_H_ */
