#include <iostream>
using namespace std;

int CalculatePowerRecursive(int podstawa, int wykladnik) {
    if (wykladnik == 0) {
        return 1;
    } else if (wykladnik > 0) {
        return podstawa * CalculatePowerRecursive(podstawa, wykladnik - 1);
    } else {
        return 1 / CalculatePowerRecursive(podstawa, -wykladnik);
    }
}


int DisplayResult(int wynik) {
    cout << "Wynik potęgowania: " << wynik << endl;
}


int main() {
    int podstawa;
    int wykladnik;

   
    cout << "Podaj liczbę podstawową: ";
    cin >> podstawa;
    cout << "Podaj wykładnik: ";
    cin >> wykladnik;

    int wynik = CalculatePowerRecursive(podstawa, wykladnik);
    DisplayResult(wynik);

    return 0;
}
