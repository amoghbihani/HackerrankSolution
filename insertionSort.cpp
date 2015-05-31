#include <iostream>
using namespace std;

void insertionSort(int ar_size, int *  ar) {
    for (int i = 1; i < ar_size; ++i) {
        int temp = ar[i];
        int j = i;
        while ((ar[j] < ar[j - 1]) && j > 0) {
            ar[j] = ar[j - 1];
            ar[j - 1] = temp;
            --j;
        }
        for (int k = 0; k < ar_size; ++k) {
            cout << ar[k] << " ";
        }
        cout << endl;
    }
}

int main(void) {
    int _ar_size;
    cin >> _ar_size;
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        cin >> _ar[_ar_i];
    }

   insertionSort(_ar_size, _ar);
   return 0;
}
