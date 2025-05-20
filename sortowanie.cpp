#include <iostream>
using namespace std;

void merge(int tab[], int l, int m, int r) {  
   
    int lSize = m - l + 1;
    int rSize = r - m;

    int* tabL = new int[lSize];  
    int* tabR = new int[rSize];

   
    for (int x = 0; x < lSize; ++x) {  
        tabL[x] = tab[l + x];
    }

    for (int y = 0; y < rSize; ++y) {
        tabR[y] = tab[m + 1 + y];
    }

    int indexL = 0;  
    int indexR = 0; 
    int currIndex = l;  

  
    while (indexL < lSize && indexR < rSize) {  
        if (tabL[indexL] <= tabR[indexR]) {
            tab[currIndex++] = tabL[indexL++];
        } else {
            tab[currIndex++] = tabR[indexR++];
        }
    }

    while (indexL < lSize) {  
        tab[currIndex++] = tabL[indexL++];
    }

    while (indexR < rSize) {
        tab[currIndex++] = tabR[indexR++];
    }

    delete[] tabL;  
    delete[] tabR;
}

void mergeSort(int tab[], int l, int r) {  
    if (l < r) {
        int m = l + (r - l) / 2;  

        mergeSort(tab, l, m);  
        mergeSort(tab, m + 1, r);
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
