Problem Statement
Given are a positive integer N and a string S of length N consisting of lowercase Uppercase English letters and Number.
Determine whether the string is a concatenation of two copies of some string. That is, determine whether there is a  such that S=T+T.
Constraints
1≤N≤100
S consists of lowercase English letters.
|S|=N
Input
The first line contains an integer q (1 ≤ q ≤ 100).
The next q lines each contain a integer N (1 ≤ N ≤ 100) and string S (1 ≤ |S| ≤ 100) separate by space. 

Output
For each query, print "Yes" if S is a concatenation of two copies of some string, otherwise print "No".
Sample Input 1 
6
abcabc
Sample Output 1 
Yes
Let T = abc, and S = T + T.

Sample Input 2 
6
abcadc
Sample Output 2 
No
Sample Input 3 
1
z
Sample Output 3 
No
