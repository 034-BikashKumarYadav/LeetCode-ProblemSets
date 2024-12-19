class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        
        prefix_sum, expected_sum, chunk_count = 0, 0, 0
        
        for i, num in enumerate(arr):
            # Update the running prefix sum for the array
            prefix_sum += num
            # Calculate the expected sum for the sorted array up to index i
            expected_sum += i
            # If prefix sum matches the expected sum, a chunk ends here
            if prefix_sum == expected_sum:
                chunk_count += 1
        
        return chunk_count