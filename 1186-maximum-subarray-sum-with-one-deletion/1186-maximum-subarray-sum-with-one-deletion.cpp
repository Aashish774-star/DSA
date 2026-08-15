class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        int power = 0;   // one deletion used
        int nopower = arr[0];  // no deletion
        int res = arr[0];

        for(int i = 1; i < n; i++)
        {
            int v1 = arr[i];            // new subarray
            int v2 = nopower + arr[i];  // continue without deletion
            int v3 = power + arr[i];    // continue after deletion
            int v4 = nopower;           // delete current element

            int curr = max(max(v1, v2), max(v3, v4));

            res = max(res, curr);

            nopower = max(v1, v2);
            power = max(v3, v4);
        }

        return res;
    }
};