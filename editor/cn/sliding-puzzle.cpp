/*
 * @lc app=leetcode.cn id=773 lang=cpp
 * @lcpr version=30201
 *
 * [773] 滑动谜题
 */

// @lc code=start
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target="123450";
        string start="";
        for (int i = 0; i < board.size(); ++i) {
          for (int j = 0; j < board[0].size(); ++j) {
            start=start+to_string(board[i][j]);
          }
        }
        queue<string> q;
        unordered_set<string> visited;
        int step=0;
        q.push(start);
        visited.insert(start);
        while (!q.empty()) {
          int sz=q.size();
          for (int i = 0; i < sz; ++i) {
            string cur=q.front();
            q.pop();
            if (cur==target) {
              return step;
            }
            for (const auto& neighbor : getNeighbors(cur)) {
              if (!visited.count(neighbor)) {
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
        vector<vector<int>> mapping={
            {1,3},
            {0,4,2},
            {1,5},
            {0,4},
            {1,3,5},
            {2,4}
        };
        int idx=s.find('0');
        vector<string> neighbors;
        for (const auto& adj : mapping[idx]) {
          string t=swap(s,idx,adj);
          neighbors.push_back(t);
        }
        return neighbors;
    }
    string swap(string s,int i,int j){
        char tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
        return  s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,0,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[5,4,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,1,2],[5,0,3]]\n
// @lcpr case=end

 */

