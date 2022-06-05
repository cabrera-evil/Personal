package com.company;

import java.util.Arrays;

public class rectangle extends polygon{
    private double[] side = new double[2];

    public double[] getSide() {
        return side;
    }

    public rectangle(int sides, double[] side) {
        super(sides);
        this.side = side;
    }

    public double area(){
        return side[0] * side[1];
    }

    @Override
    public String toString() {
        return "\nRectangle " + super.toString() +"\nSide: " + Arrays.toString(side);
    }
}
