#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:
    // Comparator function to sort items by value/weight ratio
    bool static comp(Item a, Item b) {
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;
    }

    // Function to compute the maximum value
    double fk(Item arr[], int w, int n) {
        // Sort items by value/weight ratio in descending order
        sort(arr, arr + n, comp);
        double totval = 0.0;  // Total value of knapsack
        int curweight = 0;    // Current weight of knapsack

        // Iterate through the sorted items
        for (int i = 0; i < n; i++) {
            if (curweight + arr[i].weight <= w) {
                // If the current item can be fully added
                curweight += arr[i].weight;
                totval += arr[i].value;
            } else {
                // If the current item can only be partially added
                int remain = w - curweight;
                totval += arr[i].value * ((double) remain / (double) arr[i].weight);
                break;
            }
        }
        return totval;
    }
};

int main() {
    int n = 3, weight = 50;
    Item arr[n] = { {100, 20}, {60, 10}, {120, 30} };
    Solution obj;
    double ans = obj.fk(arr, weight, n);
    cout << "The maximum value is " << setprecision(2) << fixed << ans << endl;
    return 0;
}
