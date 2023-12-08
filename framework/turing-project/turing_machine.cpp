#include "turing_machine.h"
#include <cmath>

string pad_space(int num){
    string s = ""s;
    for(int i = 0; i < num; i++) s += " ";
    return s;
}

Turing::Turing(bool verbose){
    this->verbose = verbose;
    this->output = "";
    this->is_accept = this->final_status.count(this->q0);
}

void Turing::set_status(unordered_set<string> status){
    this->status = status;
}

void Turing::set_input_syms(unordered_set<char> input_syms){
    this->input_syms = input_syms;
}

void Turing::set_tape_syms(unordered_set<char> tape_syms){
    this->tape_syms = tape_syms;
}

void Turing::set_q0_and_init_curr(string q0){
    this->q0 = q0;
    this->curr_status = q0;
}

void Turing::set_blank(){
    this->blank = '_';
}

void Turing::set_final_status(unordered_set<string> final_status){
    this->final_status = final_status;
}

void Turing::set_tape(int tape_num){
    this->tape_num = tape_num;
    
    for(int i = 0; i < tape_num; i++) this->tapes.push_back(Tape());
}

void Turing::add_transition(vector<string> delta){
    this->transitions[delta[0]].push_back(Delta(delta[0], delta[1], delta[2], delta[3], delta[4]));
}

void Turing::process(string input){
    this->input = input;
    this->validate();
    this->pad_tape();
    // cout << (this->transitions.find("cmp") == this->transitions.end()) << endl;
    int step = 0;
    int pad_length = ceil(log10((double)this->tape_num + 1)) + 6; // length of "Index" + length of tape number + " "

    while(true){
        if(verbose){
            this->output += "Step"s + pad_space(pad_length - 4) + ": "s + to_string(step) + "\n"s;
            this->output += "State"s + pad_space(pad_length - 5) + ": "s + this->curr_status + "\n"s;
            this->output += "Acc"s + pad_space(pad_length - 3) + ": "s + (this->is_accept ? "Yes" : "No") + "\n"s;
            for(int i = 0; i < this->tape_num; i++){
                int pad = ceil(log10((double)i + 2));
                string is = to_string(i);
                this->output += "Index"s + is + pad_space(pad_length - pad - 5) + ":"s + this->tapes[i].get_space_index() + "\n"s;
                this->output += "Tape"s + is + pad_space(pad_length - pad - 4) + ":"s + this->tapes[i].get_space_content() + "\n"s;
                this->output += "Head"s + is + pad_space(pad_length - pad - 4) + ":"s + this->tapes[i].get_space_position() + "\n"s;
            }
            this->output += "---------------------------------------------\n"s;
        }
        if(this->transitions.find(this->curr_status) == this->transitions.end()){
            if(verbose){
                this->output += (this->is_accept ? "ACCEPTED"s : "UNACCEPTED"s) + "\n"s;
                this->output += "Result:"s + this->tapes[0].get_content() + "\n"s;
                this->output += "==================== END ====================\n"s;
            }else this->output += (this->is_accept ? "(ACCEPTED)"s : "(UNACCEPTED)"s) + this->tapes[0].get_content() + "\n"s;
            break;
        }

        for(Delta& delta : this->transitions[this->curr_status]){
            if(delta.match(this->get_curr_syms())){
                delta.apply(*this);
                break;
            }
        }

        if(this->final_status.count(this->curr_status)) this->is_accept = true;
        step++;
    }
    
}

void Turing::validate(){
    for(const char c : this->input){
        if(!this->input_syms.count(c)){
            if(verbose){
                this->output += "Input: "s + this->input + "\n"s;
                this->output += "==================== ERR ====================\n"s;
                this->output += "error: Symbol \""s + c + "\" in input is not defined in the set of input symbols\n"s;
                this->output += "Input: "s + this->input + "\n"s;
                this->output += "       "s;
                
                for(const char ch : this->input){
                    if(ch == c){
                        this->output += "^\n"s;
                        break;
                    }
                    this->output += " "s;
                }
                this->output += "==================== END ====================\n"s;
            }else this->output += " illegal input string\n"s;

            cerr << this->output;
            exit(-4);
        }
    }
    if(verbose){
        this->output += "Input: "s + this->input + "\n"s;
        this->output += "==================== RUN ====================\n"s;
    }
}

void Turing::pad_tape(){
    this->tapes[0].init(this->input);
}

void Turing::output_result(){
    cout << this->output;
}

string Turing::get_curr_syms(){
    string s = ""s;
    for(int i = 0; i < this->tape_num; i++) s += this->tapes[i].get();
    return s;
}

void Turing::set_curr_status(string s){
    this->curr_status = s;
}

void Turing::set_curr_tapes(string syms, string dir){
    for(int i = 0; i < this->tape_num; i++){
        if(syms[i] != '*') this->tapes[i].set(syms[i]);
        switch (dir[i]){
            case 'l':
                this->tapes[i].move_left();
                break;
            case 'r':
                this->tapes[i].move_right();
                break;
        }
    }
}


Tape::Tape(){
    this->position = 0;
    this->left_bound = 0; // include
    this->right_bound = 0; // include
    forward.push_back('_');
    backward.push_back('_'); // take place the position 0
}

char Tape::get(){
    if(this->position >= 0) return this->forward[this->position];
    else return this->backward[-this->position];
}

void Tape::set(char c){
    if(this->position >= 0) this->forward[this->position] = c;
    else this->backward[-this->position] = c;
}

void Tape::move_left(){
    this->position--;
    if(this->position < this->left_bound){
        this->left_bound = this->position;
        if(this->position < 0) this->backward.push_back('_');
    }
    if(this->position + 1 == this->right_bound){
        if(this->right_bound >= 0 && this->forward[this->right_bound] == '_'){
            this->forward.pop_back();
            this->right_bound--;
        } 
        else if(this->right_bound < 0 && this->backward[-this->right_bound] == '_') this->right_bound--;
    }
}

void Tape::move_right(){
    this->position++;
    if(this->position > this->right_bound){
        this->right_bound = this->position;
        if(this->position >= 0) this->forward.push_back('_');
    }
    if(this->position - 1 == this->left_bound){
        if(this->left_bound < 0 && this->backward[-this->left_bound] == '_'){ 
            this->backward.pop_back();
            this->left_bound++;
        }
        else if(this->left_bound >= 0 && this->forward[this->left_bound] == '_') this->left_bound++;
    }
}

void Tape::init(string s){
    if(!s.empty()){
        this->forward.pop_back();
        this->right_bound--;
    }
    for(const char c : s){ 
        this->forward.push_back(c);
        this->right_bound++;
    }
}

string Tape::get_content(){
    string content = " "s;

    for(int i = this->left_bound; i <= this->right_bound; i++){
        if(i < 0) content += this->backward[-i];
        else content += this->forward[i];
    }
    return content;
}

string Tape::get_space_index(){
    string indexes = " "s;

    for(int i = this->left_bound; i <= this->right_bound; i++){
        if(i < 0) indexes += to_string(-i);
        else indexes += to_string(i);
        indexes += " "s;
    }
    return indexes;
}

string Tape::get_space_content(){
    string content = " "s;

    for(int i = this->left_bound; i <= this->right_bound; i++){
        if(i < 0) content += this->backward[-i];
        else content += this->forward[i];
        content += (abs(i) < 10) ? " "s : "  "s;
    }
    return content;
}

string Tape::get_space_position(){
    string head = " "s;

    for(int i = this->left_bound; i <= this->right_bound; i++){
        if(i < this->position) head += (abs(i) < 10) ? "  "s : "   "s;
        else{
            head += "^"s;
            break;
        }
    }
    return head;
}


Delta::Delta(){
    
}

Delta::Delta(string old_status, string old_syms, string new_syms, string dirts, string new_status){
    this->old_status = old_status;
    this->old_syms = old_syms;
    this->new_syms = new_syms;
    this->dirts = dirts;
    this->new_status = new_status;
}

bool Delta::match(string old_syms){
    bool matched = true;
    int length = this->old_syms.size();

    for(int i = 0; i < length; i++){
        if(this->old_syms[i] != old_syms[i] && this->old_syms[i] != '*'){
            matched = false;
            break;
        }
    }
    
    return matched;
}

void Delta::apply(Turing& tm){
    tm.set_curr_status(this->new_status);
    tm.set_curr_tapes(this->new_syms, this->dirts);
}