#include <iostream>
#include <vector>
#include <algorithm>
#include "Container With Most Water.h"
using namespace std;

int main()
{
    Solution solution;
    //vector<int> height = {1,8,6,2,5,4,8,3,7};
    vector<int> height = {1,1};
    int result = solution.maxArea(height);
    cout << "The maximum area of water the container can contain is: " << result << endl;
    return 0;
}


