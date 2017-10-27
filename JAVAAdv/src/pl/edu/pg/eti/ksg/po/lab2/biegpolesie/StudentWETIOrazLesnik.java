package pl.edu.pg.eti.ksg.po.lab2.biegpolesie;

public class StudentWETIOrazLesnik {
	private String name;
	private String lastName;
	private Czlowiek.Plec plec;
	private String dziedzina;
	
	public StudentWETIOrazLesnik(String name, String lastName, Czlowiek.Plec plec, String dziedzina) {
		this.name = name;
		this.lastName = lastName;
		this.plec = plec;
		this.dziedzina = dziedzina;
	}
	
}
