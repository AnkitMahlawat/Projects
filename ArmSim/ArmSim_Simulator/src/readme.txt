small addition in ldr and str instruction formats 
now you will have 
1. LDR Rd, [Rn]
2. STR Rd, [Rn] 
instructions supported no need to put additional imm if you don't have a non-zero imm.

latency.txt related information
latency file can have latency for one instruction in one line
comment for latency canbe give using # before writing comments
latency file can have latency for ldr,ldr_pseudo,str,str_pseudo,add,sub,cmp,mul,bne,bge,b,bl,mov,and,orr,mnv,swi_exit
note that you can give latency for and,orr,mnv because I have implemented them in my simulator also you can give latency for swi_exit command by writing:-
swi_exit = <latency> ;  
similarly other latencies can be given 
If a latency is give twice in a file like :
...some latencies...
ldr = x ;
...some other latencies...
ldr =y ;
...rest of latencies...
then latest latency will be assigned to instruction (in this case latency of ldr will be = y)
if latency of some instructions is not found in latency.txt or found latency is zero then (some) default latency will be assigned to instruction.
like if ldr latency is not there in file or it is there in file but is equal to zero then ldr latency will become 20.
negative ltencies are not allowed An error will pop up saying non numeric latency;

