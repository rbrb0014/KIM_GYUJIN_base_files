#include <stdio.h>
#define MAX 503
#define max(a,b) a>b?a:b

int main (){
    int sum=0;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            for(int k=1;k<=6;k++){
                if(i==j&&j==k){
                    sum+=10000+i*1000;
                }else if(i==j||j==k||k==i){
                    if(i==j) 1000+i*100;
                    else if(j==k) 1000+j*100;
                    else 1000+k*100;
                }else{
                    sum+=max(max(i,j),k)*100;
                }
            }
        }
    }
    printf("%d",sum);
}

//ctrl+shift+B  gcc_compile     build
//ctrl+P    task execute_c      execute