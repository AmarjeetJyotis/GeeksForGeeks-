class Solution {
  public:
    // यह helper function बताता है कि कितने numbers हैं जो 'mid' से छोटे या बराबर हैं
    int countLessEqual(int m, int n, int mid) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(mid / i, n);  // हर row में कितने numbers mid से छोटे हैं
        }
        return count;
    }

    int kthSmallest(int m, int n, int k) {
        int low = 1, high = m * n;

        while (low < high) {
            int mid = (low + high) / 2;
            int count = countLessEqual(m, n, mid);

            if (count < k) {
                low = mid + 1;  // मतलब अभी का mid छोटा है, हमें right में देखना होगा
            } else {
                high = mid;     // हो सकता है यही answer हो या इससे छोटा
            }
        }

        return low;  // low ही वो smallest number है जो k-th position पर आता है
    }
};