#include <iostream>
#include <cmath>    
#include <iomanip>
using namespace std;

// от дипсика рекуррентная формула a(n)=a(n-1)(-(2n-1)/2n)x

int main() {
	//setlocale(LC_ALL, "Russian");

	double x;

	cout << "Enter x(|x| <= 1):\n";
	cin >> x;

	if (abs(x) >= 1) {
		cout << "Mistake. -1 < x < 1\n";
		return 1;
	}

	int k;

	cout << "Enter k(k > 1)\n";
	cin >> k;

	if (k <= 1) {
		cout << "Mistake. k > 1";
		return 1;
	}

	double epsilon = pow(10.0, -k);

	double rowSum = 0.0;
	double termNum = 1.0;
	int n = 0;

	while (abs(termNum) >= epsilon) {
		rowSum += termNum;
		n++;

		termNum *= -1.0 * (2.0 * n - 1.0) / (2.0 * n) * x;
	}

	double calculatedValue = 1.0 / sqrt(1.0 + x);

	cout << fixed << setprecision(k);
	cout << rowSum << "\n";
	cout << calculatedValue << "\n";
	cout << abs(rowSum - calculatedValue) << "\n";

	return 0;
}