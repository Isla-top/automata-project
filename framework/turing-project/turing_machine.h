#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Tape;
class Delta;

class Turing{

private:
    unordered_set<string> status;
    unordered_set<char> input_syms;
    unordered_set<char> tape_syms;
    string q0;
    char blank;
    unordered_set<string> final_status;
    unordered_map<string, vector<Delta>> transitions;

    int tape_num;
    vector<Tape> tapes;
    string curr_status;
    bool is_accept;

    string input;

    string output;

    bool verbose;
    
public:
    Turing(bool verbose);

    void set_status(unordered_set<string> status);
    void set_input_syms(unordered_set<char> input_syms);
    void set_tape_syms(unordered_set<char> tape_syms);
    void set_q0_and_init_curr(string q0);
    void set_blank();
    void set_final_status(unordered_set<string> final_status);
    void set_tape(int tape_num);
    void add_transition(vector<string> delta);

    void process(string input);
    void validate();
    void pad_tape(); // pad the input to first tape
    void output_result();

    string get_curr_syms();

    void set_curr_status(string s);
    void set_curr_tapes(string syms, string dir);
};


class Tape{

private:
    vector<char> forward;
    vector<char> backward;
    int position;
    int left_bound;
    int right_bound;

public:
    Tape();

    char get();
    void set(char c);
    void move_left();
    void move_right();

    void init(string s);
    string get_content();

    string get_space_index();
    string get_space_content();
    string get_space_position();
};


class Delta{

private:
    string old_status;
    string old_syms;
    string new_syms;
    string dirts;
    string new_status;

public:
    Delta();

    Delta(string old_status, string old_syms, string new_syms, string dirts, string new_status);

    bool match(string old_syms);
    void apply(Turing& tm);
};