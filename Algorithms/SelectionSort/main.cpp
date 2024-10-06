#include "SelectioSort.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {6, 5, 4, 3, 2, 1};

    cout << "Source vector:\n";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    cout << "\n\n";

    SelectionSort(&nums);

    cout << "\nSorted vector:\n";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    cout << '\n';

    return 0;
}