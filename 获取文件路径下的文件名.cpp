#include <string>
#include <string.h>
#include <io.h>
#include <vector>
#include <stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

/************************************************************************/
/*  ��ȡ�ļ����������ļ���
    ���룺
		path	:	�ļ���·��
		exd		:   ��Ҫ��ȡ���ļ�����׺����jpg��png�ȣ����ϣ����ȡ����
					�ļ���, exd = ""
	�����
		files	:	��ȡ���ļ����б�

	shao, 20140707
*/
/************************************************************************/
void getFiles( string path, string exd, vector<string>& files )
{
	//�ļ����
	long   hFile   =   0;
	//�ļ���Ϣ
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
			//������ļ����������ļ���,����֮
			//�������,�����б�
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
    cout<<"ֱ����ʾ������1���ļ���ʾ������2"<<endl;

    int flag;
    cin>>flag;
    while(flag!=1&&flag!=2)
    {
        cout<<"�����������������"<<endl;
        cin>>flag;
    }

    cout<<"������Ҫ�ҵ��ļ�����׺��;���Ҫ���е��ļ�������*"<<endl;
    char * exdtend= new char [256];
    cin>>exdtend;

    string a;
    cout<<"������·��"<<endl;
    cin>>a;

	const char * filePath =a.c_str();

	vector<string> files;

	//��ȡ��·���µ�����jpg�ļ�
	getFiles(filePath, exdtend, files);

	delete []exdtend;
	int size = files.size();
	cout<<"һ����"<<size-1<<"���ļ�"<<endl;


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
