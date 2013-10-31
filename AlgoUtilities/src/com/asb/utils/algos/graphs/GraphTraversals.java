package com.asb.utils.algos.graphs;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

import com.asb.utils.bean.Neighbour;
import com.asb.utils.bean.Node;
import com.asb.utils.bean.consts.NodeColor;

public class GraphTraversals {

	private int counter = -1;

	Stack<Node> stack = new Stack<Node>();

	public void displayGraph(List<Node> graph) {
		for (Node node : graph) {
			System.out
					.println(node.getNodeNumber() + ": ("
							+ node.getVisitCount() + ", "
							+ node.getFinishCount() + ")");
		}
	}

	private void initGraph(List<Node> graph) {
		for (Node node : graph) {
			node.setNodeColor(NodeColor.RED);
		}
	}

	public void dfs(List<Node> graph) {
		initGraph(graph);
		for (Node node : graph) {
			if (NodeColor.RED == node.getNodeColor()) {
				node.setNodeColor(NodeColor.RED);
				dfsTraversal(node, graph);
			}
		}
	}

	public void dfsTraversal(Node node, List<Node> graph) {
		counter += 1;
		node.setVisitCount(counter);
		node.setNodeColor(NodeColor.GRAY);
		List<Neighbour> neighbours = node.getAdjacentNodes();
		for (Neighbour neighbour : neighbours) {
			int adjNodeNo = neighbour.getNodeNumber();
			Node adjNode = graph.get(adjNodeNo);
			if (NodeColor.RED == adjNode.getNodeColor()) {
				dfsTraversal(adjNode, graph);
			}
		}
		stack.add(node);
		node.setNodeColor(NodeColor.GREEN);
		counter += 1;
		node.setFinishCount(counter);
	}

	public void bfs(List<Node> graph) {
		initGraph(graph);
		Queue<Node> queue = new LinkedList<Node>();
		queue.add(graph.get(0));
		while (!queue.isEmpty()) {
			Node node = queue.poll();
			node.setNodeColor(NodeColor.GRAY);
			counter += 1;
			node.setVisitCount(counter);
			List<Neighbour> neighbours = node.getAdjacentNodes();
			for (Neighbour neighbour : neighbours) {
				int adjNodeNo = neighbour.getNodeNumber();
				Node adjNode = graph.get(adjNodeNo);
				if (NodeColor.RED == adjNode.getNodeColor()) {
					adjNode.setNodeColor(NodeColor.GRAY);
					queue.add(adjNode);
				}
			}
			node.setNodeColor(NodeColor.GREEN);
			counter += 1;
			node.setFinishCount(counter);
		}
	}

	public void topologicalSort(List<Node> graph) {
		dfs(graph);
		Node node = null;
		System.out.println("Topological Ordering");
		while (!stack.isEmpty()) {
			node = stack.pop();
			System.out
					.println(node.getNodeNumber() + ": ("
							+ node.getVisitCount() + ", "
							+ node.getFinishCount() + ")");
		}
	}
}
