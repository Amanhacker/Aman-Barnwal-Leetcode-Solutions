<h2><a href="https://leetcode.com/problems/find-anagram-mappings/">760. Find Anagram Mappings</a></h2><h3>Easy</h3><hr><div><p>You are given two integer arrays <code>nums1</code> and <code>nums2</code> where <code>nums2</code> is <strong>an anagram</strong> of <code>nums1</code>. Both arrays may contain duplicates.</p>

<p>Return <em>an index mapping array </em><code>mapping</code><em> from </em><code>nums1</code><em> to </em><code>nums2</code><em> where </em><code>mapping[i] = j</code><em> means the </em><code>i<sup>th</sup></code><em> element in </em><code>nums1</code><em> appears in </em><code>nums2</code><em> at index </em><code>j</code>. If there are multiple answers, return <strong>any of them</strong>.</p>

<p>An array <code>a</code> is <strong>an anagram</strong> of an array <code>b</code> means <code>b</code> is made by randomizing the order of the elements in <code>a</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [12,28,46,32,50], nums2 = [50,12,32,46,28]
<strong>Output:</strong> [1,4,3,2,0]
<strong>Explanation:</strong> As mapping[0] = 1 because the 0<sup>th</sup> element of nums1 appears at nums2[1], and mapping[1] = 4 because the 1<sup>st</sup> element of nums1 appears at nums2[4], and so on.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [84,46], nums2 = [84,46]
<strong>Output:</strong> [0,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length &lt;= 100</code></li>
	<li><code>nums2.length == nums1.length</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums2</code> is an anagram of <code>nums1</code>.</li>
</ul>
</div>