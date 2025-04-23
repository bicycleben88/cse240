edge(ca, or).
edge(co, nm).
edge(co, ut).
edge(co, wy).
edge(id, mt).
edge(id, nv).
edge(id, or).
edge(id, ut).
edge(id, wa).
edge(id, wy).
edge(mt, wy).
edge(nv, or).
edge(nv, ut).
edge(or, id).
edge(or, wa).
edge(ut, wy).
color(az, orange).
color(co, orange).
color(mt, orange).
color(wa, orange).
color(wy, blue).
color(nv, blue).
color(ak, blue).
color(hi, blue).
color(ca, yellow).
color(id, yellow).
color(nm, yellow).
color(or, red).
color(ut, red).

/*Rules*/
adjacent(X,Y):-
        edge(X,Y); edge(Y,X).

miscolor(S1,S2,C):-
        adjacent(S1,S2),
        color(S1,C),
        color(S2,C).
q:-
        miscolor(_,_,_).
