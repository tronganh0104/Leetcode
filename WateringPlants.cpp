#include <bits/stdc++.h>

using namespace std;

int wateringPlants(vector<int>& plants, int capacity) {
    int stand = -1;
    int water = capacity;
    int output = 0;
    while (stand < plants.size()) {
        if (water >= plants[stand + 1]) {
            water -= plants[stand + 1];
            output += 1;
        } else {
            water = capacity - plants[stand + 1];
            output = output + stand + 1 + stand + 2;
        }
        stand++;
    }
    return output;
}

int main() {
    return 0;
    return 0;
}