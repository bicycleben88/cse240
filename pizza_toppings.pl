/*rules*/
pizza(P, M, B, O, C):-
        member(P,[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]), /* num of peps under 45 oz */
        member(M,[0, 1, 2, 3, 4]), /* num of meatballs under 45 oz */
        member(B,[0, 1, 2, 3, 4, 5, 6]), /* num of basil under 45 oz */
        member(O,[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]), /* num of olives under 45 oz */
        member(C,[0, 1, 2, 3, 4, 5]), /* num of chicken under 45 oz */
        W is (P * 5) + (M * 10) + (B * 7) + (O * 3) + (C * 8), /* add weight based on combinations of toppings multiplied by their weights*/
        W =:= 45,
        write('pepperoni: '), write(P), write(', meatballs: '), write(M), write(', basil: '), write(B), write(', olives: '), write(O), write(', chicken: '), write(C).
q2:-
        pizza(1, 2, 2, 2, 2).

q3:-
        pizza(1, M, 1, O, C).

q4:-
        pizza(P, M, B, O, 1).
