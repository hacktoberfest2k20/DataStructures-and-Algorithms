
// Code for implementation of Bubble Sort in java
class BubbleSort
{
  
 
    public static void main(String args[])
    {
        BubbleSort ob = new BubbleSort();
        int arr[] = {64, 34, 25, 12, 22, 11, 90};
       
        System.out.println("Your Sorted array is: ");
        

        // Sorting Code
        int n = arr.length;
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-i-1; j++)
                if (arr[j] > arr[j+1])
                {
                    // swap temp and arr[i]
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }

                
                for (int i=0; i<arr.length; ++i)
                    System.out.print(arr[i] + " ");
                System.out.println();
    }
}