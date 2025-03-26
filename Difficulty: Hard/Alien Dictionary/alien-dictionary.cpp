//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  string topoSort(int V,vector<vector<int>>&adj ,int n,unordered_set<char>&letters){
      // topoSort ka ordering likho aab sidha se
      //indegree bna lete h
      vector<int>InDegree(V,0);
      
      for(int i=0;i<26;i++){
          for(auto it:adj[i]){
                 InDegree[it]++;
          }
      }
      queue<int>q;
      
     // map lena he padega kyuki haamko unique laphabet nhi diya 
     // hua to Map to use karna he padega 
     
    for (char ch : letters) {
            if (InDegree[ch - 'a'] == 0) {
                  q.push(ch - 'a');
            }
        }
      
      string ans ="";
      
      while(!q.empty()){
           int top =q.front();
           q.pop();
           ans += char(top+'a');
           
           for(auto it:adj[top]){
                 InDegree[it]--;
                 
                 if(InDegree[it]==0){
                       q.push(it);
                 }
           }
      }
      
     if (ans.size() < letters.size()) return "";
       return ans;
       
  }
    string findOrder(vector<string> &words) {
        // code here
    //to be sorted lexicographically according to the language’s rules.-->>>IMPORTANT LINE TO to catch Somethings to which topic is this come from
    
      //ADJ list ka kuch karet h Basicallly graph bnanae ka upaye karte h
      int V = 26; 
      unordered_set<char> letters; 
      
       for (int i = 0; i < words.size(); i++) {
            for (char ch : words[i]) {
                letters.insert(ch); 
            }
        }
       
        int n = letters.size();
      vector<vector<int>>adj(26);
      
      for(int i=0;i<words.size()-1;i++){
            string s1 = words[i];
            string s2 = words[i+1];
             
                int len =min(s1.size(),s2.size());
                
                  if (s1.size() > s2.size() && s1.substr(0, len) == s2) {
                     return "";
                  } 
                  
                 for(int j=0;j<len;j++){
                        if(s1[j] != s2[j]){
                              adj[s1[j]-'a'].push_back(s2[j]-'a');
                              break;
                        }
                 }
      }
      
      // aab baas Ordering nikalna h
     
        return topoSort(V,adj,n,letters);
        
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends