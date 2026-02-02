public class TestLettre {
    public static void main(String[] args) {
        for (char c = 'a'; c <= 'z'; c++) {
            final var l = new Lettre(c);
            System.out.print(l.getCarac() + " ");
            if ((c - 'a' + 1)%5 == 0) System.out.print("\n");
        }
    }
}
