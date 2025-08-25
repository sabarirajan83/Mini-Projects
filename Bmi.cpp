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
	{
		cout << "UnderWeight" << endl;
		cout<<"You should have to take more proteins and carbohydrates"<<endl;
	}

	else if (bmi < 24.9)
	{
		cout << "Normal Weight" << endl;
		cout<<"Wow,well done keep it up"<<endl;
	}

	else if (bmi < 29.9)
	{
		cout << "OverWeight" << endl;
		cout<<"It seems like that you are need to do exercises daily"<<endl;
	}

	else if (bmi < 34.9)
	{
		cout << "Obesity (Class I)" << endl;
		cout<<"It should have to do exercises daily"<<endl;
	}

	else if (bmi < 39.9)
	{
		cout << "Obesity (Class II)" << endl;
		cout<<"You should have to do exercises daily"<<endl;
	}

	else if (bmi >= 40)
	{
		cout << "Obesity (Class III)" << endl;
		cout<<"Reduce the intake of fats and burn the calories as soon as possible";
	}

	return 0;
}
