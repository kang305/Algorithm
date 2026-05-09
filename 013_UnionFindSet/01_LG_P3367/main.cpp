/*https://www.luogu.com.cn/problem/P3367#id*/
#include <iostream>
using namespace std;
int father[200005];
int find1(int x) {//原先递归版本，会超时
    if (x == father[x]) {
        return x;
    }
    else {
        return find1(father[x]);//将当前节点的父节点递归调用去找根节点
    }
}

int find(int x) {//路径压缩版本-->O(c)
    if (x == father[x]) {
        return x;
    }
    else {//基于上面的基础，将同个集合所有的元素的父节点连到根节点上
        return father[x]=find(father[x]);
    }
}
int main() {
    int N;
    cin >> N;
    int M;
    cin >> M;
    int z,x,y,fx,fy;
    for(int i=1;i<=N;i++) {//对并查集进行初始化，每个节点的
        father[i] = i;
    }
    while(M--) {
        cin >> z >> x >> y;
        if(z == 1) {//进行合并
            fx = find(x);
            fy = find(y);
            father[fx]=fy;
        }
        else {//进行查询
            fx = find(x);
            fy = find(y);
            if(fx == fy) {
                cout <<'Y'<<endl;
            }
            else {
                cout <<'N'<<endl;
            }
        }
    }
    return 0;
}