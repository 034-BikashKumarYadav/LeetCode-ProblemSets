class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        ranges::sort(obstacles);
        int n = obstacles.size();
        int dir = 0; // 0 = N, 1 = E, 2 = S, 3 = W
        int posX = 0, posY = 0;
        int res = 0;
        for (int i : commands) {
            if (i == -2) {
                dir += 3;
                dir %= 4;
                // -1, but modulo
            }
            else if (i == -1) {
                dir++;
                dir %= 4;
                // +1, but modulo
            }
            else {
                for (int j = 0; j < i; j++) {
                    // currX + isNorth - isSouth
                    int newX = posX + (dir==1) - (dir==3);
                    int newY = posY + (!dir) - (dir==2);
                    
                    // find lower bound using binary search
                    int l = 0, r = n;
                    while (l < r) {
                        int mid = (l+r) / 2;
                        if (obstacles[mid][0] >= newX) {
                            r = mid;
                        }
                        else {
                            l = mid+1;
                        }
                    }

                    // check for obstacles[k] == [newX, newY]
                    bool flag = false;
                    while (l < n && obstacles[l][0] == newX) {
                        if (obstacles[l][1] == newY) {
                            // obstacle found
                            flag = true;
                            break;
                        }
                        l++;
                    }
                    if (!flag) { // no obstacle found; update pos
                        posX = newX;
                        posY = newY;
                    }
                    else { // obstacle found; move to next command
                        break;
                    }
                }

                // x^2 + y^2 = r^2
                res = max(res, posX*posX + posY*posY);
            }
        }
        return res;
    }
};