/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkgfinal.project;
import java.io.*;

public class FinalProject {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
         // Use BufferedReader rather than RandomAccessFile; it's much faster
                                                  // input file name goes above
    //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
						  // Get line, break into tokens
    int i1 = 5;    // first integer
    int i2 = 5;    // second integer
    //out.println(i1+i2); 
    System.out.println("Hello, World");// output result
    //out.close();                                  // close the output file
    }
    
}


