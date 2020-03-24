#include <stdio.h>
#define MAX 503
#define max(a,b) a>b?a:b

double dp[7][7][7][1001];

int max3(int a,int b,int c){
    return max(max(a,b),c);
}
int prize(int i,int j,int k){
    if(i==j&j==k) return 10000+i*1000;
    else if(i==j) return 1000+i*100;
    else if(j==k) return 1000+j*100;
    else if(k==i) return 1000+k*100;
    else return max3(i,j,k)*100;
}
double dice(int i,int j,int k,int cur,int N){
    double curPrize = (double)prize(i,j,k);
    if(cur==N)return curPrize;

    if(dp[i][j][k][cur]) return curPrize;

    double next =0;
    for(int s=1;s<=6;s++){
        next+=dice(j,k,s,cur+1,N);
    }
    dp[i][j][k][cur]=max(next/6,curPrize);

    return max(next/6,curPrize);
}
int main(){
    int N;
    scanf("%d",&N);

    double ans=0;
    int cur=3;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            for(int k=1;k<=6;k++){
                ans+=dice(i,j,k,3,N);
            }
        }
    }
    printf("%lf",ans/(6*6*6));
}

//ctrl+shift+B  gcc_compile     build
//ctrl+P    task execute_c      execute