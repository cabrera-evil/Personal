package com.company;

import java.util.Arrays;

public class triangle extends polygon{
    private double[] side = new double[3];

    public triangle(int sides, double[] side) {
        super(sides);
        this.side = side;
    }

    public double[] getSide() {
        return side;
    }

    @Override
    public double area(){
        double p = (side[0] + side[1] + side[2]) / 2;
        return Math.sqrt((p * (p - side[0]) * (p - side[1]) * (p - side[2])));
    }

    @Override
    public String toString() {
        return "\nTriangle " + super.toString() +"\nSide:" + Arrays.toString(side);
    }
}
