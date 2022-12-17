# Minimum number of deletions and insertions.
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given two strings <strong>str1</strong> and <strong>str2</strong>. The task is to remove or insert the minimum number of characters from/in <strong>str1</strong> so as to transform it into <strong>str2</strong>. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>str1 = "heap", str2 = "pea"
<strong>Output:</strong> 3
<strong>Explanation: </strong>2 deletions and 1 insertion</span>
<strong><span style="font-size:18px">p</span></strong><span style="font-size:18px"> and <strong>h</strong> deleted from <strong>heap</strong>. Then, <strong>p</strong> is 
inserted at the beginning One thing to 
note, though <strong>p</strong> was required yet it was 
removed/deleted first from its position 
and then it is inserted to some other 
position. Thus, <strong>p</strong> contributes one to the 
<strong>deletion_count</strong> and one to the 
<strong>insertion_count</strong>.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input : </strong>str1 = "geeksforgeeks"
str2 = "geeks"
<strong>Output: </strong>8
<strong>Explanation: </strong>8 deletions</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read or&nbsp;print anything. Your task is to complete the function <strong>minOperations()&nbsp;</strong>which takes both strings as input parameter and returns the minimum number of operation required.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(|str1|*|str2|)<br>
<strong>Expected Space Complexity: </strong>O(|str1|*|str2|</span><span style="font-size:18px">)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ |str1|, |str2| ≤ 1000</span><br>
<span style="font-size:18px">All the characters are lower case English alphabets</span></p>
</div>