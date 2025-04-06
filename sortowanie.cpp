#include <iostream>
using namespace std;

void merge(int tab[], int l, int m, int r) {
    // K1: Obliczenie rozmiaru tablic pomocniczych
    int lSize = m - l + 1;
    int rSize = r - m;

    // K3 i K4: Utworzenie dwóch tablic pomocniczych
    int* tabL = new int[lSize];
    int* tabR = new int[rSize];

    // K5: Kopiowanie danych do tablicy tabL
    for (int x = 0; x < lSize; ++x) {
        tabL[x] = tab[l + x];
    }

    // K6: Kopiowanie danych do tablicy tabR
    for (int y = 0; y < rSize; ++y) {
        tabR[y] = tab[m + 1 + y];
    }

    // K7 i K8: Inicjalizacja indeksów
    int indexL = 0;
    int indexR = 0;
    int currIndex = l;

    // K10: Łączenie tablic
    while (indexL < lSize && indexR < rSize) {
        // K11: Porównanie elementów i umieszczenie ich w odpowiednich miejscach w tablicy głównej
        if (tabL[indexL] <= tabR[indexR]) {
            tab[currIndex++] = tabL[indexL++];
        } else {
            tab[currIndex++] = tabR[indexR++];
        }
    }

    // K13: Kopiowanie pozostałych elementów z tabL
    while (indexL < lSize) {
        tab[currIndex++] = tabL[indexL++];
    }

    // K14: Kopiowanie pozostałych elementów z tabR
    while (indexR < rSize) {
        tab[currIndex++] = tabR[indexR++];
    }

    // K15 i K16: Zwolnienie pamięci
    delete[] tabL;
    delete[] tabR;
}

void mergeSort(int tab[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;  // Krok dzielenia tablicy na połowy

        // Rekurencyjne sortowanie lewej i prawej części
        mergeSort(tab, l, m);
        mergeSort(tab, m + 1, r);

        // Scalanie dwóch posortowanych części
        merge(tab, l, m, r);
    }
}

int main() {
    int tab[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(tab) / sizeof(tab[0]);

    mergeSort(tab, 0, n - 1);

    cout << "Posortowana tablica: ";
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;

    return 0;
}
