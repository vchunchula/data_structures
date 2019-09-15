# data_structures
  Based on examples and concepts from Robert Sedgewick's Algorithms in C++
  
  1. Quick find eager approach
  2. Quick find Lazy approach with weighting and path compression
        
| Algorithm | Initialize | Union | Connected |
| --- | --- | --- | --- |
| quick-find-Eager | N | N | 1 |
| quick-union-Lazy | N | N<sup>t</sup> | N |
| weighted QU | N | lg N<sup>t</sup> | lg N |

Worst Case Times

| Algorithm | Worst Case Time |
| --- | --- |
| quick-find-Eager | MN |
| quick-union-Lazy | MN |
| weighted QU | N + M logN |
| QU + path compression | N + M logN |
| weighted QU + path compression | N + M lg`*`N |

Note: M  union-find operations on a set of N objects

Interesting fact:
for 10<sup>9</sup> unions and finds with 10<sup>9</sup> objects

- WQUPC reduces time from 30 years to 6 seconds
- Supercomputer could not have helped instead a better algorithm did
