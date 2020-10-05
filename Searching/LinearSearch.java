/**
 * Algorithm : Linear Search
 * Description: Given an array of integers and you need to find a key or a number. If you finds the key in the array, it returns TRUE otherwise FALSE
 * Time Complexity : O(n)
 */

import java.util.*;

public class LinearSearch {
    private static final String ERROR_STRING = "Please provide a list of integers (\"1, 4, 5, 11, 12\") and the integer to find (\"11\")";
    public static void main(String[] args) {
        try {
            // Returns TRUE
            List<Integer> listOfNumbers = new ArrayList<Integer>(Arrays.asList(1,2,3,4,5));
            Integer keyToSearch = 5;
            InputOutputMethod(listOfNumbers, keyToSearch);

            // Returns FALSE
            keyToSearch = 6;
            InputOutputMethod(listOfNumbers, keyToSearch);

            // Gives error as no input
            listOfNumbers = new ArrayList<Integer>(Arrays.asList());
            InputOutputMethod(listOfNumbers, keyToSearch);
        }
        catch(Exception e) {
            System.out.println(ERROR_STRING);
        }
    }

    private static void InputOutputMethod(List<Integer> listOfNumbers, Integer keyToSearch) {
        if(listOfNumbers.size() >= 1){
            StringBuilder output = new StringBuilder();
            Boolean searched = linearSearch(listOfNumbers, keyToSearch);
            System.out.println(searched);
        }else{
            System.out.println(ERROR_STRING);
        }
    }

    private static Boolean linearSearch(List<Integer> list, Integer keyToSearch) {
        Boolean answer = false;
        for (Integer number : list) {
            if(number == keyToSearch) {
                answer = true;
                break;
            }
        }
        return answer;
    }
}
