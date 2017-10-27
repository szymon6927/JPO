package pl.edu.pg.eti.ksg.po.lab2.biegpolesie;
import java.util.HashSet;
import java.util.Set;

public class BiegPoLesie {
	private Set<Uczestnik> uczestnicy;
	
	public BiegPoLesie() {
		uczestnicy = new HashSet<>();
	}
	
	public void zmaganiaZElementemTrasy() {
		
	}
	
	public void dodajUczestnika(Uczestnik uczestnik) {
		uczestnicy.add(uczestnik);
	}
	
	public void przeprowadzImpreze() {
		System.out.println("Hurr dziala");
	}
}
