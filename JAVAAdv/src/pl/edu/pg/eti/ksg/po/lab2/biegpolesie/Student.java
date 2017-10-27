package pl.edu.pg.eti.ksg.po.lab2.biegpolesie;

public class Student extends Czlowiek {
	protected String dzedzina;
	
	public Student(String name, String lastName, Czlowiek.Plec plec, String dziedzina) {
		super(name, lastName, plec);
		this.dzedzina = dziedzina;
	}
}
