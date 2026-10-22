
class Solution {
public:
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> ans;

    void solve(string &digits, int idx, string &current) {
        // Saare digits process ho gaye
        if (idx == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = mp[digits[idx]];

        for (char ch : letters) {
            current.push_back(ch);

            solve(digits, idx + 1, current);

            current.pop_back(); // Backtracking
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        string current = "";
        solve(digits, 0, current);

        return ans;
    }
};
