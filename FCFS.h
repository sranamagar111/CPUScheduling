using namespace std;
class FCFS{
   public:
       int n,bt[20],wt[20],tat[20],i,j;
       float awt=0,atat=0;

       void fcfs(){
        cout<<"\tEnter total number of processes(maximum 20):";  //bt[] is of size 20
        cin>>n;

        cout<<"\n\tEnter Process Burst Time\n";
        for(i=0;i<n;i++)
        {
            cout<<"\t\tP["<<i+1<<"]:";
            cin>>bt[i];
        }

        wt[0]=0;    //waiting time for first process is 0

        //calculating waiting time
        for(i=1;i<n;i++)
        {
            wt[i]=0;
            for(j=0;j<i;j++)
                wt[i]+=bt[j];
        }

        cout<<"\n\tProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

        //calculating turnaround time
        for(i=0;i<n;i++)
        {
            tat[i]=bt[i]+wt[i];
            awt+=wt[i];
            atat+=tat[i];
            cout<<"\n\t P["<<i+1<<"]"<<"\t\t   "<<bt[i]<<"\t\t   "<<wt[i]<<"\t\t   "<<tat[i];
        }

        awt/=i;
        atat/=i;
        cout<<"\n\n\tAverage Waiting Time:"<<awt;
        cout<<"\n\tAverage Turnaround Time:"<<atat<<"\n\n\n";
        return;
       }
};
