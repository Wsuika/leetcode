//
//  main.cpp
//  39_CombinationSum
//
//  Created by melon on 9/10/21.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    
    vector<vector<int>> myCombinationSum(vector<int>& candidates, int target, vector<int> temp_ans) { //DFS
        auto result = vector<vector<int> >();
        if (target < 0)
            return result;
        
        if(candidates.empty())
            return result;
        
        if(target == 0) {
            result.push_back(temp_ans);
            return result;
        }
        
        auto i = candidates.begin(); //i != candidates.end() && (*i) > target; i++)   {
            //用i的情况
        auto temp_ans_with_i = temp_ans;
        temp_ans_with_i.push_back(*i);
        auto part_ans_with_i = myCombinationSum(candidates,target - (*i),temp_ans_with_i);
        result.insert(result.end(),part_ans_with_i.begin(),part_ans_with_i.end());
    
        //不用i
        auto smaller_candidates = vector<int>(i+1, candidates.end());
        auto part_ans_without_i= myCombinationSum(smaller_candidates, target, temp_ans);
        result.insert(result.end(), part_ans_without_i.begin(),part_ans_without_i.end());
        
        
        return result;
    }
    
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty())
            return vector<vector<int> >();
        
        //re-order it as largest first
        
        quicksort(candidates,0,candidates.size() - 1);
        
        
        return myCombinationSum(candidates, target, vector<int>());
        
    }
    
    void quicksort(vector<int> &s,int l,int r) {
        if (l< r) {
            int i = l, j = r, x = s[l];
            while (i < j)
            {
                while(i < j && s[j] <= x) // 从右向左找第一个大于x的数
                    j--;
                if(i < j)
                    s[i++] = s[j];
                while(i < j && s[i] > x) // 从左向右找第一个小于等于x的数
                    i++;
                if(i < j)
                    s[j--] = s[i];
            }
            s[i] = x;
            quicksort(s, l, i - 1); // 递归调用
            quicksort(s, i + 1, r);
        }
    }
};

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



