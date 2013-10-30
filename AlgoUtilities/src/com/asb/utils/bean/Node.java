package com.asb.utils.bean;

import java.util.ArrayList;
import java.util.List;

import com.asb.utils.bean.consts.NodeColor;

public class Node {

	/**
	 * Node Number
	 */
	private int nodeNumber;

	/**
	 * Node Color
	 */
	private NodeColor nodeColor;
	/**
	 * visit count
	 */
	private int visitCount;
	/**
	 * finish count
	 */
	private int finishCount;
	/**
	 * Sorted Map of Distance and List of Nodes
	 */
	List<Neighbour> adjacentNodes = new ArrayList<Neighbour>();

	public Node(int nodeNumber) {
		super();
		this.nodeNumber = nodeNumber;
		this.visitCount = 0;
		this.finishCount = 0;
	}

	public int getNodeNumber() {
		return nodeNumber;
	}

	public void setNodeNumber(int nodeNumber) {
		this.nodeNumber = nodeNumber;
	}

	public List<Neighbour> getAdjacentNodes() {
		return adjacentNodes;
	}

	public void setAdjacentNodes(List<Neighbour> adjacentNodes) {
		this.adjacentNodes = adjacentNodes;
	}

	public NodeColor getNodeColor() {
		return nodeColor;
	}

	public void setNodeColor(NodeColor nodeColor) {
		this.nodeColor = nodeColor;
	}

	public int getVisitCount() {
		return visitCount;
	}

	public void setVisitCount(int visitCount) {
		this.visitCount = visitCount;
	}

	public int getFinishCount() {
		return finishCount;
	}

	public void setFinishCount(int finishCount) {
		this.finishCount = finishCount;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("Node No: ").append(nodeNumber);
		sb.append("\n\tAdj (Node No, Distance): ");
		for (Neighbour neighbour : adjacentNodes) {
			sb.append("(").append(neighbour.getNodeNumber()).append(", ")
					.append(neighbour.getDistance()).append(") ");
		}

		sb.append("\n");
		return sb.toString();
	}

}
