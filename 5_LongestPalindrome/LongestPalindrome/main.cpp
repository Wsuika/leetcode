//
//  main.cpp
//  LongestPalindrome
//
//  Created by melon on 8/16/20.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string longestPalindrome(string s) {
        if ("" == s)
            return "";
            
        string s2;
        // create a s2 with '+' split every s element;
        s2.reserve(s.length()*2+1);
        bool addPlus = true;
        for(int i=0;s2.length() <= s.length()*2+1;)
        {
            if(addPlus)
                s2.push_back('+');
            else
            {
                s2.push_back(s[i]);
                i++;
            }
            addPlus = !addPlus;
        }
        
        int l=0, r=-1;
        
        
        int max=0,index=0;
        vector<int> d(s.length()*2+1,0);
        for(int i = 0; i < d.size(); i++)
        {
            if(i>r || d[l+r-i] >= r-i )
            {
                if (i<=r)
                {
                    d[i] = r-i;
                }
                //trival algorithm
                for(int j = d[i]+1; i+j<d.size() && i-j>=0 && s2[i+j] == s2[i-j]; j++)
                {
                    d[i]=j;
                }
            }
            else if(i<=r && d[l+r-i] < r-i)
            {
                //save time XD
                d[i]=d[l+r-i];
            }
            
            
            if(i+d[i]>r)
            {
                r = i+d[i];
                l = i-d[i];
            }
            
            if(d[i]>max)
            {
                max=d[i];
                index=i;
            }
        }
        
        string palindrome="";
        for(int i = index-max;i<=index+max;i++)
        {
            if(s2[i]!='+')
                palindrome.push_back(s2[i]);
        }
        return palindrome;
        
    }

int main(int argc, const char * argv[]) {
    // test case
    cout<<longestPalindrome("bb");
    cout<<longestPalindrome("bbdd");
    cout<<longestPalindrome("bbdddase");
    cout<<longestPalindrome("bqwiijjjjwhhhoslllfjbbbvsuwlajhfhsjasdfjkl;asdfjk;");
    return 0;
}
