# AVL Tree
AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes.

### Why AVL Trees?
Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST. The cost of these operations may become O(n) for a skewed Binary tree. If we make sure that height of the tree remains O(Logn) after every insertion and deletion, then we can guarantee an upper bound of O(Logn) for all these operations. The height of an AVL tree is always O(Logn) where n is the number of nodes in the tree

Below are the examples of balanced and unbalanced trees:

![image](https://user-images.githubusercontent.com/65532584/94902466-d390b580-04b5-11eb-8867-973a567bdb5b.png)

In the second tree, the left subtree of C has height 2 and the right subtree has height 0, so the difference is 2. In the third tree, the right subtree of A has height 2 and the left is missing, so it is 0, and the difference is 2 again. AVL tree permits difference (balance factor) to be only 1.

**BalanceFactor** = height(left-sutree) − height(right-sutree)

If the difference in the height of left and right sub-trees is more than 1, the tree is balanced using some rotation techniques.

### AVL Rotations
To balance itself, an AVL tree may perform the following four kinds of rotations
- Left rotation
- Right rotation
- Left-Right rotation
- Right-Left rotation
The first two rotations are single rotations and the next two rotations are double rotations. To have an unbalanced tree, we at least need a tree of height 2. With this simple tree, let's understand them one by one.

### Left Rotation
If a tree becomes unbalanced, when a node is inserted into the right subtree of the right subtree, then we perform a single left rotation
![image](https://user-images.githubusercontent.com/65532584/94902994-b5778500-04b6-11eb-9e83-c3fed8aca751.png)

In our example, node A has become unbalanced as a node is inserted in the right subtree of A's right subtree. We perform the left rotation by making A the left-subtree of B.

### Right Rotation
AVL tree may become unbalanced, if a node is inserted in the left subtree of the left subtree. The tree then needs a right rotation.
![image](https://user-images.githubusercontent.com/65532584/94903054-d344ea00-04b6-11eb-80e0-2d9ebd85d283.png)

As depicted, the unbalanced node becomes the right child of its left child by performing a right rotation.

### Left-Right Rotation
Double rotations are slightly complex version of already explained versions of rotations. To understand them better, we should take note of each action performed while rotation. Let's first check how to perform Left-Right rotation. A left-right rotation is a combination of left rotation followed by right rotation.

|State|Action|
|:-------------|:-------------|
|![image](https://user-images.githubusercontent.com/65532584/94904242-a396e180-04b8-11eb-9c5d-dc1219e75d91.png)|A node has been inserted into the right subtree of the left subtree. This makes C an unbalanced node. These scenarios cause AVL tree to perform left-right rotation.|
|![image](https://user-images.githubusercontent.com/65532584/94904269-b1e4fd80-04b8-11eb-81da-86e0fe1a0167.png)|We first perform the left rotation on the left subtree of C. This makes A, the left subtree of B.|
|![image](https://user-images.githubusercontent.com/65532584/94904309-c1644680-04b8-11eb-90a9-6016571a8beb.png)|Node C is still unbalanced, however now, it is because of the left-subtree of the left-subtree.|
|![image](https://user-images.githubusercontent.com/65532584/94904344-ccb77200-04b8-11eb-9182-c00ac76e2c2e.png)|We shall now right-rotate the tree, making B the new root node of this subtree. C now becomes the right subtree of its own left subtree.|
|![image](https://user-images.githubusercontent.com/65532584/94904370-d6d97080-04b8-11eb-82ec-6c01d98431ce.png)|The tree is now balanced|

### Right-Left Rotation
The second type of double rotation is Right-Left Rotation. It is a combination of right rotation followed by left rotation.

|State|Action|
|:-------------|:-------------|
|![image](https://user-images.githubusercontent.com/65532584/94904411-ebb60400-04b8-11eb-98a4-caa64da46123.png)|A node has been inserted into the left subtree of the right subtree. This makes A, an unbalanced node with balance factor 2.|
|![image](https://user-images.githubusercontent.com/65532584/94904448-f53f6c00-04b8-11eb-81c7-45f0b52d8821.png)|First, we perform the right rotation along C node, making C the right subtree of its own left subtree B. Now, B becomes the right subtree of A.|
|![image](https://user-images.githubusercontent.com/65532584/94904522-13a56780-04b9-11eb-9c4b-e1d84467a121.png)|Node A is still unbalanced because of the right subtree of its right subtree and requires a left rotation.|
|![image](https://user-images.githubusercontent.com/65532584/94904553-1d2ecf80-04b9-11eb-8fde-ff4389431899.png)|A left rotation is performed by making B the new root node of the subtree. A becomes the left subtree of its right subtree B.|
|![image](https://user-images.githubusercontent.com/65532584/94904574-291a9180-04b9-11eb-8ddb-7b5fa408931b.png)|The tree is now balanced|
