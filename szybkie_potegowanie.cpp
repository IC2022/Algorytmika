#include <iostream>
using namespace std; 
    int szybkiePotegowanie(int a, int n) {
    int wynik = 1; // K1: Inicjalizacja wyniku jako 1
 
    while (n > 0) { // K2: Dopóki n > 0
        if (n % 2 == 1) { // K3: Jeśli n % 2 = 1
            wynik *= a; // Mnożymy wynik przez bazę
        }
        a *= a; // K4: Kwadratowanie bazy
        n /= 2; // K5: Dzielimy wykładnik przez 2
    } // K6: Zakończ pętlę
 
    return wynik; // K7: Zwróć wynik
}
 
int main() {
    int a, n;
    cout << "Podaj baze (a): ";
    cin >> a;
    cout << "Podaj wykladnik (n): ";
    cin >> n;
 
    int wynik = szybkiePotegowanie(a, n);
    cout << a << "^" << n << " = " << wynik << endl;
 
    return 0;
}