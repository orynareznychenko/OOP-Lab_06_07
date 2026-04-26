#include <iostream>
#include "Long.h"

using namespace std;

int main() {
    int size;
    cout << "Enter the number of array elements: ";
    cin >> size;

    if (size <= 0) {
        cout << "Error: the array must contain at least 1 element." << endl;
        return 1;
    }

    int* a = new int[size];
    cout << "Enter " << size << " array elements separated by space:\n"
        << "(Try entering consecutive duplicates, e.g., 2 2 2 -3 -3 5 5 7)\n> ";
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    int* b = new int[size];
    int* c = new int[size];
    int* d = new int[size];

    int b_size = unique_copy_custom(&a[0], &a[size], &b[0]);
    cout << "\n1. Result of unique_copy (ALL consecutive duplicates removed):\n   ";
    for (int i = 0; i < b_size; i++) cout << b[i] << ' ';
    cout << endl;

    Even<int> even_pred;
    int c_size = unique_copy_if_custom(&a[0], &a[size], &c[0], even_pred);
    cout << "2. Result of unique_copy_if (only EVEN duplicates removed):\n   ";
    for (int i = 0; i < c_size; i++) cout << c[i] << ' ';
    cout << endl;

    Negative<int> neg_pred;
    int d_size = unique_copy_if_custom(&a[0], &a[size], &d[0], neg_pred);
    cout << "3. Result of unique_copy_if (only NEGATIVE duplicates removed):\n   ";
    for (int i = 0; i < d_size; i++) cout << d[i] << ' ';
    cout << endl;

    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;

    return 0;
}