# Target Sum
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array of integers <strong>A[]</strong> of length N and an integer <strong>target</strong>.<br>
You want to build an <strong>expression&nbsp;</strong>out of <strong>A&nbsp;</strong>by adding one of the symbols '<strong>+</strong>' and '<strong>-</strong>' before each integer in <strong>A</strong>&nbsp;and then concatenate all the integers.</span></p>

<ul>
	<li><span style="font-size:18px">For example, if arr&nbsp;= {2, 1}, you can add a '<strong>+</strong>' before 2 and a '<strong>-</strong>' before 1 and concatenate them to build the expression "+2-1".</span></li>
</ul>

<p><span style="font-size:18px">Return the number of different&nbsp;<strong>expressions</strong>&nbsp;that can be built, which evaluates to&nbsp;<strong>target</strong>.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5
A[] = {1, 1, 1, 1, 1}
target = 3
<strong>Output:
</strong>5<strong>
Explanation:
</strong>There are 5 ways to assign symbols to 
make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3</span><span style="font-size:18px"><strong>
</strong>
</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 1
A[] = {1}
target = 1
<strong>Output:
</strong>1
</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
The task is to complete the function <strong>findTargetSumWays</strong>() which finds and returns the number of different expressions that can be built.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N*sum), where sum refers to the range of sum possible.<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 20<br>
0 ≤ A[i] ≤ 1000<br>
0 &lt;= sum(A[i]) &lt;= 10<sup>4</sup><br>
-1000 &lt;= target &lt;= 1000</span></p>
</div>