class Solution
{
public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {

        // in start make eat all to mouse2
        int sumofmouse2 = 0;
        for (auto i : reward2)
        {
            sumofmouse2 += i;
        }

        // now to maximize store the max difference to eat exactly k items by mouse 1 to maximize because mouse 1 can eat exactly k;

        priority_queue<int> pq;
        for (int i = 0; i < reward1.size(); i++)
        {
            pq.push(reward1[i] - reward2[i]);
        }
        int hold = sumofmouse2;
        while (k--)
        {

            hold += pq.top();
            pq.pop();
        }
        return hold;

        //         priority_queue<pair<int,int>>ph;
        //         priority_queue<pair<int,int>>du;
        //         if(reward1==reward2){
        //             sort(reward1.begin(),reward1.end());
        //             sort(reward2.begin(),reward2.end());
        //             int ind=reward1.size()-1;
        //             int sum=0;
        //             while(k--){
        //                 sum+=reward1[ind--];

        //             }
        //             return sum;
        //         }
        //         for(int i=0;i<reward1.size();i++){
        //             ph.push({reward1[i],i});
        //             du.push({reward2[i],i});
        //         }

        //         vector<bool>visited(reward1.size(),false);
        //         int hold=0;
        //         while(k--){
        //             pair<int,int>phla=ph.top();
        //             pair<int,int>dusra=du.top();
        //             cout<<phla.first<<" "<<dusra.first<<endl;
        //             // hold+=(phla.first+dusra.first);
        // //             if(phla.first>dusra.first){
        // //                 visited[phla.second]=true;
        // //                 hold+=phla.first;
        // //                 if(!visited[dusra.second]){
        // //                      // visited[dusra.second]=true;
        // //                     hold+=dusra.first;
        // //                 }

        // //             }else {
        // //                 visited[dusra.second]=true;
        // //                 hold+=dusra.first;
        // //                 if(!visited[phla.second]){
        // //                     // visited[phla.second]=true;
        // //                     hold+=phla.first;
        // //                 }

        // //             }
        //             if(dusra.second==phla.second&&phla.first==dusra.first){
        //                 hold+=phla.first;
        //             }else{
        //                 hold+=phla.first;
        //                 hold+=dusra.first;
        //             }

        //             ph.pop();
        //             du.pop();

        //         }
        //         return hold;
    }
};