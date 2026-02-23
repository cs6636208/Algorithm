#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r, bool asc) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[100], R[100];

    for (int i = 0; i < n1; i++) 
		L[i] = a[l + i];
    for (int i = 0; i < n2; i++) 
		R[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (asc) {
            if (L[i] <= R[j]) 
				a[k++] = L[i++];
            else 
				a[k++] = R[j++];
        } else {
            if (L[i] >= R[j]) 
				a[k++] = L[i++];
            else 
				a[k++] = R[j++];
        }
    }

    while (i < n1) 
		a[k++] = L[i++];
    while (j < n2) 
		a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r, bool asc) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m, asc);
        mergeSort(a, m + 1, r, asc);
        merge(a, l, m, r, asc);
    }
}

int main() {
    int n;
    cin >> n;

    int a[100], even[100], odd[100];
    int ec = 0, oc = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) 
			even[ec++] = a[i];
        else 
			odd[oc++] = a[i];
    }

    int minEven = 100000, minOdd = 100000;

    for (int i = 0; i < ec; i++)
        if (even[i] < minEven) 
			minEven = even[i];
    for (int i = 0; i < oc; i++)
        if (odd[i] < minOdd) 
			minOdd = odd[i];

    if (minOdd < minEven) {
        mergeSort(odd, 0, oc - 1, true);
        mergeSort(even, 0, ec - 1, false);

        for (int i = 0; i < oc; i++) 
			cout << odd[i] << " ";
        for (int i = 0; i < ec; i++) 
			cout << even[i] << " ";
    } else {
        mergeSort(even, 0, ec - 1, true);
        mergeSort(odd, 0, oc - 1, false);

        for (int i = 0; i < ec; i++) 
			cout << even[i] << " ";
        for (int i = 0; i < oc; i++) 
			cout << odd[i] << " ";
    }
    return 0;
}

