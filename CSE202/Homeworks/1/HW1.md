# [CSE202 Homework 1](http://cseweb.ucsd.edu/classes/sp16/cse202-a/homework1.pdf) #

## Problem 1 ##

### 1 ###

### 2 ###

Proof by contradiction. Assume there is a MST $T$ and $e$ is not in it. Then we can add $e$ into $T$. This will lead to a cycle $C$ which contains $e$.

We could always remove any other edge from cycle $C$ since every other edge in $c$ has a bigger weight than $e$. After that, we will still have a tree but this tree will have a smaller weight compared with $T$. Therefore $T$ is not a MST and we have found a contradiction.

### 3 ###

False. We could have this cycle $C$ with 4 nodes. Each edge has weight bigger than 100. And there is another path including one more node between each 2 nodes which only cause 2 more weight. In this situation, the MST will have no edge from $C$.

### 4 ###

Same as problem 3.

False. We could have this cycle $C$ with 4 nodes. Each edge has weight bigger than 100. And there is another path including one more node between each 2 nodes which only cause 2 more weight. In this situation, the MST will have no edge from $C$.

### 5 ###

Proo by contradiction. Assume $T_1$ and $T_2$ are two different MSTs. Lets say $e_1$ is the edge with smallest weight that is in $T_1$ but not in $T_2$. Then we add $e_1$ into $T_2$ and we get a cycle. Therefore one edge in the cycle we call it $e_2$ is not in $T_1$.

We know that the weight of $e_2$ is bigger than the weight of $e_1$, and therefore we know $T_2$ = $T_1$ $\union$ {$e_2$} \\ {$e_1$} has a total weight bigger than $T_1$. Therefore it is not a valid MST. Contradiction found.

## Problem 2 ##

### 1 ###

1, 3, 3, 1

### 2 ###

#### a ####

Assume that $i \leq d_1 + 1, j > d_1 + 1$ and there is a link between $v_1$ and $v_j$. Then we can have $(v_1, v_i) \notin E and (v_1, v_j) \in E$.

Another thing is that we know that the degree of $v_i$ should be bigger than or equal to $v_j$, and since we already have $(v_1, v_i) \notin E and (v_1, v_j) \in E$. We know that there must be another node $u$ that $(u, v_i) \in E and (u, v_j) \notin E$.

#### b ####




### 3 ###

## Problem 3 ##

### 1 ###

### 2 ###

### 3 ###
