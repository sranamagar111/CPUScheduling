using namespace std;
class WeightedRoundRobin{
    public:
        int i,B[20],B_rem[20],Q,t,k,W[20],n,Bu[20],Tat[20],Wt[20];
        float Awt=0.0,Atat=0.0;
        float Twt=0.0;
        float Ttat=0.0;

        void weightedRoundRobin(){
            cout<<"\tEnter total number of processes(maximum 20):";  //bt[] is of size 20
            cin>>n;
            for(i=1;i<=n;i++){
            cout<<"\tEnter The BurstTime for Process p"<<i<<"= ";
            cin>>Bu[i];
            }
            for(i=1;i<=n;i++)
            {
             B[i]=Bu[i];
             cout<<"\n\tBurst Time for process P"<<i<<"=";
             cout<<B[i];
             cout<<"\n\tWeight for process P"<<i<<"=";
             cin>>W[i];
            }
            cout<<"\n\tInput Quantum: ";
             cin>>Q;
            for(i=1; i<=n; i++)
                B_rem[i]=B[i];
                t=0;
                while(1)
                {
                    bool done =true;
                    for(int i=1; i<=n;i++)
                    {
                        k=W[i];
                        for(int j=1;j<=k;j++)
                        {
                            if(B_rem[i]>0)
                            {
                                done=false;
                                if(B_rem[i]>Q)
                                {
                                    t=t+Q;
                                    B_rem[i]=B_rem[i]-Q;
                                }else
                                    {
                                    t=t+B_rem[i];
                                    Wt[i]=t-B[i];
                                    B_rem[i]=0;
                                    }
                            }
                        }
                    }
                    if(done==true)
                    break;
                }
                cout<<"\n\tProcess\t\tBurst Time\tWeight\tWaiting Time\tTurnaround Time";
                //calculating Average Waiting Time and Average Turnaround Time
            for(i=1;i<=n;i++)
                {
                    Tat[i]=B[i]+Wt[i];
                    cout<<"\n\t P["<<i+1<<"]"<<"\t\t   "<<B[i]<<"\t\t   "<<W[i]<<"\t\t   "<<Wt[i]<<"\t\t   "<<Tat[i];
                }
                for(i=1;i<=n;i++)
                {
                    Twt=Twt+Wt[i];
                    Ttat=Ttat+Tat[i];
                }
                Awt=(float)Twt/n;
                Atat=(float)Ttat/n;
                cout<<"\n\n\tAverage Waiting Time:"<<Awt;
                cout<<"\n\tAverage Turnaround Time:"<<Atat<<"\n\n\n";

            }

};
