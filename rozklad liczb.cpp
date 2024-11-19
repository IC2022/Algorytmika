#include <iostream>
using namespace std;
 
int main() {
    // K1: Wprowadź liczbę n.
    int n;
    cout << "Podaj liczbe n: ";
    cin >> n;
 
    // K2: Ustaw k = 2 (pierwsza liczba pierwsza).
    int k = 2;
 
    // K3: Dopóki n > 1, wykonuj kroki K4-K6:
    while (n > 1) {
        // K4: Dopóki n % k == 0:
        while (n % k == 0) {
            // 1. Wyświetl k.
            cout << k << " ";
            // 2. Podziel n = n / k.
            n /= k;
        }
        // K5: Zwiększ k o 1.
        k++;
    }
 
    // K6: Zakończ.
    cout << endl;
    return 0;
}