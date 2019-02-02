.equ swi_exit 0x11
.text
mov r1, #1
loop:
	add r2, r1, r0
	mov r0,r1
	mov r1,r2
        add r4,r4,#1
        cmp r4, #10
        bne loop
       str r1,=#0 
       swi swi_exit
.data

.end
