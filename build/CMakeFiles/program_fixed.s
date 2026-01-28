
; ===== Corrected calculator program =====
; Uses readChar / writeChar / readInt / writeInt

; ---------- IO ----------
writeChar:
    setio 2
    out r0
    ret

readChar:
    setio 3
    in r0
    ret

; ---------- readInt ----------
readInt:
    li  r1, 0      ; result
    li  r2, 0      ; sign (0=+,1=-)
    li  r5, 0      ; gotDigit

ri_loop:
    call readChar

    ; stop on '\n'
    li  r4, 10
    eq  r0, r4
    jnz r0, ri_finish

    ; minus
    li  r4, 45
    eq  r0, r4
    jnz r0, ri_minus

    ; digit
    li  r4, 48
    sub r3, r0, r4     ; r3 = digit
    mul r1, r1, 10
    add r1, r1, r3
    li  r5, 1
    j   ri_loop

ri_minus:
    li  r4, 0
    eq  r5, r4
    jnz r5, ri_loop
    li  r2, 1
    j   ri_loop

ri_finish:
    mov r0, r1
    li  r4, 0
    eq  r2, r4
    jnz r2, ri_neg
    ret

ri_neg:
    li  r0, 0
    sub r0, r1
    ret

; ---------- writeInt ----------
writeInt:
    mov r1, r0
    li  r2, 0
    eq  r1, r2
    jnz r1, wi_zero

    lt  r1, r2
    jnz r1, wi_neg

wi_pos_start:
    mov r3, r0
    li  r6, wi_buf
    li  r5, 0

wi_div:
    li  r2, 0
    eq  r3, r2
    jnz r3, wi_out_prep

    mod r1, r3, 10
    store r6, r1
    add r6, r6, 4
    add r5, r5, 1
    div r3, r3, 10
    j   wi_div

wi_out_prep:
    sub r6, r6, 4

wi_out:
    li  r2, 0
    eq  r5, r2
    jnz r5, wi_nl

    load r1, r6
    add r1, r1, 48
    mov r0, r1
    call writeChar
    sub r6, r6, 4
    sub r5, r5, 1
    j   wi_out

wi_neg:
    mov r3, r0
    li  r0, 45
    call writeChar
    li  r0, 0
    sub r0, r3
    j   wi_pos_start

wi_zero:
    li  r0, 48
    call writeChar

wi_nl:
    li  r0, 10
    call writeChar
    ret

; ---------- main ----------
main:
    li r6, var_main_x
    li r0, 0
    store r6, r0

main_loop:
read_op:
    call readChar
    li r1, 10
    eq r0, r1
    jnz r0, read_op
    li r1, 13
    eq r0, r1
    jnz r0, read_op
    li r1, 32
    eq r0, r1
    jnz r0, read_op

    li r6, var_main_op
    store r6, r0

    call readInt
    li r6, var_main_y
    store r6, r0

    li r6, var_main_x
    load r1, r6
    li r6, var_main_y
    load r2, r6
    li r6, var_main_op
    load r3, r6

    li r4, 43
    eq r3, r4
    jnz r3, do_add
    li r4, 45
    eq r3, r4
    jnz r3, do_sub
    li r4, 42
    eq r3, r4
    jnz r3, do_mul
    li r4, 47
    eq r3, r4
    jnz r3, do_div
    j main_loop

do_add:
    add r1, r1, r2
    j store_x
do_sub:
    sub r1, r1, r2
    j store_x
do_mul:
    mul r1, r1, r2
    j store_x
do_div:
    li r4, 0
    eq r2, r4
    jnz r2, store_x
    div r1, r1, r2

store_x:
    li r6, var_main_x
    store r6, r1
    mov r0, r1
    call writeInt
    j main_loop

; ---------- data ----------
var_main_x:
    .word 0
var_main_y:
    .word 0
var_main_op:
    .word 0
wi_buf:
    .space 64
