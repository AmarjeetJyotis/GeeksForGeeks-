//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/*You are required to complete this method */
class Solution {
  public:
bool helper(vector<int> &nums,int threshold,int idx,vector<int> &ans)
{
    if(idx==nums.size())
    {
        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i+1]!=ans[i])
            {
                return false;
            }
        }
        return true;
    }
    for(int i=0;i<ans.size();i++)
    {
        ans[i]+=nums[idx];
        if(ans[i]<=threshold && helper(nums,threshold,idx+1,ans))
        {
            return true;
        }
        ans[i]-=nums[idx];
        if(ans[i]==0)
        {
            break;
        }
    }
    return false;
}
    bool isKPartitionPossible(vector<int> &nums, int k)
    {
        vector<int> ans(k,0);
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%k!=0)
        {
            return false;
        }
        return helper(nums,sum/k,0,ans);           
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> a;
        int n;
        while (ss >> n)
            a.push_back(n);
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        if (obj.isKPartitionPossible(a, k))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends