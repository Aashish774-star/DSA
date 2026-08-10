class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();

        vector<vector<int>> res;
        bool inserted = false;

        // Insert
        for (int i = 0; i < n; i++) {

            if (!inserted && newInterval[0] < intervals[i][0]) {
                res.push_back(newInterval);
                inserted = true;
            }

            res.push_back(intervals[i]);
        }

        if (!inserted) {
            res.push_back(newInterval);
        }

        // Merge
        vector<vector<int>> ans;

        int st1 = res[0][0];
        int end1 = res[0][1];

        for (int i = 1; i < res.size(); i++) {

            int st2 = res[i][0];
            int end2 = res[i][1];

            if (end1 >= st2) {
                st1 = st1;
                end1 = max(end1, end2);
                continue;
            }

            ans.push_back({st1, end1});
            st1 = st2;
            end1 = end2;
        }

        ans.push_back({st1, end1});

        return ans;
    }
};