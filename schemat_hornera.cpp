#include <iostream>
using namespace std;

double horner(int* wspolczynniki, int stopien, double x) {
    double wynik = wspolczynniki[0]; 
    
    for (int i = 1; i <= stopien; i++) {
        wynik = wynik * x + wspolczynniki[i];
    }

    return wynik;
}

int main() {
    int stopien; 
    double x;    
    
    cout << "Podaj stopień wielomianu: ";
    cin >> stopien; 
    
    int* wspolczynniki = new int[stopien + 1];
    
    for (int i = 0; i <= stopien; i++) {
        cout << "Podaj wspolczynnik dla x^" << (stopien - i) << ": ";
        cin >> wspolczynniki[i]; 
    }
    
    cout << "Podaj wartość argumentu (x): ";
    cin >> x; 

    double wynik = horner(wspolczynniki, stopien, x);
    cout << "Wynik wielomianu w punkcie x = " << x << " wynosi: " << wynik << endl;
    delete[] wspolczynniki;
    
    return 0;
}
