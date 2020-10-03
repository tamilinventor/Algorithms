# Prim's Spanning Tree Algorithm

Prim's algorithm to find minimum cost spanning tree (as Kruskal's algorithm) uses the greedy approach. Prim's algorithm shares a similarity with the shortest path first algorithms.

Prim's algorithm, in contrast with Kruskal's algorithm, treats the nodes as a single tree and keeps on adding new nodes to the spanning tree from the given graph.

To contrast with Kruskal's algorithm and to understand Prim's algorithm better, we shall use the same example −

![image](https://user-images.githubusercontent.com/65532584/94996056-eee7e780-05bf-11eb-9777-80cea5f031c4.png)

### Step 1 - Remove all loops and parallel edges

![image](https://user-images.githubusercontent.com/65532584/94996074-045d1180-05c0-11eb-8b15-54b5a864140f.png)

Remove all loops and parallel edges from the given graph. In case of parallel edges, keep the one which has the least cost associated and remove all others

![image](https://user-images.githubusercontent.com/65532584/94996089-163eb480-05c0-11eb-9b35-799fe45c9737.png)

### Step 2 - Choose any arbitrary node as root node

In this case, we choose S node as the root node of Prim's spanning tree. This node is arbitrarily chosen, so any node can be the root node. One may wonder why any video can be a root node. So the answer is, in the spanning tree all the nodes of a graph are included and because it is connected then there must be at least one edge, which will join it to the rest of the tree

### Step 3 - Check outgoing edges and select the one with less cost

After choosing the root node S, we see that S,A and S,C are two edges with weight 7 and 8, respectively. We choose the edge S,A as it is lesser than the other.

![image](https://user-images.githubusercontent.com/65532584/94996110-38d0cd80-05c0-11eb-8c64-83bb9d8abbb0.png)

Now, the tree S-7-A is treated as one node and we check for all edges going out from it. We select the one which has the lowest cost and include it in the tree.

![image](https://user-images.githubusercontent.com/65532584/94996118-45552600-05c0-11eb-9698-c96df349e4fd.png)

After this step, S-7-A-3-C tree is formed. Now we'll again treat it as a node and will check all the edges again. However, we will choose only the least cost edge. In this case, C-3-D is the new edge, which is less than other edges' cost 8, 6, 4, etc.

![image](https://user-images.githubusercontent.com/65532584/94996129-530aab80-05c0-11eb-9f5e-1ea643397e72.png)

After adding node D to the spanning tree, we now have two edges going out of it having the same cost, i.e. D-2-T and D-2-B. Thus, we can add either one. But the next step will again yield edge 2 as the least cost. Hence, we are showing a spanning tree with both edges included.

![image](https://user-images.githubusercontent.com/65532584/94996136-66b61200-05c0-11eb-9c1b-ea205186f1f9.png)

We may find that the output spanning tree of the same graph using two different algorithms is same.

