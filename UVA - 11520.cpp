//THIS IS NOT MY OWN SOLUTION
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
 
const int maxn = 12;
char map[maxn][maxn];
int n;
 
char fill(int row, int col){
    for(int ch='A'; ch<='Z'; ++ch){
        if(ch != map[row][col-1] && 
           ch != map[row][col+1] &&
           ch != map[row+1][col] &&
           ch != map[row-1][col] 
          ) 
        return ch;
    }
}
 
void solve(){
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) 
            if(map[i][j] == '.') 
                map[i][j] = fill(i,j);
    for(int i=1; i<=n; ++i) 
        puts(map[i]+1);
}
 
int main(){
    
    int T, cas=1;
    scanf("%d", &T);
    
    while(T--){
        printf("Case %d:\n", cas++);
        scanf("%d", &n);
        memset(map, 0, sizeof(map));
        for(int i=1; i<=n; ++i)
            scanf("%s", map[i]+1);
        solve(); 
    }
	return 0;
}
