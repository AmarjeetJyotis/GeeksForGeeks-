//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    stack<char> s;
    for(int i = 0;i<num.length();i++)
    {
        while(!s.empty() && s.top() > num[i] && k > 0)
        {
            s.pop();
            k--;
        }
            
        s.push(num[i]);
    }
    while(k > 0)
    {
        s.pop();
        k--;
    }
    string ans = "";
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    while(ans.length() && ans[ans.length() - 1] == '0') ans.pop_back();
    if(ans.length() == 0)   return "0";
    reverse(ans.begin(), ans.end());
    return ans;
}