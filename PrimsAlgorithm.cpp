#include <bits/stdc++.h>
using namespace std;


int main() {
    int q,u,v,n,m;
    vector<vector <int> > a(10009);
    cin>>q;
    while(q--)
    {
        cin>>n>>m;
        for(int i=0;i<m;i++)
            {
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        int s;
        cin>>s;
        int d[n+1];
        bool v[n+1];
        for(int i=0;i<=n;i++)
            v[i]=false,d[i]=0;
        list<int> q;
        v[s]=true;
     
        q.push_back(s);
        while(!q.empty())
            {
            
            int e=q.front();
            q.pop_front();
            for(int i=0;i<a[e].size();i++)
                {
                int t=a[e][i];
                if(!v[t])
                    {
                    v[t]=true;
                    d[t]=d[e]+6;
                    q.push_back(t);
                }
            }
            a[e].clear();
        }
        for(int i=1;i<=n;i++)
            {
            if(i!=s)
                {
                if(d[i]==0)
                    
                cout<<"-1 ";
            else
                cout<<d[i]<<" ";
        }
        }
        cout<<endl;
    }
    return 0;
}
