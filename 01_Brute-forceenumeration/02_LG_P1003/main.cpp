/*https://www.luogu.com.cn/problem/P1003*/
#include <iostream>
using namespace std;
int a[10001][2],b[10001][2],x,y,i,n,m;//a存放左下角坐标,b存放右上角坐标
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    scanf ("%d",&i);
    for (int j=1;j<=i;j++) {
        scanf("%d%d%d%d",&a[j][0],&a[j][1],&n,&m);//左下角
        //右上角
        b[j][0]=a[j][0]+n;
        b[j][1]=a[j][1]+m;
    }
    scanf ("%d%d",&x,&y);
    for (int j=i;j>=1;j--)
        if (x>=a[j][0]&&x<=b[j][0]&&y>=a[j][1]&&y<=b[j][1]) {//右上角X坐标>=x,Y坐标>=y,左下角X坐标<=x,Y坐标<=y
            printf("%d",j); //输出最上层
            return 0;
        }
    cout <<-1;
    return 0;
}
