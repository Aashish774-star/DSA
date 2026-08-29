class Solution {
public:
    struct cmp {
        bool operator()(pair<int, char>& a, pair<int, char>& b) {
            if (a.first == b.first)
                return a.second < b.second;

            return a.first < b.first;
        }
    };

    string reorganizeString(string s) {

        unordered_map<char, int> f;

        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;

        string res = "";
        int seat = 0;

        // Count frequency
        for (int i = 0; i < s.size(); i++) {
            f[s[i]]++;
        }

        // Push into priority queue
        for (auto i : f) {
            pair<int, char> curr = {i.second, i.first};
            pq.push(curr);
        }

        while (!pq.empty()) {

            pair<int, char> p = pq.top();
            pq.pop();

            if (seat == 0 || res[seat - 1] != p.second) {

                res.push_back(p.second);
                seat++;

                p.first--;

                if (p.first > 0) {
                    pq.push(p);
                }
            }

            else {

                // No other character available
                if (pq.empty()) {
                    return "";
                }

                // Take another character
                pair<int, char> p2 = pq.top();
                pq.pop();

                res.push_back(p2.second);
                seat++;

                p2.first--;

                if (p2.first > 0) {
                    pq.push(p2);
                }

                // p was not used, so put it back
                if (p.first > 0) {
                    pq.push(p);
                }
            }
        }

        return res;
    }
};