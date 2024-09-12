class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> freq(27,0);
        for(int i=0;i<allowed.size();i++){
            int convert_ind = allowed[i] - 'a';
            // cout<<convert_ind<<" ";
            freq[convert_ind] = 1;
        }

        int ans=0;

        for(int i=0;i<words.size();i++){
            string tmp = words[i];

            bool fl = true;

            for(int j=0;j<tmp.size();j++){
                int convert_ind = tmp[j] - 'a';
                if(freq[convert_ind]==1){ continue; }
                else{
                    fl = false;
                    break;
                }
            }

            if(fl == true){ans++;}
        }

        return ans;
    }
};