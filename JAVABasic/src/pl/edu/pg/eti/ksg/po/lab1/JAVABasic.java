package pl.edu.pg.eti.ksg.po.lab1;

import pl.edu.pg.eti.ksg.po.lab1.transformacje.Translacja;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.ZlozenieTransformacji;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.Skalowanie;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.BrakTransformacjiOdwrotnejException;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.Punkt;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.Transformacja;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.Obrot;

public class JAVABasic {
	public static void main(String[] args) {
		/*
		 * Konstrukcja jêzykowa try {} catch (...){} s³u¿y do obs³ugi wyj¹tków.
		 * Kod w bloku try jest monitorowany pod k¹tem wyst¹pienia wyj¹tku b¹dŸ
		 * wyj¹tków wspomnianych na pocz¹tku bloku/bloków catch. Je¿eli gdzieœ w
		 * bloku try wyst¹pi wyj¹tek, to sterowanie zostanie natychmiast
		 * przeniesione do bloku catch. Tam powinien znajdowaæ siê kod
		 * obs³uguj¹cy wyj¹tek. Mo¿e to byæ np. wypisanie stosu wywo³añ na
		 * wyjœcie b³êdów lub zapisanie wyj¹tku w logach, lub wyrzucenie
		 * (zg³oszenie) innego wyj¹tku lepiej opisuj¹cego sytuacje (mo¿na
		 * za³¹czyæ wyj¹tek który zainicjowa³ to zdarzenie patrz. Konstruktor
		 * klasy java.lang.Exception)
		 */ 
		try {
			Punkt p1 = Punkt.E_X;
			System.out.println(p1);
			Transformacja tr = new Translacja(5, 6);
			System.out.println(tr);
			Punkt p2 = tr.transformuj(p1);
			System.out.println(p2);
			Transformacja trr = tr.getTransformacjaOdwrotna();
			System.out.println(trr);
			Punkt p3 = trr.transformuj(p2);
			System.out.println(p3);
		} 
		catch (BrakTransformacjiOdwrotnejException ex) {
			ex.printStackTrace();
		}
		System.out.println();
		try {
			Punkt p1 = new Punkt(2, 2);
			System.out.println(p1);
			Transformacja tr2 = new Skalowanie(5, 4);
			System.out.println(tr2);
			Punkt p2 = tr2.transformuj(p1);
			System.out.println(p2);
			Transformacja trr2 = tr2.getTransformacjaOdwrotna();
			System.out.println(trr2);
			Punkt p3 = trr2.transformuj(p2);
			System.out.println(p3);
		} catch (BrakTransformacjiOdwrotnejException ex) {
			ex.printStackTrace();
		}
		System.out.println();
		try {
			Punkt p1 = new Punkt(2, 2);
			Transformacja tr2 = new Skalowanie(5, 0);
			System.out.println(tr2);
			System.out.println(p1);
			Punkt p2 = tr2.transformuj(p1);
			System.out.println(p2);
			Transformacja trr2 = tr2.getTransformacjaOdwrotna();
			System.out.println(trr2);
			Punkt p3 = trr2.transformuj(p2);
			System.out.println(p3);
		} 
		catch (BrakTransformacjiOdwrotnejException ex) {
			ex.printStackTrace();
		}
		System.out.println();
		try {
			Punkt p1 = new Punkt(3,2);
			System.out.println(p1);
			Transformacja tr2 = new Obrot(80);
			System.out.println(tr2);
			Punkt p2 = tr2.transformuj(p1);
			System.out.println(p2);
			Transformacja trr2 = tr2.getTransformacjaOdwrotna();
			System.out.println(trr2);
			Punkt p3 = trr2.transformuj(p2);
			System.out.println(p3);
		}
		catch(BrakTransformacjiOdwrotnejException ex) {
			ex.printStackTrace();
		}
		System.out.println();
		try {
			Punkt p1 = new Punkt(5,5);
			System.out.println(p1);
			Transformacja tr2 = new ZlozenieTransformacji(3, "Skalowanie");
			System.out.println(tr2);
			Punkt p2 = tr2.transformuj(p1);
			System.out.println(p2);
			System.out.println("Transformacja odwrotna: ");
			Transformacja trr2 = tr2.getTransformacjaOdwrotna();
			Punkt p3 = trr2.transformuj(p2);
			System.out.println(p3);
		}
		catch(BrakTransformacjiOdwrotnejException ex) {
			ex.printStackTrace();
		}
		
		System.out.println();
		try {
			Punkt p1 = new Punkt(5,5);
			System.out.println(p1);
			Transformacja tr2 = new ZlozenieTransformacji(3, "Translacja");
			System.out.println(tr2);
			Punkt p2 = tr2.transformuj(p1);
			System.out.println(p2);
			System.out.println("Transformacja odwrotna translacja: ");
			Transformacja trr2 = tr2.getTransformacjaOdwrotna();
			Punkt p3 = trr2.transformuj(p2);
			System.out.println(p3);
		}
		catch(BrakTransformacjiOdwrotnejException ex) {
			ex.printStackTrace();
		}
	}
}