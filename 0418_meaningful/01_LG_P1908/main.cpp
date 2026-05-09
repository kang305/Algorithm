/*https://www.luogu.com.cn/problem/P1908#ide*/
#include<iostream>
using namespace std;
int arr1[500005];//输入数组
int arr2[500005];//辅助数组
long long res;//统计
int n;
//归并排序
void solve(int left ,int right) {
    if (left == right) {//递归退出条件,当左边界等于右边界,此时每组只有一个
        return;
    }
    int mid = left + (right - left) / 2;//计算中间值
    int j=left;//左指针(用于左边的分组)
    int i=mid+1;//右指针(用于右边的放在)
    int k=left;//用于在辅助数组里的辅助指针(记录辅助数组已经存到那一位的)
    /*后序遍历:先左子树,再右子树,最后根节点*/
    solve(left,mid);//左区间:[left,mid]-->先递归左子树
    solve(mid+1,right);//右区间[mid+1,right]-->再递归右子树
    while (j<=mid&&i<=right) {//开始处理-->处理根节点
        if (arr1[j] <= arr1[i]) {//如果左边j下标的值比右边i下标更小,即left[j]<=right[i](取等于是因为相等不是逆序对,不进行计数操作,如果只是归并排序的话这里可以不取等也可以取等)
            arr2[k++]=arr1[j++];//将更小的值存入辅助数组,同时j索引向后移动一位
        }else {              //与if情况相反
            arr2[k++]=arr1[i++];//将更小的值存入辅助数组,同时i索引向后移动一位
            res+=mid-j+1;//题目需求(不加就是归并排序的板子)
            //计数公式推导mid-j+1:
            //l1 l2 l3 l4...     r1 r2 r3 r4...(这个可能只是某个左或右区间的分组)-->体现递归的分组
            //此时left和right各自是有序的(因为在递归归出来的时候已经排好--->在各自区间的逆序对已经统计好了,开始统计此时左右区间的逆序对)
            //已知条件:left和right数组各自有序,left数组的下标<right数组的下标(mid就是分界)
            //看下面例子
        }
    }
    //第一个while退出无非就是1&&0或0&&1
    while (j<=mid) {//1&&0-->左边数组还有元素
        arr2[k++]=arr1[j++];//将剩余元素依次放入arr2
    }
    while (i<=right) {//0&&1-->右边数组还有元素
        arr2[k++]=arr1[i++];//同上
    }
    for (int g=left; g<=right; g++) {//将arr2中排序好的放回arr1对应的位置(保证在下一次统计的时候左右区间各自是有序的)
        arr1[g]=arr2[g];
    }

    //把以下注释解开可以看到各次归时排序的结果
    // printf("arr1:");
    // for(int g=1;g<=n;g++) {
    //     cout<<arr1[g]<<" ";
    // }
    // cout<<endl;
    // printf("arr2:");
    // for(int g=1;g<=n;g++) {
    //     cout<<arr2[g]<<" ";
    // }
    // cout<<endl;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr1[i];
    }
    // printf("every mergesort:\n");
    solve(1,n);
    cout<<res<<endl;
    // printf("mergesort:\n");
    // printf("arr1:");
    // for(int i=1;i<=n;i++) {
    //     cout<<arr1[i]<<" ";
    // }
    // cout<<endl;
    // printf("arr2:");
    // for(int i=1;i<=n;i++) {
    //     cout<<arr2[i]<<" ";
    // }
    return 0;
}

/*
1 2 3   4 5 6(下标)
5 4 2   6 3 1
以最后一次归出来为例子:mid=3,此时res已经统计完各自区间的逆序对,目前统计的是最后一个左右区间的逆序对
l       r
2 4 5   1 3 6
l>r  r++
arr2:1
res=res+mid-left+1=res+3-1+1=res+3(相当于left数组里有mid-left+1个比此时right[i]更大,所有均是逆序对,只用考虑right[i]在left数组中的逆序对)

l         r
2 4 5   1 3 6
r>l  l++
arr2:1 2
res contain

  l       r
2 4 5   1 3 6
l>r  r++
arr2:1 2 3
res=res+mid-left+1=res+2

  l         r
2 4 5   1 3 6
r>l  l++
arr2:1 2 3 4
res contain

    l       r
2 4 5   1 3 6
r>l   l++
arr2:1 2 3 4 5
res contain

      l     r
2 4 5   1 3 6
l>mid-->while退出
arr2:1 2 3 4 5 6(将还未遍历完的区间依次放到arr2)
res contain
*/


/*第一次
l r
1 2    3 4 5 6(下标)
5 4    2 6 3 1
l>r
4 5    2 6 3 1
.....后面的排序同理
 */