import java.util.*;
import java.lang.*;
import java.io.*;

class Solution {
	
	// Scanner sc = new Scanner(System.in);

	// String s[] = sc.nextLine().trim().split(" ");
	// int target = sc.nextInt();

	// int[] nums = new int[s.length];
	// for (int i = 0; i < s.length; i++)
	// 	nums[i] = Integer.parseInt(s[i]);

	public int[] twoSum(int[] nums, int target) {
		Map<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < nums.length; i++) {
			map.put(nums[i], i);
		}
		for (int i = 0; i < nums.length; i++) {
			int complement = target - nums[i];
			if (map.containsKey(complement) && map.get(complement) != i) {
				return new int[] { i, map.get(complement) };
			}
		}
		throw new IllegalArgumentException("No two sum solution");
	}
}