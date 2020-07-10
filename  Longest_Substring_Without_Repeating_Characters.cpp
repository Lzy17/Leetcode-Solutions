class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> progress;
        string words = s;
        int max_len = 0;
        int pos = 0;
        for(int i = 0; i < s.size(); i++){
            auto it = progress.find(s[i]);
            while( it != progress.end() && it->second < pos){
                progress.erase(it);
                it = progress.find(s[i]);
            }
            if(it == progress.end()){
                progress.insert({s[i], i});
                if(i == s.size() - 1){
                    if(max_len < s.size() - pos){
                        max_len = s.size() - pos;
                    }
                }
            }
            else{
                if(max_len < i - pos){
                    max_len = i - pos;
                }

                pos = it->second + 1;
                progress.erase(it);
                progress.insert({s[i], i});
            }

        }
            return max_len;

    }
};
