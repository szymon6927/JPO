package pl.edu.pg.eti.ksg.po.lab2.biegpolesie;

public class Zadanie implements ElementTrasy {
	private String zadanie;
	private DziedzinaZadania dziedzinaZadania;
	
	public Zadanie(String zadanie, DziedzinaZadania dziedzinaZadania) {
		this.zadanie = zadanie;
		this.dziedzinaZadania = dziedzinaZadania;
	}
}
