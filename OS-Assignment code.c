#include<stdio.h>


void scheduling_and_priority();


/*
Consider a scheduling approach which is non pre-emptive similar to shortest job next in nature. The priority of each job is dependent on its estimated run time, and also the amount of time it has spent waiting. Jobs gain higher priority the longer they wait, which prevents indefinite postponement. The jobs that have spent a long time waiting compete against those estimated to have short run times. The priority can be computed as :  Priority = 1+ Waiting time / Estimated run time
*/

int main()
{
  

  //calling the function 
  scheduling_and_priority();
  return 0;
}

/*
NOTE : BELOW FUNCTON IS RESPONSIBLE FOR SCHEDULING AND SORTING ! 
*/


void scheduling_and_priority(){


     printf("\t SCHEDULING STARTS HERE \n\n");
  long int n,i=0,j=0;
  //entering the no of the processes


  printf("Enter the total no of processes :");
  scanf("%ld",&n ); 
  double priority[n],avg_waiting,avg_turnaround,bTime[n],aTime[n],wTime[n],turn_a_TIME[n], process[n], tmpry, completionTime[n],min,sum=0,sum2=0,final_wait, turnaround_final, average_wait, t_avg;
  
  // ENTERING THE  PROCESSES AND THE BURST TIME/ARRVAL TIME
  for(i=0;i<n;i++)
  {
    printf("\nPlease enter the BURST TIME of the Process    (%d) : ", i+1 );
    scanf("%lf", &bTime[i]);
    printf("Please enter the ARRIVAL TIME of the Process  (%d) : ", i+1 );
    scanf("%lf", &aTime[i] );
    process[i]=i+1; // INCREMENTING THE COUNTER OF PROCESS
  }

  printf("\n\t YOUR ENTERED VALUES ARE :\n\n");
  for(i=0;i<n;i++){
      printf("\n\tProcess          : (%0.0lf)  " ,process[i]);
      printf("\n\tArrival Time     : %0.0lf",aTime[i]);
      printf("\n\tBurst Time       : %0.0lf",bTime[i]);
      printf("\n\n");
  }



// SORTING UNIT STARTS HERE : 

  printf("\n\t NOTE : SORTING OF PROCESSES BEGINS HERE \n");

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(aTime[i]<aTime[j])
      { 

        
        tmpry = bTime[j];
        bTime[j] = bTime[i];
        bTime [i] = tmpry;
	
	      tmpry = process[j];
        process[j] = process[i];
        process[i] = tmpry;

	    tmpry = aTime[j];
        aTime[j] = aTime[i];
        aTime[i] = tmpry;
      
      }
    }
  }

  //SORTING UNIT ENDED ! 



printf("\n\t NOTE : SORTING ENDED ! \n");
printf("\n\t UPDATED VALUES ARE AS FOLLOWS\n");
for(i=0;i<n;i++){
      printf("\n\tProcess          : (%0.0lf)  " ,process[i]);
      printf("\n\tArrival Time     : %0.0lf",aTime[i]);
      printf("\n\tBurst Time       : %0.0lf",bTime[i]);
      printf("\n\n");
  }



//USING THE FORMULA , Arrival time is less than or equal to execution time 

  long int k = 1;
  double b_time = 0;
  for(j=0;j<n;j++)
  {
    b_time = b_time + bTime[j];
    min = bTime[k];

    for(i=k;i<n;i++)
    {
      if((b_time >= aTime[i])&&(bTime[i]<min))
      {
        tmpry = bTime[k];
        bTime[k] = bTime[i];
        bTime[i] = tmpry;

        tmpry = aTime[k];
        aTime[k] = aTime[i];
        aTime[i] = tmpry;

        tmpry = process[k];
        process[k] = process[i];
        process[i] = tmpry;
      }
    }
    k++;
  }
  wTime[0] = 0;
  for(i=1;i<n;i++)
  {
    sum += bTime[i-1];
    wTime[i] = sum - aTime[i];
    final_wait += wTime[i]; 
  }
  average_wait = final_wait/n;
  for(i=0;i<n;i++)
  {
    sum2 += bTime[i];
    turn_a_TIME[i] = sum2 - aTime[i];
    turnaround_final += turn_a_TIME[i];
  }
  t_avg=turnaround_final/n;


printf("\n\t NOTE : CALCULATION OF WATITING TIME AND TURN AROUND TIME");
printf("\n\t NOTE : Constraint : Arrival time <= execution time\n\n");
printf("\n\t INTERMEDIATE VALUES ARE  : \n\n");

for(i=0;i<n;i++){
      printf("\n\tProcess          : (%0.0lf)  " ,process[i]);
      printf("\n\tArrival Time     : %0.0lf",aTime[i]);
      printf("\n\tBurst Time       : %0.0lf",bTime[i]);
      printf("\n\tWaiting Time     : %0.0lf" ,wTime[i] );
      printf("\n\tTurn Around Time : %0.0lf" , turn_a_TIME[i]);
      printf("\n\n");
  }





//Priority UNIT starts here 
//Priority = 1+ Waiting time / Estimated run time  


  completionTime[0] = bTime[0];
  for(i=1;i<n;i++)
  {
    completionTime[i] = completionTime[i-1] + bTime[i];
  }

  for(i=0;i<n;i++)
  {
    priority[i] = 1+wTime[i]/completionTime[i];
    printf("\n\t\tPriority   : %lf\n",priority[i]);
  }


  printf("\n\n\tResultant Values are as follows : \n\n");
  printf("\t=============================================================================\n");
  printf("\t| Process | Arrival Time | Burst Time |  Waiting Time  |  Turn Around Time  |\n");
  printf("\t=============================================================================\n");
  printf("\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[0],aTime[0],bTime[0],wTime[0],turn_a_TIME[0]);
  for(i=n-1;i>0;i--)
  {
    printf("\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[i],aTime[i],bTime[i],wTime[i],turn_a_TIME[i]);
  }
    printf("\t=============================================================================\n");



  printf("\n\n");
  printf("=========================================");
  printf("\n|  Average TURN AROUND TIME  : %lf | " ,t_avg);
  printf("\n|  Average WATITING TIME     : %lf | ",average_wait);
  printf("\n=========================================\n");


}