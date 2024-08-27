class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

    vector<vector<pair<int,double>>>adj(n);
      //  vector<pair<int,double>>adj[n];

       

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});

        }
 

        vector<double>prob(n,0);

        priority_queue<pair<double,int>>pq;

        prob[start]=1;
        pq.push({1,start});

        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            double nodeP=it.first;

            for(auto it:adj[node])
            {
                int adjNode=it.first;
                double adjNP=it.second;

                if(prob[adjNode]<(nodeP*adjNP))
                {
                    prob[adjNode]=nodeP*adjNP;
                    pq.push({prob[adjNode],adjNode});
                }
            }
           
        }

        return prob[end];
        
    }
};