package pl.edu.pg.eti.ksg.po.lab2.biegpolesie;

public class Czlowiek implements Uczestnik {
	protected String name;
	protected String lastName;
	protected Czlowiek.Plec plec;
	
	public Czlowiek(String name, String lastName, Czlowiek.Plec plec) {
		this.name = name;
		this.lastName = lastName;
		this.plec = plec;
	}
	
	public enum Plec {
		MEZCZYZNA,
		KOBIETA
	}
	
	@Override
	public boolean rozwiazZadanie() {
		return Uczestnik.randInt(0, 9) == 0;
	}

	@Override
	public int predkoscPoruszaniaSie() {
		// TODO Auto-generated method stub
		return 0;
	}
	
	
}
