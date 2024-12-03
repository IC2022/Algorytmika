#include <iostream>
using namespace std;

// Funkcja rekurencyjna obliczająca potęgę liczby
double CalculatePowerRecursive(double base, int exponent) {
    if (exponent == 0) {
        return 1; // Każda liczba do potęgi zerowej wynosi 1
    } else if (exponent > 0) {
        return base * CalculatePowerRecursive(base, exponent - 1);
    } else {
        return 1 / CalculatePowerRecursive(base, -exponent); // Obsługa ujemnego wykładnika
    }
}

// Funkcja wyświetlająca wynik
void DisplayResult(double result) {
    cout << "Wynik potęgowania: " << result << endl;
}

// Funkcja main
int main() {
    double base;
    int exponent;

    // Pobranie danych od użytkownika
    cout << "Podaj liczbę podstawową: ";
    cin >> base;
    cout << "Podaj wykładnik: ";
    cin >> exponent;

    // Obliczenie potęgi i wyświetlenie wyniku
    double result = CalculatePowerRecursive(base, exponent);
    DisplayResult(result);

    return 0;
}
