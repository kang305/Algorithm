#include<iostream>
#include<string>
using namespace std;
/*朴素方法-->n^1.5*/
bool isPrime_nomal(int x) {
    if (x<2) {
        return false;
    }
    for (int i = 2; i <=(int)sqrt(x); i++) {//x开根-->x=y*z,若y<=sqrt(x)则z>=sqrt(x)只需要检查前面是否符合(只要右侧有左侧也一定有)
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
/*埃氏筛法-->n*log(log(n))*/
void isPrime_EratosthenesSieve(int x) {
    int prime[10005];// 定义整型数组 prime,用于存储筛选出的质数
    int sum = 0;  //用于统计筛选出的质数个数，初始化为0
    bool isPrime[1000005]={0};//标记是否为质数,isPrime[i]=0 i是质数,isPrime[i]=1 i不是质数
    isPrime[1]=1;// 手动标记数字1为非质数（因为1不符合质数定义：大于1且只能被1和自身整除）
    // 外层循环：遍历从2到x的所有数字，逐个判断是否为质数
    for (int i = 2; i <=x; i++) {
        // 若isPrime[i]为0，说明i未被标记为非质数，即i是质数
        if (isPrime[i]==0) {
            // 质数个数加1
            sum++;
            // 将当前质数i存入prime数组的第sum个位置（数组从1开始使用，而非默认的0）
            prime[sum] = i;
            // 内层循环：标记i的所有倍数为非质数（从2*i开始，步长为i）
            for (int j = 2*i;j<=x;j+=i ) {//就是i的倍数,把j标记为合数
                // 将i的倍数j标记为1（非质数）
                isPrime[j]=1;
            }
        }
    }

    // 遍历prime数组，打印所有筛选出的质数（从第1个到第sum个）
    for (int i = 1; i <= sum; i++) {
        cout << prime[i] << " ";
    }
    // 打印换行，优化输出格式（避免质数和后续内容连在一起）
    cout << endl;
}
/*欧拉筛法(线性筛)-->n*/
//x只能被它的最小质因数筛去
//使用欧拉筛（线性筛）算法找出所有小于等于x的质数
void isPrime_EulerSieve(int x) {
    int p[10005], sum = 0;//存储找到的质数
    bool isPrime[1000005] = {0}; // 标记数组：isPrime[i]=0表示i是质数，=1表示i是合数
    // 1不是质数,特殊处理
    isPrime[1] = 1;
    // 从2开始枚举所有数
    for (int i=2;i<=x;i++) {
        // 如果i是质数（未被标记为合数）
        if (isPrime[i] == 0) {
            sum++;            // 质数计数器增加
            p[sum]=i;       // 将质数i存入数组p
        }
        // 核心筛法部分：用当前数i乘以所有已找到的质数
        for (int j = 1; j <= sum; j++) {
            int tmp=p[j]*i;  // 产生合数p[j]*i
            //如果合数超出范围，终止内层循环
            if(tmp>x)break;
            // 标记该合数为非质数
            isPrime[tmp] = 1;
            // 保证每个合数只被其最小质因子筛掉一次
            if(i%p[j]==0)break;//核心代码
        }
    }
    // 输出所有找到的质数
    for (int i = 1; i <= sum; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}
//证明：假设没有59行(p[j]质数数组是单调增)
//当i % p[j] == 0时，对于任意p[k] > p[j],合数p[k] × i的最小质因数不是p[k],而是p[j]或者更小
//i%p[j]==0-->i=p[j]*m
//p[k]>p[j]-->N = p[k] × i = p[k] × (m × p[j]) = p[j] × (p[k] × m)
void m_isPrime(int x) {
    int p[10005], sum = 0;
    bool isprime[10005]={0};
    isprime[1]=1;
    for (int i=2;i<=x;i++) {
        if (isprime[i]==0) {
            sum++;
            p[sum]=i;
        }
        for (int j = 1; j <= sum; j++) {
            int tmp=p[j]*i;
            if (tmp>x)break;
            isprime[tmp] = 1;
            if (i%p[j]==0)break;
        }
    }
    for (int i = 1; i <= sum; i++) {
        cout << p[i] << " ";
    }
}

int main(){
int n;
    cin >> n;
    /*
    for (int i = 2; i <= n; i++) {
        if (isPrime_nomal(i)) {
            cout << i << endl;
        }
    }
    */
    // isPrime_EratosthenesSieve(n);
    isPrime_EulerSieve(n);
    return 0;
}
