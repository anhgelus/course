public class Point {
    private int posX, posY;

    public Point(int x, int y) {
        posX = x;
        posY = y;
    }

    public Point() {
        posX = (int) (Math.random()*10);
        posY = (int) (Math.random()*10);
    }

    public Point(Point p) {
        posX = p.posX;
        posY = p.posY;
    }

    public String toString() {
        return String.format("(%d,%d)", posX, posY);
    }

    public double distance(Point p) {
        return Math.sqrt(
                (p.posX - posX)*(p.posX - posX) + (p.posY - posY)*(p.posY - posY)
        );
    }

    public void deplaceToi(int x, int y) {
        posX = x;
        posY = y;
    }

    public boolean equals(Object o) {
        if (!(o instanceof final Point p)) return false;
        return posX == p.posX && posY == p.posY;
    }
}
