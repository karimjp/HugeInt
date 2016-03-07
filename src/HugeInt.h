/**
 * @file HugeInt.h
 * @author  Karim Jana <karimjana@gmail.com>
 * @date	July, 2015.
 * @version 1.0
 * @details Proffesor Doug Ferguson - C++ class
 *
 * @brief This is my HugeInt definition file.
 *
 */

#ifndef HUGEINT_H_
#define HUGEINT_H_

#include<iostream>
#include<vector>
#include "Operand.h"

class HugeInt
{
public:
	HugeInt();
	void input();
	std::string getNumber();
	void setNumber(std::string number);
	std::vector<int> getIntegers();
	void setIntegers(std::vector<int> integerChunks);
	std::string convertToString(std::vector<int> integerChunks);
	std::vector<int> convertToVector(std::string number);
	std::vector<int> vectorSum(std::vector<int> number1,
			std::vector<int> number2);
	std::vector<int> vectorSubtraction(std::vector<int> number1,
			std::vector<int> number2);
	std::vector<int> vectorMultiplication(std::vector<int> number1,
			std::vector<int> number2);
	std::vector<int> vectorDivision(std::vector<int> number1,
			std::vector<int> number2);
	int getCarry();
	void setCarry(int carry);
	int calculateCarry(int presum);
	void numberZeroBalancer(std::vector<int> &number1,
			std::vector<int> &number2);
	std::vector<int> subtractionController(HugeInt hugeInt);
	std::vector<int> sumController(HugeInt hugeInt);
	std::vector<int> multiplicationController(HugeInt hugeInt);
	std::vector<int> divisionController(HugeInt hugeInt);
	HugeInt operator+(int intRightOperand);
	HugeInt operator-(int intRightOperand);
	HugeInt operator*(int intRightOperand);
	HugeInt operator/(int intRightOperand);
	std::vector<int> getGreatestVector(std::vector<int> numbers1,
			std::vector<int> numbers2);
	void setRightOperandSign(bool rightOperandSign);
	void setLeftOperandSign(bool leftOperandSign);
	bool getRightOperandSign();
	bool getLeftOperandSign();
	Operand getLeftOperand();
	void setLeftOperand(const Operand &leftOperand);
	Operand getRightOperand();
	void setRightOperand(const Operand &rightOperand);
	void getOperandsSignValues();
	void setBothPositive(bool value);
	bool getBothPositive();
	void setNegativeAndPositive(bool value);
	bool getNegativeAndPositive();
	void setPositiveAndNegative(bool value);
	bool getPositiveAndNegative();
	void setBothNegative(bool value);
	bool getBothNegative();
	void setIntegerAndHugeIntVectors(std::vector<int> &number1,
			std::vector<int> &number2, HugeInt hugeInt,
			bool &isIntegerRightOperand);
	void printTwoVectors(std::vector<int> &number1, std::vector<int> &number2);
	void sumNegativeAndPositiveOrPositiveAndNegativeLogic(
			std::vector<int> number1, std::vector<int> number2,
			std::vector<int> &result);
	void sumBothNegative(std::vector<int> number1, std::vector<int> number2,
			std::vector<int> &result);
	void setRightAndLeftOperandVectors(bool isIntegerRightOperand,
			std::vector<int> &rightOperandNumber,
			std::vector<int> &leftOperandNumber, std::vector<int> number1,
			std::vector<int> number2);
	void bothPositiveSubtractionLogic(std::vector<int> &leftOperandNumber,
			std::vector<int> &rightOperandNumber, std::vector<int> &result);
	std::vector<int> addVectors(std::vector<std::vector<int>> results);
	void prettyPrint(int numberOperand, HugeInt hugeIntOperand,
			char operatorKeyword);
	void prettyPrint(HugeInt hugeIntOperand, int numberOperand,
			char operatorKeyword);

private:
	std::string number;
	std::vector<int> integers;
	int carry;
	Operand leftOperand;
	Operand rightOperand;
	bool bothPositive;
	bool negativeAndPositive;
	bool positiveAndNegative;
	bool bothNegative;

};//end class HugeInt

//non-member declaration prototype
HugeInt operator+(int HugeIntLeftOperand, HugeInt HugeIntRightOperand);
HugeInt operator-(int HugeIntLeftOperand, HugeInt HugeIntRightOperand);
HugeInt operator*(int intLeftOperand, HugeInt HugeIntRightOperand);
HugeInt operator/(int intLeftOperand, HugeInt HugeIntRightOperand);

#endif /* OPERAND_H_ */
