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
    int linenum = 0;
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
    string body = this->pre_check(line, linenum, true);
    string ss = body.substr(1, body.size() - 2);
    vector<string> status_vector = split(ss, ',');
    regex pattern("[^a-zA-Z0-9_]");

    for(string& s : status_vector){
        this->check(!s.empty(), "illegal status symbol", linenum); // illegal symbol ','
        this->check(!regex_search(s, pattern), "illegal status symbol", linenum);
    }

    this->status.insert(status_vector.begin(), status_vector.end());
    
    tm.set_status(this->status);
}

void Parser::process_S(string line, int linenum, Turing& tm){
    string body = this->pre_check(line, linenum, true);
    string is = body.substr(1, body.size() - 2);
    vector<string> input_sym_vector = split(is, ',');
    unordered_set<string> exclude = {" ", ";", "{", "}", "*", "_"};

    for(string& s : input_sym_vector){
        this->check(!s.empty(), "illegal input symbol", linenum); // illegal symbol ','
        this->check(s.size() == 1, "length of symbol should be 1", linenum);
        this->check(!exclude.count(s), "illegal input symbol", linenum);
    }

    for(string& s : input_sym_vector) this->input_syms.insert(s[0]);
    for(const char c : this->input_syms) this->check(c >= 32 && c <= 126, "illegal input symbol", linenum);
    
    tm.set_input_syms(this->input_syms);
}

void Parser::process_G(string line, int linenum, Turing& tm){
    string body = this->pre_check(line, linenum, true);
    string ts = body.substr(1, body.size() - 2);
    vector<string> tape_sym_vector = split(ts, ',');
    unordered_set<string> exclude = {" ", ";", "{", "}", "*"};

    for(string& s : tape_sym_vector){
        this->check(!s.empty(), "illegal tape symbol", linenum); // illegal symbol ','
        this->check(s.size() == 1, "length of symbol should be 1", linenum);
        this->check(!exclude.count(s), "illegal tape symbol", linenum);
    }

    for(string& s : tape_sym_vector) this->tape_syms.insert(s[0]);
    for(const char c : this->tape_syms) this->check(c >= 32 && c <= 126, "illegal tape symbol", linenum);
    for(const char c : this->input_syms) this->check(this->tape_syms.count(c), "tape alphabet should contain input alphabet", linenum);

    tm.set_tape_syms(this->tape_syms);
}

void Parser::process_q0(string line, int linenum, Turing& tm){
    string body = this->pre_check(line, linenum, false);
    this->check(this->status.count(body), "illegal start status", linenum);

    tm.set_q0_and_init_curr(body);
}

void Parser::process_B(string line, int linenum, Turing& tm){
    string body = this->pre_check(line, linenum, false);
    this->check(body == "_", "illegal blank symbol", linenum);

    tm.set_blank();
}

void Parser::process_F(string line, int linenum, Turing& tm){
    string body = this->pre_check(line, linenum, true);
    string fs = body.substr(1, body.size() - 2);
    vector<string> final_status_vector = split(fs, ',');

    for(string& s : final_status_vector) this->check(this->status.count(s), "illegal final status", linenum);

    unordered_set<string> final_s;
    final_s.insert(final_status_vector.begin(), final_status_vector.end());
    tm.set_final_status(final_s);
}

void Parser::process_N(string line, int linenum, Turing& tm){
    string body = this->pre_check(line, linenum, false);
    
    int n = 0;
    for(char c : body){
        this->check('0' <= c && c <= '9', "should be numbers", linenum);
        n *= 10;
        n += c - '0';
    }
    this->check(n != 0, "empty tapes", linenum);
    this->tape_num = n;

    tm.set_tape(this->tape_num);
}

void Parser::process_Delta(string line, int linenum, Turing& tm){
    vector<string> delta = split(line, ' ');

    this->check(delta.size() == 5, "illegal delta format", linenum);
    this->check(this->status.count(delta[0]), "illegal old status: " + delta[0], linenum);
    this->check(delta[1].size() == this->tape_num, "number of old symbols can't match tape number", linenum);
    for(const char c : delta[1]) this->check(this->tape_syms.count(c) || c == '*', "illegal old symbol", linenum);
    this->check(delta[2].size() == this->tape_num, "number of new symbols can't match tape number", linenum);
    for(const char c : delta[2]) this->check(this->tape_syms.count(c) || c == '*', "illegal new symbol", linenum);
    this->check(delta[3].size() == this->tape_num, "number of directions can't match tape number", linenum);
    for(const char c : delta[3]) this->check(c == 'l' || c == 'r' || c == '*', "illegal direction", linenum);
    this->check(this->status.count(delta[0]), "illegal new status: " + delta[4], linenum);
    
    tm.add_transition(delta);
}

string Parser::pre_check(string line, int linenum, bool isSet){
    vector<string> tokens = split(line, ' ');
    this->check(tokens.size() == 3, "line format error", linenum);
    this->check(tokens[1] == "=", "unknown symbols: " + tokens[1], linenum);
    this->check(!tokens[2].empty(), "unexpected empty part", linenum);
    if(isSet) this->check(tokens[2][0] == '{' && tokens[2][tokens[2].size() - 1] == '}', "lose '{' or '}'", linenum);

    return tokens[2];
}
