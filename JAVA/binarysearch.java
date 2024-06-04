public class binarysearch{
  public static void main(String[] args) {
    int[] array={1,2,3,4,5,6,7};
    int target= 1;
    // using binary search ->
    int value = BinarySearch(array,target);
    System.out.println(" The index at which the target is    "+value);
    
  }
   static int  BinarySearch(int[] array, int target){
    int start= 0;
    int end= array.length -1;
  
    
    while(start<=end){
      int mid =  start+(end-start)/2;
      if (target<array[mid]){
         end=mid-1;
      }
     else if(target>array[mid]) {
      start=mid+1;

     }
     else{
      // ans found->
      return mid;
     }
    }
    return -1;
  
  }
}