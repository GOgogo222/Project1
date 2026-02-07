#include "Maximum Number of Vowels in a Substring.h"
#include <iostream>
using namespace std;


int main() {
    Solution solution;
    string s = "abciiidef";
    int k = 3;
    int result = solution.maxVowels(s, k);
    cout << "Maximum number of vowels in a substring of length " << k << " is: " << result << endl;
    return 0;
}