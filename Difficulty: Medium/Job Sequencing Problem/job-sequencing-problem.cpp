//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
    vector<pair<int, int>> vp;

    
    for (int i = 0; i < n; i++) {
        vp.emplace_back(deadline[i], profit[i]);
    }

    sort(vp.begin(), vp.end(), cmp);

    set<int> dd;
    for (int i = 0; i < n; i++) {
        dd.insert(i);
    }

    int sum = 0, count = 0;

    for (int i = 0; i < vp.size(); i++) {
        int d = vp[i].first - 1;
        int pr = vp[i].second;

        auto itr = dd.upper_bound(d);
        if (itr == dd.begin()) continue;  
        
        --itr; 
        sum += pr;
        count++;
        dd.erase(itr); 

        if (dd.empty()) break;
    }

    return {count, sum};
    }
    static bool cmp(pair<int, int> &a, pair<int, int> &b) 
  {
    return a.second > b.second;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends