<h2><a href="https://www.geeksforgeeks.org/problems/max-min-height--170647/1">Max min Height</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">You have a garden with n flowers lined up in a row. The height of ith flower is a</span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><sub>i</sub></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"> units. You will water them for k days. In one day you can water w continuous flowers (you can do this only once in a single day). Whenever you water a flower its height increases by 1 unit. You need to maximize the height of the smallest flower all the time.</span></span></span></p>

<p><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Example 1:</strong></span></span></span></p>

<pre><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Input:</strong></span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">n=6</span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">k=2</span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">w=3</span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">a[]={2,2,2,2,1,1}</span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Output:</strong></span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">2</span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Explanation:</strong></span></span></span>
<span style="color:#000000; font-family:Arial; font-size:13.5pt">Water last three flowers for first day &amp; 
first three flowers for second day.The 
new heights</span> <span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">will be {3,3,3,3,2,2}</span></span></span></pre>

<p><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Example 2:</strong></span></span></span></p>

<pre><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Input:</strong></span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">n=2</span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">k=5</span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">w=1</span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">a[]={5,8}</span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Output:</strong></span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">9</span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Explanation:</strong></span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">For the first four days water the first flower then</span></span></span>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">water the last flower once.</span></span></span></pre>

<p><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Your Task:&nbsp;</strong></span></span></span><br>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">You don't need to read input or print anything. Your task is to complete the function </span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>maximizeMinHeight()</strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"> which takes the array a[], its size N</span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>, </strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">integer K, and an integer W</span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong> </strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">as input parameters and returns the maximum height possible for the smallest flower.</span></span></span></p>

<p><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Expected Time Complexity:</strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"> O(NLogN)</span></span></span><br>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Expected Space Complexity:</strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"> O(N)</span></span></span></p>

<p><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Constraints:</strong></span></span></span><br>
<span style="font-size:18px"><span style="font-family:Arial"><span style="color:#000000">1 &lt;= n&lt;= 10<sup>5</sup></span></span></span><br>
<span style="font-size:18px"><span style="font-family:Arial"><span style="color:#000000">1&lt;=w&lt;=n</span></span></span><br>
<span style="font-size:18px"><span style="font-family:Arial"><span style="color:#000000">1&lt;=k&lt;=10<sup>5</sup></span></span></span><br>
<span style="font-size:18px"><span style="font-family:Arial"><span style="color:#000000">1 &lt;= a[i] &lt;= 10<sup>9</sup></span></span></span></p>

<p>&nbsp;</p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Binary Search</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;