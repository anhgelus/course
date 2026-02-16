public final class Coureur {
    private int numDossard;
    private double tempsAu100;
    private boolean possedeTemoin;

    public Coureur(int num) {
        numDossard = num;
        possedeTemoin = false;
        tempsAu100 = Math.random() * (16-12) + 12;
    }

    public Coureur() {
        this((int) (Math.random() * 999 + 1));
    }

    public int getNumDossard() {
        return numDossard;
    }

    public double getTempsAu100() {
        return tempsAu100;
    }

    public boolean getPossedeTemoin() {
        return possedeTemoin;
    }

    public void setNumDossard(int num) {
        numDossard = num;
    }

    public void setTempsAu100(double temps) {
        tempsAu100 = temps;
    }

    public void setPossedeTemoin(boolean has) {
        possedeTemoin = has;
    }

    public String toString() {
        return String.format("Coureur %d tempsAu100 : %.1f au 100m possedeTemoin %s", numDossard, tempsAu100, possedeTemoin ? "oui" : "non");
    }

    public void passeTemoin(Coureur c) {
        System.out.println("moi, coureur "+numDossard+", je passe le témoin au coureur "+c.numDossard);
        c.possedeTemoin = true;
        possedeTemoin = false;
    }

    public void courir() {
        System.out.println("e suis le coureur "+numDossard+" et je cours");
    }
}
