#pragma once
#include "string"


enum class OperationType
{
	ADD,
	SUB,
	DIV,
	MUL,
};


struct OperationsFunction
{
	std::string firstVal;
	OperationType operation;
	std::string secondVal;
	bool wasTwoOperands;
};
