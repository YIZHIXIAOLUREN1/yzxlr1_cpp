# 读取第一行输入
first_line = input().split()
n = int(first_line[0])
Q = int(first_line[1])

# 读取第二行输入
second_line = input().split()
arr = []
for num in second_line:
    arr.append(int(num))

# 创建前缀和数组
pre = [0]  # 第一个元素是0
total = 0
for num in arr:
    total += num
    pre.append(total)

# 处理每个查询
for i in range(Q):
    query = input().split()
    l = int(query[0])
    r = int(query[1])
    
    # 计算区间和
    result = pre[r] - pre[l-1]
    print(result)


#powered by deepseek
#不知道需要什么东西的时候，就去学，要用到什么，你就学什么
#你已经不需要从互联网大海捞针，你可以问ai