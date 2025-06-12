class Solution {
  public:
    void Rearrange(int arr[], int n) {
        vector<int> negatives;
        vector<int> positives;

        for (int i = 0; i < n; i++) {
            if (arr[i] < 0)
                negatives.push_back(arr[i]);
            else
                positives.push_back(arr[i]);
        }

        // Combine back into original array
        int index = 0;
        for (int x : negatives)
            arr[index++] = x;
        for (int x : positives)
            arr[index++] = x;
    }
};
