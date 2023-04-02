# Boolean Parenthesization
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a boolean expression <strong>S</strong>&nbsp;of length <strong>N</strong> with following symbols.<br>
Symbols<br>
&nbsp;&nbsp;&nbsp; 'T' ---&gt; true<br>
&nbsp;&nbsp;&nbsp; 'F' ---&gt; false<br>
and following operators filled between symbols<br>
Operators<br>
&nbsp;&nbsp;&nbsp; &amp;&nbsp;&nbsp; ---&gt; boolean AND<br>
&nbsp;&nbsp;&nbsp; |&nbsp;&nbsp; ---&gt; boolean OR<br>
&nbsp;&nbsp;&nbsp; ^&nbsp;&nbsp; ---&gt; boolean XOR<br>
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.</span></p>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 7
S = T|T&amp;F^T
<strong>Output:</strong> 4
<strong>Explaination:</strong> The expression evaluates 
to true in 4 ways ((T|T)&amp;(F^T)), 
(T|(T&amp;(F^T))), (((T|T)&amp;F)^T) and (T|((T&amp;F)^T)).</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 5
S = T^F|F
<strong>Output:</strong> 2
<strong>Explaination:</strong> ((T^F)|F) and (T^(F|F)) are the 
only ways.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your task is to complete the function <strong>countWays()</strong> which takes N and S as input parameters and returns number of possible ways modulo 1003.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N<sup>3</sup>)<br>
<strong>Expected Auxiliary Space:</strong> O(N<sup>2</sup>)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 200&nbsp;</span></p>
</div>