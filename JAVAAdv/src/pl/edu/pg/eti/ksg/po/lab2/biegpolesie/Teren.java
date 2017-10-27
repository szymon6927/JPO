package pl.edu.pg.eti.ksg.po.lab2.biegpolesie;

public class Teren implements ElementTrasy {
	protected String teren;
	private RodzajTerenu rodzajTerenu;
	
	protected Teren(String teren,RodzajTerenu rodzajTerenu) {
		this.teren = teren;
		this.rodzajTerenu = rodzajTerenu;
	}
}
