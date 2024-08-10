#ifndef UNTITLED1_MYPARSER_H
#define UNTITLED1_MYPARSER_H
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

class MyParser {
public:
    static map<string, int> id_map;
    static map<int, string> name_map;
    static set<string> names;
    static int id_level;

    // Necessary for catch-tests where MyParser will be reused
    static void Initialize(){
        id_map.clear();
        name_map.clear();
        names.clear();
        id_level = 0;
    }
    static pair<int, int> GetIDs(string from, string to) {
        int to_id = -1;
        int from_id = -1;

        //Process to
        if (names.insert(to).second) {  // To string never seen before
            to_id = id_level++;
            id_map[to] = to_id;
            name_map[to_id] = to;
        } else {
            to_id = id_map[to];
            name_map[to_id] = to;
        }

        //Process from
        if (names.insert(from).second) {    // From string never seen before
            from_id = id_level++;
            id_map[from] = from_id;
            name_map[to_id] = to;
        } else {
            from_id = id_map[from];
            name_map[to_id] = to;
        }

        return make_pair(from_id, to_id);
    }

    static pair<string, string> SplitFromTo(string connection){
        bool spaced = false;
        string from;
        string to;

        for(char i : connection){
            if(i == ' '){ spaced = true; continue;}
            if(!spaced) from.push_back(i);
            if(spaced) to.push_back(i);
        }
        pair<string, string> from_to(from, to);
        return from_to;

    }

};


map<string, int> MyParser::id_map;
set<string> MyParser::names;
int MyParser::id_level = 0;
map<int, string> MyParser::name_map;

#endif // UNTITLED1_MYPARSER_H
