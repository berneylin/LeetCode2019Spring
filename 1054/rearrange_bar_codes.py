from collections import Counter

class Solution:
    def rearrangeBarcodes(self, barcodes):
        if len(barcodes) <= 2:
            return barcodes
        cnt_dict = dict(Counter(barcodes))
        sorted_keys = [x[0] for x in sorted(list(cnt_dict.items()), key=lambda x: x[-1], reverse=True)]

        rtn_list = []
        lhs = sorted_keys[0]
        rhs = sorted_keys[1]

        for _ in range(len(barcodes)):
            rtn_list.append(lhs)
            rtn_list.append(rhs)

            cnt_dict[lhs] -= 1
            cnt_dict[rhs] -= 1

            







x = [1,1,1,1,2,2,3,3]
sol = Solution()
sol.rearrangeBarcodes(x)



