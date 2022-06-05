package com.company;

public class vanVehicle extends vehicle{
    private int charge;

    public vanVehicle(String registration, String brand, String model, int charge) {
        super(registration, brand, model);
        this.charge = charge;
    }

    public int getCharge() {
        return charge;
    }

    @Override
    public String showData(){
        return "Registration: "+registration+"\nBrand: "+brand+"\nmodel: "+model+"\nCharge: "+charge;
    }
}
