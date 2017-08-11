/*
 * DirectedGraph.c
 *
 *  Created on: Aug 11, 2017
 *      Author: baekhg
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct
{
    int vn;
    int **matrix;
}Graph;

Graph *NewGraph(int max_vertex);
void DeleteGraph(Graph *graph);
void AddEdge(Graph *graph, int start, int goal);
void ViewGraph(Graph *graph);
void ViewIndegree(Graph *g);
void ViewOutdegree(Graph *g);

int main(void)
{
    Graph *graph;
    graph = NewGraph(6);
    AddEdge(graph, 0, 1);
    AddEdge(graph, 3, 1);
    AddEdge(graph, 2, 4);
    AddEdge(graph, 4, 2);

    ViewGraph(graph);
    ViewIndegree(graph);
    ViewOutdegree(graph);
    DeleteGraph(graph);

    return 0;
}

Graph *NewGraph(int max_vertex)
{
    int i = 0;
    Graph *graph = (Graph*)malloc(sizeof(Graph));

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
}

void ViewGraph(Graph *graph)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < graph->vn; i++)
    {
        printf("The vertex from %d: ",i);
        for(j = 0; j < graph->vn; j++)
        {
            if(graph->matrix[i][j])
            {
                printf("%d", j);
            }
        }
        printf("\n");
    }
}

void ViewIndegree(Graph *g)
{
    int i,j;
    int degree;
    printf("In-degree\n");

    for(i = 0; i < g->vn; i++)
    {
        degree = 0;
        for(j = 0; j < g->vn; j++)
        {
            if(g->matrix[j][i])
            {
                degree++;
            }
        }
        printf("%d", degree);
    }
    printf("\n");
}

void ViewOutdegree(Graph *g)
{
    int i,j;
    int degree;
    printf("Out-degree\n");
    for(i = 0; i < g->vn; i++)
    {
        degree = 0;
        for(j = 0; j < g->vn; j++)
        {
            if(g->matrix[i][j])
            {
                degree++;
            }
        }
        printf("%d", degree);
    }
    printf("\n");
}
