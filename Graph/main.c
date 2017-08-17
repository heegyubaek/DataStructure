/*
 * main.c
 *
 *  Created on: Aug 16, 2017
 *      Author: baekhg
 */


#include "Graph.h"

int main()
{
    Graph *graph = New_Graph();

    Graph_AddVertex(graph, "A");
    Graph_AddVertex(graph, "B");
    Graph_AddVertex(graph, "C");
    Graph_AddVertex(graph, "D");
    Graph_AddVertex(graph, "E");
    Graph_AddVertex(graph, "F");
    Graph_AddVertex(graph, "G");
    Graph_AddVertex(graph, "H");

    Graph_AddEdge(graph, "A", "B", 5);
    Graph_AddEdge(graph, "A", "D", 4);
    Graph_AddEdge(graph, "A", "E", 4);
    Graph_AddEdge(graph, "B", "D", 4);
    Graph_AddEdge(graph, "B", "H", 2);
    Graph_AddEdge(graph, "C", "D", 2);
    Graph_AddEdge(graph, "C", "G", 3);
    Graph_AddEdge(graph, "D", "H", 5);
    Graph_AddEdge(graph, "D", "E", 5);
    Graph_AddEdge(graph, "D", "F", 3);
    Graph_AddEdge(graph, "E", "F", 3);
    Graph_AddEdge(graph, "F", "G", 6);
    Graph_AddEdge(graph, "G", "H", 3);

    Graph_View(graph);
    Delete_Graph(graph);

    return 0;

}


