#include <iostream>
using namespace std;
 
int main() {
    int n;
    cout << "Podaj liczbe n: ";
    cin >> n;
    int k = 2;
 
    while (n > 1) {
        while (n % k == 0) {
            cout << k << " ";
            n /= k;
        }
        k++;
    }
    cout << endl;
    return 0;
}
