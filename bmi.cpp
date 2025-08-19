//BMI Calculator

#include<iostream>
#include<cmath>
using namespace std;

int main() {
	cout << "BMI Calculator" << endl;

	float ht, wt, bmi;

	cout << "Enter your height (in m): ";
	cin >> ht;
	cout << "Enter your weight (in Kg): ";
	cin >> wt;

	bmi = wt / pow(ht, 2);

	cout << "\nYour BMI: " << bmi << " (kg/m^2)\nStatus: ";

	if (bmi < 18.5)
		cout << "UnderWeight" << endl;
	else if (bmi < 24.9)
		cout << "Normal Weight" << endl;
	else if (bmi < 29.9)
		cout << "OverWeight" << endl;
	else if (bmi < 34.9)
		cout << "Obesity (Class I)" << endl;
	else if (bmi < 39.9)
		cout << "Obesity (Class II)" << endl;
	else if (bmi >= 40)
		cout << "Obesity (Class III)" << endl;

	return 0;
}