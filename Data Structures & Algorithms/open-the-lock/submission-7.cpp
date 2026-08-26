class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(),deadends.end());
        queue<pair<string,int>>q;
        if(st.count("0000")) return -1;
        q.push({"0000",0});
        st.insert("0000");
        int ans=-1;
        while(!q.empty()){
            auto  node=q.front();
            q.pop();
            string str=node.first;
            int steps=node.second;
            
            if(str==target){
                return steps;
            }
            for(int i=0;i<4;i++){
                char ch=str[i];
                str[i]=( str[i]-'0'+1)%10+'0';
                if(!st.count(str)) st.insert(str) ,q.push({str,steps+1});
                str[i]=( ch-'0'+9)%10+'0';
                if(!st.count(str)) st.insert(str) ,q.push({str,steps+1});
                str[i]=ch;
            }
            


        }
        return -1;

    }
};