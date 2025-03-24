#include <iostream>
using namespace std;

// Funkcja realizująca schemat Hornera
double horner(int* wspolczynniki, int stopien, double x) {
    double wynik = wspolczynniki[0];  // Pierwszy współczynnik (najwyższy stopień)
    
    // Przechodzimy przez pozostałe współczynniki
    for (int i = 1; i <= stopien; ++i) {
        wynik = wynik * x + wspolczynniki[i];
    }

    return wynik;
}

int main() {
    int stopien; // Stopień wielomianu
    double x;    // Argument wielomianu
    
    // K2: Deklaracja zmiennych
    cout << "Podaj stopień wielomianu: ";
    cin >> stopien;  // K3: Pobranie stopnia wielomianu
    
    // K4: Deklaracja dynamicznej tablicy na współczynniki
    int* wspolczynniki = new int[stopien + 1];
    
    // K5: Wczytywanie współczynników
    for (int i = 0; i <= stopien; ++i) {
        cout << "Podaj wspolczynnik dla x^" << (stopien - i) << ": ";
        cin >> wspolczynniki[i];  // K6: Wprowadzenie współczynnika
    }
    
    // K7: Pobranie argumentu wielomianu
    cout << "Podaj wartość argumentu (x): ";
    cin >> x;  // Pobranie wartości x
    
    // K8: Wywołanie funkcji Horner
    double wynik = horner(wspolczynniki, stopien, x);
    
    // Wyświetlanie wyniku
    cout << "Wynik wielomianu w punkcie x = " << x << " wynosi: " << wynik << endl;
    
    // K9: Usunięcie dynamicznej tablicy
    delete[] wspolczynniki;
    
    return 0;
}
