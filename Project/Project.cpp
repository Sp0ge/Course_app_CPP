#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	char task;
	int sum, num1, num2;

	cin >> num1;
	cin >> task;
	cin >> num2;
	switch(task){
		case("+"):
			sum = num1 + num2;
		case("-"):
			sum = num1 - num2;
		case("*"):
			sum = num1 * num2;
	}
	

	std::cout << sum;
}