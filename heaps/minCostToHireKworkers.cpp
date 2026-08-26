#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int n = wage.size();

        vector<pair<double,int>> worker_ratio(n);

        for(int i=0;i<n;i++){
            worker_ratio[i] = {(double)wage[i]/quality[i], quality[i]};
        }

        sort(worker_ratio.begin(), worker_ratio.end());
        int sum_quality = 0;
        priority_queue<int,vector<int>> pq;


        for(int i=0;i<k;i++){
            pq.push(worker_ratio[i].second); //push only the worker's quality
            sum_quality+=worker_ratio[i].second;
        }

        double manager_ratio = worker_ratio[k-1].first;
        double res = manager_ratio * sum_quality;

        for(int manager = k ;manager < n;manager++){

            double manager_ratio = worker_ratio[manager].first;

            pq.push(worker_ratio[manager].second);
            sum_quality+=worker_ratio[manager].second;

            if(pq.size() > k){
                sum_quality-= pq.top();
                pq.pop();
            }

            res = min(res, manager_ratio*sum_quality);

        }
        
        
        return res;
    }
};