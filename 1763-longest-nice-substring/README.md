<h2><a href="https://leetcode.com/problems/longest-nice-substring/">1763. Longest Nice Substring</a></h2><h3>Easy</h3><hr><div><p>A string <code>s</code> is <strong>nice</strong> if, for every letter of the alphabet that <code>s</code> contains, it appears <strong>both</strong> in uppercase and lowercase. For example, <code>"abABB"</code> is nice because <code>'A'</code> and <code>'a'</code> appear, and <code>'B'</code> and <code>'b'</code> appear. However, <code>"abA"</code> is not because <code>'b'</code> appears, but <code>'B'</code> does not.</p>

<p>Given a string <code>s</code>, return <em>the longest <strong>substring</strong> of <code>s</code> that is <strong>nice</strong>. If there are multiple, return the substring of the <strong>earliest</strong> occurrence. If there are none, return an empty string</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "YazaAay"
<strong>Output:</strong> "aAa"
<strong>Explanation: </strong>"aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "Bb"
<strong>Output:</strong> "Bb"
<strong>Explanation:</strong> "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "c"
<strong>Output:</strong> ""
<strong>Explanation:</strong> There are no nice substrings.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of uppercase and lowercase English letters.</li>
</ul>
</div>