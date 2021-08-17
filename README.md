# k-mean-clustering
C++ Simple algorithm to perform the largest number of clusters considering the average of each group
The vector input is integer, and the result is stored in a int* vector. The aplication need to insert the free memory
to avoid the leak memory.
P is standard deviation (SD) factor. For lower value the SD have more impact in the algorithm

Example of the algorithm:
P = 10 (to desconsider the SD)
Input[1,2,3,4,5,6,7,8,9,10]

result = means_clustering(Input)
result is 4 groups with:
[10,1] [9,2] [8,3] [7,4] [6,5]
