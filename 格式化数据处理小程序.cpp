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
			else if(-1==r){     //�ļ�ָ������ߵ��ļ�ĩβ ����-1�� 
	            printf("success\n");	            
	            fprintf(res,"%d%/%d\n",sum1,sum2);
				break;
				} 
			else{     //�����ʽ���ԣ�����0����ʾ��Ϣ��������ǰ��������ӡ�� ����ȫ�����㡣 
				
				printf("�����ļ���%d�������ʽ������\n",index+1);
				
				fprintf(res,"%d%/%d\n",sum1,sum2);
				sum2=0;
				sum1=0;
				fgets(s,1024,f);   //�����ʽ���ԣ�����һ�������������С�
				//return 0;
				break;
				} 
			index++;
	   	 }	
 	 
		if(-1==r||index==10000)//index ��������������������Ƕ����С� 
		break;
		
		
	   }
    
	fclose(f);
	fclose(res);
	getchar();
    return 0;
}