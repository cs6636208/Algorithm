#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int BinarySearch(int A[], int N, int x, int searchFirst) {
    int low = 0, high = N - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (A[mid] == x) {
            result = mid;
            if (searchFirst)
                high = mid - 1;  
            else
                low = mid + 1;    
        }
        else if (x < A[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, target;
    
    scanf("%d %d", &n, &target);
    
    int A[n];
    
    for (int i = 0; i < n; i++)
    	scanf("%d", &A[i]);
    
    qsort(A, n, sizeof(int), compare);
    
    int first = BinarySearch(A, n, target, 1);
    int last  = BinarySearch(A, n, target, 0);
    
    int count = last - first + 1;

    if (first != -1)
        printf("%d\n", count);
    else 
        printf("-1");

    return 0;
}



