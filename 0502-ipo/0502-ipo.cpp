class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,vector<int>& capital) {

        int n = profits.size();

        // {capital, profit}
        vector<pair<int, int>> projects;

        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        // Sort according to capital
        sort(projects.begin(), projects.end());

        // Max heap of profits
        priority_queue<int> pq;

        int idx = 0;

        while (k--) {

            while (idx < n) {

                if (projects[idx].first > w)
                    break;

                pq.push(projects[idx].second);
                idx++;
            }

            // No affordable project
            if (pq.empty()) {
                return w;
            }

            // Take maximum profit
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};