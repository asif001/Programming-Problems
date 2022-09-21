// Problem: https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        int min = 0;
        int index = -1;
        
        for(int i = 0;i < n;i++){
            sum += (gas[i] - cost[i]);
            if(sum < min){
                min = sum;
                index = i;
            }
        }
        
        return sum < 0 ? -1 : (index+1)%n;
    }
};
