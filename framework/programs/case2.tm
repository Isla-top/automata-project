; the finite set of states
#Q = {0,shear,reset1,vali,clear0,cmp,halt_accept,halt_reject,reject1,reject2,reject3,reject4,reject5,accept1,accept2,accept3,accept4}

; the finite set of input symbols
#S = {a,b,c}

; the complete set of tape symbols
#G = {a,b,c,_,t,r,u,e,f,l,s}

; the start state
#q0 = 0

; the blank symbol
#B = _

; the set of final states
#F = {halt_accept}

; the number of tapes
#N = 2

; the transition functions

; State 0: start state
0 a_ a_ ** shear
0 b_ b_ ** shear
0 c_ c_ ** vali
0 __ __ ** reject1 ; empty input

; State shear: shear the string from tape0 to tape1
shear a_ _a rr shear
shear b_ _b rr shear
shear c_ __ rl reset1
shear __ __ ** reject1

; State vali: validate the special input "c"
vali c_ __ r* vali
vali a_ a_ ** clear0
vali b_ b_ ** clear0
vali __ __ ** accept1

; State clear0: clear0 the tape0
clear0 a* _* r* clear0
clear0 b* _* r* clear0
clear0 c* _* r* clear0
clear0 _* _* ** reject1

; State reset1: reset the position at tape1 to the left
reset1 *a *a *l reset1
reset1 *b *b *l reset1
reset1 *_ *_ *r cmp

; State cmp: compare the reset string
cmp aa __ rr cmp
cmp bb __ rr cmp
cmp c* __ rr clear0
cmp ab __ rr clear0
cmp ba __ rr clear0
cmp a_ __ rr clear0
cmp b_ __ rr clear0
cmp _a __ ** reject1
cmp _b __ ** reject1
cmp __ __ ** accept1

accept1 _* t* r* accept2
accept2 _* r* r* accept3
accept3 _* u* r* accept4
accept4 _* e* ** halt_accept

reject1 _* f* r* reject2
reject2 _* a* r* reject3
reject3 _* l* r* reject4
reject4 _* s* r* reject5
reject5 _* e* ** halt_reject