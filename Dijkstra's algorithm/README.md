# Dijkstra's algorithm
Dijkstra's algorithm (or Dijkstra's Shortest Path First algorithm, SPF algorithm) is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks.

Let's study the algorithm with an explained example! Let's calculate the shortest path between node C and the other nodes in our graph:

![image](https://user-images.githubusercontent.com/65532584/94994959-9bbe6680-05b8-11eb-87ba-98dff0e58dd8.png)

During the algorithm execution, we'll mark every node with its minimum distance to node C (our selected node). For node C, this distance is 0. For the rest of nodes, as we still don't know that minimum distance, it starts being infinity (∞):

![image](https://user-images.githubusercontent.com/65532584/94994978-b55fae00-05b8-11eb-920e-508671720318.png)

We'll also have a current node. Initially, we set it to C (our selected node). In the image, we mark the current node with a red dot.

Now, we check the neighbours of our current node (A, B and D) in no specific order. Let's begin with B. We add the minimum distance of the current node (in this case, 0) with the weight of the edge that connects our current node with B (in this case, 7), and we obtain 0 + 7 = 7. We compare that value with the minimum distance of B (infinity); the lowest value is the one that remains as the minimum distance of B (in this case, 7 is less than infinity):

![image](https://user-images.githubusercontent.com/65532584/94994992-c9a3ab00-05b8-11eb-8ab5-1eedd2d35520.png)

So far, so good. Now, let's check neighbour A. We add 0 (the minimum distance of C, our current node) with 1 (the weight of the edge connecting our current node with A) to obtain 1. We compare that 1 with the minimum distance of A (infinity), and leave the smallest value:

![image](https://user-images.githubusercontent.com/65532584/94995004-df18d500-05b8-11eb-87d3-d392c916f669.png)

OK. Repeat the same procedure for D:

![image](https://user-images.githubusercontent.com/65532584/94995010-ee981e00-05b8-11eb-8fab-17cb0b567161.png)

Great. We have checked all the neighbours of C. Because of that, we mark it as visited. Let's represent visited nodes with a green check mark:

![image](https://user-images.githubusercontent.com/65532584/94995021-fce63a00-05b8-11eb-96a1-e5c15575e067.png)

We now need to pick a new current node. That node must be the unvisited node with the smallest minimum distance (so, the node with the smallest number and no check mark). That's A. Let's mark it with the red dot:

![image](https://user-images.githubusercontent.com/65532584/94995025-0cfe1980-05b9-11eb-9533-22b1dabb2878.png)

And now we repeat the algorithm. We check the neighbours of our current node, ignoring the visited nodes. This means we only check B.

For B, we add 1 (the minimum distance of A, our current node) with 3 (the weight of the edge connecting A and B) to obtain 4. We compare that 4 with the minimum distance of B (7) and leave the smallest value: 4.

![image](https://user-images.githubusercontent.com/65532584/94995040-20a98000-05b9-11eb-8bb5-7f6fa2b34875.png)

Afterwards, we mark A as visited and pick a new current node: D, which is the non-visited node with the smallest current distance.

![image](https://user-images.githubusercontent.com/65532584/94995046-3159f600-05b9-11eb-9865-cb2371e580f6.png)

We repeat the algorithm again. This time, we check B and E.

For B, we obtain 2 + 5 = 7. We compare that value with B's minimum distance (4) and leave the smallest value (4). For E, we obtain 2 + 7 = 9, compare it with the minimum distance of E (infinity) and leave the smallest one (9).

We mark D as visited and set our current node to B.

![image](https://user-images.githubusercontent.com/65532584/94995054-420a6c00-05b9-11eb-9306-401c7c187229.png)

Almost there. We only need to check E. 4 + 1 = 5, which is less than E's minimum distance (9), so we leave the 5. Then, we mark B as visited and set E as the current node.

![image](https://user-images.githubusercontent.com/65532584/94995064-53537880-05b9-11eb-8f85-95d8a58c3dbb.png)

E doesn't have any non-visited neighbours, so we don't need to check anything. We mark it as visited.

![image](https://user-images.githubusercontent.com/65532584/94995107-91e93300-05b9-11eb-9862-bf9aa31e88fa.png)

As there are not univisited nodes, we're done! The minimum distance of each node now actually represents the minimum distance from that node to node C (the node we picked as our initial node)!
