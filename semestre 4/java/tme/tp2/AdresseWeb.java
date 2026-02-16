public class AdresseWeb {
    private final String protocole;
    private final String domaine;
    private final String chemin;

    public AdresseWeb(String proto, String dom, String path) {
        protocole = proto;
        domaine = dom;
        chemin = path;
    }

    public AdresseWeb(String dom, String path) {
        this("http", dom, path);
    }

    public AdresseWeb(String dom) {
        this("http", dom, "");
    }

    public String toString() {
        return protocole + "://www." + domaine + chemin;
    }
}
