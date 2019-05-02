#include<iostream>
#include<conio.h>
#include"FCFS.h"
#include"NonPreemptiveSJF.h"
#include"Priority.h"
#include"RoundRobin.h"
#include"WeightedRoundRobin.h"
using namespace std;
class CPUSchedule{
    public:
        void fcfs(){
            FCFS f1;
            f1.fcfs();
        }

        void sjfP(){

        }

        void sjfNP(){
            NonPreemptiveSJF s1;
            s1.nonPreemptiveSJF();
        }

        void priorityNP(){
            Priority p1;
            p1.priority();
        }

        void roundRobin(){
            RoundRobin rr;
            rr.roundRobin();
        }
        void weightedRoundRobin(){
            WeightedRoundRobin rr;
            rr.weightedRoundRobin();
        }

};
int main(){
    int choice;
    char con;
    a:
    cout<<"\n\t\t**************************************************"<<endl;
    cout<<"\t\t*           CPU SCHEDULING ALGORITHM             *"<<endl;
    cout<<"\t\t**************************************************"<<endl;
    cout<<"\t\t*           1. FIFO                              *"<<endl;
    cout<<"\t\t*           2. SJF (Non-Preemptive)              *"<<endl;
    cout<<"\t\t*           3. Priority                          *"<<endl;
    cout<<"\t\t*           4. Round Robin                       *"<<endl;
    cout<<"\t\t*           5. Weighted Round Robin              *"<<endl;
    cout<<"\t\t**************************************************"<<endl;
    cout<<"\t\t* Enter number to chose which algo to run(1-5): ";
    cin>>choice;
    cout<<"\t\t**************************************************\n\n"<<endl;
    CPUSchedule cs; //Instantiation of object of cpuschedule class
    switch(choice){
        case 1:
            cs.fcfs();
            break;
        case 2:
            cs.sjfNP();
            break;
        case 3:
            cs.priorityNP();
            break;
        case 4:
            cs.roundRobin();
            break;
        case 5:
            cs.weightedRoundRobin();
            break;
        default:
        {
            cout<<"\t\t\t---> INVALID INPUT\n\t\t\t---> Input number 1/2/3/4/5: "<<endl;
            goto a;
        }
    }
}
