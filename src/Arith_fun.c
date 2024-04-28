#include"header\Arith_fun.h"

int ArithFunc(int num1, unsigned char op, int num2) 
{
	int result;
	switch (op)
	{
		case '+' : // addition 
		{
			result = num1 + num2;
			break;
		}
		
		case '-' : // subtraction
		{
			result = num1 - num2;
			break;
		}
		
		case '*' : // mul 
		{
			result = num1 * num2;
			break;
		}
		
		case '/' : // div 
		{
			result = num1 / num2;
			break;
		}
	}
	return result;
}