package com.company;

public class tourismVehicle extends  vehicle{
    private int doors;

    public tourismVehicle(String registration, String brand, String model, int doors) {
        super(registration, brand, model);
        this.doors = doors;
    }

    public int getDoors() {
        return doors;
    }

    @Override
    public String showData(){
        return "Registration: "+registration+"\nBrand: "+brand+"\nmodel: "+model+"\nDoors number: "+doors;
    }
}
