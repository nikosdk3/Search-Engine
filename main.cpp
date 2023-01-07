//  Nikos Kotsopulos
//  Project 2 - Search
//  Description - main.cpp: driver code that uses search engine functions to debug and run tests.

#include <iostream>
#include <fstream>
#include <string>
#include "search.h"
using namespace std;

int main()
{
    // string data = "tiny.txt";
    // map<string, set<string>> myMap;
    // map<string, set<string>>::iterator iter;//used to print each element in the inverted index and its pairs
    // ifstream inFS;
    // inFS.open(data);
    // // //test for gatherTokens and cleanToken
    // while (inFS.good())
    // {
    //     getline(inFS, data);
    //     gatherTokens(data);
    // }
    // inFS.close();
    // //test for buildIndex
    // buildIndex("uiccs-news.txt", myMap);
    // // //using tiny.txt as parameter in buildIndex to test inverted index since cplusplus.txt would be too big
    // for (iter = myMap.begin(); iter != myMap.end(); iter++)
    // {
    //     cout << iter->first << " : ";
    //     for (set<string>::iterator it = iter->second.begin(); it != iter->second.end(); ++it)
    //     {
    //         cout << "[" << *it << "] ";
    //     }
    //     cout << endl;
    // }
    // set<string> res = findQueryMatches(myMap, "vector +bool -ratio");//using test with each of the modifiers
    // for (set<string>::iterator it = res.begin(); it != res.end(); ++it)
    //     cout << *it << endl; // printing out each webpage to make sure it matches piazza output
    searchEngine("uiccs-news.txt");
    // return 0;
}
