## Prim's algorithm

### IDEA: Maintain $V - A$ as a priority queue $Q$. Key each vertex in $Q$ with the weight of the least-weight edge connecting it to a vertex in $A$.

$Q \leftarrow V$  
$key[v] \leftarrow \infty$ for all $v \in V$  
$key[s] \leftarrow 0$ for some arbitrary $s \in V$  

while $Q \neq \emptyset$  
    do $u \leftarrow \text{EXTRACT-MIN}(Q)$  
        for each $v \in Adj[u]$  
            do if $v \in Q$ and $w(u, v) < key[v]$  
                then $key[v] \leftarrow w(u, v)$    # $\triangleright$ DECREASE-KEY  
                     $\pi[v] \leftarrow u$  

At the end, $\{(v, \pi[v])\}$ forms the MST.