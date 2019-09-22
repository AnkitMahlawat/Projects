# Project : Flight Trip Planner
## Problem Statement :
In this Project you shall implement a rudimentary flight trip planner. The input is the set
of flights between various cities. It is given as a file. Each line of the file contains "city1
city2 departure-time arrival-time flight-no. price" This means that there is a flight called
"flight-no" (which is a string of the form XY012) from city1 to city2 which leaves city1 at
time "departure-time" and arrives city2 at time "arrival-time". Further the price of this
flight is "price" which is a positive integer. All times are given as a string of 4 digits in the
24hr format e.g. 1135, 0245, 2210. Assume that all city names are integers between 1
and a number N (where N is the total number of cities).<br>
**Note** that there could be multiple flights between two cities .<br>
The query that you have to answer is: given two cities "A" and "B", times "t1", "t2",
where t1 < t2, find the cheapest trip which leaves city "A" after time "t1" and arrives at
city "B" before time "t2". A trip is a sequence of flights which starts at A after time t1 and
ends at B before time t2. Further, the departure time from any transit (intermediate) city
C is at least 30 mins after the arrival at C.
Your algorithm should be as efficient as possible.
### Sample input file

=====================================================================  
7 # no of cities  
15 # no of lines with information of one flight in each line.

2 5 1026 1234 AI324 6234 # says that flight AI324 leaves from city 2 at 1026 and reaches city 5 at 1234 and costs Rs 6234

3 7 1221 1456 TG342 543

... # 13 more lines  
10 # no of queries to follow, one in each line  

3 6 0245 1735 # compute the cheapest trip from city 3 to city 6 which starts after 0245hrs and arrives before 1735.   
.... # 9 more queries  
\================================================================================  
### Output format  
For each query output the price of the cheapest trip (one number only) on one line. 

### Example output  
\=================================================================================  
34526  
34784   
73267  
....  
\========================================================================================

## My Solution:
Earlier work seems to work mostly around exponential solution in terms of time
complexity because it seems like graph problem but it has a tricky concept which I have
applied.
I have used heap data structure to work around the solution first all the input flight and
> The algorithm stores all the flights data in a heap and sorts it according to departure
time.
> The flight with minimum departure time which lies between the time gap and is visited
is stored in the adjacency list at the arrival location.
> If another flight is found which has the price lower than the previous one than a node is
added in the front.
> This process is repeated until the departure_time of the first element of heap is more
than the time gap.
Language used : C++
So it is very efficient solution compared to exponential solution if n cities and m flights
are present time efficiency is approx mlogm + n



