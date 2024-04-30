import java.util.Scanner;

public class fibonnaci {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.println("enter a number :");
    int n = input.nextInt();
    int previous = 0;
    int next = 1;
    int count = 2;
    while (count <= n) {
      int temp = next;
      next = previous + next;
      previous = temp;
      count++;
    }
    System.out.println("the sum of nth number of fibonnaci is :" + next);

  }
}
