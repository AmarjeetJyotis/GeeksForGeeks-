//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    string rearrange (string S, int N)
    {
        // your code here
        int c1=0;
        int c2=0;
       vector<int>v1(26,0);
       vector<int>v2(26,0);
        for(int i=0;i<S.size();i++){
            if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u'){
                v1[S[i]-'a']+=1;
                c1++;
            }
            else{
                  v2[S[i]-'a']+=1;
                  c2++;
            }
        }
        
        if(abs(c1-c2)>1)
        return "-1";
        string SS="";
       
        int j=0;
        int k=0;
        int i=0;
        while(j<26&&k<26){
            
          if(v1[j]==0){
          j++;
          continue;
          }
          if(v2[k]==0){
          k++;
          continue;
          }
          if(c1>c2){
              SS.push_back(j+'a');
              v1[j]--;
              c1--;
              i++;
          }
          else if(c1==c2){
          if(i==0){
              if(j<k){
                SS.push_back(j+'a');
              v1[j]--;
              c1--;
              i++;  
              }
              else{
                SS.push_back(k+'a');
              v2[k]--;
              c2--; 
              i++; 
                  
              }
              
          }   
          else{
              int ii=i;
              i--;
              if(SS[i]=='a'||SS[i]=='e'||SS[i]=='i'||SS[i]=='o'||SS[i]=='u'){
                  SS.push_back(k+'a');
              v2[k]--;
              c2--; 
              ii++; 
              }
              else{
                  
                 SS.push_back(j+'a');
              v1[j]--;
              c1--;
              ii++;  
                  
              }
               i=ii;
          }
         
              
          }
          else{
             SS.push_back(k+'a');
              v2[k]--;
              c2--; 
              i++;
          }
            
        }
        
        
        while(j<26){
            
           if(v1[j]==0){
          j++;
          continue;
          } 
          
           SS.push_back(j+'a');
              v1[j]--;
              c1--;
            
        }
          while(k<26){
            
           if(v2[k]==0){
          k++;
          continue;
          } 
          SS.push_back(k+'a');
              v2[k]--;
              c2--; 
            
        }
            
        
        
     return SS;   
    }
};


//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	
cout << "~" << "\n";
}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends