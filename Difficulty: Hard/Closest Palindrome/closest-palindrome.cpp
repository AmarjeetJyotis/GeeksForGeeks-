//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    long long int halfToPalindrome(long long int left, bool even) {
        long long int resultNum = left;
        if (!even) {
            left = left / 10;
        }

        while (left > 0) {
            int digit = left % 10;
            resultNum = (resultNum * 10) + digit;
            left /= 10;
        }
        return resultNum;
    }

    bool isPalindrome(long long int num) {
        string s = to_string(num);
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    long long int closestPalindrome(long long int num) {
        if (num >= 0 && num <= 9) return num; // Handle single-digit edge case
        if (isPalindrome(num)) return num; // Return if already a palindrome
        
        string n = to_string(num);
        int len = n.size();
        int mid = len / 2;
        long long int firstHalf = stoll(n.substr(0, len % 2 == 0 ? mid : mid + 1));

        vector<long long int> possibleResults;
        possibleResults.push_back(halfToPalindrome(firstHalf, len % 2 == 0));
        possibleResults.push_back(halfToPalindrome(firstHalf + 1, len % 2 == 0));
        possibleResults.push_back(halfToPalindrome(firstHalf - 1, len % 2 == 0));
        possibleResults.push_back((long long int)pow(10, len - 1) - 1);
        possibleResults.push_back((long long int)pow(10, len) + 1);

        long long int diff = LLONG_MAX;
        long long int result = 0;
        long long int originalNum = num;

        for (long long int &candidate : possibleResults) {
            if (candidate == originalNum) continue;
            if (abs(candidate - originalNum) < diff) {
                diff = abs(candidate - originalNum);
                result = candidate;
            } else if (abs(candidate - originalNum) == diff) {
                result = min(result, candidate);
            }
        }

        return result;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends