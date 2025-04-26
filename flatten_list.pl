/*rules*/
my_flatten([],[]):-!.

my_flatten([Head|Tail], X):-  /* size-n problem*/
        my_flatten(Head, L1), /* size-m problem for first element in list*/
        my_flatten(Tail, L2), /* size-m problem for tail of list*/
        append(L1, L2, X).    /* construction of the size-n problem from size-m problems*/

my_flatten(Head, X):-         /* special rule to turn an element into a list*/
        append([Head],[], X).

q4:-
        my_flatten([a, [b, [c, d], e]], X),
        write(X).
