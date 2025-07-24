class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for(int row=0; row<n; row++){
            // space 
            for(int col=0; col<n-row-1; col++){
                cout<<" ";
            }
            for(int col=2*row+1; col>0; col--){
                cout<<"*";
            }
            cout<<endl;
        }
    }
};