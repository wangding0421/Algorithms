#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int a = 0;
	int b = 12;
	stringstream ss;
	ss << b;
	cout << "The string result is: "<<  ss.str()  << endl;
} 