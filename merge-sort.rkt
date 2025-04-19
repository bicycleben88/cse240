;(mergesort '(6 7 4 9 7 8 3 4 2 0))
(define (mergesort list)
  (if (> (length list) 1)
      (merge (mergesort (left-half list))
             (mergesort (right-half list)))
      list))

(define (left-half list)
  (left-half-helper
   list
   (floor (/ (length list) 2))))

(define (left-half-helper list num)
  (if (= num 0)
      '()
      (cons (car list)
            (left-half-helper (cdr list) (- num 1)))))

(define (right-half list)
  (reverse (left-half-helper
            (reverse list)
            (ceiling (/ (length list) 2)))))


(define (merge left-list right-list)
  (cond ((null? left-list) right-list)
        ((null? right-list) left-list)
        (else (if (< (car left-list) (car right-list))
                  (cons (car left-list) (merge (cdr left-list) right-list))
                  (cons (car right-list) (merge left-list (cdr right-list)))))))
