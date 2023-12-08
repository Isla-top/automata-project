; the finite set of states
#Q = {0,vali1,vali2,reset0,shear,reset1_1,reset1_2,delete_a,cal,halt_accept,halt_reject,reject1,reject2,reject3,reject4,reject5,reject6,reject7,reject8,reject9,reject10,reject11,reject12,reject13}

; the finite set of input symbols
#S = {a,b}

; the complete set of tape symbols
#G = {a,b,c,_,I,l,e,g,n,p,u,t}

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
0 b_ b_ ** reject1
0 __ __ ** reject1 ; empty input

; State shear: shear the string from tape0 to tape1
shear a_ _a rr shear
shear b_ _b rr shear
shear __ __ ll reset1_1

; State vali1: valiadate the input string
vali1 _a _a *r vali1
vali1 _b _b *r vali2
vali1 __ __ ** reject1

; State vali2: valiadate the input string
vali2 _a _a ** reject1
vali2 _b _b *r vali2
vali2 __ __ *l reset1_2

; State reset1_1: reset current position in tape1 to the left
reset1_1 *a *a *l reset1_1
reset1_1 *b *b *l reset1_1
reset1_1 *_ *_ *r vali1

; State reset1_2: reset current position in tape1 to the left
reset1_2 *a *a *l reset1_2
reset1_2 *b *b *l reset1_2
reset1_2 *_ *_ *r delete_a

; State delete_a: 0.o
delete_a *a *_ *r cal
delete_a *b *b l* halt_accept

; State cal: calculate i x j and put c
cal *a *a *r cal
cal *b cb rr cal
cal *_ *_ *l reset1_2


reject1 ** I* r* reject2
reject2 ** l* r* reject3
reject3 ** l* r* reject4
reject4 ** e* r* reject5
reject5 ** g* r* reject6
reject6 ** a* r* reject7
reject7 ** l* r* reject8
reject8 ** _* r* reject9
reject9 ** I* r* reject10
reject10 ** n* r* reject11
reject11 ** p* r* reject12
reject12 ** u* r* reject13
reject13 ** t* ** halt_reject
