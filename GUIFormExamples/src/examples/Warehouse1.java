package examples;
import java.util.*;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.File;
import java.io.FileNotFoundException;

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
        File file = new File("test.in");
        try{
            Scanner sc = new Scanner(file);
            size = Integer.parseInt(sc.nextLine());//inventory amount
            for(int i = 0; i < size; i++)
            {
                String fla = sc.nextLine();
                System.out.println(fla);
                int iv = Integer.parseInt(sc.nextLine());
                double cost = Double.parseDouble(sc.nextLine());
                double price = Double.parseDouble(sc.nextLine());
                int exp = Integer.parseInt((sc.nextLine()));
                int gal = Integer.parseInt(sc.nextLine());
                iceCream newFlav = new iceCream(fla, cost, price, iv, exp, gal);
                ic.add(newFlav);
                gallonsTotal+= iv;
            }
        } catch (FileNotFoundException e) {
        e.printStackTrace();
        }
    }
    public void save()
    {
        output = "";
        output += size;
        output += "\n";
        int days = 0;
        for (iceCream i:ic){
            days = i.getDaysToExp()-1;
            output+=i.getFlavor();
            output+="\n";
            if (days==0){
                output+=0;
            } else {
                output+=i.getInventory();
            }
            output+="\n";
            output+=i.getCost();
            output+="\n";
            if(days==10){
                output+=i.getPrice()/2;
            } else {
                output+=i.getPrice();
            }
            output+="\n";
            output+=i.getDaysToExp()-1;
            output+="\n";
            output+=i.getSold();
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
    
    public String report()
    {
        String add = "<table><tr><th>Flavor</th><th>Inventory</th><th>Price</th><th>Cost</th><th>Days To Exp</th><th>Sold</th></tr>";
        for(iceCream i:ic){
            add += "<tr><td>"+i.getFlavor()+"</td><td>"+i.getInventory()+"</td><td>"+i.getPrice()+ "</td><td>"+i.getCost()+"</td><td>"+i.getDaysToExp()+"</td><td>"+i.getSold()+"</td><tr>";
        }
        add+="<tr>Available storage: "+(10000-gallonsTotal)+"</tr><table>";
        return add;
    }
    
    public void newIceCream(String fla, String cost , String price, String iv, String exp, String gal){
        int spot = getFlavorSpot(fla);
        if (spot!=-1&&ic.get(spot).getDaysToExp()==Integer.parseInt(exp)){
            ic.get(spot).setCost(Double.parseDouble(cost));
            ic.get(spot).setPrice(Double.parseDouble(price));
            ic.get(spot).setInventory(Integer.parseInt(iv));
            ic.get(spot).setDaysToExp(Integer.parseInt(exp));
            ic.get(spot).setSold(Integer.parseInt(gal));
        } else {
            size++;
            double intCost = Double.parseDouble(cost);
            double intPrice = Double.parseDouble(price);
            int intIv = Integer.parseInt(iv);
            gallonsTotal+=intIv;
            int intExp = Integer.parseInt(exp);
            int intGal = Integer.parseInt(gal);
            iceCream newFlav = new iceCream(fla, intCost, intPrice, intIv, intExp, intGal);
            int i = spot(fla);
            ic.add(i, newFlav);
        }
    }
    
    public void removeIceCream (String fla){
        size--;
        int i = getFlavorSpot(fla);
        ic.remove(i);
    }
    
    public int getFlavorSpot(String fla){
        int counter = 0;
        fla = fla.toLowerCase();
        String other;
        for(iceCream i:ic){
            other = i.getFlavor();
            other = other.toLowerCase();
            if (fla.compareTo(other)==0){
               return counter;
            }
            counter ++;
        }
        return -1;
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
}
