# Project : Flight Trip Planner
## Problem Statement :
In this Project you shall implement a rudimentary flight trip planner. The input is the set
of flights between various cities. It is given as a file. Each line of the file contains "city1
city2 departure-time arrival-time flight-no. price" This means that there is a flight called
"flight-no" (which is a string of the form XY012) from city1 to city2 which leaves city1 at
time "departure-time" and arrives city2 at time "arrival-time". Further the price of this
flight is "price" which is a positive integer. All times are given as a string of 4 digits in the
24hr format e.g. 1135, 0245, 2210. Assume that all city names are integers between 1
and a number N (where N is the total number of cities).
**Note** that there could be multiple flights between two cities .
The query that you have to answer is: given two cities "A" and "B", times "t1", "t2",
where t1 < t2, find the cheapest trip which leaves city "A" after time "t1" and arrives at
city "B" before time "t2". A trip is a sequence of flights which starts at A after time t1 and
ends at B before time t2. Further, the departure time from any transit (intermediate) city
C is at least 30 mins after the arrival at C.
Your algorithm should be as efficient as possible.
## My Solution:
Earlier work seems to work mostly around exponential solution in terms of time
complexity because it seems like graph problem but it has a tricky concept which I have
applied.
I have used heap data structure to work around the solution first all the input flight and
> The algorithm stores all the flights data in a heap and sorts it according to departure
time.
> The flight with minimum departure time which lies between the time gap and is visited
is stored in the adjacency list at the arrival location.
> If another flight is find which has the price lower than the previous one than a node is
added in the front.
> This process is repeated until the departure_time of the first element of heap is more
than the time gap.
Language used : C++
So it is very efficient solution compared to exponential solution if n cities and m flights
are present time efficiency is approx mlogm + n

Github link : https://github.com/AnkitMahlawat/Projects/tree/master/FlightTripPlanner

# Project : ArmSim Simulator
## Problem Statement : ARM Assembly Program Simulator
● Parse the given an ARM assembly program as input to simulator and use an
appropriate representation to store it in an array, with each array element
representing an instruction.
● Resolve the addresses of the labels
● Simulation starts with the Program Counter (PC) pointing to the first instruction.
● Execute the instruction. Display the values of the Register File and Memory
contents as a result of executing the instruction.
● Proceed to the next instruction and continue the execution.
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
Github link :
https://github.com/AnkitMahlawat/Projects/tree/master/ArmSim/ArmSim_Simula
tor
# Project : Lift Controller
## Problem Statement :
Design an elevator control system for 2 elevators which moves across 4 floors.
Language used : vhdl
## My Solution:
The number of floors = 4. For each floor, a pair of slide switches represent UP and
DOWN request buttons on that floor. Total no. of slide switches used for this = 8. An
equal number of LEDs are used to indicate registration of these requests. Total no. of
LEDs used for this = 8. * For each lift, 4 slide switches represent floor request buttons
inside that lift. Total no. of slide switches used for this = 8. An equal number of LEDs are
used to indicate registration of these requests. Total no. of LEDs used for this = 8. *
Slide switches are used in a way that they are turned on, then immediately turned off
(by the user). * For each lift, one 7-seg display shows the floor on which that lift is and
another 7-seg display shows the status of the lift - moving up (u) / moving down(d) /
halted with door closed(c) / halted with door open(o). Used the small letters to display
the status of the lift on the Seven Segment Display (SSD). Total no. of 7-seg displays
used = 4. keet time delays for elevator going up(between adjacent floors) / down
(between adjacent floors)/door opening and door closing as 2s,2s, 0.5s and 0.5s
respectively. Once the lift reaches the destination floor, the doors are opened. If the lift
has to serve more requests the door closes after 1 second (can be overridden by
door_closed, door_open) else, it remains open. * The lift number displayed on the
Seven Segment Display (SSD) changes after the lift has reached the certain floor, but
before the door is opened. * For each lift, two push buttons are used for door open/close
requests. Total no. of push buttons used for this = 4. The door takes 0.5s to close after
the door_close button is pressed and 0.1s to open if door_open is pressed. If the lift has
to serve more requests the door closes after 1 second (can be overridden by
door_closed, door_open) else, it remains open. * One push button is used as a reset
button to facilitate testing by bringing the system to a known state (Both lifts at floor 0,
all requests reset, doors open). * Direction must be maintained (A lift going up goes up

first and a lift going down goes down first before reversing direction). If a user requests
a floor from inside the lift in the opposite direction of movement, the request is
registered but served only after completing requests in the original direction.
Data and control path are separately handled.<br>
This project is done in VHSIC Hardware Description Language used in system design.
And is tested on FPGA board.<br>
Github Link : https://github.com/AnkitMahlawat/Projects/tree/master/Lift%20Controller

# Extra Projects:
# Project : BigInt Package for sml
## Problem statement:
Can be read by clicking at this link
https://github.com/AnkitMahlawat/ProgrammingLanguage/blob/master/Assignment1/Bigi
nt-functor.pdf
## My Solution:
Language used : sml(functional language)
Used signature and functor concept of sml to implement the package all functions are
implemented
