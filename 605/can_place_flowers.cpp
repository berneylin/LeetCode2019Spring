class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int spaceCnt = 0;
        int flowerbedSize = flowerbed.size();
        for(int i=0;i<flowerbedSize;i++){
            if(spaceCnt>=n) break;
            if(flowerbed[i]) continue;
            else{
                if(i==0){
                    if(flowerbedSize==1) return flowerbed[i]==0;
                    else{
                        spaceCnt += flowerbed[1]==0?1:0;
                        flowerbed[0] = 1;
                    }
                }else if(i==flowerbedSize-1){
                    spaceCnt += flowerbed[i-1]==0?1:0;
                }else{
                    if(flowerbed[i-1]||flowerbed[i+1]) continue;
                    else{
                        spaceCnt++;
                        flowerbed[i] = 1;
                    }
                }
            }
        }



        return spaceCnt>=n;

    }
};