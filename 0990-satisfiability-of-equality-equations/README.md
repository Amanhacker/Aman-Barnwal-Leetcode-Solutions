<h2><a href="https://leetcode.com/problems/satisfiability-of-equality-equations/">990. Satisfiability of Equality Equations</a></h2><h3>Medium</h3><hr><div><p>You are given an array of strings <code>equations</code> that represent relationships between variables where each string <code>equations[i]</code> is of length <code>4</code> and takes one of two different forms: <code>"x<sub>i</sub>==y<sub>i</sub>"</code> or <code>"x<sub>i</sub>!=y<sub>i</sub>"</code>.Here, <code>x<sub>i</sub></code> and <code>y<sub>i</sub></code> are lowercase letters (not necessarily different) that represent one-letter variable names.</p>

<p>Return <code>true</code><em> if it is possible to assign integers to variable names so as to satisfy all the given equations, or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> equations = ["a==b","b!=a"]
<strong>Output:</strong> false
<strong>Explanation:</strong> If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> equations = ["b==a","a==b"]
<strong>Output:</strong> true
<strong>Explanation:</strong> We could assign a = 1 and b = 1 to satisfy both equations.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= equations.length &lt;= 500</code></li>
	<li><code>equations[i].length == 4</code></li>
	<li><code>equations[i][0]</code> is a lowercase letter.</li>
	<li><code>equations[i][1]</code> is either <code>'='</code> or <code>'!'</code>.</li>
	<li><code>equations[i][2]</code> is <code>'='</code>.</li>
	<li><code>equations[i][3]</code> is a lowercase letter.</li>
</ul>
</div>