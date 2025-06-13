class Solution {
  public:
  
  void merg(vector<int> &arr, int l, int r){
    int mid = l+(r-l)/2;
    int len1=mid-l+1;
    int len2=r-mid;
    
    int* left= new int[len1];
    int* right=new int[len2];
    
    // copy and the values
  
    int k=l;
    // left part logic
    for(int i=0; i<len1; i++){
        left[i]=arr[k];
        k++;
    }
    // right part logic
     k=mid+1;
    for(int i=0; i<len2; i++){
        right[i]=arr[k];
        k++;
    }
    
    // merging logic
    int leftIndex=0;
    int rightIndex=0;
    int mainIndex=l;
    while(leftIndex<len1 && rightIndex<len2){
        if(left[leftIndex]<=right[rightIndex]){
            arr[mainIndex++]=left[leftIndex++];
        }
        else{
            arr[mainIndex++]=right[rightIndex++];
        }
    }
    
    // left part for logic
    while(leftIndex<len1){
        arr[mainIndex++]=left[leftIndex++];
    }
    // right part for logic
    while(rightIndex<len2){
        arr[mainIndex++]=right[rightIndex++];
    }
  }
  
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        // base condation
        if(l>=r){
            return ;
        }
        // left part
        int mid = l+(r-l)/2;
        // left part
        mergeSort(arr, l, mid);
        
        // righ part
        mergeSort(arr,mid+1, r);
        
        // merg 
        merg(arr, l, r);
    }
};