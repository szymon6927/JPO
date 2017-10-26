package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class ZlozenieTransformacji implements Transformacja  {
	private int ile;
	private String trans;
	private Transformacja[] tab = {};
	
	public ZlozenieTransformacji(int count, String rodzaTransformacji) {
		this.ile = count;
		this.trans = rodzaTransformacji;
		
		if(rodzaTransformacji.equals("Skalowanie")) {
			this.tab = new Skalowanie[count];
			for(int i=0; i<tab.length; i++){
				tab[i] = new Skalowanie(i + 1, i + 2);
				System.out.println(tab[i]);
	        }
        } 
		else if(rodzaTransformacji.equals("Translacja")) {
			this.tab = new Translacja[count];
			for(int i=0; i<tab.length; i++){
				tab[i] = new Translacja(i + 1, i + 2);
				System.out.println(tab[i]);
	        }
        }
		
	}
	
	@Override
	public Transformacja getTransformacjaOdwrotna() {
		for (int i = 0; i < tab.length; i++) {
			try {
				tab[i].getTransformacjaOdwrotna();
			} catch (BrakTransformacjiOdwrotnejException ex) {
				ex.printStackTrace();
			}
		}
		return new ZlozenieTransformacji(this.ile, this.trans);
	}

	@Override
	public Punkt transformuj(Punkt p) {
		int counter = 0;
		Punkt newPunkt = new Punkt(p.getX(), p.getY());
		if(this.trans.equals("Skalowanie")) {
			for(int i=0; i<tab.length; i++) {
				System.out.println("Transformacja nr: " + counter);
				newPunkt = tab[i].transformuj(p);
				counter++;
	        }
			return new Punkt(1 / newPunkt.getX(), 1 / newPunkt.getY());
        } 
		// je¿eli nie skalowanie to zwórc translacje
		for(int i=0; i<tab.length; i++){
			System.out.println("Transformacja nr: " + counter);
			newPunkt = tab[i].transformuj(p);
			counter++;
        }
		return new Punkt(p.getX() + newPunkt.getX(), p.getY() + newPunkt.getY());
	}
	
	@Override
	public String toString() {
		return "ZlozenieTransformacji, ilosc wykonanych transformacji: " + this.ile;
	}
}
