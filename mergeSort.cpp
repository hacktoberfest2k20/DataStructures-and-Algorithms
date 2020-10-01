#include <iostream>
using namespace std;
//merge function merge the array
//conquer
void merge(int *a, int s, int e) {
  int mid = (s + e) / 2;
  int i = s;
  int j = mid + 1;
  int k = s;
  int temp[100];
  while (i <= mid && j <= e) {
    if (a[i] < a[j]) {
      temp[k++] = a[i++];
    }
    else {
      temp[k++] = a[j++];
    }
  }
  while (i <= mid) {
    temp[k++] = a[i++];
  }
  while (j <= e) {
    temp[k++] = a[j++];
  }
  for (int i = s; i <= e; i++) {
    a[i] = temp[i];
  }
}

void mergesort(int a[], int s, int e) {
  if (s >= e) {
    return;
  }
  int mid = (s + e) / 2;
  //recursive call to divide array into 2 parts
  //divide
  mergesort(a, s, mid);
  mergesort(a, mid + 1, e);
  merge(a, s, e);
}

int main() {
  int a[] = {1, 6, 4, 8, 3, 9, 2};
  int n = 7;
  mergesort(a, 0, n - 1);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
