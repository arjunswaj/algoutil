package com.asb.test;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.List;

import com.asb.utils.FileParser;
import com.asb.utils.algos.graphs.GraphTraversals;
import com.asb.utils.bean.Node;

/**
 * Program to test DFS
 * 
 * @author arjun
 * 
 */
public class DFSTest {

	/**
	 * Test DFS
	 * 
	 * @param args
	 * @throws IOException
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException,
			IOException {
		
		FileParser fileParser = new FileParser();
		List<Node> graph = fileParser.parseDFSData(new File("DFSData2.txt"));
		GraphTraversals graphTraversals = new GraphTraversals();
		graphTraversals.dfs(graph);

	}

}
