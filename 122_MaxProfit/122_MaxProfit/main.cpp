//
//  main.cpp
//  122_MaxProfit
//
//  Created by melon on 8/21/20.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()==0) {
            return 0;
        }
        auto size = prices.size();

        int ans = 0,small=prices[0],profit = 0;
        for (int i=1; i<size; i++) {
            if (profit + small > prices[i]) {
                //price begin to go down
                profit = 0;
                small = prices[i];
                continue;
            }
            
            if (small < prices[i]) {
                //price still go up
                ans += prices[i] - small - profit;
                profit = prices[i] - small;
            }
        }
        
        return ans;
    }
    
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int> > testcases =
    {
        {7,1,5,3,6,4},
        {1,2,3,4,5},
        {2,4,5,1000}
    };
    vector<int> answers =
    {
        7,
        4,
        998,
    };
    if(testcases.size()!=answers.size())
    {
        cout<<"test cases are not match answer!!!!"<<endl;
    }
    Solution s;
    string str;
    for (int i=0; i<testcases.size(); i++) {
        int ans = s.maxProfit(testcases[i]);
        
        if(ans==answers[i])
        {
            str = "👌 your ans:";
        }
        else
        {
            str = "❌ your ans:";
            
        }
        cout<<str<<ans<<endl;
    }
    std::cout << "Hello, World!\n"<<endl;;
    return 0;
}
