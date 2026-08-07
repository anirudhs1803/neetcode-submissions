class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowSets(9);
        vector<unordered_set<char>> colSets(9);
        vector<unordered_set<char>> boxSets(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char val = board[i][j];
                if (val == '.') continue;

                int boxIndex = (i / 3) * 3 + (j / 3);

                if (rowSets[i].count(val) || colSets[j].count(val) || boxSets[boxIndex].count(val)) {
                    return false;
                }

                rowSets[i].insert(val);
                colSets[j].insert(val);
                boxSets[boxIndex].insert(val);
            }
        }
        return true;
    }
};