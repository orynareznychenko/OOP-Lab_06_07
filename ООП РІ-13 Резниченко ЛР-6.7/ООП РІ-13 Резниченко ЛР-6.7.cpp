#include <iostream>
#include "Long.h" 

using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    if (!(cin >> size) || size <= 0) {
        cout << "Input error! Size must be greater than 0.\n";
        return 1;
    }

    int* a = new int[size];

    cout << "Enter " << size << " elements (space separated):\n";
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    int* b = new int[size];
    int* c = new int[size];
    int* d = new int[size];

    cout << "\nInitial array:\n";
    for (int i = 0; i < size; i++) cout << a[i] << " ";
    cout << "\n\n";

    int n1 = unique_copy(&a[0], &a[size], &b[0]);
    cout << "unique_copy (ALL consecutive duplicates removed):\n";
    for (int i = 0; i < n1; i++) cout << b[i] << " ";
    cout << "\n\n";

    Positive<int> pos;
    int n2 = unique_copy_if(&a[0], &a[size], &c[0], pos);
    cout << "unique_copy_if with Positive (consecutive duplicates removed ONLY IF POSITIVE):\n";
    for (int i = 0; i < n2; i++) cout << c[i] << " ";
    cout << "\n\n";

    Even<int> even;
    int n3 = unique_copy_if(&a[0], &a[size], &d[0], even);
    cout << "unique_copy_if with Even (consecutive duplicates removed ONLY IF EVEN):\n";
    for (int i = 0; i < n3; i++) cout << d[i] << " ";
    cout << "\n\n";

    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;

    return 0;
}