#include "parser.h"
#include <fstream>
#include <sstream>
#include <regex>

Parser::Parser(string filename, bool verbose){
    this->filename = filename;
    this->verbose = verbose;
}

void Parser::check(bool condition, string reason, int linenum){
    // cout << reason << endl;
    if(!condition){
        cerr << "syntax error";
        if(this->verbose) cerr << ": " << reason << " at line: " << linenum << endl;
        else cerr << endl;
        exit(-1);
    }
}

void Parser::read_file_and_parser(Turing& tm){
    ifstream file(this->filename);

    if(!file.is_open()){
        cerr << "no such file or directory: " << this->filename;
        exit(-3);
    }

    string line;
    int linenum = 1;
    int flag = 0;
    while(getline(file, line)){
        line = line.substr(0, line.find(";"));
        linenum++;
        if(line.empty()) continue;
        // cout << line << "       " << line.find(";") << endl;
        if(line.find("#Q") == 0){
            this->process_Q(line, linenum, tm);
            flag |= 0x1;
        }else if(line.find("#S") == 0){
            this->process_S(line, linenum, tm);
            flag |= 0x10;
        }else if(line.find("#G") == 0){
            this->process_G(line, linenum, tm);
            flag |= 0x100;
        }else if(line.find("#q0") == 0){
            this->process_q0(line, linenum, tm);
            flag |= 0x1000;
        }else if(line.find("#B") == 0){
            this->process_B(line, linenum, tm);
            flag |= 0x10000;
        }else if(line.find("#F") == 0){
            this->process_F(line, linenum, tm);
            flag |= 0x100000;
        }else if(line.find("#N") == 0){
            this->process_N(line, linenum, tm);
            flag |= 0x1000000;
        }else{ 
            this->check(flag == 0x1111111, "Delta appear before other parts or lose the '#' at head", linenum);
            this->process_Delta(line, linenum, tm);
        }
    }

    file.close();
}

vector<string> split(string line, char delimiter){
    istringstream is(line);
    string token;
    vector<string> tokens;

    while (getline(is, token, delimiter)) {
        tokens.push_back(token);
    }

    // for (const std::string& str : tokens) {
    //     std::cout << str << std::endl;
    // }

    return tokens;
}

void Parser::process_Q(string line, int linenum, Turing& tm){
    vector<string> tokens = split(line, ' ');
    this->check(tokens.size() == 3, "status line format error", linenum);
    this->check(tokens[1] == "=", "unknown symbol: " + tokens[1], linenum);
    this->check(!tokens[2].empty(), "empty status", linenum);
    this->check(tokens[2][0] == '{' && tokens[2][tokens[2].size() - 1] == '}', "lose '{' or '}'", linenum);

    string ss = tokens[2].substr(1, tokens[2].size() - 2);
    vector<string> status_vector = split(ss, ',');
    regex pattern("[^a-zA-Z0-9_]");

    for(string& s : status_vector){
        this->check(!s.empty(), "illegal status symbol", linenum); // illegal symbol ','
        this->check(!regex_search(s, pattern), "illegal status symbol", linenum);
    }

    status.insert(status_vector.begin(), status_vector.end());
    
    //todo: add status to tm
}

void Parser::process_S(string line, int linenum, Turing& tm){
    
}

void Parser::process_G(string line, int linenum, Turing& tm){
    
}

void Parser::process_q0(string line, int linenum, Turing& tm){
    
}

void Parser::process_B(string line, int linenum, Turing& tm){
    
}

void Parser::process_F(string line, int linenum, Turing& tm){
    
}

void Parser::process_N(string line, int linenum, Turing& tm){
    
}

void Parser::process_Delta(string line, int linenum, Turing& tm){
    
}