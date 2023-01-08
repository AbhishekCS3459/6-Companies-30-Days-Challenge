#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<int> ans;
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        inorder(root1);
        inorder(root2);
        sort(ans.begin(), ans.end());
        return ans;
    }
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
};
#define fi(a, n) for (int i = a; i < n; i++)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
