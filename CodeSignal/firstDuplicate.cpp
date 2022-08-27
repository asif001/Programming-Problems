// Problem: https://app.codesignal.com/interview-practice/task/pMvymcahZ8dY4g75q/description

int solution(vector<int> a) {
    vector<int> numOfOccurences((int)a.size()+1, 0);
    
    for(int i = 0;i < a.size();i++){
        numOfOccurences[a[i]]++;
        if(numOfOccurences[a[i]] == 2){
            return a[i];
        }
    }
    
    return -1;
}
