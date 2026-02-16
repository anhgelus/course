public class TestAdresseWeb {
    public static void main(String[] args) {
        System.out.println(new AdresseWeb("hey"));
        System.out.println(new AdresseWeb("hey", "/"));
        System.out.println(new AdresseWeb("https", "hey", "/"));
    }
}
