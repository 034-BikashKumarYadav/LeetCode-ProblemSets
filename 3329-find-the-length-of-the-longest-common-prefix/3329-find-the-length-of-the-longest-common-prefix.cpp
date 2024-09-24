class Solution {
public:
    struct TrieNode {
        TrieNode* child[10];
        TrieNode() {
            for (int i = 0; i < 10; i++) {
                child[i] = nullptr;
            }
        }
    };

    void insertKey(TrieNode* root, const string& key) {
        TrieNode* curr = root;
        for (char c : key) {
            if (curr->child[c - '0'] == nullptr) {
                TrieNode* newNode = new TrieNode();
                curr->child[c - '0'] = newNode;
            }
            curr = curr->child[c - '0'];
        }
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();
        for(auto &i: arr1){
            insertKey(root, to_string(i));
        }
        int ans = 0;
        for(auto &i: arr2){
            int x  = 0;
            string s = to_string(i);
            TrieNode* curr = root;
            for (char &c : s) {
                if (curr->child[c - '0'] == nullptr) 
                    break;
                curr = curr->child[c - '0'];
                x++;
            }
            ans = max(x, ans);
        }
        return ans;
    }
};