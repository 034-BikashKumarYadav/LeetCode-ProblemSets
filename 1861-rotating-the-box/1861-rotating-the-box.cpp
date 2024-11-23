class Solution {
public:
    std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        std::vector<std::vector<char>> rotated(n, std::vector<char>(m, '.'));

        for (int i = 0; i < m; ++i) {
            int position = n - 1; // Position to place the next stone
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    rotated[j][m - i - 1] = '*';
                    position = j - 1;
                } else if (box[i][j] == '#') {
                    rotated[position--][m - i - 1] = '#';
                }
            }
        }

        return rotated;
    }
};