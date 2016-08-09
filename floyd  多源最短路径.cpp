#include<iostream>
#include <memory.h>
#include<vector>
#define max 1000
using namespace std;
int NODE=9; //用邻接矩阵的大小传递顶点个数，减少参数传递

void floyd(int distmap[9][9],//可被更新的邻接矩阵，更新后不能确定原有边
           int  path[9][9])//路径上到达该点的中转点

{
	for(int k=1; k!=NODE; ++k)//对于每一个中转点
        for(int i=0; i!=NODE; ++i)//枚举源点
            for(int j=0; j!=NODE; ++j)//枚举终点
                if(distmap[i][j]>distmap[i][k]+distmap[k][j])//不满足三角不等式
                {
                    distmap[i][j]=distmap[i][k]+distmap[k][j];//更新
                    path[i][j]=k;//记录路径
                }
}

void print( int &beg, int &end,
           int path [9][9])//传引用，避免拷贝，不占用内存空间
           //也可以用栈结构先进后出的特性来代替函数递归 
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
    int beg,end;//含义见下
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
    cout<<"计算完毕";
    
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
    cout<<"最短距离为"<<distmap[beg][end]<<endl;
   print(beg,end,path);
   
}