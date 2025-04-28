;;;
; CSE240 Functional Programming 3 Homework
; Description: Creatre an n-bit Adder
;
; Completion time: 4 hours
;
; @author Ben Higginbotham
; @version 6.0
;;;


;Q1
; enter your code here:
(define (AND-gate A B)
        (if (and (= A 1) (= B 1)) 1 0))

(define (OR-gate A B)
        (if (or (= A 1) (= B 1)) 1 0))

(define (NOT-gate A)
        (if (= A 0) 1 0))
; Test cases
(display "AND-Gate Output\n")
(AND-gate 0 0)
(AND-gate 0 1)
(AND-gate 1 0)
(AND-gate 1 1)
; Expected outputs
;0
;0
;0
;1
; Test cases
(display "OR-Gate Output\n")
(OR-gate 0 0)
(OR-gate 0 1)
(OR-gate 1 0)
(OR-gate 1 1)
; Expected outputs
;0
;1
;1
;1
; Test cases
(display "NOT-Gate Output\n")
(NOT-gate 0)
(NOT-gate 1)
; Expected outputs
;1
;0

; Q2
; enter your code here:
(define (XOR-gate A B)
        (cond 
             ((= (AND-gate A B) 1) 0)
             ((= (OR-gate A B) 1) 1) 
             (0)))
; Test cases
(display "XOR-Gate Output\n")
(XOR-gate 0 0)
(XOR-gate 0 1)
(XOR-gate 1 0)
(XOR-gate 1 1)
; Expected outputs
;0
;1
;1
;0

;Q3.1
; enter your code here:
(define (half-adder x A B)
        (XOR-gate x (XOR-gate A B)))

;Q3.2
; enter your code here:
(define (carry-out x A B)
        (OR-gate
                (AND-gate A B)
                (AND-gate (XOR-gate A B) x)))

;Q3.3
; enter your code here:
(define (full-adder x A B)
        (cons (carry-out x A B) (half-adder x A B)))

; Test cases
(Display "half-adder Output\n")
(half-adder 0 0 0) 	
(half-adder 0 0 1) 	
(half-adder 0 1 0) 	
(half-adder 0 1 1)	
(half-adder 1 0 0) 	
(half-adder 1 0 1)	
(half-adder 1 1 0) 	
(half-adder 1 1 1)

; Expected outputs
;0
;1
;1
;0
;1
;0
;0
;1


; Test cases
(Display "fullAdder Output\n")
(full-adder 0 0 0) 	
(full-adder 0 0 1) 	
(full-adder 0 1 0) 	
(full-adder 0 1 1)	
(full-adder 1 0 0) 	
(full-adder 1 0 1)	
(full-adder 1 1 0) 	
(full-adder 1 1 1)

; Expected outputs
;(0 . 0)
;(0 . 1)
;(0 . 1)
;(1 . 0)
;(0 . 1)
;(1 . 0)
;(1 . 0)
;(1 . 1)


;Q4.1
; enter your code here:
(define (tail lst)
        (if (= (length lst) 0)
            0
          (if (= (length lst) 1)
              (car lst)
              (tail (cdr lst)))))

;Q4.2
(define (rmtail lst)
        (if (< (length lst) 2)
            '()
            (cons (car lst) (rmtail (cdr lst)))))

;Q4.3
; Step 1 size-n problem: Lines of code
; ----> 163, 168

; Step 2 Stopping condition: Lines of code
; ----> 164-165, 169-170

; Step 3 size-m problem: Lines of code
; ----> 166, 172

; Step 4: Lines of code
; ----> 166, 172-173


;Q4.4
; enter your code here:
(define (n-bit-adder A B n)
        (if (> n 0)
            (recursive-add A B 0)
            (n-bit-adder (rmtail A) (rmtail B) (- n 1))))

(define recursive-add (lambda (A B c)  
        (if (null? A)
            '()
            (let ((result (full-adder 0 (tail A) (tail B))))
             (append (recursive-add (rmtail A)(rmtail B) (carry-out (car result)(tail A)(tail B)))
                     (list (cdr result)))))))


;Test cases
(define x1 '(0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0) )	
(define x2 '(1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1) )	
(define x3 '(0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1) )	
(define x4 '(1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0) )
(define x5 '(1 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1) )	
(define x6 '(1 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 1 0) )


(display "n-bit-adder Output\n")
(n-bit-adder  x1 x2 32)
(n-bit-adder  x3 x4 32)
(n-bit-adder  x5 x6 32)
(n-bit-adder  x2 x3 32)
(n-bit-adder  x4 x5 32)
(n-bit-adder  x1 x6 32)
; Expected outputs
;(0 (1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1))
;(0 (1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1))
;(1 (1 0 1 1 1 0 0 0 1 1 1 0 0 1 0 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 1))
;(1 (0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 0))
;(1 (1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1))
;(0 (1 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 1 0))


;Q5 boilerplate (implementations for reduce and filter)
(define reduce
	  (lambda (op base x) ;passing by name
		(if (null? x)
			base
			(op (car x) (reduce op base (cdr x))))))

(define filter (lambda (pred a-list)
	(if (null? a-list)
	    '()
	    (if	(pred (car a-list))
			(cons (car a-list) (filter pred (cdr a-list)))
			(filter pred (cdr a-list)))))) 


;Q5.1
; enter your code here:

;Q5.2
; enter your code here:

;Q5.3
; enter your code here: