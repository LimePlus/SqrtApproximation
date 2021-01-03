#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
using namespace std;

#pragma region Variables
int GetNum(int, int);
double GetHalfNum(double);
bool IsEven(double);
int ReverseNum(int);
double LogProx2(double);
double LogProx10(double);
double SqrtProx(double);
int NumDigits(double);
#pragma endregion

#pragma region Main

int main()
{
	double num;
	cin >> num;
	if (num >= 1)
	{
		cout << std::setprecision(15) << SqrtProx(num) << "\n";
	}
	else
	{
		cout << "cannot find sqrt of any number below 1!";
	}

	return 0;
}

#pragma endregion

#pragma region Sqrt
double SqrtProx(double n)
{
	double truen = n;
	double nw = n;
	if (NumDigits(n) == 5)
	{
		nw = n / pow(10, 2);
		n = nw;
	}
	if (NumDigits(truen) > 5)
	{
		nw = n / 10000;
		n = nw;
	}
	double ipx = (LogProx2(n) + n / GetHalfNum(n)) / 1.5;
	double fpx = (ipx + n / ipx) / 2;
	double npx = (fpx + n / fpx) / 2;
	double spx = (npx + n / npx) / 2;
	if (NumDigits(truen) < 5)
	{
		return spx;
	}
	if (NumDigits(truen) == 5)
	{
		return spx * 10;
	}
	if (NumDigits(truen) > 5)
	{
		return spx * 100;
	}




}
#pragma endregion

#pragma region digit

int NumDigits(double n)
{
	return floor(LogProx10(n) + 1);
}

double GetHalfNum(double n)
{
	int halfdig = 0;
	int numdig = floor(LogProx10(n) + 1);
	std::string st = "";
	halfdig = floor((numdig / 2))+1;
	for (int i = 0; i <= halfdig+1; i++)
	{
		int a=(GetNum(n, NumDigits(n) - i + 2));
		st += to_string(a);
	}
	int in = atoi(st.c_str());

	return in;
}

int ReverseNum(int n)
{
	bool negative = false;
	if (n < 0)
	{
		negative = true;
		n = -n;
	}

	int reversed = 0;
	while (n > 0)
	{
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}

	if (negative) reversed = -reversed;
	return reversed;
}

int GetNum(int n, int position)
{
	return (n % (int)pow(10, position) - (n % (int)pow(10, position - 1))) / (int)pow(10, position - 1);
}
#pragma endregion

#pragma region Logarithms
double LogProx2(double n)
{
	double l = 0;
	for (int i = 0; n >= 2; i++)
	{
		n /= 2;
		l++;
	}
	n = pow(n, 10);
	for (int i = 0; n >= 2; i++)
	{
		n /= 2;
		l += 0.1;
	}
	
	return l;
}
double LogProx10(double n)
{
	double l = 0;
	for (int i = 0; n >= 10; i++)
	{
		n /= 10;
		l++;
	}
	n = pow(n, 10);
	for (int i = 0; n >= 10; i++)
	{
		n /= 10;
		l += 0.1;
	}
	
	return l;
}
#pragma endregion

