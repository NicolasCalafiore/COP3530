#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "MyParser.h"
#include "Graph.h"
using namespace std;



int main()
{
    int no_of_lines, power_iterations;
    std::string from, to;
    std::cin >> no_of_lines;
    std::cin >> power_iterations;

    Graph graph;

    for(int i = 0; i < no_of_lines; i++)
    {
        cin >> from >> to;
        pair<int, int> ids = MyParser::GetIDs(from, to);
        graph.InsertEdge(ids.first, ids.second);
    }

    graph.InitializePageRanks();
    graph.PageRank(power_iterations);
    graph.PrintPageRanks();

}