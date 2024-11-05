#include <iostream>
using namespace std; 
    int szybkiePotegowanie(int a, int n) {
    int wynik = 1; 
 
    while (n > 0) { 
        if (n % 2 == 1) { 
            wynik *= a; 
        }
        a *= a;
        n /= 2; 
    } 
 
    return wynik; 
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
