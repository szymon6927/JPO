
package pl.edu.pg.eti.ksg.po.lab2.biegpolesie;

/**
 * Rodzaje terenu na jakie mog¹ natkn¹æ siê uczestnicy biegu po lesie
 * @author TB
 */
public enum RodzajTerenu {
	/** 
	 * Teren po którym ³atwo jest siê porsuzaæ 
	 */
	DROGA,
	/**
	 * Nieco mniej przebie¿na ni¿
	 * {@link pl.edu.pg.eti.ksg.po.lab2.biegpolesie.RodzajTerenu#DROGA}
	 */
	SCIEZKA,
	/** 
	 * Teren w którym trzeba siê ostro¿nie pruszaæ 
	 */
	WYSOKI_LAS,
	/** 
	 * Teren trudny 
	 */
	NISKI_LAS,
	/** 
	 * Teren niebezpieczny, prawie niemo¿liwy do przebycia 
	 */
	BAGNO;
}
