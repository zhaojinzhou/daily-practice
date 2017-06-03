//#include "header.h"	//AnycodeX includes the header.h by default, needn't cancle the notation.
#include <iostream>
using namespace std;
#define PROC int code = 0XFFFF; int line = 0XFFFE;{
#define ENDPROC }  tab:
#define JUDGE(ptr) if (ptr == NULL) THROW();
#define THROW() goto tab;
#define CATCH code =123;line=__LINE__;cout<<line<<'\t'<<code;

    
int main()
{
    PROC
    int *a = NULL;
    JUDGE(a);
    ENDPROC
    CATCH;
	
	return 0;
}