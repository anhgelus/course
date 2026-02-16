public final class Complexe {
    public final double reelle;
    public final double imag;

    public Complexe(double reelle, double imag) {
        this.reelle = reelle;
        this.imag = imag;
    }

    public Complexe() {
        this(Math.random() * 4 - 2, Math.random() * 4 - 2);
    }

    public String toString() {
        return String.format("%f + %fi", reelle, imag);
    }

    public boolean estReel() {
        return imag == 0;
    }

    public Complexe addition(Complexe c) {
        return new Complexe(reelle + c.reelle, imag + c.imag);
    }

    public Complexe multiplication(Complexe c) {
        return new Complexe(reelle * c.reelle - imag * c.imag, reelle * c.reelle + imag * c.imag);
    }
}
