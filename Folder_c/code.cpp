#include <stdio.h>
#include <vector>
#define INF 1000000
using namespace std;
vector<vector<int>> adj;


int main (){
    int n, in1,in2;
    printf("how many nodes there? : ");
    scanf("%d", n);
    adj.resize(n);

    printf("write the edge like n m. if finished, input 0.\n");
    for(int i=0;i<n;i++){
        printf("%d",scanf("%d %d",in1,in2));
    }

}

//ctrl+shift+B  gcc_compile     build
//ctrl+P    task execute_c      execute