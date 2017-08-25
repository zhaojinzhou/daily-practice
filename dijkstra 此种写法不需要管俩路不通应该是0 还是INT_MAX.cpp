// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
 
#include <stdio.h>
#include <limits.h>
 
// Number of vertices in the graph
#define V 9
 
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed distance array
int printSolution(int dist[], int n,int pre[],int src)
{
	int j;
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++){
   	  printf("%d \t\t %d\n", i, dist[i]);
   	  j=i;
   		while(j!=src){
		   	printf("%d--",j);
		   	j=pre[j];
		   	
		   }
		   printf("\n");   
   }
   
    
      
   
}
 
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
   int distance[V];
   int pre[V];
   bool flag[V];
   for (int i=0;i<V;i++){
   distance[i]=INT_MAX;
   flag[i]=0;	
   }
   
   distance[src]=0;
	
      /*!!!!!!!!!!attention!!!!!!!!!!!!!!!*/
   //注意一定不能再这里把flag[src]置1。原因是查找最小函数的时候，不把flag=1的列入比较范围，这样导致找不到最小，无法更新distance;
     /*!!!!!!!!!!attention!!!!!!!!!!!!!!!*/
	
   for(int i=0;i<V;i++){
   	int u=minDistance(distance,flag);
   	flag[u]=1;
   	for(int j=0;j<V;j++){
	   	
   		if(flag[j]==0&&graph[u][j]!=0&&distance[j]>distance[u]+graph[u][j]){
		distance[j]=distance[u]+graph[u][j];
		pre[j]=u;	   	
	      	
		   }
   		}
   }
   
   
   printSolution(distance,V,pre,src);
}
 
// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 
    dijkstra(graph, 0);
 
    return 0;
}

