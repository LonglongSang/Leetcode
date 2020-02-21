/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void trace(int *count,int **ret,int **path,int i,int j,char dir,int *n);
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int **ret,**path,*a;
    *returnSize=n;
    if(n==0){
        *returnColumnSizes=a;
        return ret;      
    }

    a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) a[i]=n;
    *returnColumnSizes=a;

    ret=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) ret[i]=(int*)malloc(sizeof(int)*n);
    
    path=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) path[i]=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            path[i][j]=0;
    int count=1;
    trace(&count,ret,path,0,0,'r',&n);
    return ret;
}
void trace(int *count,int **ret,int **path,int i,int j,char dir,int *n){
    if((i>=0 && i<*n)&&(j>=0 && j<*n)){
        path[i][j]=1;
        ret[i][j]=(*count);
        (*count)++;
        switch(dir){
            case 'l':
                if(j-1>=0 && path[i][j-1]==0) trace(count,ret,path,i,j-1,dir,n);
                break;
            case 'r':
                if(j+1<*n && path[i][j+1]==0) trace(count,ret,path,i,j+1,dir,n);
                break;
            case 'u':
                if(i-1>=0 && path[i-1][j]==0) trace(count,ret,path,i-1,j,dir,n);
                break;
            case 'd':
                if(i+1<*n && path[i+1][j]==0) trace(count,ret,path,i+1,j,dir,n);
                break;
            default:
                break;
        }
        if(dir!='r' && j-1>=0 && path[i][j-1]==0){//l
            trace(count,ret,path,i,j-1,'l',n);
        }else if(dir!='l' && j+1<*n && path[i][j+1]==0){//r
            trace(count,ret,path,i,j+1,'r',n);
        }else if(dir!='d' && i-1>=0 && path[i-1][j]==0){//u
            trace(count,ret,path,i-1,j,'u',n);
        }else if(dir!='u' && i+1<*n && path[i+1][j]==0){//d
            trace(count,ret,path,i+1,j,'d',n);
        }else{
            return;
        }
    }
}
