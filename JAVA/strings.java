public class strings{

  public static void main(String[] args) {
    String a= "vansh";
    String b="vansh";

    System.out.println(a==b);// here it will give the true a =s they are created inside "pool" in a heap  memory  as both pointing to the same stirng and string are immutable so we can not change the value of stirng ;

    // but if we sepertaely create the two string inside heap but outisde pool then it will not pount to the the same object and return false at that comaprison;
    String name1= new String("vansh");
    String name2= new String("vansh");
    System.out.println(name1==name2);


  }
}