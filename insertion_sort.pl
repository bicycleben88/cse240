isort([],[]):-!.                            /* base case returns two empty lists*/

isort([First|Tail], Sorted):-               /* size-n problem*/
        isort(Tail, Sorted_Tail),           /* size-m problem*/
        insert(First, Sorted_Tail, Sorted). /* construction of the size-n problem from size-m problems*/

insert(First, [X|Sorted_Tail], [X|Sorted]):-
        First > X, insert(First, Tail, Sorted).

insert(First, Tail, Sorted):-
        append([First], Tail, Sorted).

q5:-
        isort([8, 3, 4, 12, 25, 4, 6, 1, 9, 22, 6], Sorted),
        write(Sorted).

q6:-
        isort([4,1,2,3,5], Sorted),
        write(Sorted).
