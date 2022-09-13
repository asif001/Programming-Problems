// Problem: https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastIndexStorage[256] = {0};
        
        for(int i = 0; i < s.length();i++){
            lastIndexStorage[s[i]] = i;
        }
        
        vector<int> partitions;
        int partition_end = -1;
        int current_partition = -1;
        
        for(int i = 0; i < s.length();i++){
            if(i <= partition_end){
                partitions[current_partition]++;
                partition_end = max(partition_end, lastIndexStorage[s[i]]);
            }else{
                partitions.push_back(1);
                current_partition++;
                partition_end = lastIndexStorage[s[i]];
            }
        }
        
        return partitions;
    }
};
