//
//  main.cpp
//  LetterCombinations_17
//
//  Created by melon on 8/17/20.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> stringMulti(vector<string> A, string b);
vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> letterCombinations(string digits) {
    vector<string> ans = {};
    if(digits.size() == 0)
    {
        return ans;
    }
    
    for(int i = 0;i<digits.size();i++)
    {
        int count = (int)digits[i] - 48;

        ans = stringMulti(ans,map[count]);

    }
    
    return ans;
}

vector<string> stringMulti(vector<string> A, string b)
{
    vector<string> ans = {};
    
    if(A.size() == 0 && b.size() > 0)
    {
        for(int i= 0 ;i<b.size();i++)
        {
            ans.push_back(string{b[i]});
        }
    }
    else if(A.size() > 0 && b.size() == 0)
    {
        return A;
    }
    else if(A.size() == 0 && b.size() == 0)
    {
        return ans;
    }
    
    ans.reserve(A.size() * b.size());
    for(int i = 0;i<A.size();i++) //A[i] + b[j]
    {
        for(int j = 0; j< b.size();j++)
        {
            ans.push_back(A[i] + b[j]);
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string>testcase = {
        "23",
        "555",
        "1111",
        "6578",
    };
    
    for(int i=0;i<testcase.size();i++)
    {
        auto ans = letterCombinations(testcase[i]);
        cout<<"test case "<<i<<": ";
        for(auto i = ans.cbegin();i!=ans.cend();i++)
        {
            cout<<(*i)<<", ";
        }
        cout<<endl;
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
