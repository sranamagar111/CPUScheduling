using namespace std;
class Priority{
    public:
        int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,awt,atat;

        void priority(){
            cout<<"\tEnter total number of processes(maximum 20):";  //bt[] is of size 20
            cin>>n;

            cout<<"\n\tEnter Process Burst Time and Priority\n";
            for(i=0;i<n;i++)
            {
                cout<<"\t\tP["<<i+1<<"]:";
                cout<<"\n\t\tBurst Time:";
                cin>>bt[i];
                cout<<"\t\tPriority:";
                cin>>pr[i];
                p[i]=i+1;           //contains process number
            }

            //sorting burst time, priority and process number in ascending order using selection sort
            for(i=0;i<n;i++)
            {
                pos=i;
                for(j=i+1;j<n;j++)
                {
                    if(pr[j]<pr[pos])
                        pos=j;
                }

                temp=pr[i];
                pr[i]=pr[pos];
                pr[pos]=temp;

                temp=bt[i];
                bt[i]=bt[pos];
                bt[pos]=temp;

                temp=p[i];
                p[i]=p[pos];
                p[pos]=temp;
            }

            wt[0]=0;            //waiting time for first process is zero

            //calculate waiting time
            for(i=1;i<n;i++)
            {
                wt[i]=0;
                for(j=0;j<i;j++)
                    wt[i]+=bt[j];

                total+=wt[i];
            }

            awt=total/n;      //average waiting time
            total=0;

            cout<<"\n\tProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
            for(i=0;i<n;i++)
            {
                tat[i]=bt[i]+wt[i];     //calculate turnaround time
                total+=tat[i];
                cout<<"\n\t P["<<i+1<<"]"<<"\t\t   "<<bt[i]<<"\t\t   "<<wt[i]<<"\t\t   "<<tat[i];
            }

            atat=total/n;     //average turnaround time
            cout<<"\n\n\tAverage Waiting Time:"<<awt;
            cout<<"\n\tAverage Turnaround Time:"<<atat<<"\n\n\n";
        }
};
