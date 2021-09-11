#include <iostream>
#include <vector>
#include <string>
using namespace std;

//solution should be here

struct Testcase {
    vector<int> candidates;
    int target;
    vector<vector<int> > answer;
    
    Testcase(vector<int> candidates,
             int target,
             vector<vector<int> > answer)
    : candidates(candidates), target(target), answer(answer) {}
};

int main(int argc, const char * argv[]) {
    // insert code here... candidates = [2,3,6,7], target = 7
    vector<Testcase> testcases =
    {
       // Testcase({2,3,6,7},7,{{2,2,3},{7}}),
       //Testcase({2,3,5}, 8, {{2,2,2,2},{2,3,3},{3,5}}),
        Testcase({1,2,3,5}, 150, {{2,2,2,2},{2,3,3},{3,5}}),
    };


    Solution s;
    string str;
    for (int i=0; i<testcases.size(); i++) {
        auto ans = s.combinationSum(testcases[i].candidates, testcases[i].target);
        
        if(ans==testcases[i].answer)
        {
            str = "👌 your ans:";
        }
        else
        {
            str = "❌ your ans:";
            
        }
        cout<<str<<endl;
    }
    return 0;
}

