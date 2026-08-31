class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            auto [word,steps]=q.front();
            q.pop();
            if(word==endWord) return steps;
            int len=word.size();
            for(int i=0;i<len;i++){
                char org=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=org;
            }
        }
        return 0;
    }
};
