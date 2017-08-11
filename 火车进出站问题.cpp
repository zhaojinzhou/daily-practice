判断该序列是否可能是出栈序列


火车进出站问题：

大致的思路是：

出栈序列的特征是----任意数后的比之小的序列一定是倒序。

转化为程序的思想就是：
1.双层循环遍历；
2.找到该数A后的第一个比他小的数记为B，确保此后比A小的数都比B小。     // 此句递归可以确保倒序；已程序验证。





/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2013/08/10
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2013/08/10
    Author      : 
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*
详细描述：   
int JudgeTrainSequence (int maxNum, char *pOutSeq);
输入参数：
	 	int maxNum：进站的火车最大编号
	 	char* pOutSeq：使用字符串表示火车出站序列
输出参数（指针指向的内存区域保证有效）：
	 	无。
返回值：
		Int: 根据输入的进站序列判断，如果输入的出战序列是可能的，返回1，否则返回0；

*/

int JudgeTrainSequence (int maxNum, char *pOutSeq)
{
	if(maxNum<1 || maxNum>9)
	{
		return 0;
	}
	/*
	if(pOutSeq == 0)
	{
		return 0;
	}
	*/

	int length = strlen(pOutSeq);
	int *num = (int *)malloc(length*sizeof(int));
	memset(num,0,length);
	
	int i=0;
	while(pOutSeq[i]!='\0')
	{
		num[i] = pOutSeq[i]-'0';
		printf("%d",num[i]);
		i++;
	}
	int j,k;
	//从num[0]开始逐个选择元素
	for(j=0;j<length;j++)
	{
		int flag = num[j];
		int max = 0;
		int sw = 0;
		for(k=j+1;k<length;k++)
		{
			//找出比num[j]小的元素
			if(num[k]<flag)
			{
				//降序排列
				if(sw==0)
				{
					max = num[k];
				}
				sw = 1;

				
				if(num[k]>max)
				{
					return 0;
				}
			}
		}
	}
	return 1;
	
}

