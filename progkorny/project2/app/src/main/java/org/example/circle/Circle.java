package org.example.circle;

public class Circle {
    public Circle(double x, double y, double r) {
        _x = x;
        _y = y;
        _r = r;
    }

    public double x() {
        return _x;
    }

    public double y() {
        return _y;
    }

    public double r() {
        return _r;
    }

    private double _x;
    private double _y;
    private double _r;
}
