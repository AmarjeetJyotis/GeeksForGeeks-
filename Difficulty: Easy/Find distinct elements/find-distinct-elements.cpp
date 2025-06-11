// User function Template for C++
int distinct(vector<int>& arr) {
    // Your code here
    int count=0;
    map<int, int> mp;
    for(int i=0; i<arr.size(); i++){
        mp[arr[i]]++;
    }
    return mp.size();
    
}