#include <iostream>
using namespace std;

void merge(int tab[], int l, int m, int r) {  // Deklaracja funkcji merge, która scala dwie posortowane części tablicy tab: od lewego początku do prawego końca
    // K1: Obliczenie rozmiaru tablic pomocniczych
    int lSize = m - l + 1;
    int rSize = r - m;

    // K3 i K4: Utworzenie dwóch tablic pomocniczych
    int* tabL = new int[lSize];  // Tworzenie tymczasowych tablic tabL i tabR do przechowania lewej i prawej części danych.
    int* tabR = new int[rSize];

    // K5: Kopiowanie danych do tablicy tabL
    for (int x = 0; x < lSize; ++x) {  // Kopiowanie danych z oryginalnej tablicy tab do tabL (lewa część) i tabR (prawa część).
        tabL[x] = tab[l + x];
    }

    // K6: Kopiowanie danych do tablicy tabR
    for (int y = 0; y < rSize; ++y) {
        tabR[y] = tab[m + 1 + y];
    }

    // K7 i K8: Inicjalizacja indeksów
    int indexL = 0;  // indeks bieżącego elementu w lewej tablicy.
    int indexR = 0;  // indeks w prawej tablicy.
    int currIndex = l;  // aktualny indeks w tablicy tab, do której będą wpisywane scalone dane.

    // K10: Łączenie tablic
    while (indexL < lSize && indexR < rSize) {  // Pętla porównująca elementy z lewej i prawej tablicy. Wstawia mniejszy element do tab[currIndex], a indeksy są aktualizowane.
        // K11: Porównanie elementów i umieszczenie ich w odpowiednich miejscach w tablicy głównej
        if (tabL[indexL] <= tabR[indexR]) {
            tab[currIndex++] = tabL[indexL++];
        } else {
            tab[currIndex++] = tabR[indexR++];
        }
    }

    // K13: Kopiowanie pozostałych elementów z tabL
    while (indexL < lSize) {  // Dodaje pozostałe elementy z lewej lub prawej tablicy, jeśli druga została już wyczerpana.
        tab[currIndex++] = tabL[indexL++];
    }

    // K14: Kopiowanie pozostałych elementów z tabR
    while (indexR < rSize) {
        tab[currIndex++] = tabR[indexR++];
    }

    // K15 i K16: Zwolnienie pamięci
    delete[] tabL;  // Zwolnienie pamięci dynamicznie przydzielonej.
    delete[] tabR;
}

void mergeSort(int tab[], int l, int r) {  // Jeśli lewy indeks l jest mniejszy niż prawy r, to dzielimy tablicę na dwie części. m = środek tablicy (zabezpieczone przed przepełnieniem przez (r - l)).
    if (l < r) {
        int m = l + (r - l) / 2;  // Krok dzielenia tablicy na połowy

        // Rekurencyjne sortowanie lewej i prawej części
        mergeSort(tab, l, m);  // Rekurencyjne sortowanie lewej i prawej połowy.
        mergeSort(tab, m + 1, r);

        // Scalanie dwóch posortowanych części
        merge(tab, l, m, r);
    }
}

int main() {  // Tworzymy przykładową tablicę z liczbami do posortowania.
    int tab[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(tab) / sizeof(tab[0]); // Obliczamy rozmiar tablicy (ilość elementów).

    mergeSort(tab, 0, n - 1); // Uruchamiamy sortowanie przez scalanie dla całej tablicy.

    cout << "Posortowana tablica: "; // Wyświetlamy posortowaną tablicę.
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;

    return 0; // Zwracamy 0 — zakończenie programu.
}
