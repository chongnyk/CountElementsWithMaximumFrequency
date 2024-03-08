class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> frequencies;
        for(int num : nums){
            if(frequencies.find(num) != frequencies.end()){
                frequencies[num]++;
            }
            else {
                frequencies[num] = 1;
            }
        }

        int maxFreq = 0, elemCount = 0;
        unordered_map<int, int>::iterator freqIter;
        for(freqIter = frequencies.begin(); freqIter != frequencies.end(); freqIter++){
            if(freqIter->second > maxFreq){
                maxFreq = freqIter->second;
                elemCount = 1;
            }
            else if(freqIter->second == maxFreq){
                elemCount++;
            }
        }

        return elemCount * maxFreq;
    }
};
