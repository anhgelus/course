public class Personne {
    public final String name;
    private Personne conjoint;

    public Personne(String n) {
        name = n;
    }

    public Personne() {
        this("Pers" + (char) ((int) (Math.random() * 26) + 'A'));
    }

    public String toString() {
        return String.format("%s, %s", name, conjoint == null ? "célibataire" : "marié(e)");
    }

    public void epouser(Personne p) {
        if (p.conjoint != null || conjoint != null || p == this) {
            System.out.println(String.format(
                        "Le mariage de %s avec %s est impossible", this, p
            ));
            return;
        }
        System.out.println(String.format(
                    "%s se marie avec %s", this, p
        ));
        conjoint = p;
        p.conjoint = this;
    }

    public void divorcer() {
        if (conjoint == null) return;
        System.out.println(String.format(
                    "%s divorce avec %s", this, conjoint
        ));
        conjoint.conjoint = null;
        conjoint = null;
    }

    public static void main(String[] args) {
        final var p1 = new Personne();
        final var p2 = new Personne();
        final var p3 = new Personne();

        p1.epouser(p2);
        p1.epouser(p3);
        p3.epouser(p1);
        p3.epouser(p3);
        p1.divorcer();
        p3.divorcer();
    }
}
