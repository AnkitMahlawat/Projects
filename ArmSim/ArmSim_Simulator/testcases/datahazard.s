@code for testing Data Hazard
.text
mov r0 , #5
str r0 , [r2]
LDR r1 , [r2 , #0]
SUB r4 , r1 , r5
swi swi_exit
.data
.end
