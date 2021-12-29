<h2>787. Cheapest Flights Within K Stops</h2><h3>Medium</h3><hr><div><p>There are <code>n</code> cities connected by some number of flights. You are given an array <code>flights</code> where <code>flights[i] = [from<sub>i</sub>, to<sub>i</sub>, price<sub>i</sub>]</code> indicates that there is a flight from city <code>from<sub>i</sub></code> to city <code>to<sub>i</sub></code> with cost <code>price<sub>i</sub></code>.</p>

<p>You are also given three integers <code>src</code>, <code>dst</code>, and <code>k</code>, return <em><strong>the cheapest price</strong> from </em><code>src</code><em> to </em><code>dst</code><em> with at most </em><code>k</code><em> stops. </em>If there is no such route, return<em> </em><code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png" style="height: 360px; width: 492px;">
<pre><strong>Input:</strong> n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
<strong>Output:</strong> 200
<strong>Explanation:</strong> The graph is shown.
The cheapest price from city <code>0</code> to city <code>2</code> with at most 1 stop costs 200, as marked red in the picture.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png" style="height: 360px; width: 492px;">
<pre><strong>Input:</strong> n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
<strong>Output:</strong> 500
<strong>Explanation:</strong> The graph is shown.
The cheapest price from city <code>0</code> to city <code>2</code> with at most 0 stop costs 500, as marked blue in the picture.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= flights.length &lt;= (n * (n - 1) / 2)</code></li>
	<li><code>flights[i].length == 3</code></li>
	<li><code>0 &lt;= from<sub>i</sub>, to<sub>i</sub> &lt; n</code></li>
	<li><code>from<sub>i</sub> != to<sub>i</sub></code></li>
	<li><code>1 &lt;= price<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>There will not be any multiple flights between two cities.</li>
	<li><code>0 &lt;= src, dst, k &lt; n</code></li>
	<li><code>src != dst</code></li>
</ul>
</div>