<h2><a href="https://leetcode.com/problems/design-an-ordered-stream/">1656. Design an Ordered Stream</a></h2><h3>Easy</h3><hr><div><p>There is a stream of <code>n</code> <code>(idKey, value)</code> pairs arriving in an <strong>arbitrary</strong> order, where <code>idKey</code> is an integer between <code>1</code> and <code>n</code> and <code>value</code> is a string. No two pairs have the same <code>id</code>.</p>

<p>Design a stream that returns the values in <strong>increasing order of their IDs</strong> by returning a <strong>chunk</strong> (list) of values after each insertion. The concatenation of all the <strong>chunks</strong> should result in a list of the sorted values.</p>

<p>Implement the <code>OrderedStream</code> class:</p>

<ul>
	<li><code>OrderedStream(int n)</code> Constructs the stream to take <code>n</code> values.</li>
	<li><code>String[] insert(int idKey, String value)</code> Inserts the pair <code>(idKey, value)</code> into the stream, then returns the <strong>largest possible chunk</strong> of currently inserted values that appear next in the order.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/11/10/q1.gif" style="width: 682px; height: 240px;"></strong></p>

<pre><strong>Input</strong>
["OrderedStream", "insert", "insert", "insert", "insert", "insert"]
[[5], [3, "ccccc"], [1, "aaaaa"], [2, "bbbbb"], [5, "eeeee"], [4, "ddddd"]]
<strong>Output</strong>
[null, [], ["aaaaa"], ["bbbbb", "ccccc"], [], ["ddddd", "eeeee"]]

<strong>Explanation</strong>
// Note that the values ordered by ID is ["aaaaa", "bbbbb", "ccccc", "ddddd", "eeeee"].
OrderedStream os = new OrderedStream(5);
os.insert(3, "ccccc"); // Inserts (3, "ccccc"), returns [].
os.insert(1, "aaaaa"); // Inserts (1, "aaaaa"), returns ["aaaaa"].
os.insert(2, "bbbbb"); // Inserts (2, "bbbbb"), returns ["bbbbb", "ccccc"].
os.insert(5, "eeeee"); // Inserts (5, "eeeee"), returns [].
os.insert(4, "ddddd"); // Inserts (4, "ddddd"), returns ["ddddd", "eeeee"].
// Concatentating all the chunks returned:
// [] + ["aaaaa"] + ["bbbbb", "ccccc"] + [] + ["ddddd", "eeeee"] = ["aaaaa", "bbbbb", "ccccc", "ddddd", "eeeee"]
// The resulting order is the same as the order above.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= id &lt;= n</code></li>
	<li><code>value.length == 5</code></li>
	<li><code>value</code>&nbsp;consists only of lowercase letters.</li>
	<li>Each call to <code>insert</code>&nbsp;will have a unique <code>id.</code></li>
	<li>Exactly <code>n</code> calls will be made to <code>insert</code>.</li>
</ul>
</div>