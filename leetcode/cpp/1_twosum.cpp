#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

class Solution { // chatGPT assisted very similar to one of the top answers
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;  // To store the value and its index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];  // The value we need to find
            if (num_map.find(complement) != num_map.end()) {
                // If the complement is found, return the indices
                return {num_map[complement], i};
            }
            // Store the current number with its index in the map
            num_map[nums[i]] = i;
        }
        // If no solution found (per the problem's assumption, this won't happen)
        return {};
    }
};

// unordered_map
// stores numbers as keys and their indices as values for fast look-up.

// find == end() to check if already in

// Define a TestCase class to encapsulate test data
class TestCase {
public:
    vector<int> nums;
    int target;
    vector<int> expected;

    TestCase(const vector<int>& nums, int target, const vector<int>& expected)
        : nums(nums), target(target), expected(expected) {}
    
    // Function to check if the result matches the expected output
    bool runTest(Solution& solution) {
        vector<int> result = solution.twoSum(nums, target);
        return result == expected; // you can compare vector!
    }
};

int main() {
    Solution solution;

    // Create test cases
    vector<TestCase> testCases = {
        TestCase({2, 7, 11, 15}, 9, {0, 1}),
        TestCase({3, 2, 4}, 6, {1, 2}),
        TestCase({3, 3}, 6, {0, 1}),
        TestCase({1, 2, 3}, 5, {1, 2}),
    };

    // Run test cases
    for (int i = 0; i < testCases.size(); ++i) {
        bool passed = testCases[i].runTest(solution);
        cout << "Test Case " << i + 1 << ": " << (passed ? "Passed" : "Failed") << endl;
    }

    return 0;
}

/*
int main() {
    // Test cases
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;

    vector<int> nums3 = {3, 3};
    int target3 = 6;

    // Create an instance of Solution
    Solution solution;

    // Run test case 1
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test Case 1: ";
    for (int index : result1) {
        cout << index << " ";
    }
    cout << endl;

    // Run test case 2
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Test Case 2: ";
    for (int index : result2) {
        cout << index << " ";
    }
    cout << endl;

    // Run test case 3
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Test Case 3: ";
    for (int index : result3) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
 */
