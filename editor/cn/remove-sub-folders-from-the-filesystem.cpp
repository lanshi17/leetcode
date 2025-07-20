/*
 * @lc app=leetcode.cn id=1233 lang=cpp
 * @lcpr version=30201
 *
 * [1233] 删除子文件夹
 */

// @lc code=start
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        unordered_set<string> res;
        for (const auto& path : folder) {
            bool isSubfolder = false;
            for (int i = 1; i < path.size(); ++i) {
                if (path[i] == '/' && res.count(path.substr(0, i))) {
                    isSubfolder = true;
                    break;
                }
            }
            if (!isSubfolder) {
                res.insert(path);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["/a","/a/b","/c/d","/c/d/e","/c/f"]\n
// @lcpr case=end

// @lcpr case=start
// ["/a","/a/b/c","/a/b/d"]\n
// @lcpr case=end

// @lcpr case=start
// ["/a/b/c","/a/b/ca","/a/b/d"]\n
// @lcpr case=end

 */

