public class TestCoureur {
    public static void main(String[] args) {
        final var c1 = new Coureur();
        final var c2 = new Coureur();
        final var c3 = new Coureur();
        final var c4 = new Coureur();
        c1.courir();
        c1.passeTemoin(c2);
        c2.courir();
        c2.passeTemoin(c3);
        c3.courir();
        c3.passeTemoin(c4);
        c4.courir();
        System.out.println("temps : " + (c1.getTempsAu100() + c2.getTempsAu100() + c3.getTempsAu100() + c4.getTempsAu100()));
    }
}
