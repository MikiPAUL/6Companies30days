class Solution {
    map<TreeNode*, pair<int, int>> mp;
    pair<int, int> find(TreeNode* root){
        if(!root) return {0, 0};
        auto lft = find(root->left), rgt = find(root->right);
        return mp[root] = {lft.first+rgt.first+root->val, 1+lft.second+rgt.second};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        find(root);
        int ans = 0;
        for(auto& pr: mp){
            if(pr.first->val == pr.second.first/pr.second.second) ans++;
        }
        return ans;
    }
};
