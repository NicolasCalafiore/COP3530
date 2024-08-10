//
// Created by nicol on 7/16/2024.
//
#include <string>
#include "MyParser.h"
#include "Graph.h"

#ifndef UNTITLED1_INPUT_H
#define UNTITLED1_INPUT_H
using namespace std;
class Input{

public:

    // Used to insert predefined connections without using cin - Used for catch tests
    static Graph ReadData(const vector<string>& connections){

        Graph graph;
        MyParser::Initialize();

        for(string i : connections){
            pair<string, string> from_to = MyParser::SplitFromTo(i);
            pair<int, int> from_id_to_id = MyParser::GetIDs(from_to.first, from_to.second);
            graph.InsertEdge(from_id_to_id.first, from_id_to_id.second);

        }

        return graph;
    }
};
#endif //UNTITLED1_INPUT_H
