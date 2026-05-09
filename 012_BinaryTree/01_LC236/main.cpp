/*https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef struct TNode
{
    int val;
    struct TNode *left;
    struct TNode *right;
}TreeNode;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
   if (root==nullptr) return nullptr;
   if (p==root||q==root) return root;//谁是根节点输出谁
    TreeNode *left=lowestCommonAncestor(root->left, p, q);//在左子树中找pq根节点
    TreeNode *right=lowestCommonAncestor(root->right, p, q);//在右子树中找pq根节点

    if (left==nullptr) {//不在左子树
        return right;
    }
    if (right==nullptr) {//不在右子树
        return left;
    }
    if (left!=nullptr&&right!=nullptr) {//左右都有
        return root;
    }
    return nullptr;//如果都没有
}