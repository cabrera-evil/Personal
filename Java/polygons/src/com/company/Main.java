package com.company;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static ArrayList<polygon> myPolygon = new ArrayList<polygon>();
    static Scanner entry = new Scanner(System.in);

    public static void main(String[] args) {
        int option;
        boolean exit = false;
        do{
            System.out.println("Polygons");
            System.out.println("1. Triangle");
            System.out.println("2. Rectangle");
            System.out.println("3. Exit");
            System.out.print("Option: ");
            option = entry.nextInt();
            switch (option){
                case 1:
                    fillTriangle();
                    showAnswer();
                    break;
                case 2:
                    fillRectangle();
                    showAnswer();
                    break;
                case 3:
                    exit = true;
                    break;
                default:
                    System.out.println("Wrong Option");
                    break;
            }
        }while(!exit);
    }
    
    public static void fillTriangle(){
        double[] side = new double[3];

        System.out.println("\nFill your triangle sides");
        for (int i = 0; i < 3; i++){
            System.out.print("Side " + (i + 1) + ": ");
            side[i] = entry.nextInt();
        }
        triangle myTriangle = new triangle(3, side);
        myPolygon.add(myTriangle);
    }

    public static void fillRectangle(){
        double[] side = new double[2];

        System.out.println("\nFill your rectangle sides");
        for (int i = 0; i < 2; i++){
            System.out.print("Side " + (i + 1) + ": ");
            side[i] = entry.nextInt();
        }
        rectangle myRectangle = new rectangle(3, side);
        myPolygon.add(myRectangle);
    }

    public static void showAnswer(){
        for(polygon poly : myPolygon){
            System.out.println(poly.toString());
            System.out.println("Area: " + poly.area() + "\n");
        }
    }
}
