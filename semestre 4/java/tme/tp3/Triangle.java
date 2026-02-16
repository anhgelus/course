public class Triangle {
    private Point p1, p2, p3;

    public Triangle(Point p1, Point p2, Point p3) {
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
    }

    public Triangle() {
        this(new Point(), new Point(), new Point());
    }

    public Triangle(Triangle t) {
        this(new Point(t.p1), new Point(t.p2), new Point(t.p3));
    }

    public String toString() {
        return String.format("{%s,%s,%s}", p1, p2, p3);
    }

    public double getPerimetre() {
        return p1.distance(p2) + p2.distance(p3) + p3.distance(p1);
    }

    public boolean equals(Object o) {
        if (!(o instanceof Triangle t)) return false;
        return p1.equals(t.p1) && p2.equals(t.p2) && p3.equals(t.p3); 
    }
}
