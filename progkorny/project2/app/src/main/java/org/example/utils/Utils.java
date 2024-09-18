package org.example.utils;

import org.example.circle.Circle;

public final class Utils {
    public static double getRadius(Circle circle) {
        return 2 * circle.r() * Math.PI;
    }

    public static double getArea(Circle circle) {
        return Math.pow(circle.r(), 2) * Math.PI;
    }
}
