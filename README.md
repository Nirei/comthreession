comthreession
=============

An SFC-based, delta compression toy-algorithm I'm writing for the fun of it.

The idea is to use context-based space filling curves over data in an arbitrary number of dimensions to take advantage of the following things:
- Binary representation of an SFC in n dimensions requires only 2*n turning directions. You can start on an arbitrary position on a multi-dim matrix and move in each dimension "forward" and "backwards".
- At the same time, each new dimension added gives each cell a couple of new adjacent cells, that means the SFC will have more options to find cells with similar content. The number of adjacent cells is also 2*n.
- That means the algorithm gets more chances of finding lower deltas at the cost of more space-consuming SFCs.

The goal here is to do some science and try to figure out experimentally what's the optimum number of dimensions in which you should construct your SFC to get the best compression ratio.

Also, multidimensional context-based space filling curve compression sounds so damn cool.
