<h2><a href="https://leetcode.com/problems/find-smallest-letter-greater-than-target/">744. Find Smallest Letter Greater Than Target</a></h2><h3>Easy</h3><hr><div><p>Given a characters array <code>letters</code> that is sorted in <strong>non-decreasing</strong> order and a character <code>target</code>, return <em>the smallest character in the array that is larger than </em><code>target</code>.</p>

<p><strong>Note</strong> that the letters wrap around.</p>

<ul>
	<li>For example, if <code>target == 'z'</code> and <code>letters == ['a', 'b']</code>, the answer is <code>'a'</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> letters = ["c","f","j"], target = "a"
<strong>Output:</strong> "c"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> letters = ["c","f","j"], target = "c"
<strong>Output:</strong> "f"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> letters = ["c","f","j"], target = "d"
<strong>Output:</strong> "f"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= letters.length &lt;= 10<sup>4</sup></code></li>
	<li><code>letters[i]</code> is a lowercase English letter.</li>
	<li><code>letters</code> is sorted in <strong>non-decreasing</strong> order.</li>
	<li><code>letters</code> contains at least two different characters.</li>
	<li><code>target</code> is a lowercase English letter.</li>
</ul>
</div>