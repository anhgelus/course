public class Cabine {
    private int volume;
    private String couleur;

    public Cabine(int vol, String col) {
        volume = vol;
        couleur = col;
    }

    public Cabine(Cabine cb) {
        volume = cb.volume;
        couleur = cb.couleur;
    }

    public String toString() {
        return String.format("Cabine{%d, %s}", volume, couleur);
    }

    public void setCouleur(String col) {
        couleur = col;
    }
}
