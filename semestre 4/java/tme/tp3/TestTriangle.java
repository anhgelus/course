public class TestTriangle {
    public static void main(String[] args) {
        final var p1 = new Point();
        final var p2 = new Point();
        System.out.println(p1);
        System.out.println(p2);
        
        final var p3 = new Point();
        final var t = new Triangle(p1, p2, p3);
        System.out.println(t);
        System.out.println(t.getPerimetre());

        final var t2 = new Triangle(t);
        p1.deplaceToi(0,0);
        System.out.println(t);
        System.out.println(t2);
    }
}
