package com.asb.utils.algos.dynamicprogramming;

public class CoinDistribution {

  private int coinsSet[];
  private int matrix[][];
  private int denominationSet[];

  public CoinDistribution(int[] coinsSet) {
    this.coinsSet = coinsSet;
    this.matrix = new int[coinsSet.length + 1][];
    this.denominationSet = new int[coinsSet.length];
  }

  private int[][] findMinimumNumberOfCoins(int amount) {
    for (int counter = 0; counter < coinsSet.length + 1; counter += 1) {
      this.matrix[counter] = new int[amount + 1];
    }

    for (int counter = 0; counter < coinsSet.length + 1; counter += 1) {
      this.matrix[counter][0] = 0;
    }

    for (int counter = 0; counter < amount + 1; counter += 1) {
      this.matrix[0][counter] = Integer.MAX_VALUE;
    }

    for (int yindex = 1; yindex < coinsSet.length + 1; yindex += 1) {
      for (int xindex = 1; xindex < amount + 1; xindex += 1) {
        int vala = this.matrix[yindex - 1][xindex];
        // TODO: Fix the hack
        int valb = 100000; // Some big value, but not Integer.MAX_VALUE as it'll
                           // overflow
        if ((xindex - coinsSet[yindex - 1]) >= 0) {
          valb = this.matrix[yindex][xindex - coinsSet[yindex - 1]] + 1;
        }
        this.matrix[yindex][xindex] = vala < valb ? vala : valb;
      }
    }
    return matrix;
  }

  public int[] findDenominationSet(int amount) {
    int value = amount;
    findMinimumNumberOfCoins(amount);
    // for (int yindex = 1; yindex < matrix.length; yindex += 1) {
    // for (int xindex = 1; xindex < matrix[yindex].length; xindex += 1) {
    // System.out.format("%2d ", matrix[yindex][xindex]);
    // }
    // System.out.println();
    // }

    int yindex = matrix.length - 1;
    int xindex = matrix[yindex].length - 1;

    while (0 != value) {
      if (matrix[yindex][xindex] != matrix[yindex - 1][xindex]) {
        denominationSet[yindex - 1] += 1;
        value -= coinsSet[yindex - 1];
        xindex -= coinsSet[yindex - 1];
      } else {
        yindex -= 1;
      }
    }

    return denominationSet;
  }
}
