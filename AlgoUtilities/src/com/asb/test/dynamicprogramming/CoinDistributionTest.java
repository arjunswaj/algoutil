package com.asb.test.dynamicprogramming;

import com.asb.utils.algos.dynamicprogramming.CoinDistribution;

public class CoinDistributionTest {

  /**
   * @param args
   */
  public static void main(String[] args) {
    int[] coinsSet = { 2, 3, 7, 10 };
    CoinDistribution coinDistribution = new CoinDistribution(coinsSet);
    int amount = 12;
    int denominationSet[] = coinDistribution.findDenominationSet(amount);
    int summation = 0;
    StringBuilder sb = new StringBuilder();
    for (int counter = 0; counter < denominationSet.length; counter += 1) {
      int value = coinsSet[counter] * denominationSet[counter];
      sb.append(coinsSet[counter]).append("\t * \t")
          .append(denominationSet[counter]).append("\t = \t").append(value)
          .append("\n");
      summation += value;
    }
    sb.append("Sum : ").append(summation).append("\n");
    if (summation != amount) {
      System.out.println("No Feasible solution possible");
    } else {
      System.out.println(sb);
    }
  }
}
