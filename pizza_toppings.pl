/*rules*/
pizza(P, M, B, O, C):-
        member(P,[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]),                         /* num of peps under 45 oz */
        member(M,[0, 1, 2, 3, 4]),                                        /* num of meatballs under 45 oz */
        member(B,[0, 1, 2, 3, 4, 5, 6]),                                  /* num of basil under 45 oz */
        member(O,[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]), /* num of olives under 45 oz */
        member(C,[0, 1, 2, 3, 4, 5]),                                     /* num of chicken under 45 oz */
        W is (P * 5) + (M * 10) + (B * 7) + (O * 3) + (C * 8),            /* add weight based on combinations of toppings multiplied by their weights*/
        W =:= 45,
        write('pepperoni: '), write(P), 
	write(', meatballs: '), write(M), 
	write(', basil: '), write(B), 
	write(', olives: '), write(O), 
	write(', chicken: '), write(C).

q2:-
        pizza(1, 2, 2, 2, 2).

q3:-
        pizza(1, M, 1, O, C).

q4:-
        pizza(P, M, B, O, 1).

/*Answers:*/
/*  
 *  | ?- q2.
 
        no 
*/
/*  
 *  | ?- q3.
        pepperoni: 1, meatballs: 0, basil: 1, olives: 3, chicken: 3
 
        true ? ;
        pepperoni: 1, meatballs: 0, basil: 1, olives: 11, chicken: 0
 
        true ? ;
        pepperoni: 1, meatballs: 1, basil: 1, olives: 5, chicken: 1
 
        true ? ;
        pepperoni: 1, meatballs: 3, basil: 1, olives: 1, chicken: 0
 
        true ? ;
 
        no
*/
/*  
/ *  ?- q4.
        pepperoni: 0, meatballs: 0, basil: 1, olives: 10, chicken: 1
 
        true ? ;
        pepperoni: 0, meatballs: 0, basil: 4, olives: 3, chicken: 1

        true ? ;
        pepperoni: 0, meatballs: 1, basil: 0, olives: 9, chicken: 1

        true ? ;
        pepperoni: 0, meatballs: 1, basil: 3, olives: 2, chicken: 1

        true ? ;
        pepperoni: 0, meatballs: 2, basil: 2, olives: 1, chicken: 1

        true ? ;
        pepperoni: 0, meatballs: 3, basil: 1, olives: 0, chicken: 1

        true ? ;
        pepperoni: 1, meatballs: 0, basil: 2, olives: 6, chicken: 1

        true ? ;
        pepperoni: 1, meatballs: 1, basil: 1, olives: 5, chicken: 1

        true ? ;
        pepperoni: 1, meatballs: 2, basil: 0, olives: 4, chicken: 1

        true ? ;
        pepperoni: 2, meatballs: 0, basil: 0, olives: 9, chicken: 1

        true ? ;
        pepperoni: 2, meatballs: 0, basil: 3, olives: 2, chicken: 1

        true ? ;
        pepperoni: 2, meatballs: 1, basil: 2, olives: 1, chicken: 1

        true ? ;
        pepperoni: 2, meatballs: 2, basil: 1, olives: 0, chicken: 1
        true ? ;
        pepperoni: 3, meatballs: 0, basil: 1, olives: 5, chicken: 1

        true ? ;
        pepperoni: 3, meatballs: 1, basil: 0, olives: 4, chicken: 1

        true ? ;
        pepperoni: 4, meatballs: 0, basil: 2, olives: 1, chicken: 1

        true ? ;
        pepperoni: 4, meatballs: 1, basil: 1, olives: 0, chicken: 1

        true ? ;
        pepperoni: 5, meatballs: 0, basil: 0, olives: 4, chicken: 1

        true ? ;
        pepperoni: 6, meatballs: 0, basil: 1, olives: 0, chicken: 1

        true ? ;

        (7 ms) no
        | ?- 
*/
