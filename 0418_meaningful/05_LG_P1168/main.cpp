#include<iostream>
#include<queue>
using namespace std;
int n;
int arr[100009];
int mid;
priority_queue<int,vector<int>,less<int>> q1;//按照顺序放小于mid的元素(大顶堆)
priority_queue<int,vector<int>,greater<int>> q2;//大于mid的元素(小顶堆)
int main() {
    cin>>n;
    cin>>arr[1];
    mid=arr[1];
    cout<<mid<<endl;
    for(int i=2;i<=n;i++) {
        cin>>arr[i];
        if (arr[i]>mid) {
            q2.push(arr[i]);
        }else {
            q1.push(arr[i]);
        }
        if (i%2==1) {
            while (q1.size()!=q2.size()) {
                if (q1.size()<q2.size()) {
                    q1.push(mid);
                    mid=q2.top();
                    q2.pop();
                }
                else {
                    q2.push(mid);
                    mid=q1.top();
                    q1.pop();
                }
            }
            cout<<mid<<endl;
        }
    }
    return 0;
}