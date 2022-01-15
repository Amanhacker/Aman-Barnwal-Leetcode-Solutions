<h2><a href="https://leetcode.com/problems/most-common-word/">819. Most Common Word</a></h2><h3>Easy</h3><hr><div><p>Given a string <code>paragraph</code> and a string array of the banned words <code>banned</code>, return <em>the most frequent word that is not banned</em>. It is <strong>guaranteed</strong> there is <strong>at least one word</strong> that is not banned, and that the answer is <strong>unique</strong>.</p>

<p>The words in <code>paragraph</code> are <strong>case-insensitive</strong> and the answer should be returned in <strong>lowercase</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
<strong>Output:</strong> "ball"
<strong>Explanation:</strong> 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> paragraph = "a.", banned = []
<strong>Output:</strong> "a"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= paragraph.length &lt;= 1000</code></li>
	<li>paragraph consists of English letters, space <code>' '</code>, or one of the symbols: <code>"!?',;."</code>.</li>
	<li><code>0 &lt;= banned.length &lt;= 100</code></li>
	<li><code>1 &lt;= banned[i].length &lt;= 10</code></li>
	<li><code>banned[i]</code> consists of only lowercase English letters.</li>
</ul>
</div>