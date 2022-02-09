<h2><a href="https://leetcode.com/problems/design-an-expression-tree-with-evaluate-function/">1628. Design an Expression Tree With Evaluate Function</a></h2><h3>Medium</h3><hr><div><p>Given the <code>postfix</code> tokens of an arithmetic expression, build and return <em>the binary expression tree that represents this expression.</em></p>

<p><b>Postfix</b> notation is a notation for writing arithmetic expressions in which the operands (numbers) appear before their operators. For example, the postfix tokens of the expression <code>4*(5-(7+2))</code> are represented in the array <code>postfix = ["4","5","7","2","+","-","*"]</code>.</p>

<p>The class <code>Node</code> is an interface you should use to implement the binary expression tree. The returned tree will be tested using the <code>evaluate</code> function, which is supposed to evaluate the tree's value. You should not remove the <code>Node</code> class; however, you can modify it as you wish, and you can define other classes to implement it if needed.</p>

<p>A <strong><a href="https://en.wikipedia.org/wiki/Binary_expression_tree" target="_blank">binary expression tree</a></strong> is a kind of binary tree used to represent arithmetic expressions. Each node of a binary expression tree has either zero or two children. Leaf nodes (nodes with 0 children) correspond to operands (numbers), and internal nodes (nodes with two children) correspond to the operators <code>'+'</code> (addition), <code>'-'</code> (subtraction), <code>'*'</code> (multiplication), and <code>'/'</code> (division).</p>

<p>It's guaranteed that no subtree will yield a value that exceeds <code>10<sup>9</sup></code> in absolute value, and all the operations are valid (i.e., no division by zero).</p>

<p><strong>Follow up:</strong> Could you design the expression tree such that it is more modular? For example, is your design able to support additional operators without making changes to your existing <code>evaluate</code> implementation?</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/untitled-diagram.png" style="width: 242px; height: 241px;">
<pre><strong>Input:</strong> s = ["3","4","+","2","*","7","/"]
<strong>Output:</strong> 2
<strong>Explanation:</strong> this expression evaluates to the above binary tree with expression (<code>(3+4)*2)/7) = 14/7 = 2.</code>
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/untitled-diagram2.png" style="width: 222px; height: 232px;">
<pre><strong>Input:</strong> s = ["4","5","2","7","+","-","*"]
<strong>Output:</strong> -16
<strong>Explanation:</strong> this expression evaluates to the above binary tree with expression 4*(5-<code>(2+7)) = 4*(-4) = -16.</code>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt; 100</code></li>
	<li><code>s.length</code> is odd.</li>
	<li><code>s</code> consists of numbers and the characters <code>'+'</code>, <code>'-'</code>, <code>'*'</code>, and <code>'/'</code>.</li>
	<li>If <code>s[i]</code> is a number, its integer representation is no more than <code>10<sup>5</sup></code>.</li>
	<li>It is guaranteed that <code>s</code> is a valid expression.</li>
	<li>The absolute value of the result and intermediate values will not exceed <code>10<sup>9</sup></code>.</li>
	<li>It is guaranteed that no expression will include division by zero.</li>
</ul>
</div>