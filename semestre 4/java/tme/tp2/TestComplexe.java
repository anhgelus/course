public final class TestComplexe {
    public static void main(String[] args) {
        final Complexe[] cs = {new Complexe(), new Complexe(), new Complexe()};
        for (var c : cs) System.out.println("real " + c.estReel());
        for (var c1 : cs) {
            for (var c2 : cs) {
                System.out.println("(" + c1 + ") + (" + c2 + ") = " + c1.addition(c2));
                System.out.println("(" + c1 + ") * (" + c2 + ") = " + c1.multiplication(c2));
            }
        }
    }
}
