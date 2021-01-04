#include <iostream>
#include <iomanip>
#include <string>
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
	cout << "Please enter a number\n";//Ask the user to type a number
	double num;
	cin >> num;//Get the number typed from the user
	if (num >= 1)
	{
		cout << std::setprecision(15) << SqrtProx(num) << "\n";//Say the Square root approximation
		
	}
	else if(num<1)
	{
		cout << "cannot find sqrt of any number below 1!";//If the number is below one say an error
	}
	
	return 0;
}

#pragma endregion

#pragma region Sqrt
double SqrtProx(double n)
{
	int nd = NumDigits(n);
	//Lower the number
	if (nd == 5)n /= 100;
	if (nd > 5)n /= 10000;

	double lp =(n / GetHalfNum(n) + LogProx2(n))*0.5f;//Initial approximation
	double fi = (lp + n / lp) / 2;//First iteration
	double si = (fi + n / fi) / 2;//Second iteration
	double ti = (si + n / si) / 2;//Third iteration
	if(nd<5) return ti;
	//Higher the square root
	if (nd == 5)return ti * 10;
	if (nd > 5)return ti * 100;
}
#pragma endregion

#pragma region digit

//Returns the amount of integer digits in a number
int NumDigits(double n)
{
	return floor(LogProx10(n) + 1);
}

//Returns the floor of half the number of digits+1
//If the number is 685 it will return 68
double GetHalfNum(double n)
{
	int numdig = NumDigits(n);//Get the number of digits
	std::string st = "";//String for the answer
	int halfdig = floor((numdig / 2))+1;//Get half the number of digits

	//Loop through the first half of the digits + 1
	//And add the digit to a string
	for (int i = 0; i <= halfdig+1; i++)
	{
		int a=(GetNum(n, NumDigits(n) - i + 2));//Number at position i
		st += to_string(a);//Add the number to the string
	}

	int in = atoi(st.c_str());//Convert the digits back to integer form

	return in;
}
//Gets a number at a certain position
//Code from here https://stackoverflow.com/a/45648452
int GetNum(int n, int position)
{
	return (n % (int)pow(10, position) - (n % (int)pow(10, position - 1))) / (int)pow(10, position - 1);
}
#pragma endregion

#pragma region Logarithms
//An Approximation of Log base 2
double LogProx2(double n)
{
	double l = 0;
	//Divide n by 2 until it is under 2
	for (int i = 0; n >= 2; i++)
	{
		n /= 2;
		l++;
	}
	n = pow(n, 10);
	//Same process as last time just l+=0.1 
	for (int i = 0; n >= 2; i++)
	{
		n /= 2;
		l += 0.1;
	}

	
	return l;
}
double LogProx10(double n)
{
	//Divide n by 10 until it is under 10
	double l = 0;
	for (int i = 0; n >= 10; i++)
	{
		n /= 10;
		l++;
	}
	n = pow(n, 10);
	//Same process as last time just l+=0.1 
	for (int i = 0; n >= 10; i++)
	{
		n /= 10;
		l += 0.1;
	}
	
	return l;
}
#pragma endregion
