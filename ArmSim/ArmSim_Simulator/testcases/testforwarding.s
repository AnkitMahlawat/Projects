@code to test forwarding
.text
mov r1 , #10
mov r3 , #6
SUB r2 , r1 , r3
AND r9 , r2 , r5
OR  r8 , r6 , r2
ADD r7 , r2 , r2
STR r15, [r2]
swi swi_exit
.data
.end
