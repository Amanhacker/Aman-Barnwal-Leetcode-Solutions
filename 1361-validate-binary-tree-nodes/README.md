<h2><a href="https://leetcode.com/problems/validate-binary-tree-nodes/">1361. Validate Binary Tree Nodes</a></h2><h3>Medium</h3><hr><div><p>You have <code>n</code> binary tree nodes numbered from <code>0</code> to <code>n - 1</code> where node <code>i</code> has two children <code>leftChild[i]</code> and <code>rightChild[i]</code>, return <code>true</code> if and only if <strong>all</strong> the given nodes form <strong>exactly one</strong> valid binary tree.</p>

<p>If node <code>i</code> has no left child then <code>leftChild[i]</code> will equal <code>-1</code>, similarly for the right child.</p>

<p>Note that the nodes have no values and that we only use the node numbers in this problem.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/23/1503_ex1.png" style="width: 195px; height: 287px;">
<pre><strong>Input:</strong> n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/23/1503_ex2.png" style="width: 183px; height: 272px;">
<pre><strong>Input:</strong> n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
<strong>Output:</strong> false
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/23/1503_ex3.png" style="width: 82px; height: 174px;">
<pre><strong>Input:</strong> n = 2, leftChild = [1,0], rightChild = [-1,-1]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == leftChild.length == rightChild.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>-1 &lt;= leftChild[i], rightChild[i] &lt;= n - 1</code></li>
</ul>
</div>