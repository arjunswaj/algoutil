package com.asb.utils.algos.graphs;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import com.asb.utils.bean.Neighbour;
import com.asb.utils.bean.Node;
import com.asb.utils.bean.consts.NodeColor;

public class GraphTraversals {

	private int counter = -1;

	public void dfs(List<Node> graph) {
		for (Node node : graph) {
			node.setNodeColor(NodeColor.RED);
		}
		for (Node node : graph) {
			if (NodeColor.RED == node.getNodeColor()) {
				node.setNodeColor(NodeColor.RED);
				dfsTraversal(node, graph);
			}
		}
		for (Node node : graph) {
			System.out
					.println(node.getNodeNumber() + ": ("
							+ node.getVisitCount() + ", "
							+ node.getFinishCount() + ")");
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
		node.setNodeColor(NodeColor.GREEN);
		counter += 1;
		node.setFinishCount(counter);
	}

	public void bfs(List<Node> graph) {
		for (Node node : graph) {
			node.setNodeColor(NodeColor.RED);
		}
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
		
		for (Node node : graph) {
			System.out
					.println(node.getNodeNumber() + ": ("
							+ node.getVisitCount() + ", "
							+ node.getFinishCount() + ")");
		}
	}
}
