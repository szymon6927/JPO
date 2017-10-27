package pl.edu.pg.eti.ksg.po.lab2.biegpolesie;

public class Robot implements Uczestnik {
	private int id;
	
	public Robot(int id) {
		this.id = id;
	}
	
	@Override
	public boolean rozwiazZadanie() {
		return Uczestnik.randInt(0, 19) == 0;
	}

	@Override
	public int predkoscPoruszaniaSie() {
		// TODO Auto-generated method stub
		return 0;
	}
}
