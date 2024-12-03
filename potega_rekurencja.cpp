#include <iostream>
using namespace std;

double CalculatePowerRecursive(double podstawa, int wykladnik) {
    if (wykladnik == 0) {
        return 1;
    } else if (wykladnik > 0) {
        return podstawa * CalculatePowerRecursive(podstawa, wykladnik - 1);
    } else {
        return 1 / CalculatePowerRecursive(podstawa, -wykladnik);
    }
}

void DisplayResult(double wynik) {
    cout << "Wynik potęgowania: " << wynik << endl;
}

int main() {
    double podstawa;
    int wykladnik;

    cout << "Podaj liczbę podstawową: ";
    cin >> podstawa;
    cout << "Podaj wykładnik: ";
    cin >> wykladnik;

    double wynik = CalculatePowerRecursive(podstawa, wykladnik);
    DisplayResult(wynik);

    return 0;
}
