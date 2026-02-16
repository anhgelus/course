public class Tracteur {
    private Cabine cabine;
    private Roue r1;
    private Roue r2;
    private Roue gr1;
    private Roue gr2;

    public Tracteur(Cabine cabine, Roue r1, Roue r2, Roue gr1, Roue gr2) {
        this.cabine = cabine;
        this.r1 = r1;
        this.r2 = r2;
        this.gr1 = gr1;
        this.gr2 = gr2;
    }

    public Tracteur(Tracteur t) {
        this(new Cabine(t.cabine), t.r1, t.r2, t.gr1, t.gr2);
    }

    public void peindre(String col) {
        cabine.setCouleur(col);
    }

    public String toString() {
        return String.format("Tracteur{%s, %s, %s, %s, %s}", cabine, r1, r2, gr1, gr2);
    }
}
