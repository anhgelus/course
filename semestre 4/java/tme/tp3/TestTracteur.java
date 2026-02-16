public class TestTracteur {
    public static void main(String[] args) {
        final var r1 = new Roue();
        final var r2 = new Roue();
        final var gr1 = new Roue(120);
        final var gr2 = new Roue(120);
        final var cb = new Cabine(3, "bleue");

        final var t1 = new Tracteur(cb, r1, r2, gr1, gr2);
        System.out.println(t1);
        final var t2 = new Tracteur(t1);
        t2.peindre("rouge");
        System.out.println(t2);
    }
}
