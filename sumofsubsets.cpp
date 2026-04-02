#include <bits/stdc++.h>
using namespace std;

// Function to find subsets that sum to target using backtracking
void findSubsets(vector<int>& nums, int target, vector<int>& current, int index, int currentSum) {
    if (currentSum == target) {
        cout << "{ ";
        for (int num : current) {
            cout << num << " ";
        }
        cout << "}" << endl;
        return;
    }
    if (index == nums.size() || currentSum > target) {
        return;
    }
    // Include current element
    current.push_back(nums[index]);
    findSubsets(nums, target, current, index + 1, currentSum + nums[index]);
    current.pop_back();
    // Exclude current element
    findSubsets(nums, target, current, index + 1, currentSum);
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int target = 9;
    vector<int> current;
    cout << "Subsets that sum to " << target << ":" << endl;
    findSubsets(nums, target, current, 0, 0);
    return 0;
}