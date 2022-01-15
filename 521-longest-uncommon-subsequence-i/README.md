<h2><a href="https://leetcode.com/problems/longest-uncommon-subsequence-i/">521. Longest Uncommon Subsequence I</a></h2><h3>Easy</h3><hr><div><p>Given two strings <code>a</code> and <code>b</code>, return <em>the length of the <strong>longest uncommon subsequence</strong> between </em><code>a</code> <em>and</em> <code>b</code>. If the longest uncommon subsequence does not exist, return <code>-1</code>.</p>

<p>An <strong>uncommon subsequence</strong> between two strings is a string that is a <strong>subsequence of one but not the other</strong>.</p>

<p>A <strong>subsequence</strong> of a string <code>s</code> is a string that can be obtained after deleting any number of characters from <code>s</code>.</p>

<ul>
	<li>For example, <code>"abc"</code> is a subsequence of <code>"aebdc"</code> because you can delete the underlined characters in <code>"a<u>e</u>b<u>d</u>c"</code> to get <code>"abc"</code>. Other subsequences of <code>"aebdc"</code> include <code>"aebdc"</code>, <code>"aeb"</code>, and <code>""</code> (empty string).</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> a = "aba", b = "cdc"
<strong>Output:</strong> 3
<strong>Explanation:</strong> One longest uncommon subsequence is "aba" because "aba" is a subsequence of "aba" but not "cdc".
Note that "cdc" is also a longest uncommon subsequence.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> a = "aaa", b = "bbb"
<strong>Output:</strong> 3
<strong>Explanation:</strong>&nbsp;The longest uncommon subsequences are "aaa" and "bbb".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> a = "aaa", b = "aaa"
<strong>Output:</strong> -1
<strong>Explanation:</strong>&nbsp;Every subsequence of string a is also a subsequence of string b. Similarly, every subsequence of string b is also a subsequence of string a.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 100</code></li>
	<li><code>a</code> and <code>b</code> consist of lower-case English letters.</li>
</ul>
</div>