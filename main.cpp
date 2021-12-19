
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "BigInteger.h"
#include <stdlib.h>

using namespace std;
using namespace BigIntegerLibrary;


int main(int ac, char **av)
{
	setlocale( LC_ALL,"Russian" );
	if (ac != 1)
	{
	BigInteger a;
	a = BigInteger(av[1]);
	BigInteger b;
	b = BigInteger(av[3]);
	BigInteger c('0');
	if (av[2][0] == '+')
		c = a + b;
	else if (av[2][0] == '-')
		c = a - b;
	else if (av[2][0] == '*')
		c = a * b;
	else if (av[2][0] == '/')
		c = a / b;
	else if (av[2][0] == '%')
		c = a % b;
	else if (av[2][0] == '>')
		c = a > b;
	else if (av[2][0] == '<')
		c = a < b;
	else if (av[2][0] == '=')
		c = a == b;
	cout << "Результат:: " << c << '\n';
	}
	else
	{
		cout << "<<<___________ Довга арифметика __________>>>\n" << endl;
		cout << "Доступні операції:\n1) '+' - додавання;\n2) '-' - віднімання;\n3) '*' - множення;'\n4) '/' - ділення без остачі;\n5) '%' - остача від ділення\n6) '<', '=', '>' -  порівняння чисел\n7) 's' -  найбільший цілий корінь\n8) '^' - піднесення до степеня.\n";
		string line = "";
		while (line != "Stop" && line != "0")
		{
			cout << "Введіть числа та операцію між ними\n";
			cout << "Щоб зупити виконання програми введіть 0 або Stop\n";
			getline(cin, line);
			char operation;
			BigInteger a, b, c;
			a = BigInteger(atoi(line.c_str()));
			while (1)
			{
			int	i = 0;
			while (line[i] != '+' && line[i] != '-' && line[i] != '*' && line[i] != '/' 
				&& line[i] != '^' && line[i] != '>' && line[i] != '<' &&
				line[i] != '=' && line[i] != '%' && line[i] != 's' && i < line.length())
				i++;
				if (i == line.length())
					break;
				
				operation = line[i];
				if (i == 184)
					break;
				i++;
				b = BigInteger(atoi(line.c_str() + i));
				if (operation == '+')
					c = a + b;
				else if (operation == '-')
					c = a - b;
				else if (operation == '*')
					c = a * b;
				else if (operation == '/')
					c = a / b;
				else if (operation == '%')
					c = a % b;
				else if (operation == '>')
					c = a > b;
				else if (operation == '<')
					c = a < b;
				else if (operation == '=')
					c = a == b;
				else if (operation == '^')
					c = pow(a,b);
				else if (operation == 's')
				{
					if (c != 0)
						c = sqrt(c);
					else
						c = sqrt(b);
				}	 
				else
				{
					cout << "dDd";
					c = 0;
					break;
				}
				cout << "Результат: " << c;
				a = c;
				operation = '0';
				b = 0;
				getline(cin, line);
			}
		}

		
	}
	return 0;
}
