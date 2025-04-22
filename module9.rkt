;;;
; CSE240 Functional Programming 2 Homework
; (fill in)
;
; Completion time: (fill in)
;
; @author Ben Higginbotham
; @version (fill in)
;;;


; Q1
(define (sumEven list)
  (cond ((null? list) 0)
        ((even? (car list)) (+ (car list) (sumEven (cdr list))))
        (else (sumEven (cdr list)))))

((lambda (lst)
   (let ((sum 0) (rest-of-list (cdr lst)))
     (+ sum (car lst)))) '(1 3 -4 5 6 -7))

;(sumEven '(1 3 -4 5 6 -7))

; Q2
;(define (list-push-back lst new-list)
;  (append (lst new-list)))

;(list-push-back '(4 3 7 1 2 9) '(1 2))

; Q3

 
; Q4


; Q5


; Q6

;1. Create an anonymous function that takes one argument: the input list.
;2. Inside, set up a helper called “loop” with two variables:
;remaining = the list you still need to process
;sum = the running total of even numbers, start at 0
;3. Loop (recurse) until remaining is empty:
;If remaining is empty, return sum.
;Otherwise, let x = the first element of remaining.
;If x is even, add x to sum.
;Remove the first element from remaining.
;Call “loop” again with the new remaining and updated sum.
;4. Finally, invoke your anonymous function on the literal list '(1 3 -4 5 6 -7).

;When you follow those steps, you’ll get 2 (because –4 + 6 = 2).