# Subset Sum Problem
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array of non-negative integers, and a value <em>sum</em>, determine if there is a subset of the given set with sum equal to given <em>sum</em>.&nbsp;</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong></span>:
<span style="font-size:18px">N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
<strong>Output:</strong>&nbsp;1&nbsp;
<strong>Explanation</strong>: Here there exists a subset with
sum = 9, 4+3+2 = 9.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong></span>:
<span style="font-size:18px">N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 30
<strong>Output:</strong>&nbsp;0&nbsp;
<strong>Explanation</strong>: There is no subset with sum 30.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>isSubsetSum()</strong>&nbsp;which takes the array arr[], its size N<strong>&nbsp;</strong>and an integer <strong>sum </strong>as input parameters&nbsp;and returns boolean value true if there exists a subset with given sum and false otherwise.<br>
The driver code itself prints 1, if returned value is true and prints 0 if returned value is false.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(sum*N)<br>
<strong>Expected Auxiliary Space:</strong> O(sum*N)</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 100</span><br>
<span style="font-size:18px">1&lt;= arr[i] &lt;= 100<br>
1&lt;= sum &lt;= 10<sup>5</sup></span></p>
</div>