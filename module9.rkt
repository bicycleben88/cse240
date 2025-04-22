;;;
; CSE240 Functional Programming 2 Homework
;
; Description: Module 9 Scheme exercise
;
; Completion time: 4 hrs
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
     (cond ((null? remains) sum)
       ((even? (car remains))(add (+ (car remains) sum) (cdr remains)))
       (else (add sum (cdr remains)))))
   )'(1 3 -4 5 6 -7))

; Q2
(define (list-push-back lst new-list)
  (append lst new-list))

; Q3
(define (list-push-front lst new-list)
  (append new-list lst))
 
; Q4
(define (list-draw-front n lst)
  (if (= n 0)
      '()
      (cons (car lst) (list-draw-front (- n 1) (cdr lst))))) 

; Q5
(define (list-draw-back n lst)
  (if (= n (length lst))
      '()
      (cons (list-ref lst n) (list-draw-back (+ n 1) lst))))

; Q6
