# First negative integer in every window of size k
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an array <strong>A[] </strong>of size <strong>N</strong> and a positive integer <strong>K</strong>, find the first negative integer for each and every window(contiguous subarray) of size <strong>K</strong>.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input : 
</strong>N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
<strong>Output : </strong>
-8 0 -6 -6
<strong>Explanation :</strong>
First negative integer for each window of size k
<strong>{-8, 2}</strong> = -8
<strong>{2, 3}</strong> = 0 (does not contain a negative integer)
<strong>{3, -6}</strong> = -6
<strong>{-6, 10}</strong> = -6</span></pre>

<div>&nbsp;</div>

<div><span style="font-size:18px"><strong>Example 2:</strong></span></div>

<pre><span style="font-size:18px"><strong>Input : </strong>
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
<strong>Output :</strong>
-1 -1 -7 -15 -15 0 </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>printFirstNegativeInteger()</strong>&nbsp;which takes the array <strong>A[]</strong>, its size <strong>N </strong>and an integer <strong>K </strong>as inputs and returns the first negative number in every window of size K&nbsp;starting from the first till the end. If a window does not contain a negative integer , then return 0 for that window.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space:</strong> O(K)<br>
<br>
<strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>5</sup><br>
-10<sup>5</sup> &lt;= A[i] &lt;= 10<sup>5</sup><br>
1 &lt;= K &lt;= N</span></p>
 <p></p>
            </div>