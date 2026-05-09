#include<iostream>
#include<string>
using namespace std;
int a[100010],b[100010],c1[100010];
int c2[200020];//乘法位数最大是相加
string s1, s2;//用于判断数据大小

/*高精度加法*/
int init_add(int x[]) {//读入数据并且返回读入数据的位数
    string s;
    cin>>s;
    int len=s.size();//数据的长度
    for(int i=0;i<len;i++) {
        x[i]=s[len-1-i]-'0';
    }
    return len;
}
void addition(int a[],int b[]) {
    int a_len=init_add(a);//处理数据1
    int b_len=init_add(b);//处理数据2
    int c_len=max(a_len,b_len)+1;//结果最大数
    for (int i=0;i<max(a_len,b_len);i++) {
        c1[i]+=a[i]+b[i];
        if(c1[i]>=10) {
            c1[i]-=10;
            c1[i+1]++;
        }
    }
    //去除前导0
    c_len--;//从0到len-1,所有len--,长度和下标差一位
    while(c1[c_len]==0&&c_len>0) {
        c_len--;
    }//现在c_len指向的是最高非0位的下标
    for(int i=c_len;i>=0;i--) {
        cout<<c1[i];
    }
    cout<<endl;
}
/*高精度减法:要先判断±*/
int init_sub(int x[],string s) {
    int len=s.size();//数据的长度
    for(int i=0;i<len;i++) {
        x[i]=s[len-1-i]-'0';
    }
    return len;
}

void Subtraction() {
    cin>>s1>>s2;
    if ((s1.size()<s2.size())||(s1.size()==s2.size()&&s1<s2)) {//相减是负数,提前输出负号,将两者交换
        cout<<'-';
        swap(s1,s2);
    }
    int a_len=init_sub(a,s1);
    int b_len=init_sub(b,s2);
    int c_len=max(a_len,b_len);
    for(int i=0;i<c_len;i++) {
        /*借位法1:
          c[i]+=a[i]-b[i];//注意这里是+=
          if(c[i]<0) {
              c[i]+=10;
              c[i+1]--;
          }
          */
        //借位法2:
        if (a[i]<b[i]) {
            a[i]+=10;
            a[i+1]--;
        }
        c1[i]=a[i]-b[i];
    }
    //去前导0
    c_len--;
    while (c1[c_len]==0&&c_len>0) {
        c_len--;
    }
    for(int i=c_len;i>=0;i--) {
        cout<<c1[i];
    }
    cout<<endl;
}

/*高精度乘法*/
int init_mul(int x[]) {
    string s;
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++)
    {
        x[i]=s[l-1-i]-'0';
    }
    return l;
}
void multiplication() {
    int a_len=init_mul(a);
    int b_len=init_mul(b);
    int c_len=a_len+b_len;
    for(int i=0;i<a_len;i++) {//乘的时候不处理进位
        for(int j=0;j<b_len;j++) {
            c2[i+j]+=a[i]*b[j];
        }
    }
    //处理进位
    for(int i=0;i<c_len;i++) {
        if (c2[i]>=10) {
            c2[i+1]+=(c2[i]/10);
            c2[i]%=10;
        }
    }
    //去除前导0
    c_len--;
    while (c2[c_len]==0&&c_len>0) {
        c_len--;
    }
    for(int i=c_len;i>=0;i--) {
        cout<<c2[i];
    }
}
/*高精度除法*/
//数组0下标存放数据长度
void init_div(int x[]) {
    string s;
    cin>>s;
    x[0]=s.size();  // x[0]存储数字的长度（位数）
    for(int i=1;i<=x[0];i++) {
        // 将字符串转换为数字数组，倒序存储（个位在x[1]，最高位在x[x[0]]）
        x[i]=s[x[0]-i]-'0';
    }
}

// 比较函数：判断x是否大于等于y
// 返回1表示x>=y，返回0表示x<y
bool check_div(int x[],int y[]) {
    if(x[0]>y[0])return 1;  // x位数更多，x>y
    if(x[0]<y[0])return 0;  // x位数更少，x<y

    // 长度相等，从最高位开始逐位比较
    for (int i=x[0];i>=1;i--) {
        if (x[i]>y[i]) return 1;  // 当前位x更大，x>y
        if (x[i]<y[i]) return 0;  // 当前位x更小，x<y
    }
    return 1;  // 所有位都相等，x=y
}

// 高精度减法：x = x - y（假设x>=y）
void sub(int x[],int y[]) {
    for(int i=1;i<=x[0];i++) {  // 从个位开始逐位相减
        if(x[i]<y[i]) {  // 需要借位
            x[i]+=10;    // 当前位加10
            x[i+1]-=1;   // 前一位减1（借位）
        }
        x[i]-=y[i];      // 相减
    }

    // 去掉前导0，重新计算差的位数
    int i=x[0];
    while(x[i]==0&&i>1) {  // 从最高位开始检查，去除前导0
        i--;
    }
    x[0]=i;  // 更新位数
}

// 高精度除法主函数
int Division() {
    init_div(a);  // 读入被除数a
    init_div(b);  // 读入除数b

    // 去除被除数a的前导0（如005变成5）
    while(a[a[0]]==0&&a[0]>1) {
        a[0]--;  // 减少位数，去掉最高位的0
    }

    // 去除除数b的前导0
    while(b[b[0]]==0&&b[0]>1) {
        b[0]--;
    }

    // 判断被除数是否小于除数
    if(check_div(a,b)==0) {
        // 小数除以大数，商为0
        cout<<0<<endl;
        return 0;
    }

    // 商的位数：被除数位数减去除数位数再加1（最大可能位数）
    c1[0]=a[0]-b[0]+1;

    // 逐位计算商
    for(int i=c1[0];i>=1;i--) {
        int t[10005]={0};  // 临时数组,用于存储补0后的除数

        // 将除数b后面补i-1个0，使b与a的当前部分位数对齐,相当于b * 10^(i-1)
        for(int j=1;j<=b[0];j++) {  // 复制b的每一位
            t[j+i-1]=b[j];  // 偏移i-1位，实现补0效果
        }
        t[0]=b[0]+i-1;  // 计算补0后的总位数

        // 用减法模拟除法：不断从a中减去t，直到a<t
        while(check_div(a,t)==1) {
            sub(a,t);      // a = a - t
            c1[i]++;       // 每减去一次，商当前位加1
        }
    }

    // 去除商的前导0
    while(c1[c1[0]]==0&&c1[0]>1) {
        c1[0]--;  // 减少商的位数
    }

    // 输出商（注意：存储是倒序，所以要从高位到低位输出）
    for(int i=c1[0];i>=1;i--) {
        cout<<c1[i];
    }
    cout<<endl;

    return 0;
}
int main(){
    Division();
    return 0;
}