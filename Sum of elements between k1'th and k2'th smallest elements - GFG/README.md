# Sum of elements between k1'th and k2'th smallest elements
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:18px">Given an array <strong>A[]</strong>&nbsp;of <strong>N</strong>&nbsp;positive&nbsp;integers and two positive integers <strong>K<sub>1</sub></strong> and <strong>K<sub>2</sub></strong>. Find the sum of all elements between K<sub>1</sub><sup>th</sup> and&nbsp;K<sub>2</sub><sup>th</sup> smallest elements of the array.&nbsp;</span></span><span style="font-size:18px">It may be assumed that (1 &lt;= k1 &lt; k2 &lt;= n).</span></p>

<p>&nbsp;</p>

<p><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:18px"><strong>Example 1:</strong></span></span></p>

<pre><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:18px"><strong>Input:</strong></span><span style="font-size:18px">
N  = 7
A[] = {20, 8, 22, 4, 12, 10, 14}
K1 = 3, K2 = 6
<strong>Output:</strong></span>
<span style="font-size:18px">26
<strong>Explanation:</strong></span><span style="font-size:18px">
3rd smallest element is 10
6th smallest element is 20
Element between 10 and 20 
12,14. Their sum = 26.</span></span></pre>

<p>&nbsp;</p>

<p><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:18px"><strong>Example 2:</strong></span></span></p>

<pre><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:18px"><strong>Input</strong>
N = 6
A[] = {10, 2, 50, 12, 48, 13}
K1= 2, K2 = 6
<strong>Output:</strong></span><span style="font-size:18px">
73</span></span></pre>

<p>&nbsp;</p>

<p><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>sumBetweenTwoKth()</strong>&nbsp;which takes the array <strong>A[]</strong>, its size <strong>N</strong><strong> </strong>and two integers <strong>K1</strong> and <strong>K2</strong> as inputs and returns the sum of all the elements between K<sub>1</sub><sup>th</sup> and K<sub>2</sub><sup>th</sup> smallest elements.</span></span><br>
&nbsp;</p>

<p><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N. log(N))<br>
<strong>Expected Auxiliary Space:</strong> O(N)</span></span></p>

<p>&nbsp;</p>

<p><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>5</sup><br>
1 ≤ K<sub>1</sub>, K<sub>2</sub> ≤ 10<sup>9</sup></span></span></p>
</div>