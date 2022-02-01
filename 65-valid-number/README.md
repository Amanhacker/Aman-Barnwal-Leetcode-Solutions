<h2><a href="https://leetcode.com/problems/valid-number/">65. Valid Number</a></h2><h3>Hard</h3><hr><div><p>A <strong>valid number</strong> can be split up into these components (in order):</p>

<ol>
	<li>A <strong>decimal number</strong> or an <strong>integer</strong>.</li>
	<li>(Optional) An <code>'e'</code> or <code>'E'</code>, followed by an <strong>integer</strong>.</li>
</ol>

<p>A <strong>decimal number</strong> can be split up into these components (in order):</p>

<ol>
	<li>(Optional) A sign character (either <code>'+'</code> or <code>'-'</code>).</li>
	<li>One of the following formats:
	<ol>
		<li>One or more digits, followed by a dot <code>'.'</code>.</li>
		<li>One or more digits, followed by a dot <code>'.'</code>, followed by one or more digits.</li>
		<li>A dot <code>'.'</code>, followed by one or more digits.</li>
	</ol>
	</li>
</ol>

<p>An <strong>integer</strong> can be split up into these components (in order):</p>

<ol>
	<li>(Optional) A sign character (either <code>'+'</code> or <code>'-'</code>).</li>
	<li>One or more digits.</li>
</ol>

<p>For example, all the following are valid numbers: <code>["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]</code>, while the following are not valid numbers: <code>["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]</code>.</p>

<p>Given a string <code>s</code>, return <code>true</code><em> if </em><code>s</code><em> is a <strong>valid number</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "0"
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "e"
<strong>Output:</strong> false
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "."
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
	<li><code>s</code> consists of only English letters (both uppercase and lowercase), digits (<code>0-9</code>), plus <code>'+'</code>, minus <code>'-'</code>, or dot <code>'.'</code>.</li>
</ul>
</div>