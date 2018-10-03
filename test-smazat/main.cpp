(defun soucet (a b)
        (if (eq b 0)
            a
            (+ 1 (soucet a ( - b 1))) ))

(defun rozdil (a b)
(if (eq a 0)
(- b)
    (+ 1 ( rozdil (- a 1)  b )) ))



























(defun soucin (a b)
    (if (eq a 0)
    0
    (+ b (soucin (- a 1) b ))))

(defun podil (a b)
    (if ( < a  b )
        0
(+ 1 (podil (rozdil a b ) b ))
        )

)

(defun ctvrty (s)
        (car(cdr (cdr (cdr  s))))
)

(defun obsahuje (lst x)
        (if (equal lst nil)
        nil
                (if (equal (car lst) x)
                x
                        (obsahuje (cdr lst) x)
                )
        )
)

(defun obsahujePlus (lst x )
        (if (equal lst nil)
        nil
                (if (atom (car lst))
                    (if (equal car x )
                        x
                    )
                    (if (obsahujePlus (cdr lst) x)
                        x
                                (obsahujePlus ((cdr (cdr lst))) x)
                )
        )
)