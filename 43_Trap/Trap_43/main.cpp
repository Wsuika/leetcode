//
//  main.cpp
//  Trap_43
//
//  Created by melon on 8/18/20.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool higher(int i, int j);
int sumWater(int i, int j);
class TreeNode;
vector<int> h;
void compareAndReplace(TreeNode* i, TreeNode* &j);
class TreeNode
{
public:
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    const int index;
    TreeNode(const int i) : index(i)
    {
    
    }
    ~TreeNode()
    {
        delete left;
        delete right;
    }
    
    void push_back(TreeNode* i)
    {
        if(!i)
            return;

        if(index < i->index){
            compareAndReplace(i, right);
            return;
        }
        else {
            compareAndReplace(i, left);
        }
    }
};
void compareAndReplace(TreeNode* i, TreeNode* &j)
{
    if(!j){
        j = i;
        return;
    }
    
    if(higher(i->index,j->index)){
        i->push_back(j);
        j = i;
        return;
    }
    else {
        j->push_back(i);
        return;
    }
}
int trap(vector<int>& height) {
    if (height.size() == 0)
        return 0;
    h = height;
    TreeNode* boundIndices = nullptr;
    for(int i = 0; i < height.size();i++)
    {
        if(boundIndices == nullptr && height[i] > 0 )
        {
            boundIndices = new TreeNode(i);
        }
        
        else if (height[i] > 0)
        {
            compareAndReplace(new TreeNode(i), boundIndices);
        }
    }
    
    int lwater = 0, rwater = 0;
    TreeNode* lp = boundIndices,*rp = boundIndices;
    while(lp && lp->left)
    {
        lwater += sumWater(lp->index, lp->left->index);
        lp = lp->left;
    }
    while(rp && rp->right)
    {
        rwater += sumWater(rp->index, rp->right->index);
        rp = rp->right;
    }

    return lwater + rwater;
}

int sumWater(int i, int j)
{
    int minHeight = min(h[i],h[j]);
    int left = min(i,j);
    int right = max(i,j);
    int water = 0;
    for(int k=left+1 ;k<right;k++)
        water += minHeight - h[k];
    return water;
}

bool higher(int i, int j)
{
    return h[i] > h[j];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int> > testcase =
    {
        {0,1,0,2,1,0,1,3,2,1,2,1},
        {0,1,0,2,1,0,1,3,0,1,2,1},
        {7,0,0,0,7},
        {},
        {0,1,0,1},
        {1,1,0,1}
    };
    for(int i = 0;i<testcase.size();i++)
    {
        cout<<trap(testcase[i])<<endl;
    }
    return 0;
}
