#include <stdio.h>
#include<iostream>
using namespace std;
int i,j,sum1=0,sum2=0;
float fl;
int r;
FILE *f;
FILE *res;
int  main() {
    f=fopen("aaaaa.txt","r");
    res=fopen("result.txt","w");
    int index=0;
  	char  s[1024];
  	 while(1){
	   	while (1) {
	        r=fscanf(f,"%f%% : %d of %d",&fl,&i,&j);
	        if (r>0) {
	          //  printf("%d of %d\n",i,j);
	            
	            sum1+=i;
	            sum2+=j;
					} 
			else if(-1==r){     //文件指针如果走到文件末尾 返回-1； 
	            printf("success\n");	            
	            fprintf(res,"%d%/%d\n",sum1,sum2);
				break;
				} 
			else{     //如果格式不对，返回0；提示信息。并将此前的总数打印。 总数全部置零。 
				
				printf("请检查文件第%d行输入格式有问题\n",index+1);
				
				fprintf(res,"%d%/%d\n",sum1,sum2);
				sum2=0;
				sum1=0;
				fgets(s,1024,f);   //如果格式不对，吧这一行跳过继续运行。
				//return 0;
				break;
				} 
			index++;
	   	 }	
 	 
		if(-1==r||index==10000)//index 用来控制行数！！最多是多少行。 
		break;
		
		
	   }
    
	fclose(f);
	fclose(res);
    return 0;
}