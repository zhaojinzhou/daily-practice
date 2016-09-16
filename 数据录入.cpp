#include <stdio.h>
#include<iostream>
#include<string>
using namespace std;
float fl;
int r;
FILE *f;
FILE *res;
class location{
    public:
    double x;
    double y;
    double z;

};


int  main() {
    f=fopen("aaaaa.txt","rb");
    res=fopen("result.txt","wb");

    double a;
    int index=0;
    int iNumofbasestation;
    int iNumofmobiledevice;
    int dimension;
    fscanf(f,"%d",&iNumofbasestation);
    fscanf(f,"%d",&iNumofmobiledevice);
    fscanf(f,"%d",&dimension);
    location *locationofbase= new location[iNumofbasestation];
    location *locationofmobile= new location[iNumofmobiledevice];

    for(int i=0;i<iNumofbasestation;i++)
    {
       fscanf(f,"%Lf\t%Lf\t%Lf\t",&locationofbase[i].x,&locationofbase[i].y,&locationofbase[i].z);
    }


    double inputdata[30];
    int i=0;
    while(1){
        i=fscanf(f,"%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\t",&inputdata[0],&inputdata[1],&inputdata[2],&inputdata[3],&inputdata[4],&inputdata[5],&inputdata[6],&inputdata[7],&inputdata[8],&inputdata[9],&inputdata[10],&inputdata[11],&inputdata[12],&inputdata[13],&inputdata[14],&inputdata[15],&inputdata[16],&inputdata[17],&inputdata[18],&inputdata[19],&inputdata[20],&inputdata[21],&inputdata[22],&inputdata[23],&inputdata[24],&inputdata[25],&inputdata[26],&inputdata[27],&inputdata[28],&inputdata[29]);
        fprintf(res,"%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t%0.14f\t\n",inputdata[0],inputdata[1],inputdata[2],inputdata[3],inputdata[4],inputdata[5],inputdata[6],inputdata[7],inputdata[8],inputdata[9],inputdata[10],inputdata[11],inputdata[12],inputdata[13],inputdata[14],inputdata[15],inputdata[16],inputdata[17],inputdata[18],inputdata[19],inputdata[20],inputdata[21],inputdata[22],inputdata[23],inputdata[24],inputdata[25],inputdata[26],inputdata[27],inputdata[28],inputdata[29]);
        if(i<0)break;

    }
    fclose(f);
	fclose(res);
	getchar();
    return 0;
}
