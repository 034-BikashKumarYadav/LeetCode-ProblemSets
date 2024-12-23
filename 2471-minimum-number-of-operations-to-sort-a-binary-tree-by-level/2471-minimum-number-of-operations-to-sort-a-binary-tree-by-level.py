from collections import defaultdict, deque

class Solution:
    def minimumOperations(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        queue = deque([root])
        total_swaps = 0
        
        while queue:
            level_nodes = [node.val for node in queue]
            n = len(level_nodes)
            sorted_nodes = sorted(level_nodes)
            index_map = {v: i for i, v in enumerate(level_nodes)}
            
            visited = [False] * n
            
            for i in range(n):
                if visited[i] or index_map[sorted_nodes[i]] == i:
                    continue
                
                cycle_size = 0
                x = i
                
                while not visited[x]:
                    visited[x] = True
                    x = index_map[sorted_nodes[x]]
                    cycle_size += 1
                
                total_swaps += cycle_size - 1
            
            for _ in range(len(queue)):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        
        return total_swaps