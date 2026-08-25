class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char ,int>map;
        int n=words.size();
        for(int i=0;i<26;i++) map[order[i]]=i;
        for(int i=0;i<n-1;i++){
            string word1=words[i];
            string word2=words[i+1];
            int len=min(word1.size(),word2.size());
            int found=true;
            for(int j=0;j<len;j++){
                if(map[word1[j]]==map[word2[j]]) continue;
                if(map[word1[j]] <map[word2[j]]){
                    found=false;
                    break;
                }else return false;
            }
            if(found && word1.size() >word2.size()) return false;
        }
        return true;
    }
};