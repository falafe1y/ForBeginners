#include "InsertSort.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> nums = {5, 4, 3, 2, 1};
 
    InsertSort(&nums);

    cout << '\n';
    cout << "Sorted vector:" << '\n';
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
}