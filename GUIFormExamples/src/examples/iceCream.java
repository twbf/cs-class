/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package examples;

/**
 *
 * @author thomas
 */
public class iceCream {
    private String flavor;
    private double cost;
    private double price;
    int inventory;
    int daysToExp; // several ways of doing this ???
    int sold;

    public iceCream(){
        flavor = "";
        cost = 0.0;
        price = 0.0;
        inventory = 0;
        daysToExp = 0;
        sold = 0;
    }
    
    //constructor for initial file load
    public iceCream(String s, double c, double p, int i, int d, int gone){
        flavor = s;
        cost = c;
        price = p;
        inventory = i;
        daysToExp = d;
        sold = gone;
    }

    //constructor for new ice Cream
    public iceCream(String s, double c, double p, int i, int d){
        flavor = s;
        cost = c;
        price = p;
        inventory = i;
        daysToExp = d;
        sold = 0;
    }

    public String getFlavor(){
        return flavor;
    }

    public void setFlavor(String s){
        flavor = s;
    }

    public int getInventory(){
        return inventory;
    }

    public void setInventory(int k){
        inventory = k;
    }

    public double getCost(){
        return cost;
    }

    public void setCost(double c){
        cost = c;
    }

    public double getPrice(){
        return price;
    }

    public void setPrice(double p){
        price = p;
    }
    public int getDaysToExp(){
        return daysToExp;
    }

    public void setDaysToExp (int p){
        daysToExp = p;
    }
    public int getSold(){
        return sold;
    }

    public void setSold(int p){
        sold = p;
    }

    //removes i gallons of ice Cream if possible, if not remove the total and return that amount
    public int removeInventory(int i)
    {
        if(inventory < i) {
            int amt = inventory;
            inventory = 0;
            return amt;
        }
        inventory -=i;
        return i;
    }
}
