import java.util.Scanner;
public class reverseNumber {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.println("enter a number :");
    int n = input.nextInt();
    int ans=0;
    while(n>0){
      int remainder=n%10;
      ans=ans*10+remainder;
      n=n/10;

    }
    System.out.println(ans);
    
  }
}
