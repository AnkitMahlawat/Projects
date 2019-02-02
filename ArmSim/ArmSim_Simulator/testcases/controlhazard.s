@code for testing Control Hazard
.text
mov r5 , #2
mov r6 , #3
mov r1 , #1
L: 
OR r7 , r8 , r9
ADD r4 , r5 , r6
add r2,r2,#1
cmp r1,r2
BEQ L
swi swi_exit
.data
.end
