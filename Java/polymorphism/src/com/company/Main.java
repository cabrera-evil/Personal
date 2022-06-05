package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        vehicle myVehicles[] = new vehicle[4];
        myVehicles[0] = new vehicle("GH64", "Ferrari", "A89");
        myVehicles[1] = new tourismVehicle("78HJ", "Audi", "P14", 2);
        myVehicles[2] = new sportVehicle("45GH", "Toyota", "KJ8", 500);
        myVehicles[3] = new vanVehicle("JI8", "Toyota", "J9", 200);

        for(vehicle vehicles: myVehicles){
            System.out.println((vehicles.showData()));
            System.out.println("");
        }
    }
}
