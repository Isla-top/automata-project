#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Tape;

class Turing{

private:
    vector<string> status;
    unordered_set<char> input_syms;
    unordered_set<char> tape_syms;
    string q0;
    char blank;
    vector<string> final_status;
    vector<Tape> tapes;
    int tape_num;
    bool verbose;
    
public:
    Turing(bool verbose);
};

class Tape{

private:
    vector<char> forward;
    vector<char> backward;
    int position;

public:
    Tape();
};

class Delta{

private:

};