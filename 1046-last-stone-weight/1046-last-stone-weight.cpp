class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; // max heap
        // heap me da diya
        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }
        // jb tk km se km 2 stone h
        while (pq.size() > 1) {
            int y = pq.top(); // y = sabse bada
            pq.pop();
            int x = pq.top(); // x = dsoore sabse bada
            pq.pop();
            // agar equal ni toh diff
            if (x != y) {
                pq.push(y - x);
            }
        }
        // agar koi stone nahi bacha
        if (pq.empty()) {
            return 0;
        }
        // last stone
        return pq.top();
    }
};