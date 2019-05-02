using namespace std;
class RoundRobin{

    public:
        int count,j,n,time,remain,flag=0,time_quantum;
        int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
        float awt=0, atat=0;

        void roundRobin(){
            cout<<"\tEnter total number of processes(maximum 20):";  //bt[] is of size 20
            cin>>n;

            remain=n;

            cout<<"\n\tEnter Arrival Time and Process Burst Time\n";
            for(count=0;count<n;count++)
            {
                cout<<"\t\tP["<<count+1<<"]:";
                cout<<"\n\t\tArrival Time: ";
                cin>>at[count];
                cout<<"\t\tBrust Time: ";
                cin>>bt[count];
                rt[count]=bt[count];
            }
            cout<<"\n\tEnter Time Quantum: ";
            cin>>time_quantum;
            cout<<"\n\tProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time";
            for(time=0,count=0;remain!=0;)
            {
            if(rt[count]<=time_quantum && rt[count]>0)
            {
              time+=rt[count];
              rt[count]=0;
              flag=1;
            }
            else if(rt[count]>0)
            {
              rt[count]-=time_quantum;
              time+=time_quantum;
            }
            if(rt[count]==0 && flag==1)
            {
              remain--;
              cout<<"\n\t P["<<count+1<<"]"<<"\t\t   "<<at[count]<<"\t\t   "<<bt[count]<<"\t\t   "<<time-at[count]-bt[count]<<"\t\t   "<<time-at[count];
              wait_time+=time-at[count]-bt[count];
              turnaround_time+=time-at[count];
              flag=0;
            }
            if(count==n-1)
              count=0;
            else if(at[count+1]<=time)
              count++;
            else
              count=0;
            }
            awt=wait_time*1.0/n;
            atat=turnaround_time*1.0/n;
            cout<<"\n\n\tAverage Waiting Time:"<<awt;
            cout<<"\n\tAverage Turnaround Time:"<<atat<<"\n\n\n";
        }

};
