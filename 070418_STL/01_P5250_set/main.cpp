//https://www.luogu.com.cn/problem/P5250
#include <iostream>
#include <set>
using namespace std;
int n, op, t;
set<int>::iterator lwb, l2, l3;//set容器的迭代器
set<int> s;
int main(){
    cin >> n;
    for (int i = 1;i <= n;i ++){
        cin>>op>>t;
        if (op == 1){//操作为1，插入容器中还未有的元素
            if (!s.insert(t).second) cout << "Already Exist\n";
        }
        else {//操作为2
            if (s.empty()){//容器为空
                cout << "Empty\n";
                continue;
            }
            if (s.find(t)!=s.end()) {//找到了和t相同的元素
                cout<<t;
                s.erase(s.find(t));//删除该元素
            }
            else {
                lwb = l2 = l3 = s.lower_bound(t);//找到>=t的元素
               if (lwb==s.begin()) {//所有元素都>=t,删除第一个
                   cout<<*lwb;
                   s.erase(lwb);
               }else if (lwb==s.end()) {//都比t小，删除前一个
                   cout<<*(--l2);
                   s.erase(l2);
               }else if (*lwb-t<t-*(--l3)) {//左右都有且大的更加接近，删除左边的
                   cout<<*(l2);
                   s.erase(l2);
               }else {//删除右边的
                   cout<<*(--l2);
                   s.erase(l2);
               }
            }
            cout << endl;
        }
    }
    return 0;
}