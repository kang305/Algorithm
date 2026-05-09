/*https://leetcode.cn/problems/dui-cheng-de-er-cha-shu-lcof/description/*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef struct T_Node
{
    int val;
    T_Node *left;
    T_Node *right;
}TreeNode;
bool check(TreeNode* p,TreeNode* q)
{
   if (p == nullptr&&q == nullptr) {//无向下的根节点
    return true;
    }
    if (p == nullptr||q == nullptr) {//有一个为空
        return false;
    }
    /*简便的格式
     return (p->val==q->val)&&(p->left=q->right)&&(p->right==q->left)
     */
    bool flag1=0,flag2=0,flag3=0;
    if (p->val == q->val) {//判断根节点的左子树=右子树
        flag1=1;
    }
    //向下一层
    if (check(p->left,q->right)) {//左的左=右的右
        flag2=1;
    }
    if (check(p->right,q->left)) {//左的右=右的左
        flag3=1;
    }
    return flag1&&flag2&&flag3;
}
bool checkSymmetricTree(TreeNode* root)
{
    if(root==NULL) {//防止访问空指针
        return true;
    }else {
        return check(root->left,root->right);
    }

}