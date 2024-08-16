from cyaron import *

io = IO("data.in")

op = 17 # 需要的数据类型

n = randint(10) # 随机点数
n = 10  # 点数
m = 10 + randint(10) # 随机边数
m = 25  # 边数
L = 1  # 数列的最小值
R = 10  # 数列的最大值

if op == 1:
    # 生成一个随机数
    x = randint(1, 100)
    io.input_writeln(x)
elif op == 2:
    # 生成一个有向图
    graph = Graph.graph(n, m, directed=True, weight_limit=(5, 300))
    io.input_writeln(n, m)
    io.input_writeln(graph)
elif op == 3:
    # 生成一个无向图
    graph = Graph.graph(n, m, directed=False, weight_limit=(1, 1))
    io.input_writeln(n, m)
    io.input_writeln(graph.to_str(output=Edge.unweighted_edge))
elif op == 4:
    # 生成一个n点，m边的无向图，禁止重边和自环
    graph = Graph.graph(n, m, self_loop=False, repeated_edges=False)
    io.input_writeln(n, m)
    io.input_writeln(graph.to_str(output=Edge.unweighted_edge))
elif op == 5:
    # 生成一条n个节点的链，是Graph.tree(n, 1, 0)的别名
    chain = Graph.chain(n)
    io.input_writeln(n)
    io.input_writeln(chain.to_str(output=Edge.unweighted_edge))
elif op == 6:
    # 生成一朵n个节点的菊花图，是Graph.tree(n, 0, 1)的别名
    flower = Graph.flower(n)
    io.input_writeln(n)
    io.input_writeln(flower.to_str(output=Edge.unweighted_edge))
elif op == 7:
    # 生成一棵n个节点的随机树
    tree = Graph.tree(n)
    io.input_writeln(n)
    io.input_writeln(tree.to_str(output=Edge.unweighted_edge))
elif op == 8:
    # 生成一棵n个节点的树，其中40%的节点呈现链状，35%的节点呈现菊花图状，剩余25%的节点随机加入
    tree = Graph.tree(n, 0.4, 0.35)
    io.input_writeln(n)
    io.input_writeln(tree.to_str(output=Edge.unweighted_edge))
elif op == 9:
    binary_tree = Graph.binary_tree(n)  # 生成一棵n个节点的随机二叉树
    io.input_writeln(n)
    io.input_writeln(binary_tree.to_str(output=Edge.unweighted_edge))
elif op == 10:
    # 生成一棵n个节点的二叉树，其中节点有40%的概率是左儿子，35%的概率是右儿子，25%的概率被随机选择
    binary_tree = Graph.binary_tree(n, 0.4, 0.35)
    io.input_writeln(n)
    io.input_writeln(binary_tree.to_str(output=Edge.unweighted_edge))
elif op == 11:
    # 生成一个 n 点，m 边的有向无环图
    graph = Graph.DAG(n, m)
    io.input_writeln(n, m)
    io.input_writeln(graph.to_str(output=Edge.unweighted_edge))
elif op == 12:
    # 生成一个 n 点，m 边的有向有环图
    graph = Graph.DAG(n, m, loop=True)
    io.input_writeln(n, m)
    io.input_writeln(graph.to_str(output=Edge.unweighted_edge))
elif op == 13:
    # 生成一个 n 点，m 边的无向联通图
    graph = Graph.UDAG(n, m)
    io.input_writeln(n, m)
    io.input_writeln(graph.to_str(output=Edge.unweighted_edge))
elif op == 14:
    # 生成一个N个点的凸包
    p = Polygon.convex_hull(n)
    io.input_writeln(n)
    io.input_writeln(p)
elif op == 15: # 有问题，无法正常使用
    # 生成一个N个点的简单多边型
    p = Polygon.simple_polygon(n)
    io.input_writeln(n)
    io.input_writeln(p)
elif op == 16:
    # 生成n个范围在[L,R]之间的不重复数字数列
    output = Vector.random(n, [(L, R)])
    io.input_writeln(n)
    io.input_writeln(output)
elif op == 17:
    # 生成n个[0,R]之间的随机数，会有重复
    output = Vector.random(n, [(L, R)], vector.VectorRandomMode.repeatable)
    io.input_writeln(n)
    io.input_writeln(output)
