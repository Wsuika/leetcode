#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
    return 0;
}
