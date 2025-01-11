class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if k > len(s): return False

        count = Counter(s) # {a: 1, b: 2, ...}
        for c in count:
            if count[c] % 2 == 0:
                continue
            k -= 1

        return k >= 0