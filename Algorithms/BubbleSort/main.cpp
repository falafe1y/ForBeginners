#include <iostream>
#include "BubbleSort.h"

using namespace std;

int main() {
    vector<int> nums = {5, 2, 6, 4, 1, 3};
    cout << "Source vector:\n";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    cout << "\n\n";

    BubbleSort(&nums);

    cout << "\nSorted vector:\n";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    cout << '\n';
    return 0;
}