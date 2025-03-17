//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}


class IntMatrix
{
    public static int[][] input(BufferedReader br, int n, int m) throws IOException
    {
        int[][] mat = new int[n][];

        for(int i = 0; i < n; i++)
        {
            String[] s = br.readLine().trim().split(" ");
            mat[i] = new int[s.length];
            for(int j = 0; j < s.length; j++)
                mat[i][j] = Integer.parseInt(s[j]);
        }

        return mat;
    }

    public static void print(int[][] m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }

    public static void print(ArrayList<ArrayList<Integer>> m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int N;
            N = Integer.parseInt(br.readLine());
            
            
            int num;
            num = Integer.parseInt(br.readLine());
            
            
            int[] A = IntArray.input(br, N);
            
            
            int[][] Q = IntMatrix.input(br, num, 3);
            
            Solution obj = new Solution();
            ArrayList<Integer> res = obj.solveQueries(N, num, A, Q);
            
            IntArray.print(res);
            
        
System.out.println("~");
}
    }
}

// } Driver Code Ends



class Solution {
    public static ArrayList<Integer> solveQueries(int N, int num, int[] A, int[][] Q) {
        // code here
        int[] freq = new int[A.length];
        HashMap<Integer, Integer> m = new HashMap<>();
    
        for(int j = A.length-1; j >= 0;  j--){
            m.put(A[j],m.getOrDefault(A[j],0)+1);
            freq[j] = m.get(A[j]);
        }
        int s  = Q.length;
        ArrayList<Integer> lt = new ArrayList<>();
        for(int i =0 ; i < s; i++){
                int l = Q[i][0];
                int r = Q[i][1];
                int k = Q[i][2];
                int count = 0;
                for(int j = l ; j <= r ;j++){
                    if(freq[j]==k) count++;
                }
                lt.add(count);
            }
        
        return lt;
    }
}
        
        
