#include<iostream>
using namespace std;
//brute force - use set concept
int main() {
    int a[] = {1, 1, 2, 3, 4, 5};
    int b[] = {2, 3, 4, 4, 5, 6};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    int i = 0, j = 0, k = 0;
    int n = n1 + n2;
    int u[n]; // Potentially larger than needed, we'll adjust size later

    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (k == 0 || a[i] != u[k - 1]) {
                u[k++] = a[i];
            }
            i++;
        } else if (b[j] < a[i]) {
            if (k == 0 || b[j] != u[k - 1]) {
                u[k++] = b[j];
            }
            j++;
        } else {
            if (k == 0 || a[i] != u[k - 1]) {
                u[k++] = a[i];
            }
            i++;
            j++;
        }
    }

    // Copy remaining elements
    while (i < n1) {
        if (k == 0 || a[i] != u[k - 1]) {
            u[k++] = a[i];
        }
        i++;
    }

    while (j < n2) {
        if (k == 0 || b[j] != u[k - 1]) {
            u[k++] = b[j];
        }
        j++;
    }

    // Output the union array
    for (int x = 0; x < k; x++) {
        cout << u[x] << " ";
    }
    return 0;
}
//time complexity - O(n1 + n2)
// space complexity to return the answer (worst case) - O(n1 +n2) 
