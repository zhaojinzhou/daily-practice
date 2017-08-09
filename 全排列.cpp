//全排列的递归实现
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

vector<string> res;

//k表示当前选取到第几个数,m表示共有多少数.
void AllRange(char *pszStr, int k, int m)
{
    bool flag[m+1];
    if(k==m){
        
        res.push_back(pszStr);
        return;
    }
    
        for(int i= k; i<=m;i++){
            swap(pszStr[i],pszStr[k]);
            AllRange(pszStr,k+1,m);
            swap(pszStr[i],pszStr[k]);
       }
    
}
void Foo(char *pszStr)
{
	AllRange(pszStr, 0, strlen(pszStr) - 1);
}
int main()
{
	printf("         全排列的递归实现\n");
	printf("  --by MoreWindows( http://blog.csdn.net/MoreWindows )--\n\n");
	char szTextStr[] = "12345";
	printf("%s的全排列如下:\n", szTextStr);
	Foo(szTextStr);
	
	
	
    for(auto i = res.begin(); i!= res.end();i++)
    {
        cout<<*i<<endl;        
    }
    
    
	return 0;

}
