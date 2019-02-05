# Project : ArmSim Simulator
## Problem Statement : ARM Assembly Program Simulator
● Parse the given an ARM assembly program as input to simulator and use an
appropriate representation to store it in an array, with each array element
representing an instruction.<br>
● Resolve the addresses of the labels<br>
● Simulation starts with the Program Counter (PC) pointing to the first instruction.<br>
● Execute the instruction. Display the values of the Register File and Memory
contents as a result of executing the instruction.<br>
● Proceed to the next instruction and continue the execution.<br>
● Simulation stops when there is no further instruction to execute.
At the end of execution, report any interesting statistics regarding the number and types
of instructions executed, etc.
## My Solution:
My program support the following minimum instructions.<br>
LDR,STR,ADD,SUB,MUL,CMP<br>
Also incorporated pipelining. Made an attempt to be as aggressive as I can with respect
to avoiding data and control hazards. As a rule, in such project, complete simpler
versions of the software before adding complex features. So, to begin with, just stalled
the pipeline on hazards, and ensure functional correctness. Print out statistics about the
clock cycle counts and average Instructions Per Cycle (IPC) for the input program. My
program is also capable of displaying, after each instruction, the various instructions
that are currently residing in the pipeline, along with the stage that they are in.
i also added added more advanced branch instruction later like BNE,BGE,B,BL and
MOV. Used structures to represent states calcutes latency of the instructions in first go
and created machine code representation in second go of arm file give as input to the
program. And then executed instructions represented by machine code sequentially .
Used arrays to represent registers I used MIPS instruction set. I also applied two bit
predictor.<br>
2-bit Predictor => The predictor that fixes the two mis-predictions per anomaly
behavior of the one bit predictor is called a two bit predictor.<br><br>

Language used : C<br>
Many problems like memory allocation and control hazard and data hazard are also
handled carefully.<br>
