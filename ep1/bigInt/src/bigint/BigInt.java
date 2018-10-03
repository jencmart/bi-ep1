/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bigint;

import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author jencmart
 */
public class BigInt {
    public static void main(String[] args) {
        BigInteger three  = new BigInteger("3"); 
        BigInteger two  = new BigInteger("2"); 

        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();

        for(int i = 0 ; i < rows ; ++i)
        {
            BigInteger num = sc.nextBigInteger();
            BigInteger result =  (num.pow(3).add(num.pow(2).multiply(three)).add(num.multiply(two))).divide(two);
            System.out.println( result.toString() );
        }
    }
}
