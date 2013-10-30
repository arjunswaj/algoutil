package com.asb.utils;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

import com.asb.utils.bean.Neighbour;
import com.asb.utils.bean.Node;

public class FileParser {

	private static final String MINUS_ONE = "-1";

	public List<Node> parseDFSData(File file) throws FileNotFoundException,
			IOException {

		List<Node> nodes = new ArrayList<Node>();
		BufferedReader bufferedReader = null;
		try {
			bufferedReader = new BufferedReader(new FileReader(file));			
			String line = null;
			int index = 0;
			while (null != (line = bufferedReader.readLine())) {
				Node mainNode = new Node(index);
				StringTokenizer st = new StringTokenizer(line);
				int adjNodeNo = 0;
				while (st.hasMoreTokens()) {
					String token = st.nextToken();
					if (!token.equals(MINUS_ONE)) {
						int distance = Integer.parseInt(token);
						Neighbour neighbour = new Neighbour(adjNodeNo, distance);						
						mainNode.getAdjacentNodes().add(neighbour);
					}
					adjNodeNo += 1;
				}
				nodes.add(mainNode);
				System.out.println(mainNode);
				index += 1;
			}

		} finally {
			if (null != bufferedReader) {
				bufferedReader.close();
			}
		}
		return nodes;
	}

}
