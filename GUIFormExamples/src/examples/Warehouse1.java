

package examples;
import java.util.*;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.FileWriter;




import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Warehouse1 {
    ArrayList<iceCream> ic; //ice cream list
    private int size;//number of ice creams on list
    private int gallonsTotal; //total gallons currently stored
    private String fileIn;
    private String fileOut;
    private StringTokenizer st;
    private BufferedReader f;
    private String output;

    public Warehouse1(String in)
    {
        ic= new ArrayList<iceCream>();
        fileIn = in;
        fileOut = in;
        gallonsTotal= 0;
        openFile();
        //Opening menu
        //System.out.println("************************************************************************\n");
        //System.out.println("\t\tFLAVOR\t\t\tIN STOCK\tPRICE\tCOST\n");
        //System.out.println("------------------------------------------------------------------------\n\n");
        //reportInventory();
        //System.out.println("************************************************************************\n");
        //System.out.println("\t\t\t\t\tAvailable storage:\t"+(10000-gallonsTotal)+"\n");
        //main warehouse menu
        //menu();
    }

    public void openFile(){

    try{
        f = new BufferedReader(new FileReader(fileIn) );
        getData();
        f.close();
    }
    catch(IOException ioexp)
    {
        System.out.println("IOEXCEPT   ION");
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
    public void save()
    {
        output = "";
        output += size;
        output += "\n";
        for (iceCream i:ic){
            output+=i.getFlavor();
            output+="\n";
            output+=i.getInventory();
            output+="\n";
            output+=i.getCost();
            output+="\n";
            output+=i.getPrice();
            output+="\n";
            output+=0;
            output+="\n";
            output+=0;
            output+="\n";
        }
        try {
            PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.in")));
            out.println(output);
            out.close();
        }  catch(IOException ioexp)
        {
            System.out.println("IOEXCEPT   ION");
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
    public String report()
    {
        String add = "";
        for(iceCream i:ic){
            add += "\n\n\t\t"+i.getFlavor()+"\t\t"+i.getInventory()+"\t\t"+i.getPrice()+ "\t"+i.getCost();
        }
        return add;
    }

    public void menu()
    {
        int i =0;
        Scanner sc = new Scanner(System.in);
        while (i!=4){
            System.out.println("************************************************************************\n");
            System.out.println("1. Transaction menu\n");
            System.out.println("2. Inventory Report\n");
            System.out.println("3. Expiration Report\n");
            System.out.println("4. Clean and Cose file\n");
            i = sc.nextInt();
            switch (i){
                case 1:
                    transactionMenu();
                    break();
                case 2:
                    System.out.println("************************************************************************\n");
                    System.out.println("\t\tFLAVOR\t\t\tIN STOCK\tPRICE\tCOST\n");
                    System.out.println("------------------------------------------------------------------------\n\n");
                    reportInventory();
                    System.out.println("************************************************************************\n");
                    System.out.println("\t\t\t\t\tAvailable storage:\t"+(10000-gallonsTotal)+"\n");
                    break;
                case 3:
                    expirationReport();
                    break();
                case 4:
                    save();
                    break;
                default:
                    System.out.println("Invalid Entry");
                    menu();
            }
        }
    }
    
    public void transactionMenu(){
        int i =0;
        Scanner sc = new Scanner(System.in);
        while (i!=4){
            System.out.println("************************************************************************\n");
            System.out.println("1. Purchase Ice Cream\n");
            System.out.println("2. Sale Ice Cream\n");
            System.out.println("3. Remove and Destroy Ice Cream\n");
            System.out.println("4. Update Inventory Information\n");
            System.out.println("5. Return to Previous Menu\n");
            i = sc.nextInt();
            switch (i){
                case 1:
                    newIceCream();
                    break;
                case 2:
                case 3:
                    expirationReport();
                    break;
                case 4:
                    save();
                    break;
                case 5:
                    menu();
                    break;
                default:
                    System.out.println("Invalid Entry");
                    transactionMenu();
            }
        }
    }
    public void newIceCream(){
        size++;
        System.out.println("Enter new Flavor:");
        Scanner sc = new Scanner(System.in);
        String fla = sc.next();
        
        System.out.println("Enter Cost:");
        sc = new Scanner(System.in);
        double cost  = sc.nextDouble();
        
        System.out.println("Enter Price:");
        sc = new Scanner(System.in);
        double price = sc.nextDouble();
        
        System.out.println("Enter Inventory:");
        sc = new Scanner(System.in);
        int iv = sc.nextInt();
        
        System.out.println("Enter Experaton Date:");
        sc = new Scanner(System.in);
        int exp = sc.nextInt();
        
        System.out.println("Enter Gallons:");
        sc = new Scanner(System.in);
        int gal = sc.nextInt();
        
        iceCream newFlav = new iceCream(fla, cost, price, iv, exp, gal);
        int i = spot(fla);
        ic.add(i, newFlav);
        transactionMenu();
    }
    
    public int spot (String fla){
        int counter = 0;
        fla = fla.toLowerCase();
        String other;
        for(iceCream i:ic){
            System.out.println(counter);
            other = i.getFlavor();
            other = other.toLowerCase();
            if (fla.compareTo(other)<0){
                System.out.println("eeeee");
               return counter;
            }
            counter ++;
        }
        return counter;
    }
    
    public void sale(){
    }
    
   // public static void main(String[] args) {
    //    Warehouse t = new Warehouse();
     //   Warehouse1 w = new Warehouse1("test.in");
   // }
}
