class Solution {
public:
    void fun(vector<int>& a, int n, int idx,
             vector<int>& diary, int sum, int target,
             vector<vector<int>>& res) {

        if (sum == target) {
            res.push_back(diary);
            return;
        }

        if (idx == n) {
            return;
        }

        // Choice 1: Current element nahi lena
        fun(a, n, idx + 1, diary, sum, target, res);

        // Choice 2: Current element lena
        if (sum + a[idx] <= target) {
            diary.push_back(a[idx]);

            // Same index, kyunki element dobara le sakte hain
            fun(a, n, idx, diary, sum + a[idx], target, res);

            diary.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> diary;
        int n = candidates.size();

        fun(candidates, n, 0, diary, 0, target, res);

        return res;
    }
};