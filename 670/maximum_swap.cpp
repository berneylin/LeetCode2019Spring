class Solution
{
  public:
    int maximumSwap(int num)
    {
        if (num == 0)
            return 0;
        vector<int> vNums;
        int tmp = num;
        while (tmp)
        {
            vNums.insert(vNums.begin(), tmp % 10);
            tmp /= 10;
        }

        int maxIdx = getMaxMobileNumIdx(vNums);
        if (maxIdx == -1)
            return num;

        int minIdx = getMinMobileNumIdx(vNums, maxIdx);

        tmp = vNums[maxIdx];
        vNums[maxIdx] = vNums[minIdx];
        vNums[minIdx] = tmp;

        int ret = 0;
        for (int i = 0; i < vNums.size(); i++)
        {
            ret *= 10;
            ret += vNums[i];
        }

        return ret;
    }

  private:
    int getMaxMobileNumIdx(vector<int> &vNums)
    {
        int maxNum = -1, maxIdx = -1, len = vNums.size();
        for (int curr_idx = len - 1; curr_idx >= 0; curr_idx--)
        {
            bool l_flag = false, r_flag = true;
            int curr_num = vNums[curr_idx];
            for (int i = curr_idx + 1; i < len; i++)
            {
                if (curr_num < vNums[i])
                {
                    r_flag = false;
                    break;
                }
            }
            if (r_flag)
            {
                for (int i = curr_idx - 1; i >= 0; i--)
                {
                    if (curr_num > vNums[i])
                    {
                        l_flag = true;
                        break;
                    }
                }
            }
            if (l_flag && r_flag)
            {
                if(maxNum<curr_num){
                    maxNum = curr_num;
                    maxIdx = curr_idx;
                }
            }
        }
        return maxIdx;
    }

    int getMinMobileNumIdx(vector<int> &vNums, int maxIdx)
    {
        int maxMobileNum = vNums[maxIdx];
        int minIdx = -1;
        for (int i = 0; i < vNums.size(); i++)
        {
            if (vNums[i] < maxMobileNum)
            {
                minIdx = i;
                break;
            }
        }
        return minIdx;
    }
};