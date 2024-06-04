

public class recursion {
  public static void main(String[] args) {
    System.out.println(fibo(7));
  }

  // fibonaci number code->

  static int fibo(int n){
    if (n==0){
      return 0;
    }
    if (n==1|| n==2){
      return 1;
    }
    else return fibo(n-1)+fibo(n-2);
  }

  // fibo code ends here
}
