;;;
; CSE240 Functional Programming 1 Homework
; This assignment involves pracicing various expressions and procedures in Scheme.
; 
; For the first assignment, we are providing the default header so you can see how it
; looks in Scheme. For future assignments, you will need to add it yourself.
;
; Completion time: (3 hrs)
;
; @author Ben Higginbotham
; @version 04-14-2025
;;;


; Q1

; 1.1 9 - 2 + 5
(+ 5 (- 9 2))

; 1.2 5 * ( 6 + 12 + 5 ) – 25
(- (* 5 (+ 6 12 5)) 25)

 ; 1.3 7 * (( 5 - ( 1 * 3 )) + ( 2 * 4 ) )
(* 7 (+ (- 5 (* 1 3)) (* 2 4)))

; 1.4 3 * ( 4 + ( ( ( 6 * 6 ) + ( 6 * 6 ) ) / ( 10 + 2 )( ) )
(* 3 (+ 4(/ (+ (* 6 6) (* 6 6)) (+ 10 2))))

; 1.5 ( ( ( ( ( ( 4 + 6 ) * ( 6 + 4 ) ) / 2 ) / 2 )– 5 ) / 2 ) + ( ( ( ( 4 * 5 ) + ( 5 * 4 ) ) / 2 ) + ( 4 * 5 ) )
(+ (/ (- (/ (/ (* (+ 4 6) (+ 6 4)) 2) 2) 5) 2) (+ (/ (+ (* 5 4) (* 4 5)) 2) (* 4 5))) 

; Q2
(define (add x y) (+ x y)) 

; Q3
; The code for size-n problem is: 
(define (square x)
  ; The code for stopping condition and its return value are:
  (if (= x 0)
      0
      ; The code for size-m problem is: (square (- (abs x) 1))
      ; The code for constructing size-n problem is:
      (add (square (- (abs x) 1)) (- (* 2 (abs x)) 1))))

; Q4
(define (read-for-square) (square(read)))

; Q5
(define (diff-squares)
  (abs (- (read-for-square) (read-for-square))))

; Q6
(define (sum-odds max)
  (cond ((<= max 1) 1)
        ((odd? max) (+ (sum-odds (- max 1)) max)) 
        (else (sum-odds (- max 1))
       ))) 

; Q7
(define (fib a)
  (cond ((= a 0) 0)
        ((= a 1) 1)
        (else (add (fib (- a 1)) (fib (- a 2)))
      )))
   