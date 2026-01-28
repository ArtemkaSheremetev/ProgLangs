[section code]
main:
    ldsp -4    ; init sp
    ldbp -4    ; init bp
    li r7, 0    ; frame init
    push r7
bb_stmt_5ee8d5d22cd0:
    call readChar
    getbp r6    ; bp
    li r7, 4    ; off ch
    sub r6, r7
    store r6, r0    ; store ch
    jmp bb_call_writeChar_5ee8d5d22610
bb_call_writeChar_5ee8d5d22610:
    getbp r6    ; bp
    li r7, 4    ; off ch
    sub r6, r7
    load r0, r6    ; load ch
    mov r0, r0    ; arg
    call writeChar
    jmp bb_exit_5ee8d5d235d0
bb_exit_5ee8d5d235d0:
    li r0, 0    ; return default 0
    ret
readChar:
__bi_readChar_loop:
    in r0
    mov r1, r0
    li r2, 32
    eq r1, r2
    jnz r1, __bi_readChar_loop
    mov r1, r0
    li r2, 9
    eq r1, r2
    jnz r1, __bi_readChar_loop
    mov r1, r0
    li r2, 10
    eq r1, r2
    jnz r1, __bi_readChar_loop
    mov r1, r0
    li r2, 13
    eq r1, r2
    jnz r1, __bi_readChar_loop
    ret
writeChar:
    out r0
    ret
    hlt

[section dataMem]
var_main_ch:
    dd 0    ; ch

