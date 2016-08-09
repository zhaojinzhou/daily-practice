#include <stdio.h>
#include <malloc.h>
#define VERTEXNUM 5

void createGraph(int (*edge)[VERTEXNUM], int start, int end);
void displayGraph(int (*edge)[VERTEXNUM]);
void DFT(int (*edge)[VERTEXNUM],int* vertexStatusArr);
void DFTcore(int (*edge)[VERTEXNUM],int i,int* vertexStatusArr);

int main(void){
		//��̬������űߵĶ�ά����
        int (*edge)[VERTEXNUM] = (int (*)[VERTEXNUM])malloc(sizeof(int)*VERTEXNUM*VERTEXNUM);
        int i,j;
        for(i=0;i<VERTEXNUM;i++){
                for(j=0;j<VERTEXNUM;j++){
                        edge[i][j] = 0;
                }
        }
		//��Ŷ���ı���״̬��0��δ������1���ѱ���  
        int* vertexStatusArr = (int*)malloc(sizeof(int)*VERTEXNUM);
        for(i=0;i<VERTEXNUM;i++){
                vertexStatusArr[i] = 0;
        }
		
        printf("after init:\n");
        displayGraph(edge);
		//����ͼ
        createGraph(edge,0,3);
        createGraph(edge,0,4);
        createGraph(edge,3,1);
        createGraph(edge,3,2);
        createGraph(edge,4,1);

        printf("after create:\n");
        displayGraph(edge);
		//������ȱ���
        DFT(edge,vertexStatusArr);

        free(edge);
        return 0;
}
//����ͼ 
void createGraph(int (*edge)[VERTEXNUM], int start, int end){
        edge[start][end] = 1;
}
//��ӡ�洢��ͼ
void displayGraph(int (*edge)[VERTEXNUM]){
        int i,j;
        for(i=0;i<VERTEXNUM;i++){
                for(j=0;j<VERTEXNUM;j++){
                        printf("%d ",edge[i][j]);
                }
                printf("\n");
        }
}
//������ȱ���
void DFT(int (*edge)[VERTEXNUM], int* vertexStatusArr){
        printf("start BFT graph:\n");
        int i;
        for(i=0;i<VERTEXNUM;i++){
                DFTcore(edge,i,vertexStatusArr);
        }
        printf("\n");
}
void DFTcore(int (*edge)[VERTEXNUM],int i,int* vertexStatusArr){
        if(vertexStatusArr[i] == 1){
                return;
        }
        printf("%d ",i);
        vertexStatusArr[i] = 1;

        int j;
        for(j=0;j<VERTEXNUM;j++){
                if(edge[i][j] == 1){
                        DFTcore(edge, j, vertexStatusArr);
                }
        }
}