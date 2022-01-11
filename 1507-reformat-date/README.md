<h2><a href="https://leetcode.com/problems/reformat-date/">1507. Reformat Date</a></h2><h3>Easy</h3><hr><div><p>Given a <code>date</code> string in the form&nbsp;<code>Day Month Year</code>, where:</p>

<ul>
	<li><code>Day</code>&nbsp;is in the set <code>{"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}</code>.</li>
	<li><code>Month</code>&nbsp;is in the set <code>{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}</code>.</li>
	<li><code>Year</code>&nbsp;is in the range <code>[1900, 2100]</code>.</li>
</ul>

<p>Convert the date string to the format <code>YYYY-MM-DD</code>, where:</p>

<ul>
	<li><code>YYYY</code> denotes the 4 digit year.</li>
	<li><code>MM</code> denotes the 2 digit month.</li>
	<li><code>DD</code> denotes the 2 digit day.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> date = "20th Oct 2052"
<strong>Output:</strong> "2052-10-20"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> date = "6th Jun 1933"
<strong>Output:</strong> "1933-06-06"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> date = "26th May 1960"
<strong>Output:</strong> "1960-05-26"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The given dates are guaranteed to be valid, so no error handling is necessary.</li>
</ul>
</div>