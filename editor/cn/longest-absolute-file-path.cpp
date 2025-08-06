/*
 * @lc app=leetcode.cn id=388 lang=cpp
 * @lcpr version=30202
 *
 * [388] 文件的最长绝对路径
 */

// @lc code=start
class Solution {
public:
    int lengthLongestPath(string input) {
       deque<int> stack;
       int maxLen = 0;
       vector<string> parts = split(input, '\n');
       for (const auto& part : parts) {
         int level=part.rfind('\t')+1;
         while (level<stack.size()) {
           stack.pop_back();
         }
         stack.push_back(part.size()-level);
         string name = part.substr(level);
         bool isFile = (name.find('.') != string::npos);
         if (isFile) {
           int sum=0;
           for(auto len : stack)
           {
            sum+=len;
           }
           sum+=stack.size()-1;
           maxLen=max(maxLen,sum);
         }

       }
       return maxLen;
    }
private:
    vector<string> split(const string &s,char delimiter ){
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream,token,delimiter)) {
          tokens.push_back(token);
        }
        return tokens;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"\n
// @lcpr case=end

// @lcpr case=start
// "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

// @lcpr case=start
// "file1.txt\nfile2.txt\nlongfile.txt"\n
// @lcpr case=end

 */

