#ifndef UNTITLED1_GRAPH_H
#define UNTITLED1_GRAPH_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include "MyParser.h"
#include <cmath>
#include <sstream>


using namespace std;
class Graph {
private:
    map<int, vector<int>> graph;    // Adjacency List
    map<int, double> page_rank_map;
public:
    Graph(){}
    int V;
    int E;

    void InsertEdge(int from, int to) {

        graph[to].push_back(from);
        if(graph.find(from) == graph.end())
            graph[from] = {};
    }

    // Returns vector<int> of inward connections for int in map<int, vector>
    vector<int> GetInward(int vertex) {

        if (graph.find(vertex) != graph.end())
            return graph[vertex];

        return {};
    }

    // Iterates through all connections in adjecency list and returns all vertices connected to vertex
    vector<int> GetOutward(int vertex) {

        vector<int> outwards;
        for (const auto &entry : graph) {
            if (entry.second.end() != find(entry.second.begin(), entry.second.end(), vertex))
                outwards.push_back(entry.first);
        }
        return outwards;
    }

    // Equivalent to PageRank Algorithm with p=1;
    void InitializePageRanks() {

        for (const auto &entry : graph) {
            page_rank_map[entry.first] = 1.0f / static_cast<double>(GetVertices());
        }
    }

    void PageRank(int p) {

        map<int, double> previous_page_rank_map = page_rank_map;
        while (p > 1) {
            map<int, double> new_page_rank_map;

            for (const auto &entry : graph) {
                int vertex = entry.first;
                double rank = 0.0f;
                vector<int> inwardVertices = GetInward(vertex);

                for (const auto &adj : inwardVertices) {
                    double outwardConnections = static_cast<double>(GetOutward(adj).size());
                    if (outwardConnections > 0) {
                        rank += previous_page_rank_map[adj] / outwardConnections;
                    }
                }

                new_page_rank_map[vertex] = rank;
            }

            previous_page_rank_map = new_page_rank_map;
            p--;
        }

        page_rank_map = previous_page_rank_map;
    }

    int GetVertices() {
        return MyParser::names.size();
    }

    void PrintPageRanks() {

        for (const auto &name : MyParser::names) {
            cout << name << " " << setprecision(2) << fixed << round(page_rank_map[MyParser::id_map[name]] * 100) / 100 << endl;
        }
    }

    vector<string> ReturnPageRanks() {

        vector<string> vec;
        for (const auto &name : MyParser::names) {
            ostringstream oss;
            oss << name << " " << setprecision(2) << fixed << round(page_rank_map[MyParser::id_map[name]] * 100) / 100;
            vec.push_back(oss.str());
        }
        return vec;
    }
};

#endif
