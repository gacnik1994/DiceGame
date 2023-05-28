Game with Dice

In this game we have 6 workers (A, B, C, D, E, F).
Workers work in chain one after another.
The amount of work thay can do is generate with 1d6 throw,
(randomly generated number from 1-6 in code). The work that workers do is stored 
in their work in progress storage for the first five workers(wpA, wpB, wpC, wpD, wpE).
The work from the last worker (F) is stored in TOTAL items that they build. First 
worker (A), can always make work per his dice throw. Other workers can make the work 
per their dice throw but only, if the storake in work in progress is big enough.
Othervase they can only take what is in the work in progress from previous worker.

The work proces lasts 10 day. Work in progress storage is transfered form prevous day.
If they want to have succesful 10 day thay have to make 30 parts at the end. of day 10.

---------------------------------------------------------------------------------------

My program (./DiceGame_v2/main.cpp) generated 10 random games and after runing the 
program a couple of times, the number was alway lower than 30. We are limited by the
1d6 throw. With max number of 6, we would have to have luck to generate final score of
30 or more. (Results are in ./results.txt)

In my second program (./DiceGame_v2_improvement), the throws are as follows:
A & F = 1d20, B & E = 1d10, C & D = 1d6. With this we have a chance to win, but win
percantage was stil not 100% ( not even 90 %). (Results are in 
./results_improvement.txt)




