#include <iostream>
#include "parser.h"
using namespace std;
int main(int argc, char* argv[]){
    
    bool hp = false, verb = false;
    string filename = "", data = "";
    
    for(int i = 1; i < argc; i++){
        if(argv[i] == "-h"s || argv[i] == "--help"s) hp = true;
        else if(argv[i] == "-v"s || argv[i] == "--verbose"s) verb = true;
        else if(filename.empty()) filename = argv[i];
        else if(data.empty()) data = argv[i];
        else {
            cerr << "illegal command format" << endl;
            exit(-2);
        }
    }

    if(hp){
        cerr << "usage: turing [-v|--verbose] [-h|--help] <tm> <input>" << endl;
        return 0;
    }
    if(filename.empty() || data.empty()){
        cerr << "illegal command format" << endl;
        exit(-2);
    }

    Parser parser = Parser(filename, verb);
    Turing tm = Turing(verb);
    parser.read_file_and_parser(tm);
    tm.process(data);
    tm.output_result();

    return 0;
}