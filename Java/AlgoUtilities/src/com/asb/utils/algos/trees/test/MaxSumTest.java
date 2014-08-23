package com.asb.utils.algos.trees.test;

import java.util.Random;

import com.asb.utils.algos.trees.TreeNode;
import com.asb.utils.algos.trees.TreeUtils;

public class MaxSumTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Random rd = new Random();
		TreeNode<Integer> root = null;
		
		for (int i = 0; i < 10; i += 1) {
			int data = rd.nextInt(100);			
			root = TreeUtils.addNodeToBST(root, data);
		}
		TreeUtils.levelOrder(root);
		StringBuilder sb = new StringBuilder(); 
		int maxSum = TreeUtils.maxSum(sb, root);
		System.out.println("Max Sum: " + maxSum);
		System.out.println(sb);

	}

}
