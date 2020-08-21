//
//  main.cpp
//  121_MaxProfit
//
//  Created by melon on 8/20/20.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, buyday = 0;
        if(prices.size() == 0)
            return  ans;
        for(int i = 1;i < prices.size();i++)
        {
            if(prices[i] - prices[buyday] >= ans)
                ans = prices[i] - prices[buyday];
            if(prices[i] < prices[buyday])
                buyday = i;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<vector<int> > testcases = {
        {7,1,5,3,6,4},
        {7,6,4,3,1},
    };
    for(int i=0;i<testcases.size();i++){
        std::cout << s.Solution::maxProfit(testcases[i])<<endl;
    }
    return 0;
}
