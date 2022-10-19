class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int greatestElement = -1;
        for(int i = arr.size() - 1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = greatestElement;
            greatestElement = max(greatestElement, temp);
        }
        return arr;
    }
};