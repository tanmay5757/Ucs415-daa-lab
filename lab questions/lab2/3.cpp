#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double solveFractionalKnapsack(int W, vector<int>& values, vector<int>& weights, int n) {
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        items[i].value = values[i];
        items[i].weight = weights[i];
    }

    sort(items.begin(), items.end(), compare);

    int currentWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        } else {
            int remain = W - currentWeight;
            finalValue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int N = 3;
    vector<int> value = {100, 60, 120};
    vector<int> weight = {20, 10, 40};
    int W = 50;

    cout << "Maximum value = " << solveFractionalKnapsack(W, value, weight, N) << endl;

    return 0;
}