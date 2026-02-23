#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r);
void mergesort(int arr[], int l, int r);

void printarr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void mergesort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int L[n1], R[n2];
	
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
		
	i = 0;
	j = 0;
	k = l;
	
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[i];
			j++;
		}
		k++;
	}
	
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2) {
		j++;
		k++;
	}
}

int binarysearch(int arr[], int l, int r, int target) {
	if (l > r) {
		return -1;
	}
	
	int mid = (l + r) / 2;
	if (arr[mid] == target) {
		return mid;
	}
	if (arr[mid] > target) {
		return binarysearch(arr, l, mid - 1, target);
	} else {
		return binarysearch(arr, mid + 1, r, target);
	}
}

int duplicate(vector<int> &arr , int target, int start)
{
    int idx = bts(arr, start, arr.size() - 1, target);
    if (idx == -1)
    {
        return -1;
    }

    int first, last, current;
    first = last = current = idx;
    while (current != -1)
    {
        first = current;
        current = bts(arr, start, current - 1, target);
    }

    current = idx;

    while (current != -1)
    {
        last = current;
        current = bts(arr, current + 1, arr.size() - 1, target);
    }

    return last - first + 1;
}

int main() {
	int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);
    int maxCount = INT_MIN;
    int value = arr[0];
    for(int i = 0; i < n;){
        int target = arr[i];
        int step = duplicate(arr, target, i);
        if (step > maxCount && step != -1){
            maxCount = step;
            value = arr[i];
        }
        i += step;
    }

    cout << value << " " << maxCount << " " << roundCount;
	return 0;
}


