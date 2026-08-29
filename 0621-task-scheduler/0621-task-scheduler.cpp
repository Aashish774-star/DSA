class Solution {
public:
    struct cmp {
        bool operator()(pair<int, char>& a, pair<int, char>& b) {
            if (a.first == b.first)
                return a.second < b.second;

            return a.first < b.first;
        }
    };

    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> f;

        priority_queue<
            pair<int, char>,
            vector<pair<int, char>>,
            cmp
        > pq;

        // Count frequency
        for (int i = 0; i < tasks.size(); i++) {
            f[tasks[i]]++;
        }

        // Push frequency and character
        for (auto i : f) {
            pair<int, char> curr = {i.second, i.first};
            pq.push(curr);
        }

        int ans = 0;

        while (!pq.empty()) {

            vector<pair<int, char>> temp;

            // Ek cycle = n + 1 intervals
            for (int i = 0; i <= n; i++) {

                if (!pq.empty()) {

                    pair<int, char> p = pq.top();
                    pq.pop();

                    // Execute task
                    ans++;

                    // Frequency decrease
                    p.first--;

                    // Abhi bhi task remaining hai
                    if (p.first > 0) {
                        temp.push_back(p);
                    }
                }
                else {

                    // Heap empty hai
                    // Agar future me task remaining hai,
                    // toh idle time lagega
                    if (temp.empty()) {
                        break;
                    }

                    ans++;
                }
            }

            // Remaining tasks ko wapas heap me daalo
            for (int i = 0; i < temp.size(); i++) {
                pq.push(temp[i]);
            }
        }

        return ans;
    }
};