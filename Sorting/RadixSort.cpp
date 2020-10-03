// Radix sort in C++

#include <iostream>
#include <algorithm>
using namespace std;

void radixSort(int *begin, int *end) {
    int *begin1 = new int[end - begin];
    int *end1 = begin1 + (end - begin);
    for (int shift = 0; shift < 32; shift += 8) {
        size_t count[0x100] = {};
        for (int *p = begin; p != end; p++)
            count[(*p >> shift) & 0xFF]++;
        int *bucket[0x100], *q = begin1;
        for (int i = 0; i < 0x100; q += count[i++])
            bucket[i] = q;
        for (int *p = begin; p != end; p++)
            *bucket[(*p >> shift) & 0xFF]++ = *p;
        std::swap(begin, begin1);
        std::swap(end, end1);
    }
    delete[] begin1;
}

int main() {
    int array[] = {23, 12, 65, 10, 45, 2, 7};
    int arrSize = sizeof(array)/sizeof(array[0]);
    radixSort(array, array + arrSize);
   cout << "Sorted array: \n";
    for (int i = 0; i < arrSize; i++)
        cout << array[i] << " ";
    cout << endl;
}
