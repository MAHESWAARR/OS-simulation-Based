# OS-simulation Based



# qns

Consider a scheduling approach which is non pre-emptive similar to shortest job next in nature. The priority of each job is dependent on its estimated run time, and also the amount of time it has spent waiting. Jobs gain higher priority the longer they wait, which prevents indefinite postponement. The jobs that have spent a long time waiting compete against those estimated to have short run times. The priority can be computed as : Priority = 1+ Waiting time / Estimated run time.

Write a program to implement such an algorithm. Ensure

1. The input is given dynamically at run time by the user.
2. The priority of each process is visible after each unit of time.
3. The gantt chart is shown as an output.
4. Calculate individual waiting time and average waiting time.

# report



Report on the given code:

The given code implements a scheduling approach that is non-preemptive and similar to the shortest job next (SJN) scheduling algorithm. The priority of each job is calculated based on its estimated run time and the amount of time it has spent waiting. Jobs that have spent a longer time waiting gain higher priority, which prevents indefinite postponement. The priority of a job is computed using the formula:

Priority = 1 + Waiting time / Estimated run time

The code takes input from the user for the total number of processes and their respective burst times and arrival times. It then sorts the processes based on their arrival times in ascending order using a selection sort algorithm.

After sorting the processes, the code calculates the waiting time and turn around time for each process. It uses a loop to iterate through the processes and calculates the waiting time and turn around time using the formulas:

Waiting Time = Sum of burst times of previous processes - Arrival time of the current process
Turn Around Time = Sum of burst times of previous processes + Burst time of the current process - Arrival time of the current process

Finally, the code calculates the average waiting time and average turn around time by dividing the sum of waiting times and turn around times by the total number of processes.

The code provides intermediate values for each process, including the process number, arrival time, burst time, waiting time, and turn around time, which are displayed as output.

It is worth mentioning that the code does not include error handling for invalid input or handle cases where two processes have the same arrival time. Additionally, the code does not handle cases where the estimated run time of a job is zero, which may result in division by zero and unexpected behavior. These are some potential issues that could be addressed to make the code more robust.
  
 
