public class linearSearch {
  public static void main(String[] args) {
    int[] nums = { 1, 22, 34, 6, 7, 65, 8, 7, 5, 3 };
    int target = 5;
    int ans = linearSearchFunction(nums, target);
     System.out.println(ans);

    String Name = "vansh";
    char target2 = 'x';
    boolean ans2 = stringSearch(Name, target2);
    System.out.println(ans2);

  }

  // function return the index of the searched element
  static int linearSearchFunction(int[] arr, int target) {
    if (arr.length <= 0) {
      return -1;
    }
    for (int i = 0; i < arr.length; i++) {
      if (target == arr[i]) {
        return i;
      }
    }
    return -1;
  }

  // for strings ->

  static boolean stringSearch(String name, char target2) {
    if (name.length() == 0) {
      return false;
    }
    for (int i = 0; i < name.length(); i++) {
      if (name.charAt(i) == target2) {
        return true;
      }
    }
    return false;
  }

}
