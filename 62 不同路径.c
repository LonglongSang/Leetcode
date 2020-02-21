double fact(int a);
int uniquePaths(int m, int n){
    long path[m+1][n+1];
    for(int i=1;i<n+1;i++) path[1][i]=1;
    for(int j=1;j<m+1;j++) path[j][1]=1;
    for(int i=2;i<m+1;i++){
        for(int j=2;j<n+1;j++){
            path[i][j]=path[i-1][j]+path[i][j-1];
        }
    }
    double a=(fact(m+n-2)/(fact(m-1)*fact(n-1)));
    return (int)a;
    return path[m][n];
    
}
double fact(int a){
    if(a==1){
        return 1;
    }else{
        return a*fact(a-1);
    }
}
