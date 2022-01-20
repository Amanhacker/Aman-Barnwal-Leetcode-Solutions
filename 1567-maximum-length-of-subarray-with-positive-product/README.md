<h2><a href="https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/">1567. Maximum Length of Subarray With Positive Product</a></h2><h3>Medium</h3><hr><div><p>Given an array of integers <code>nums</code>, find the maximum length of a subarray where the product of all its elements is positive.</p>

<p>A subarray of an array is a consecutive sequence of zero or more values taken out of that array.</p>

<p>Return <em>the maximum length of a subarray with positive product</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,-2,-3,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The array nums already has a positive product of 24.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,-2,-3,-4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest subarray with positive product is [1,-2,-3] which has a product of 6.
Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [-1,-2,-3,0,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The longest subarray with positive product is [-1,-2] or [-2,-3].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>