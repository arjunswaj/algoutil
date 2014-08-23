package com.asb.utils.algos.trees;

import java.util.LinkedList;
import java.util.Queue;

public class TreeUtils {

	public static TreeNode<Integer> addNodeToBST(TreeNode<Integer> root,
			int data) {
		if (null == root) {
			TreeNode<Integer> node = new TreeNode<Integer>(data, null, null);
			return node;
		}
		if (data < root.getData()) {
			root.setLeft(addNodeToBST(root.getLeft(), data));
		} else {
			root.setRight(addNodeToBST(root.getRight(), data));
		}
		return root;
	}

	public static void levelOrder (TreeNode<Integer> root) {
		Queue queue = new LinkedList();
		queue.add(root);
		queue.add("End");
		while (!queue.isEmpty()) {
			Object obj = queue.remove();
			if (obj instanceof String) {
				System.out.println();
				if(!queue.isEmpty()) {
					queue.add(obj);
				}
			} else {
				TreeNode<Integer> node = (TreeNode<Integer>) obj;
				System.out.print(node.getData() + " ");
				TreeNode<Integer> lnode = node.getLeft(); 
				if (null != lnode){
					queue.add(lnode);
				}
				TreeNode<Integer> rnode = node.getRight(); 
				if (null != rnode){
					queue.add(rnode);
				}
			}
		}
	}
	
	public static int maxSum(StringBuilder sb, TreeNode<Integer> root) {
		if (null == root) {
			return 0;
		}
		StringBuilder sbl = new StringBuilder(sb);
		sbl.append(" ").append(root.getData());

		StringBuilder sbr = new StringBuilder(sb);
		sbr.append(" ").append(root.getData());

		int leftSum = maxSum(sbl, root.getLeft()) + root.getData();
		int rightSum = maxSum(sbr, root.getRight()) + root.getData();

		System.out.println("Left: " + leftSum + "; " + sbl);
		System.out.println("Right: " + rightSum + "; " + sbr);

		sb.setLength(0);
		if (leftSum > rightSum) {
			sb.append(sbl);
			return leftSum;
		} else {
			sb.append(sbr);
			return rightSum;
		}
	}

	public static void inorderTraversal(TreeNode<Integer> root) {
		if (null == root) {
			return;
		}
		inorderTraversal(root.getLeft());
		System.out.print(root.getData() + " ");
		inorderTraversal(root.getRight());
	}
}
