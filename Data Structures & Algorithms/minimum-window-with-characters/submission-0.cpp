class Solution {
public:
    bool isValid(unordered_map<char,int>& window, unordered_map<char,int>& need) {
        for (auto& [ch, cnt] : need) {
            if (window[ch] < cnt) {
                return false;  
            }
        }
        return true;   
    }
    int bestleft = -1;
    int minlen = INT_MAX;

    string minWindow(string s, string t) {
        int left =0;
        
        unordered_map<char,int> mp1;
        for(int i =0; i<t.size(); i++){
            mp1[t[i]]++;
        }
        unordered_map<char,int> mp2;
        int n = s.size();
        for(int right =0; right< n; right++){
            mp2[s[right]]++;
            while(isValid(mp2,mp1)){
                if(right-left+1 < minlen){
                    minlen = right-left+1;
                    bestleft = left;
                }
                mp2[s[left]]--;
                left++;
            }


        }
        if(bestleft == -1){
            return "";
        }
        return s.substr(bestleft, minlen);

    }
};
