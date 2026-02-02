public class Villageois {
    private String nom;
    private double poids;
    private boolean malade;

    public Villageois(String nom) {
        this.nom = nom;
        this.poids = Math.random() * (150-50)+50;
        this.malade = Math.random() < 0.2;
    }

    public String getNom() { return nom; }
    public double getPoids() { return poids; }
    public boolean getMalade() { return malade; }

    public double poidsSouleve() {
        return malade ? (double) 1/3 * poids : (double) 1/4 * poids;
    }

    public String toString() {
        return String.format("Villageois [%s, %.2f, %b, %.2f]", nom, poids, malade, poidsSouleve());
    }
}
