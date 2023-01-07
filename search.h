//  Nikos Kotsopulos
//  Project 2 - Search
//  Description - header file: Mini search engine that cleans the text files and uses a query to
//                match the webpages containing the query terms.

#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

// cleans each token based on if there is punctuation at the beginning or end of each word.
// helper function for gatherTokens
string cleanToken(string s)
{
    string newstring;
    int count = 0;
    for (long unsigned int i = 0; i < s.size(); i++) // clean beginning of token.
    {
        if (ispunct(s[i]))
        {
            s.erase(i, 1);
            i--; // decrement i because we are erasing the letter but still incrementing i. Used as an offset.
        }
        else
            break;
    }
    for (long unsigned int i = s.size() - 1; i >= 0; i--) // clean the end of the token.
    {
        if (ispunct(s[i]))
        {
            s.erase(i, 1);
        }
        else
            break;
    }
    for (long unsigned int i = 0; i < s.size(); i++) // convert to lowercase letters and check if there are any alphabetical characters.
    {
        newstring += tolower(s[i]);
        if (isalpha(s[i]))
            count++;
    }
    if (count == 0) // return empty string if there are no alphabetical characters.
        return "";
    return newstring;
}

// creative component
// uncomment lines 92-95 to execute creative component
vector<string> stopwords() // list of stopwords used in gatherTokens to shorten index.
{
    vector<string> stopwords;
    stopwords.push_back("the");
    stopwords.push_back("and");
    stopwords.push_back("if");
    stopwords.push_back("a");
    stopwords.push_back("an");
    stopwords.push_back("another");
    stopwords.push_back("for");
    stopwords.push_back("nor");
    stopwords.push_back("but");
    stopwords.push_back("or");
    stopwords.push_back("yet");
    stopwords.push_back("so");
    stopwords.push_back("in");
    stopwords.push_back("under");
    stopwords.push_back("towards");
    stopwords.push_back("before");
    stopwords.push_back("to");
    return stopwords;
}

// function used to separate the body text into individual words and insert them into a set
set<string> gatherTokens(string text)
{
    set<string> tokens;
    stringstream tokenize(text);
    string token;
    while (tokenize >> token) // separating each token
    {
        if (!cleanToken(token).empty()) // do not insert empty strings into set
        {
            tokens.insert(cleanToken(token));
            // for(int i = 0; i<stopwords().size();i++){
            //     if(cleanToken(token)==stopwords().at(i))
            //         tokens.erase(cleanToken(token));
            // }
        }
    }
    return tokens;
}

// builds the inverted index by separating the websites and the words
int buildIndex(string filename, map<string, set<string>> &index)
{
    set<string>::iterator itr;
    string text; // words in the website
    int count = 0;
    ifstream inFS(filename); // filename is the website url
    if (!inFS.is_open())
        return 0;
    while (getline(inFS, filename)) // getline for the websites
    {
        count++;             // count used for searchEngine function to get how many websites were indexed
        getline(inFS, text); // getline for the text of the websites
        set<string> tokens = gatherTokens(text);
        for (itr = tokens.begin(); itr != tokens.end(); itr++) // iterating through the set to ipair the website
                                                               // url with each word in that website into the map
        {
            index[*itr].insert(filename);
        }
    }
    return count;
}

// finds website indexes of a given word. can use + or - modifiers to customize search.
set<string> findQueryMatches(map<string, set<string>> &index, string sentence)
{
    int count = 0;         // used to skip modifiers in first word
    set<string> result;    // used for initial word
    set<string> newresult; // used for words that contain modifiers
    stringstream sstr(sentence);
    string token;
    while (sstr >> token)
    {
        newresult.clear();//clear newresult to get ready to push in new websites
        if (index.count(cleanToken(token)))
        {
            if (token.at(0) == '+' && count > 0) // count>0 to make sure its not the first term
            {
                set_intersection(result.begin(), result.end(), index.at(cleanToken(token)).begin(), index.at(cleanToken(token)).end(), std::inserter(newresult, newresult.begin()));
            }
            else if (token.at(0) == '-' && count > 0) // count > 0 to make sure its not the first term
            {
                set_difference(result.begin(), result.end(), index.at(cleanToken(token)).begin(), index.at(cleanToken(token)).end(), std::inserter(newresult, newresult.begin()));
            }
            else
            {
                set_union(result.begin(), result.end(), index.at(cleanToken(token)).begin(), index.at(cleanToken(token)).end(), std::inserter(newresult, newresult.begin()));
            }
        }
        result = newresult; // used for intersection and difference modifiers
        count++;            // skip any modifiers in the first term
    }
    return newresult;
}

//interface for searching which lets user input search term and show information about the txt file
void searchEngine(string filename)
{
    map<string, set<string>> search;
    string searchTerm;
    cout << "Stand by while building index..." << endl;
    cout << "Indexed " << buildIndex(filename, search) << " pages containing " << search.size() << " unique terms" << endl;
    while (true)
    {
        cout << endl
             << "Enter query sentence (press enter to quit): ";
        getline(cin, searchTerm);
        if (searchTerm == "")//when enter is hit there will be no input to cin so empty string counts as enter
            break;//finish looping
        set<string> res = findQueryMatches(search, searchTerm);//stores the set of websites to print
        cout << "Found " << res.size() << " matching pages" << endl;
        for (set<string>::iterator it = res.begin(); it != res.end(); ++it)
            cout << *it << endl;//iterate through set to print websites.
    }
    cout << "Thank you for searching!" << endl;
}
