/* Facts */
weather(phoenix, spring, hot).
weather(phoenix, summer, hot).
weather(phoenix, fall, hot).
weather(phoenix, winter, warm).
weather(wellington, spring, warm).
weather(wellington, summer, warm).
weather(wellington, fall, hot).
weather(wellington, winter, cold).
weather(toronto, spring, cold).
weather(toronto, summer, hot).
weather(toronto, fall, cold).
weather(toronto, winter, cold).
/* Rules */
warmer(C1, C2) :-
weather(C1, spring, hot), weather(C2, spring, warm).
warmer(C1, C2) :-
weather(C1, spring, hot), weather(C2, spring, cold).
/* The following rule is in fact a compound question. It will cause a number of goals (questions) to be called. */
/* It can be considered as the "main" program. Please note, since the questions are connected by "and" */
/* relationship, it stops if a "no" answer is given to any single question. */ Page 3 of 4
/* You could use the "or" relationship to connect questions. The compound question will stop if a "yes" */
/* answer is found. */
weatherquestions :-
warmer(phoenix, X),
write('Phoenix is warmer than '), write(X), nl,
weather(City1, fall , hot),
write('City1 = '), write(City1), nl,
weather(City2, _ , hot),
write('City2 = '), write(City2), nl,
weather(_, Season , warm),
write('Season = '), write(Season), nl,
weather(C1, summer , hot),
weather(C1, fall , hot),
write('C1 = '), write(C1), nl,
weather(C2, spring, warm),
weather(C2, fall , warm),
write('C2 = '), write(C2), nl, nl.
