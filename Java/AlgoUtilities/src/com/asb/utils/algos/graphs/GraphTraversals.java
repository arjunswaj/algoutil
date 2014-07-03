package com.asb.utils.algos.graphs;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

import com.asb.utils.bean.Neighbour;
import com.asb.utils.bean.Node;
import com.asb.utils.bean.consts.NodeColor;

class NodeComparatorOnFinishCount implements Comparator<Node> {

	/**
	 * Descending Order
	 */
	@Override
	public int compare(Node node1, Node node2) {
		return node2.getFinishCount() - node1.getFinishCount();
	}

}

public class GraphTraversals {

	private int counter = -1;

	Stack<Node> stack = new Stack<Node>();

	Queue<Node> queue = new LinkedList<Node>();

	List<Node> graphTranspose = new ArrayList<Node>();

	public void displayGraph(List<Node> graph) {
		for (Node node : graph) {
			System.out
					.println(node.getNodeNumber() + ": ("
							+ node.getVisitCount() + ", "
							+ node.getFinishCount() + ")");
		}
	}

	private void initGraph(List<Node> graph) {
		counter = 0;
		stack.clear();
		queue.clear();
		for (Node node : graph) {
			node.setNodeColor(NodeColor.RED);
		}
	}

	public void dfs(List<Node> graph) {
		initGraph(graph);
		for (Node node : graph) {
			if (NodeColor.RED == node.getNodeColor()) {
				node.setNodeColor(NodeColor.GRAY);
				dfsTraversal(node, graph);
			}
		}
	}

	private void dfsTraversal(Node node, List<Node> graph) {
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

		for (Node node : graph) {
			if (NodeColor.RED == node.getNodeColor()) {
				queue.add(node);
				bfsTraversal(graph);
			}
		}
	}

	private void bfsTraversal(List<Node> graph) {
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

	public void computeTransposeOfGraph(List<Node> graph) {
		for (int index = 0; index < graph.size(); index += 1) {
			graphTranspose.add(new Node(index));
		}
		for (Node node : graph) {
			List<Neighbour> neighbours = node.getAdjacentNodes();
			for (Neighbour neighbour : neighbours) {
				Neighbour transposeNeighbor = new Neighbour(
						node.getNodeNumber(), neighbour.getDistance());
				graphTranspose.get(neighbour.getNodeNumber())
						.getAdjacentNodes().add(transposeNeighbor);
			}
			Node transposeNode = graphTranspose.get(node.getNodeNumber());
			transposeNode.setFinishCount(node.getFinishCount());
			transposeNode.setVisitCount(node.getVisitCount());
		}
	}

	public void stronglyConnectedComponents(List<Node> graph) {
		dfs(graph);
		computeTransposeOfGraph(graph);
		Collections.sort(graphTranspose, new NodeComparatorOnFinishCount());
		initGraph(graphTranspose);
		int componentCount = 0;
		for (Node node : graphTranspose) {
			if (NodeColor.RED == node.getNodeColor()) {				
				node.setNodeColor(NodeColor.GRAY);
				dfsTraversal(node, graphTranspose);
				componentCount +=1;
				System.out.println("Component No: " + componentCount);
				printStack();
			}
		}
	}

	private void printStack() {
		while(!stack.isEmpty()) {
			Node node = stack.pop();
			System.out.println(node);
		}		
	}
}
