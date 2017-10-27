package pl.edu.pg.eti.ksg.po.lab2.biegpolesie;

public class Student extends Czlowiek {
	private String name;
	private String lastName;
	private Czlowiek.Plec plec;
	private String dzedzina;
	
	public Student(String name, String lastName, Czlowiek.Plec plec, String dziedzina) {
		this.name = name;
		this.lastName = lastName;
		this.plec = plec;
		this.dzedzina = dziedzina;
	}
}
