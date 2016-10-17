#include <string>
#include <string.h>
#include <io.h>
#include <vector>
#include <stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

/************************************************************************/
/*  获取文件夹下所有文件名
    输入：
		path	:	文件夹路径
		exd		:   所要获取的文件名后缀，如jpg、png等；如果希望获取所有
					文件名, exd = ""
	输出：
		files	:	获取的文件名列表

	shao, 20140707
*/
/************************************************************************/
void getFiles( string path, string exd, vector<string>& files )
{
	//文件句柄
	long   hFile   =   0;
	//文件信息
	struct _finddata_t fileinfo;
	string pathName, exdName;

	if (0 != strcmp(exd.c_str(), ""))
	{
		exdName = "\\*." + exd;
	}
	else
	{
		exdName = "\\*";
	}

	if((hFile = _findfirst(pathName.assign(path).append(exdName).c_str(),&fileinfo)) !=  -1)
	{
		do
		{
			//如果是文件夹中仍有文件夹,迭代之
			//如果不是,加入列表
			if((fileinfo.attrib &  _A_SUBDIR))
			{
				if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
					getFiles( pathName.assign(path).append("\\").append(fileinfo.name), exd, files );
			}
			else
			{
				if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
					files.push_back(fileinfo.name);
			}
		}while(_findnext(hFile, &fileinfo)  == 0);
		_findclose(hFile);
	}
}

int main()
{
    FILE *file1;
    cout<<"直接显示请输入1；文件显示请输入2"<<endl;

    int flag;
    cin>>flag;
    while(flag!=1&&flag!=2)
    {
        cout<<"输入错误请重新输入"<<endl;
        cin>>flag;
    }

    cout<<"请输入要找的文件名后缀名;如果要所有的文件请输入*"<<endl;
    char * exdtend= new char [256];
    cin>>exdtend;

    string a;
    cout<<"请输入路径"<<endl;
    cin>>a;

	const char * filePath =a.c_str();

	vector<string> files;

	//获取该路径下的所有jpg文件
	getFiles(filePath, exdtend, files);

	delete []exdtend;
	int size = files.size();
	cout<<"一共有"<<size-1<<"个文件"<<endl;


	if(flag==1){
        for (int i = 0;i < size;i++)
        {
            cout<<files[i].c_str()<<endl;
        }
	}
	else{
        file1=fopen("result.txt","w");
        for (int i = 0;i < size;i++)
        {
            fprintf(file1,"%s\n",files[i].c_str());
        }
        fclose(file1);
	}

	getchar();

	return 0;
}
