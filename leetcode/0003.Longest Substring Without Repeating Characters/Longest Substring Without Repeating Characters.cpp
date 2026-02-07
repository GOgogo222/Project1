#include "Longest Substring Without Repeating Characters.h"
#include <iostream>
using namespace std;

int main() {
    Solution solution;
    string testStr = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(testStr);
    cout << "The length of the longest substring without repeating characters in \"" 
         << testStr << "\" is: " << result << endl;
    return 0;
}