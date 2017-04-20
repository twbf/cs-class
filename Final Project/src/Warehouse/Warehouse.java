

package Warehouse;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Warehouse {
    ArrayList<iceCream> ic; //ice cream list
    private int size;//number of ice creams on list
    private int gallonsTotal; //total gallons currently stored
    private String fileIn;
    private String fileOut;
    private StringTokenizer st;
    private BufferedReader f;
    private String output;

    public Warehouse(String in)
    {
        ic= new ArrayList<iceCream>();
        fileIn = in;
        fileOut = in;
        gallonsTotal= 0;
        openFile();
        //Opening menu
        System.out.println("************************************************************************\n");
        System.out.println("\t\tFLAVOR\t\t\tIN STOCK\tPRICE\tCOST\n");
        System.out.println("------------------------------------------------------------------------\n\n");
        reportInventory();
        System.out.println("************************************************************************\n");
        System.out.println("\t\t\t\t\tAvailable storage:\t"+(10000-gallonsTotal)+"\n");
        //main warehouse menu
    }

    public void openFile(){

    try{
        f = new BufferedReader(new FileReader(fileIn) );
        getData();
        f.close();
    }
    catch(IOException ioexp)
    {
        System.out.println("IOEXCEPTIO     N");
    }

    }

    public void getData()
    {
        size = Integer.parseInt(getNext() );//inventory amount
        for(int i = 0; i < size; i++)
        {
            String fla = getNext();
            int iv = Integer.parseInt(getNext());
            double cost = Double.parseDouble(getNext());
            double price = Double.parseDouble(getNext());
            int exp = Integer.parseInt((getNext()));
            int gal = Integer.parseInt(getNext());
            iceCream newFlav = new iceCream(fla, cost, price, iv, exp, gal);
            ic.add(newFlav);
            gallonsTotal+= iv;
        }
    }

    public String getNext()
    {
        try{
            st = new StringTokenizer(f.readLine() );
            String s1 = st.nextToken() ;
            if(st.hasMoreTokens() ){
                s1 += " ";
                s1 +=st.nextToken();
            }
            return s1;
        }
        catch(IOException ioexp){
            System.out.println("IOEXCEPTION");
        }
        return " ";
    }

    public void reportInventory()
    {
        for(iceCream i:ic){
            System.out.println("\t\t"+i.getFlavor()+"\t\t"+i.getInventory()+"\t\t"+i.getPrice()+ "\t"+i.getCost());
        }
    }

    public void menu()
    {

    }

    public static void main(String[] args) {
        Warehouse w = new Warehouse("test.in");
    }
}
