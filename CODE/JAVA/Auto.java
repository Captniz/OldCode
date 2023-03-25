//221128_garage.java
public class Auto {
    private String marca;
    private String modello;
    private int cilindrata;
    private float costo;
    private boolean autodistruttore;

    Auto(String marca, String modello, int cilindrata, float costo, boolean autodistruttore) {
        this.marca = marca;
        this.modello = modello;
        this.cilindrata = cilindrata;
        this.costo = costo;
        this.autodistruttore = autodistruttore;
    }

    public String getMarca() {
        return marca;
    }
    public String getModello() {
        return modello;
    }
    public int getCilindrata() {
        return cilindrata;
    }
    public float getCosto() {
        return costo;
    }
    public boolean getAutodistruttore() {
        return autodistruttore;
    }
}
