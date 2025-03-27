//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    queue<vector<string>>q;
    q.push({beginWord});
    vector<string>usedonlevel;
    int level=0;
    vector<vector<string>>result;
    unordered_set<string>st(wordList.begin(),wordList.end());
    while(!q.empty()){
        vector<string>vec=q.front();
        q.pop();
        string word=vec.back();
        if(word==endWord){
            if(result.size()==0) result.push_back(vec);
            else if(result[0].size()==vec.size()) result.push_back(vec);
        }
        if(vec.size()>level){
            level++;
            for(auto it:usedonlevel){
                st.erase(it);
            }
        }
        
      for(int i=0;i<word.length();i++){
          char original=word[i];
          for(char ch='a';ch<='z';ch++){
              word[i]=ch;
              
              if(st.count(word)>0){
                  vec.push_back(word);
                  q.push(vec);
                  usedonlevel.push_back(word);
                  vec.pop_back();
                  
              }
          }
          word[i]=original;
          
      }  
        
        
        
    }
    return result;
    }
};


//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends