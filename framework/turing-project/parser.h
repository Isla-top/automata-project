#pragma once

#include <iostream>
#include "turing_machine.h"

using namespace std;

class Parser{

private:
    string filename;
    bool verbose;

    unordered_set<string> status;
    unordered_set<char> input_syms;
    unordered_set<char> tape_syms;
    int tape_num;

public:
    Parser(string filename, bool verbose);

    void check(bool condition, string reason, int linenum);

    void read_file_and_parser(Turing& tm);

    void process_Q(string line, int linenum, Turing& tm);

    void process_S(string line, int linenum, Turing& tm);
    
    void process_G(string line, int linenum, Turing& tm);
    
    void process_q0(string line, int linenum, Turing& tm);

    void process_B(string line, int linenum, Turing& tm);

    void process_F(string line, int linenum, Turing& tm);

    void process_N(string line, int linenum, Turing& tm);

    void process_Delta(string line, int linenum, Turing& tm);

private:
    string pre_check(string line, int linenum, bool isSet);
};