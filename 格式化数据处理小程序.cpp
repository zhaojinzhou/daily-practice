#include <stdio.h>
int i,j,sum1,sum2;
float fl;
int r;
FILE *f;
int  main() {
    f=fopen("aaaaa.txt","r");
    int i=0;
    while (1) {
        r=fscanf(f,"%f%% : %d of %d",&fl,&i,&j);
        if (r>0) {
            printf("%d of %d\n",i,j);
				} 
		else if(-1==r){
            printf("success");
            break;
			} 
		else{
			printf("请检查文件---输入格式有问题\n");
			break;
		}
        i++;
    }
    fclose(f);
    
    return 0;
}