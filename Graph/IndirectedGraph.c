/*
 * IndirectedGraph.c
 *
 *  Created on: Aug 11, 2017
 *      Author: baekhg
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct
{
    int vn; //number of vertex
    int **matrix; //adjacency matrix of graph
}Graph;

Graph *MakeGraph();
void ViewNeighbors(Graph *g);
void DeleteGraph(Graph *graph);

int main(void)
{
    Graph *graph;
    graph = MakeGraph();
    ViewNeighbors(graph);
    DeleteGraph(graph);
    return 0;
}

Graph *NewGraph(int max_vertex);
void AddEdge(Graph *graph, int start, int goal);
Graph *MakeGraph()
{
    Graph *graph;
    graph = NewGraph(9);
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 2);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 1, 3);
    AddEdge(graph, 2, 4);
    AddEdge(graph, 3, 6);
    AddEdge(graph, 4, 5);
    AddEdge(graph, 4, 6);
    AddEdge(graph, 4, 7);
    AddEdge(graph, 6, 8);
    return graph;
}

Graph *NewGraph(int max_vertex)
{
    int i = 0;
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vn = max_vertex;
    graph->matrix = (int **)malloc(sizeof(int*) * max_vertex);
    for(i = 0; i < max_vertex; i++)
    {
        graph->matrix[i] = (int *)malloc(sizeof(int) * max_vertex);
        memset(graph->matrix[i], 0, sizeof(int) * max_vertex);
    }
    return graph;
}

void DeleteGraph(Graph *graph)
{
    int i = 0;

    for(i = 0; i < graph->vn; i++)
    {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}

void AddEdge(Graph *graph, int start, int goal)
{
    graph->matrix[start][goal] = 1;
    graph->matrix[goal][start] = 1;
}

void ViewNeighbor(Graph *g, int vt);
void ViewNeighbors(Graph *g)
{
    int i = 0;
    printf("neighbors vertex\n");

    for(i = 0; i < g->vn; i++)
    {
        printf("%d neighbor: ",i);
        ViewNeighbor(g,i);
        printf("\n");
    }
}

void ViewNeighbor(Graph *g, int vt)
{
    int i;
    for(i = 0; i < g->vn; i++)
    {
        if(g->matrix[vt][i])
        {
            printf("%d",i);
        }
    }
}

