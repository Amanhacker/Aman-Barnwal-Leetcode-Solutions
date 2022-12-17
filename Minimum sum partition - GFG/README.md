# Minimum sum partition
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array&nbsp;<strong>arr</strong> of size <strong>n&nbsp;</strong>containing <strong>non-negative </strong>integers, the task is to divide it into two sets <strong>S1</strong> and <strong>S2</strong> such that the absolute difference between their sums is minimum and find the <strong>minimum</strong> difference</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: N = 4, arr[] = {1, 6, 11, 5}</span> <span style="font-size:18px">
<strong>Output:</strong> 1
<strong>Explanation</strong>: </span>
<span style="font-size:18px">Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11  </span> </pre>

<div><span style="font-size:18px"><strong>Example 2:</strong></span></div>

<pre><span style="font-size:18px"><strong>Input: </strong>N = 2, arr[] = {1, 4}
<strong>Output: </strong>3
<strong>Explanation</strong>: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Complete the function <strong><code>minDifference</code>()&nbsp;</strong>which takes <strong>N</strong> and array <strong>arr </strong>as input parameters and returns the integer value</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N*|sum of array elements|)<br>
<strong>Expected Auxiliary Space:</strong> O(N*|sum of array elements|)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤&nbsp;N*|sum of array elements| ≤ 10<sup>6</sup><br>
0 &lt; arr[i] &lt;= 10<sup>5</sup></span></p>
</div>