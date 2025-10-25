import random
import sys
from collections import deque

class DataGenerator:
    def __init__(self, seed=None):
        if seed is None:
            seed = random.randint(1, 1000000)
        random.seed(seed)
        self.seed = seed
        
    def generate_maze(self, n, m, connectivity=0.7):
        """生成随机迷宫，保证一定连通性"""
        # 初始化所有房间，默认四面都是墙
        maze = [[[0, 0, 0, 0] for _ in range(m)] for _ in range(n)]
        
        # 使用BFS确保连通性
        visited = [[False] * m for _ in range(n)]
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]  # 上右下左
        
        # 从随机点开始
        start_x, start_y = random.randint(0, n-1), random.randint(0, m-1)
        queue = deque([(start_x, start_y)])
        visited[start_x][start_y] = True
        
        while queue:
            x, y = queue.popleft()
            
            # 随机打乱方向
            dirs = list(range(4))
            random.shuffle(dirs)
            
            for d in dirs:
                dx, dy = directions[d]
                nx, ny = x + dx, y + dy
                
                if 0 <= nx < n and 0 <= ny < m:
                    # 有一定概率打通墙壁
                    if random.random() < connectivity:
                        maze[x][y][d] = 1
                        maze[nx][ny][(d + 2) % 4] = 1
                        
                    if not visited[nx][ny]:
                        visited[nx][ny] = True
                        queue.append((nx, ny))
        
        # 确保起点和终点附近有通路
        return maze
    
    def generate_safe_path(self, maze, starts, checkpoints, max_steps=500):
        """生成一条安全的随机路径"""
        n, m = len(maze), len(maze[0])
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]  # 上右下左
        
        # 选择起点和检查点
        start = random.choice(starts)
        checkpoint = random.choice(checkpoints)
        
        # 使用A*算法找路径
        def heuristic(a, b):
            return abs(a[0] - b[0]) + abs(a[1] - b[1])
        
        open_set = [(heuristic(start, checkpoint), 0, start[0], start[1], [])]
        closed_set = set()
        
        while open_set:
            open_set.sort()
            _, steps, x, y, path = open_set.pop(0)
            
            if (x, y) in closed_set:
                continue
                
            closed_set.add((x, y))
            new_path = path + [(x, y)]
            
            if (x, y) == checkpoint:
                # 找到路径后，随机绕路增加长度（但不超过max_steps）
                final_path = self._extend_path(maze, new_path, max_steps)
                return final_path, start, checkpoint
            
            for d in range(4):
                if maze[x][y][d] == 1:
                    dx, dy = directions[d]
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < m and (nx, ny) not in closed_set:
                        new_steps = steps + 1
                        priority = new_steps + heuristic((nx, ny), checkpoint)
                        open_set.append((priority, new_steps, nx, ny, new_path))
        
        # 如果找不到路径，重新生成迷宫
        return None, None, None
    
    def _extend_path(self, maze, path, max_steps):
        """扩展路径，增加随机绕路"""
        if len(path) >= max_steps:
            return path[:max_steps]
            
        n, m = len(maze), len(maze[0])
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        current_path = path.copy()
        
        # 在路径中间随机选择点进行绕路
        for _ in range(random.randint(0, 3)):  # 绕路次数
            if len(current_path) >= max_steps - 10:
                break
                
            # 随机选择路径中的一个点（除了起点和终点）
            if len(current_path) > 5:
                idx = random.randint(2, len(current_path) - 3)
                center_x, center_y = current_path[idx]
                
                # 尝试找到附近的环路线路
                for attempt in range(10):
                    detour = self._find_detour(maze, center_x, center_y, 
                                             current_path[idx-1], current_path[idx+1])
                    if detour and len(current_path) + len(detour) - 3 <= max_steps:
                        current_path = current_path[:idx] + detour + current_path[idx+1:]
                        break
        
        return current_path[:max_steps]
    
    def _find_detour(self, maze, x, y, prev, next_pos):
        """在给定点附近找绕路"""
        n, m = len(maze), len(maze[0])
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        
        # 找到所有可用的邻居（除了prev和next）
        neighbors = []
        for d in range(4):
            dx, dy = directions[d]
            nx, ny = x + dx, y + dy
            if (0 <= nx < n and 0 <= ny < m and maze[x][y][d] == 1 and 
                (nx, ny) != prev and (nx, ny) != next_pos):
                neighbors.append((nx, ny, d))
        
        if len(neighbors) < 2:
            return None
            
        # 随机选择两个邻居创建小环路
        random.shuffle(neighbors)
        path1 = neighbors[0]
        path2 = neighbors[1]
        
        # 检查是否能形成环路
        for d1 in range(4):
            dx1, dy1 = directions[d1]
            nx1, ny1 = path1[0] + dx1, path1[1] + dy1
            if (nx1, ny1) == (path2[0], path2[1]) and maze[path1[0]][path1[1]][d1] == 1:
                return [(x, y), (path1[0], path1[1]), (path2[0], path2[1]), (x, y)]
        
        return None
    
    def generate_scp_movements(self, maze, safe_path, num_scps=3):
        """生成SCP的移动轨迹，确保不会干扰安全路径"""
        n, m = len(maze), len(maze[0])
        T = len(safe_path)
        
        scp_data = []
        scp_types = []
        
        # 随机选择SCP类型
        available_scps = ['173', '096', '106', '939']
        #selected_scps = random.sample(available_scps, min(num_scps, len(available_scps)))
        
        for scp_type in available_scps:
            scp_types.append(scp_type)
            scp_path = []
            
            if scp_type == '173':
                # SCP-173：确保不在玩家当前时刻的直线上
                for t in range(T):
                    player_x, player_y = safe_path[t]
                    
                    # 找到不在玩家同行同列的位置
                    attempts = 0
                    while attempts < 100:
                        x, y = random.randint(0, n-1), random.randint(0, m-1)
                        if x != player_x and y != player_y:
                            # 检查是否在畅通无阻的直线上
                            if x == player_x:
                                # 同一行，检查是否畅通
                                blocked = False
                                min_y, max_y = min(y, player_y), max(y, player_y)
                                for check_y in range(min_y + 1, max_y):
                                    dir_idx = 1 if y > player_y else 3
                                    if maze[player_x][check_y][dir_idx] == 0:
                                        blocked = True
                                        break
                                if not blocked:
                                    continue
                            elif y == player_y:
                                # 同一列，检查是否畅通
                                blocked = False
                                min_x, max_x = min(x, player_x), max(x, player_x)
                                for check_x in range(min_x + 1, max_x):
                                    dir_idx = 2 if x > player_x else 0
                                    if maze[check_x][player_y][dir_idx] == 0:
                                        blocked = True
                                        break
                                if not blocked:
                                    continue
                            break
                        attempts += 1
                    
                    scp_path.append((x, y,0))  # 最后一个0是占位
                    
            elif scp_type == '096':
                # SCP-096：确保不面向玩家且畅通无阻
                for t in range(T):
                    player_x, player_y = safe_path[t]
                    
                    # 随机位置和朝向
                    x, y = random.randint(0, n-1), random.randint(0, m-1)
                    direction = random.randint(0, 3)
                    
                    # 如果面向玩家且畅通无阻，调整朝向
                    directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
                    dx, dy = directions[direction]
                    
                    # 检查是否面向玩家
                    if ((direction == 0 and player_x < x and player_y == y) or
                        (direction == 1 and player_y > y and player_x == x) or
                        (direction == 2 and player_x > x and player_y == y) or
                        (direction == 3 and player_y < y and player_x == x)):
                        
                        # 检查是否畅通无阻
                        blocked = False
                        if player_x == x:  # 同一行
                            min_y, max_y = min(y, player_y), max(y, player_y)
                            for check_y in range(min_y + 1, max_y):
                                dir_idx = 1 if player_y > y else 3
                                if maze[x][check_y][dir_idx] == 0:
                                    blocked = True
                                    break
                        else:  # 同一列
                            min_x, max_x = min(x, player_x), max(x, player_x)
                            for check_x in range(min_x + 1, max_x):
                                dir_idx = 2 if player_x > x else 0
                                if maze[check_x][y][dir_idx] == 0:
                                    blocked = True
                                    break
                        
                        if not blocked:
                            # 调整朝向
                            direction = (direction + random.randint(1, 3)) % 4
                    
                    scp_path.append((x, y, direction))
                    
            elif scp_type == '106':
                # SCP-106：确保传送范围不包含玩家下一步位置
                for t in range(T):
                    player_x, player_y = safe_path[min(t, T-1)]
                    L = random.randint(2, 5)  # 精力值
                    
                    # 找到不在玩家L范围内的位置
                    attempts = 0
                    while attempts < 100:
                        x, y = random.randint(0, n-1), random.randint(0, m-1)
                        distance_sq = (x - player_x)**2 + (y - player_y)**2
                        if distance_sq > L**2:
                            break
                        attempts += 1
                    
                    scp_path.append((x, y, L))
                    
            elif scp_type == '939':
                # SCP-939：确保不连续两个时刻和玩家在一起
                for t in range(T):
                    player_x, player_y = safe_path[t]
                    
                    if t > 0 and scp_path[t-1][0] == player_x and scp_path[t-1][1] == player_y:
                        # 上个时刻在一起，这个时刻要分开
                        x, y = random.randint(0, n-1), random.randint(0, m-1)
                        while x == player_x and y == player_y:
                            x, y = random.randint(0, n-1), random.randint(0, m-1)
                    else:
                        # 可以随机位置
                        x, y = random.randint(0, n-1), random.randint(0, m-1)
                    
                    scp_path.append((x, y,0))
            
            scp_data.append((scp_type, scp_path))
        
        
        return scp_data
    
    def generate_century_problem(self, maze, safe_path, scp_data):
        """生成世纪难题场景（173和096在同一方向且畅通无阻）"""
        T = len(safe_path)
        n, m = len(maze), len(maze[0])
        
        # 找一个合适的时刻插入世纪难题
        problem_time = random.randint(1, T-2)
        player_x, player_y = safe_path[problem_time]
        
        # 找到173和096的数据
        scp173_data = None
        scp096_data = None
        
        for scp_type, path in scp_data:
            if scp_type == '173':
                scp173_data = path
            elif scp_type == '096':
                scp096_data = path
        
        if scp173_data and scp096_data:
            # 选择一个方向（上右下左）
            direction = random.randint(0, 3)
            directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
            dx, dy = directions[direction]
            
            # 放置173和096在同一个方向但不同距离
            distance_173 = random.randint(2, min(5, max(n, m)//2))
            distance_096 = distance_173 + random.randint(1, 3)
            
            scp173_x = player_x + dx * distance_173
            scp173_y = player_y + dy * distance_173
            scp096_x = player_x + dx * distance_096  
            scp096_y = player_y + dy * distance_096
            
            # 确保位置有效且路径畅通
            if (0 <= scp173_x < n and 0 <= scp173_y < m and 
                0 <= scp096_x < n and 0 <= scp096_y < m):
                
                # 检查路径是否畅通
                畅通 = True
                if direction in [0, 2]:  # 上下方向
                    min_x, max_x = min(player_x, scp096_x), max(player_x, scp096_x)
                    for x in range(min_x + 1, max_x):
                        dir_idx = 2 if scp096_x > player_x else 0
                        if maze[x][player_y][dir_idx] == 0:
                            畅通 = False
                            break
                else:  # 左右方向
                    min_y, max_y = min(player_y, scp096_y), max(player_y, scp096_y)
                    for y in range(min_y + 1, max_y):
                        dir_idx = 1 if scp096_y > player_y else 3
                        if maze[player_x][y][dir_idx] == 0:
                            畅通 = False
                            break
                
                if 畅通:
                    # 更新SCP位置
                    scp173_data[problem_time] = (scp173_x, scp173_y, 0)
                    scp096_data[problem_time] = (scp096_x, scp096_y, direction)
                    
                    # 确保玩家在这个时刻有安全的选择（不能移动）
                    # 这需要在路径规划时特别处理
        
        return scp_data
    
    def generate_test_case(self, n=30, m=30, min_steps=100, max_steps=400):
        """生成完整的测试用例"""
        # 生成迷宫
        maze = self.generate_maze(n, m)
        
        # 生成起点和检查点
        starts = [(random.randint(n//2, n-1), random.randint(m//4, 3*m//4)) for _ in range(2)]
        checkpoints = [(0, random.randint(1, m//4)), (0, random.randint(3*m//4, m-1))]
        
        # 生成安全路径
        safe_path, start, checkpoint = self.generate_safe_path(maze, starts, checkpoints, max_steps)
        
        if safe_path is None:
            # 重新生成
            return self.generate_test_case(n, m, min_steps, max_steps)
        
        T = len(safe_path)
        
        # 生成SCP移动
        scp_data = self.generate_scp_movements(maze, safe_path)
        
        # 有概率添加世纪难题
        if random.random() < 0.3:  # 30%概率出现世纪难题
            scp_data = self.generate_century_problem(maze, safe_path, scp_data)
        
        # 构建输出
        output = []
        
        # 第一行：N M
        output.append(f"{n} {m}")
        
        # 起点和检查点
        for x, y in starts:
            output.append(f"{x} {y}")
        for x, y in checkpoints:
            output.append(f"{x} {y}")
        
        # 迷宫数据
        for i in range(n):
            row = []
            for j in range(m):
                row.append(''.join(str(x) for x in maze[i][j]))
            output.append(' '.join(row))
        
        # 步数T
        output.append(str(T))
        
        # 每个时刻的SCP信息
        for t in range(T):
            time_data = []
            for scp_type, path in scp_data:
                x, y, extra = path[t]
                if scp_type == '173':
                    time_data.append(f"{x} {y} {0}")
                elif scp_type == '096':
                    time_data.append(f"{x} {y} {extra}")
                elif scp_type == '106':
                    time_data.append(f"{x} {y} {extra}")
                elif scp_type == '939':
                    time_data.append(f"{x} {y} {0}")
            
            output.extend(time_data)
        
        return '\n'.join(output), T, self.seed

def main():
    """主函数，生成多个测试用例"""
    import argparse
    
    parser = argparse.ArgumentParser(description='生成SCP逃生问题的测试数据')
    parser.add_argument('--num-cases', type=int, default=5, help='生成的测试用例数量')
    parser.add_argument('--min-steps', type=int, default=100, help='最小步数')
    parser.add_argument('--max-steps', type=int, default=400, help='最大步数')
    parser.add_argument('--size', type=int, default=30, help='迷宫大小N和M')
    parser.add_argument('--seed', type=int, help='随机种子')
    
    args = parser.parse_args()
    
    generator = DataGenerator(args.seed)
    
    for i in range(args.num_cases):
        print(f"生成测试用例 {i+1}...")
        test_case, steps, seed = generator.generate_test_case(
            n=args.size, 
            m=args.size,
            min_steps=args.min_steps,
            max_steps=args.max_steps
        )
        
        filename = f"testcase_{i+1}_steps{steps}.txt"
        with open(filename, 'w', encoding='utf-8') as f:
            f.write(test_case)
        
        print(f"已生成: {filename} (步数: {steps}, 种子: {seed})")
    
    print(f"\n共生成 {args.num_cases} 个测试用例")

if __name__ == "__main__":
    main()
