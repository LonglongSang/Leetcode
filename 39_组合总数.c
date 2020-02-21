/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void check(int index,int **ret,int *candidates,int candidatesSize,int target,int *a,int *row_count,int col_count);
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int **ret;
    int *a;
    if(candidatesSize==0){
        printf("in last\n");    
        *returnSize=0;
        *returnColumnSizes=a;
        return ret;
    }
    int min=0x7fffffff;
    for(int i=0;i<candidatesSize;i++) if(candidates[i]<min) min=candidates[i];
    int row=150,col=target/min;
    ret=(int**)malloc(sizeof(int*)*row);
    a=(int*)malloc(sizeof(int)*row);//
    for(int i=0;i<row;i++) ret[i]=(int*)malloc(sizeof(int)*col);
    int sign=10000000;
    for(int i=1;i<row;i++){
        for(int j=0;j<col;j++){    
            ret[i][j]=sign;
        }
    }
    int row_count=0;
    check(0,ret,candidates,candidatesSize,target,a,&row_count,0);
    for(int i=1;i<row_count;i++){
        for(int j=0;j<a[i];j++){
            if(ret[i][j]==sign) ret[i][j]=ret[i-1][j];
        }
    }
    *returnSize=row_count;
    *returnColumnSizes=a;
    return ret;
}
void check(int index,int **ret,int *candidates,int candidatesSize,int target,int *a,int *row_count,int col_count){
    if(index==candidatesSize-1){
        for(int i=0;i<=(target/candidates[index]);i++){
            if(target-i*candidates[index]==0){
                for(int j=0;j<i;j++) ret[*row_count][col_count++]=candidates[index];
                a[(*row_count)++]=col_count;
                break;
            }else if(target-i*candidates[index]<0){
                break;
            }
        }        
    }else{
        int range=(target/candidates[index]);

        for(int i=0;i<=range;i++){
            int cal=i*candidates[index];
            //printf("can is %d,now is %d,range is %d,my mul is %d\n",candidates[index],target-cal,range,i);
            int now_count=col_count;
            if(target-cal==0){
                for(int j=0;j<i;j++) ret[*row_count][col_count++]=candidates[index];
                a[(*row_count)++]=col_count;
                break;
            }else if(target-cal>0){
                for(int j=0;j<i;j++) ret[*row_count][now_count++]=candidates[index];
                int call=target-cal;
                check(index+1,ret,candidates,candidatesSize,call,a,row_count,now_count);
            }else{
                break;
            }
        }
    }
}
