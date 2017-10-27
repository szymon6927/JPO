package pl.edu.pg.eti.ksg.po.lab2.biegpolesie;

public class StudentPolitechniki extends Student {
	public StudentPolitechniki(String name, String lastName, Czlowiek.Plec plec, String dziedzina) {
		super(name, lastName, plec, dziedzina);
	}
	
	@Override
	public boolean rozwiazZadanie() {
		// TODO Auto-generated method stub
		return super.rozwiazZadanie();
	}

	@Override
	public int predkoscPoruszaniaSie() {
		// TODO Auto-generated method stub
		return super.predkoscPoruszaniaSie();
	}
}
