/*There is one meeting room in a firm. There are N meetings in the form of (Si, Fi) where Si is the start time of meeting i and Fi is finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers*/
#include<iostream>
using namespace std;


void maxMeetings(int s[],int f[],int n){
    int i,j,timelimit,temp,temp1;
    for(i=0;i<n-2;i++){
        for(j=0;j<n-2-i;j++){
            if(f[j]>f[j+1]){
                temp=f[j+1];
                f[j+1]=f[j];
                f[j]=temp;
                temp1=s[j+1];
                s[j+1]=s[j];
                s[j]=temp1;
            }
        }
    }
    cout<<"after swapping :"<<endl;
    for(i=0;i<n;i++){
        cout<<"Meeting "<<i<<": "<<s[i]<<" to "<<f[i]<<endl;
    }
    cout<<"Maximum meetings are ---->";
    cout<<"Meeting 1: "<<s[0]<<" to "<<f[0]<<endl;
    timelimit=f[0];
    for(i=1;i<n;i++){
        if(s[i]>=timelimit){
            cout<<"Meeting "<<i+1<<": "<<s[i]<<" to "<<f[i]<<endl;
            timelimit=f[i];
        }
    }
}

int main(){
    int s[10],f[10],i,n;    
    cout<<"Enter the number of meetings: ";
    cin>>n;
    cout<<"Enter the start time ----> "<<endl;
    for(i=0;i<n;i++){
        cin>>s[i];
    }
    cout<<"Enter the end time ----> "<<endl;
    for(i=0;i<n;i++){
        cin>>f[i];
    }
    maxMeetings(s,f,n);
    return 0;
}
