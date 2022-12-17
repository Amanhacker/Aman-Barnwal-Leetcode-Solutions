# 0 - 1 Knapsack Problem
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">You are given weights and values of <strong>N</strong> items, put these items in a knapsack of capacity <strong>W</strong> to get the maximum total value in the knapsack. Note that we have only <strong>one quantity of each item</strong>.<br>
In other words, given two integer arrays <strong>val[0..N-1]</strong> and <strong>wt[0..N-1]</strong> which represent values and weights associated with <strong>N</strong> items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of <strong>val[]</strong> such that sum of the weights of this subset is smaller than or equal to <strong>W.</strong> You cannot break an item, <strong>either pick the complete item or dont pick it (0-1 property)</strong>.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
<strong>Output: </strong>3</span>
</pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
<strong>Output: </strong>0</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
Complete the function&nbsp;<strong>knapSack()</strong>&nbsp;which takes maximum capacity W, weight array wt[], value array val[], and the number of items n as a parameter and returns the&nbsp;<strong>maximum possible</strong>&nbsp;value you can get.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N*W).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N*W)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span><br>
<span style="font-size:18px">1 ≤ N ≤ 1000</span><br>
<span style="font-size:18px">1 ≤ W ≤ 1000</span><br>
<span style="font-size:18px">1 ≤ wt[i] ≤ 1000</span><br>
<span style="font-size:18px">1 ≤ v[i] ≤ 1000</span></p>
</div>