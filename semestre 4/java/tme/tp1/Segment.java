public class Segment {
    private int x;
    private int y;

    public Segment(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int longueur() {
        return x < y ? y - x : x - y;
    }

    public String toString() {
        return String.format("Segment [%d, %d]", x, y);
    }
}
