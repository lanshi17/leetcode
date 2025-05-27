/*
 * @lc app=leetcode.cn id=752 lang=cpp
 * @lcpr version=30201
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
       unordered_set<string> deads(deadends.begin(),deadends.end());
       if (deads.count("0000")) {
         return -1;
       }
       unordered_set<string> visited;
       queue<string> q;
       int step=0;
       q.push("0000");
       visited.insert("0000");
       while (!q.empty()) {
         int sz=q.size();
         for (int i = 0; i < sz; i++)
         {
            string cur=q.front();
            q.pop();
            if (cur==target) {
              return step;
            }
            for (const auto& neighbor : getNeighbors(cur)) {
              if (!visited.count(neighbor)&&!deads.count(neighbor)) {
                q.push(neighbor);
                visited.insert(neighbor);
              }
            }
         }
         step++;
       }
       return -1;
    }
    vector<string> getNeighbors(string s){
        vector<string> neighbors;
        for (int i = 0; i < 4; ++i) {
          neighbors.push_back(plusOne(s,i));
          neighbors.push_back(minusOne(s,i));
        }
        return neighbors;
    }
    string plusOne(string s,int j){
        if (s[j]=='9') {
          s[j]='0';
        }
        else
        {
            s[j]+=1;
        }
        return s;

    }
    string minusOne(string s,int j){
        if (s[j]=='0') {
          s[j]='9';
        }
        else s[j]-=1;
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["0201","0101","0102","1212","2002"]\n"0202"\n
// @lcpr case=end

// @lcpr case=start
// ["8888"]\n"0009"\n
// @lcpr case=end

// @lcpr case=start
// ["8887","8889","8878","8898","8788","8988","7888","9888"]\n"8888"\n
// @lcpr case=end

 */

