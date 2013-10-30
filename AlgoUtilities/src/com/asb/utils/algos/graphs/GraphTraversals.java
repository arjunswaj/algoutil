package com.asb.utils.algos.graphs;

import java.util.List;
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

}
