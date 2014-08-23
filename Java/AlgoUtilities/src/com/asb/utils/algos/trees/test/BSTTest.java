package com.asb.utils.algos.trees.test;

import java.util.Random;

import com.asb.utils.algos.trees.TreeNode;
import com.asb.utils.algos.trees.TreeUtils;

public class BSTTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Random rd = new Random();
		TreeNode<Integer> root = null;
		
		for (int i = 0; i < 50; i += 1) {
			int data = rd.nextInt(100);
			System.out.print(data + " ");
			root = TreeUtils.addNodeToBST(root, data);
		}
		System.out.println();
		TreeUtils.inorderTraversal(root);
		
	}

}
