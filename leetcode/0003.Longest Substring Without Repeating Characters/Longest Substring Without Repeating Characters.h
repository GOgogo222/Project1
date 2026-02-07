#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxStr = 0;
        int left = 0;
        unordered_set<char> lookup;

        for (int i = 0; i < s.length(); ++i) {
            while (lookup.find(s[i]) != lookup.end()) { // lookup.find() == lookup.end() means not found
                lookup.erase(s[left]);
                left++;
            }
            maxStr = max(maxStr, i - left + 1);
            lookup.insert(s[i]);
        }
        return maxStr;
        
    }
};