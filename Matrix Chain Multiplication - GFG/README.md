# Matrix Chain Multiplication
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a sequence of matrices, find the most efficient way to multiply these matrices together.&nbsp;The efficient way is the one that involves&nbsp;the least number of&nbsp;multiplications. </span></p>

<p><span style="font-size:18px">The dimensions of the matrices are given in an array <strong>arr[]</strong>&nbsp;of&nbsp;size&nbsp;<strong>N</strong> (such that N = number of matrices + 1) where the <strong>i<sup>th</sup></strong> matrix has the dimensions&nbsp;<strong>(arr[i-1]&nbsp;x arr[i])</strong>.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 5
arr = {40, 20, 30, 10, 30}
<strong>Output:</strong> 26000
<strong>Explaination:</strong> There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.</span></pre>

<p><br>
<strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 4
arr = {10, 30, 5, 60}
<strong>Output:</strong> 4500
<strong>Explaination:</strong> The matrices have dimensions 
10*30, 30*5, 5*60. Say the matrices are A, B 
and C. Out of all possible combinations,the
most efficient way is (A*B)*C. The 
number of multiplications are -
10*30*5 + 10*5*60 = 4500.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to take input or print anything. Your task is to complete the function <strong>matrixMultiplication()</strong> which takes the value <strong>N</strong> and the array <strong>arr[]</strong> as input parameters and returns the minimum number of multiplication operations needed to be performed.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N<sup>3</sup>)<br>
<strong>Expected Auxiliary Space:</strong> O(N<sup>2</sup>)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong>&nbsp;<br>
2 ≤ N ≤ 100<br>
1 ≤ arr[i] ≤ 500</span></p>
</div>