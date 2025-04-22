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
   (let add ((sum 0) (remains lst))
     (cond
       ((null? remains) sum)
       ((even? (car remains))
        (add (+ (car remains) sum) (cdr remains)))
       (else (add sum (cdr remains)))))
   )'(1 3 -4 5 6 -7))

; Q2
(define (list-push-back lst new-list)
                        (append lst new-list))

; Q3
(define (list-push-front lst new-list)
                        (append new-list lst))
 
; Q4


; Q5


; Q6
