/* Rules */

qsort2([],[]) :- !.                              /* stopping condition that returns two empty lists */

qsort2([Head|[Pivot|Tail]],Sorted):-             /* size-n problem */
        split2(Pivot, [Head|Tail], L1, L2),
        qsort2(L1,Sorted1),                      /* size-m problem for numbers before the pivot */
        qsort2(L2,Sorted2),                      /* size-m problem for numbers after the pivot */
        append(Sorted1,[Pivot|Sorted2], Sorted). /* construction of the size-n problem from size-m problems */

qsort2(L,L).                                     /* special rule for a list with only one element */

split2(_,[],[],[]).

split2(Pivot,[X|Tail],[X|LessThan],GreaterThan):-
        X=<Pivot, split2(Pivot,Tail,LessThan,GreaterThan).

split2(Pivot,[X|Tail],LessThan,[X|GreaterThan]):-
        X > Pivot, split2(Pivot,Tail,LessThan,GreaterThan).

q3:-
        qsort2([8, 3, 4, 12, 25, 4, 6, 1, 9, 22, 6], Sorted),
        write(Sorted).

q4:-
        qsort2([4, 12, 8], Sorted),
        write(Sorted).
