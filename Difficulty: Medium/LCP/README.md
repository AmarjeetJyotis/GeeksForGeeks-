<h2><a href="https://www.geeksforgeeks.org/problems/lcp--170637/1">LCP</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px"><strong>Note: This&nbsp;<a href="http://practice.geeksforgeeks.org/problem-of-the-day">POTD</a>&nbsp;is a part of&nbsp;<a href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=potd&amp;utm_medium=problempage&amp;utm_campaign=gsc22">Geek Summer Carnival</a>. Solve all POTD consecutively from 5th to 10th April and get a chance to win exclusive discount vouchers on our GfG courses.</strong></span></p>

<hr>
<p><span style="font-size:18px">Geek is at the geek summer carnival. He is given an array of N strings. To unlock exclusive course discounts he needs to find the longest common prefix among all strings present in the array. Can you help him ?</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px">Input:
N = 4
ar[] = {geeksforgeeks, geeks, geek, geezer}</span>

<span style="font-size:18px">Output:
gee</span>

<span style="font-size:18px">Explanation: 
Longest common prefix in all the given string is gee. </span></pre>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px">Input:
N = 3
ar[] = {apple, ape, april}</span>

<span style="font-size:18px">Output:
ap</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Complete the function LCP() that takes integer n and ar[] as input parameters and return the LCP (in case there is no common prefix return -1).&nbsp;</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected time complexity: </strong>O(NlogN)<br>
<strong>Expected space complexity:</strong> O(string length)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10^3<br>
1 &lt;= String Length &lt;= 100</span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Sorting</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Trie</code>&nbsp;