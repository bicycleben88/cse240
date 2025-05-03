(define (hotpo n count)
  (cond
    ((= n 1) 1)
    ((even? n) hotpo (/ n 2) (+ count 1))
    ((odd? n) hotpo (+ (* n 3) 1)(+ count 1))
    (else cons n count)
  )) 