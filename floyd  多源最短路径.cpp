#include<iostream>
#include <memory.h>
#include<vector>
#define max 1000
using namespace std;
int NODE=9; //���ڽӾ���Ĵ�С���ݶ�����������ٲ�������

void floyd(int distmap[9][9],//�ɱ����µ��ڽӾ��󣬸��º���ȷ��ԭ�б�
           int  path[9][9])//·���ϵ���õ����ת��

{
	for(int k=1; k!=NODE; ++k)//����ÿһ����ת��
        for(int i=0; i!=NODE; ++i)//ö��Դ��
            for(int j=0; j!=NODE; ++j)//ö���յ�
                if(distmap[i][j]>distmap[i][k]+distmap[k][j])//���������ǲ���ʽ
                {
                    distmap[i][j]=distmap[i][k]+distmap[k][j];//����
                    path[i][j]=k;//��¼·��
                }
}

void print( int &beg, int &end,
           int path [9][9])//�����ã����⿽������ռ���ڴ�ռ�
           //Ҳ������ջ�ṹ�Ƚ���������������溯���ݹ� 
{
    if(path[beg][end]>=0)
    {
        print(beg,path[beg][end],path);
        print(path[beg][end],end,path);
    }
    else cout<<"->"<<end;
    
    
}
int main()
{
    int beg,end;//�������
    int path [9][9];
    memset(path,-1,sizeof(path));
   
    int distmap[9][9]={{max, 4, max, max, max, max, max, 8, max},
                      {4, max, 8, max, max, max, max, 11, max},
                      {max, 8, max, 7, max, 4, max, max, 2},
                      {max, max, 7, max, 9, 14, max, max, max},
                      {max, max, max, 9, max, 10, max, max, max},
                      {max, max, 4, max, 10, max, 2, max, max},
                      {max, max, max, 14, max, 2, max, 1, 6},
                      {8, 11, max, max, max, max, 1, max, 7},
                      {max, max, 2, max, max, max, 6, 7, max}
                     };

	for(int i=0;i<9;i++)
	{
	for(int j=0;j<9;j++)
	{
	
	cout<<path[i][j]<<' ';
    }cout<<endl;
	}
	
    
    floyd(distmap,path);
    cout<<"�������";
    
    cout<<endl;
    	for(int i=0;i<9;i++)
	{
	for(int j=0;j<9;j++)
	{
	
	cout<<path[i][j]<<' ';
    }cout<<endl;
	}
    for(int i=0;i<9;i++)
	{
	for(int j=0;j<9;j++)
	{
	
	cout<<distmap[i][j]<<' ';
    }cout<<endl;
	}

    cin>>beg>>end;
    cout<<"��̾���Ϊ"<<distmap[beg][end]<<endl;
   print(beg,end,path);
   
}