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
    bool flag[V]={0};
    int pre[V];
	int u;
    int distance[V];
    for(int i=0;i<V;i++)
    {distance[i]=graph[src][i];
    if(distance[i]!=INT_MAX)
    pre[i]=src;
    else
    pre[i]=-1;
	}
    distance[src]=0;
    flag[src]=1;
    for(int j=1;j<V;j++){
    	u=minDistance(distance,flag);
		flag[u]=true;
		for(int i=0;i<V;i++)
		if(!flag[i]&&graph[u][i]!=INT_MAX&&((distance[u]+graph[u][i])<distance[i]))
		{distance[i]=	(distance[u]+graph[u][i]);
		pre[i]=u;
		}
		
    }
     printSolution(distance, V,pre,0);
}
 
// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 8, INT_MAX},
                      {4, INT_MAX, 8, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 11, INT_MAX},
                      {INT_MAX, 8, INT_MAX, 7, INT_MAX, 4, INT_MAX, INT_MAX, 2},
                      {INT_MAX, INT_MAX, 7, INT_MAX, 9, 14, INT_MAX, INT_MAX, INT_MAX},
                      {INT_MAX, INT_MAX, INT_MAX, 9, INT_MAX, 10, INT_MAX, INT_MAX, INT_MAX},
                      {INT_MAX, INT_MAX, 4, INT_MAX, 10, INT_MAX, 2, INT_MAX, INT_MAX},
                      {INT_MAX, INT_MAX, INT_MAX, 14, INT_MAX, 2, INT_MAX, 1, 6},
                      {8, 11, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 1, INT_MAX, 7},
                      {INT_MAX, INT_MAX, 2, INT_MAX, INT_MAX, INT_MAX, 6, 7, INT_MAX}
                     };
 
    dijkstra(graph, 0);
 
    return 0;
}

