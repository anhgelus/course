public class TestSegment {
    public static void main(String[] args) {
        final var s1 = new Segment(6, 8);
        final var s2 = new Segment(12, 5);

        final var l1 = s1.longueur();
        final var l2 = s2.longueur();
        System.out.println(l1 > l2 ? "Le premier est plus long." : "Le deuxième est plus long.");
    }
}
