#include <iostream>
using namespace std;

double CalculatePowerRecursive(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else if (exponent > 0) {
        return base * CalculatePowerRecursive(base, exponent - 1);
    } else {
        return 1 / CalculatePowerRecursive(base, -exponent);
    }
}


void DisplayResult(double result) {
    cout << "Wynik potęgowania: " << result << endl;
}


int main() {
    double base;
    int exponent;

   
    cout << "Podaj liczbę podstawową: ";
    cin >> base;
    cout << "Podaj wykładnik: ";
    cin >> exponent;

    double result = CalculatePowerRecursive(base, exponent);
    DisplayResult(result);

    return 0;
}
