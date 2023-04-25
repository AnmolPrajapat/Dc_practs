#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ns,ncs,timestamp,site;
    cout<<"Enter number of sites :";
    cin>>ns;
    cout<<"Enter number of sites which want to enter critical section:";
    cin>>ncs;
    vector<int> ts(ns,0);
    vector<int> request;
    map <int,int> mp;
    for(int i=0;i<ncs;i++)
    {
        cout<<"\nEnter timestamp:";
        cin>>timestamp;
        cout<<"Enter site number:";
        cin>>site;
        ts[site-1]=timestamp;
        request.push_back(site);
        mp[timestamp]=site;
    }

    cout<<"\nSites and Timestamp:\n";
    for(int i=0;i<ts.size();i++)
    {
        cout<<i+1<<" "<<ts[i]<<endl;
    }

    for(int i=0;i<request.size();i++)
    {
        cout<<"\n Request from site:"<<request[i]<<endl;
        for(int j=0;j<ts.size();j++)
        {
            if(request[i]!=(j+1))
            {
                if(ts[j]>ts[request[i]-1] || ts[j]==0)
                    cout<<j+1<<" Replied\n";
                else
                    cout<<j+1<<" Delayed\n";
            }}}

    cout<<endl;
    map<int,int>:: iterator it;
    it=mp.begin();
    int c=0;
    for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<"Site "<<it->second<<" entered Critical Section \n";
        if(c==0)
            cout<<"\nSimilarly,\n\n";
        c++;
    }
    return 0;
}

/*output :
Enter number of sites :5
Enter number of sites which want to enter critical section:3

Enter timestamp:2
Enter site number:2

Enter timestamp:3
Enter site number:3

Enter timestamp:1
Enter site number:4

Sites and Timestamp:
1 0
2 2
3 3
4 1
5 0

 Request from site:2
1 Replied
3 Replied
4 Delayed
5 Replied

 Request from site:3
1 Replied
2 Delayed
4 Delayed
5 Replied

 Request from site:4
1 Replied
2 Replied
3 Replied
5 Replied

Site 4 entered Critical Section 

Similarly,

Site 2 entered Critical Section 
Site 3 entered Critical Section*/